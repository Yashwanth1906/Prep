#include <bits/stdc++.h>
using namespace std;

class Fib {
    int n;
    class Iterator {
        int a, b, index, n;
    public:
        Iterator(int index, int n, int a = 0, int b = 1)
            : index(index), n(n), a(a), b(b) {}

        int operator*() const { return a; }
   
        Iterator& operator++() {
            int next = a + b;
            a = b;
            b = next;
            ++index;
            return *this;
        }
        bool operator!=(const Iterator& other) const {
            return index != other.index;
        }
    };

public:
    Fib(int n) : n(n) {}

    Iterator begin() const { return Iterator(0, n); }
    Iterator end() const { return Iterator(n, n); }
};

int main() {
    for (int f : Fib(10)) {
        cout << f << " ";
    }
    cout<<endl;
}
