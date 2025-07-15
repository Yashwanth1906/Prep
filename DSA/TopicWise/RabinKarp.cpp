#include <bits/stdc++.h>
using namespace std;
#define ll long long

class RabinKarp {
    const ll PRIME = 101;

    ll power(ll base, ll exp) {
        ll result = 1;
        while (exp--) result *= base;
        return result;
    }

public:
    ll findHash(string s) {
        ll hash = 0;
        for (ll i = 0; i < s.size(); i++) {
            hash += s[i] * power(PRIME, i);
        }
        return hash;
    }

    ll updateHash(ll oldHash, char oldChar, char newChar, ll slen) {
        ll newHash = (oldHash - oldChar) / PRIME;
        newHash += newChar * power(PRIME, slen - 1);
        return newHash;
    }

    bool search(string s, string pattern) {
        ll plen = pattern.size();
        if (s.size() < plen) return false;

        ll phash = findHash(pattern);
        ll shash = findHash(s.substr(0, plen));

        for (ll i = 0; i <= s.size() - plen; i++) {
            if (shash == phash) {
                if (s.substr(i, plen) == pattern) {
                    return true;
                }
            }
            if (i + plen < s.size()) {
                shash = updateHash(shash, s[i], s[i + plen], plen);
            }
        }
        return false;
    }
};


// this is the actual rolling hash implementation using prefix
#define ll long long
class Solution {
public:
    int beautifulSplits(vector<int>& nums)  {
        int n = nums.size();
        if(n < 3) return 0;
        ll mod = 1e9 + 7;
        ll base = 31;
        int ans = 0;
        vector<long> pHash(n+1,0);
        vector<long> power(n+1, 1);
        for(int i = 0; i < n;i++) {
            power[i+1] = (power[i] * base) % mod;
            pHash[i+1] = (pHash[i] * base + nums[i]) % mod;
        }
        for(int i = 1; i < n - 1;i++) {
            for(int j = i+1; j < n;j++) {
                bool valid = false;
                if(isPrefix(pHash,0,i,i,j,mod,power)) {
                    valid = true;
                }
                if(!valid && isPrefix(pHash, i,j,j,n,mod, power)) {
                    valid = true;
                }
                if(valid) {
                    ans++;
                }
            }
        }
        return ans;
    }

private:
    bool isPrefix(const vector<long>& hash, int start1, int end1, int start2, int end2, long mod, const vector<long>& pow) {
        int len1 = end1 - start1;
        int len2 = end2 - start2;
        if (len1 > len2) {
            return false;
        }
        long hash1 = (hash[end1] - (hash[start1] * pow[len1]) % mod + mod) % mod;
        long hash2 = (hash[start2 + len1] - (hash[start2] * pow[len1]) % mod + mod) % mod;
        return hash1 == hash2;
    }
};


int main() {
    string s = "HelloHowareyou";
    string pattern = "Howv";
    RabinKarp r;
    cout << r.search(s, pattern) << endl; // Expected: 1
}
