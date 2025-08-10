# C++ notes

VECTOR FUNCTIONS:

### 🔹 Construction & Assignment

- `vector<T> v` – default constructor
- `vector<T> v(n)` – creates vector with `n` default-initialized elements
- `vector<T> v(n, val)` – vector with `n` copies of `val`
- `v = other` – copy assignment
- `v = std::move(other)` – move assignment

### 🔹 Capacity

- `v.size()` – number of elements
- `v.capacity()` – current allocated capacity
- `v.max_size()` – max possible elements
- `v.empty()` – check if vector is empty
- `v.resize(n)` – resizes to `n` elements
- `v.reserve(n)` – reserves capacity for at least `n` elements
- `v.shrink_to_fit()` – reduce capacity to fit size

### 🔹 Element Access

- `v[i]` or `v.at(i)` – access element
- `v.front()` – first element
- `v.back()` – last element
- `v.data()` – pointer to underlying array

### 🔹 Modifiers

- `v.push_back(x)` – append at end
- `v.pop_back()` – remove last
- `v.insert(pos, x)` – insert `x` at `pos` (iterator)
- `v.erase(pos)` – remove at position (iterator)
- `v.clear()` – remove all elements
- `v.assign(n, x)` – fill with `n` copies of `x`
- `v.swap(v2)` – swap with another vector

### 🔹 Iterators

- `v.begin(), v.end()`
- `v.rbegin(), v.rend()` – reverse iterators
- `v.cbegin(), v.cend()` – const iterators

SET FUNCTIONS:

### 🔹 Basic Operations

- `set<T> s` – default constructor
- `s.insert(x)` – insert element
- `s.erase(x)` – remove element by value
- `s.erase(it)` – remove element by iterator
- `s.find(x)` – returns iterator to `x` or `s.end()`
- `s.count(x)` – returns 1 if `x` exists, 0 otherwise
- `s.clear()` – removes all elements

### 🔹 Properties

- `s.size()`
- `s.empty()`
- `s.max_size()`

### 🔹 Iterators

- `s.begin(), s.end()`
- `s.rbegin(), s.rend()`
- `s.cbegin(), s.cend()`

### 🔹 Range Queries (very useful)

- `s.lower_bound(x)` – first element not less than `x`
- `s.upper_bound(x)` – first element greater than `x`
- `s.equal_range(x)` – returns pair of `(lower_bound(x), upper_bound(x))`

### 🔹 Others

- `s.swap(s2)`
- `s.emplace(x)` – insert using in-place construction (like insert, but more efficient)


### Important NOTES:

- ASCII VALUES : 0 - 9 -> 48 - 57
- ASCII VALUES : a - z -> 97 - 122
- ASCII VALUES : a - z -> 65 - 90


## Dangling Pointers:

- A dangling pointer in C++ is a pointer that still holds the address of a memory location that has already been freed or is no longer valid.Using a dangling pointer leads to undefined behavior — your program might crash, produce wrong results, or even seem to work sometimes (which is worse).

How Dangling Pointers Happen

1. Deleting memory but still keeping the pointer
#include <iostream>
using namespace std;

int main() {
    int* ptr = new int(10);
    delete ptr;   // Memory freed
    // ptr still holds the old address — now dangling

    cout << *ptr; // ❌ Undefined behavior
}

2. Pointer to a local variable (goes out of scope)

int* getPointer() {
    int x = 42;    // Stored on stack
    return &x;     // Returning address of local variable ❌
}                  // x is destroyed when function ends

int main() {
    int* p = getPointer();
    cout << *p;    // ❌ Dangling pointer
}

3. Pointer to an object that has been destroyed

struct Demo {
    void show() { cout << "Hello\n"; }
};

int main() {
    Demo* p;
    {
        Demo d;
        p = &d;  // Points to object on stack
    }            // d is destroyed here
    p->show();   // ❌ Dangling pointer
}


