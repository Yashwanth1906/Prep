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

int main() {
    string s = "HelloHowareyou";
    string pattern = "Howv";
    RabinKarp r;
    cout << r.search(s, pattern) << endl; // Expected: 1
}
