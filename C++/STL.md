- unordered_set -> https://takeuforward.org/c/unordered-set-in-c-stl/
- vector -> https://takeuforward.org/c/vector-in-c-stl/
- set -> https://takeuforward.org/c/set-in-c-stl/
- unordered-multiset -> https://takeuforward.org/c/unordered-multiset-in-c-stl
- multiset -> https://takeuforward.org/c/multiset-in-c-stl
- unordered_map -> https://takeuforward.org/c/unordered_map-in-c-stl
- map -> https://takeuforward.org/c/unordered_map-in-c-stl
- unordered_multimap -> https://takeuforward.org/c/unordered_multimap-in-c-stl/
- queue -> https://takeuforward.org/c/queue-in-c-stl/
- stack -> https://takeuforward.org/c/stack-in-c-stl/
- deque -> https://takeuforward.org/c/deque-in-c-stl/
- priority_queue -> https://takeuforward.org/c/priority_queue-in-c-stl/
- multimap -> https://takeuforward.org/c/multimap-in-c-stl/
- list -> https://takeuforward.org/c/list-in-c-stl/
- next_permutation ->  https://takeuforward.org/c/next_permutation-in-c-stl/
- builtin-popcount-in-stl -> https://takeuforward.org/c/builtin-popcount-in-stl-cpp-count-set-bits/
- sort-in-c-stl -> https://takeuforward.org/c/sort-in-c-stl/
- min_element -> https://takeuforward.org/c/min-element-in-c-stl/
- max_element -> https://takeuforward.org/c/max-element-in-c-stl/

Vector:
A vector is a dynamic array that stores elements in contiguous memory. Its special property is random access in O(1) time and amortized O(1) insertion at the end (push_back). However, inserting or erasing in the middle or front costs O(n) because elements must be shifted. Searching is also O(n) unless sorted with binary search.

Deque:
A deque (double-ended queue) is like a vector but supports fast insertion and deletion at both ends. Its special thing is O(1) push/pop at front and back while still supporting O(1) random access. Middle insertions are O(n) and searching is O(n).

List:
A list is a doubly linked list where elements are scattered in memory and connected by pointers. Its strength is that insertion and deletion at any position is O(1) if you already have the iterator. The weakness is no random access (access by index is O(n)), and searching is O(n).

Stack:
A stack is a container adapter that provides Last-In-First-Out (LIFO) access. Its special thing is that you can only access the top element. Both push, pop, and top are O(1) operations. Searching is not supported efficiently.

Queue:
A queue is a container adapter providing First-In-First-Out (FIFO) access. Its special feature is that you can only access the front and back. Push, pop, front, and back are O(1) operations.

Priority Queue:
A priority_queue is a max-heap (by default) that always gives access to the largest element. Its specialty is that top is O(1) while push and pop are O(log n) due to heap reordering. Searching for arbitrary elements is O(n).

Set:
A set is an ordered container that stores unique keys in sorted order. Its special property is that all operations like search, insert, and erase are O(log n). It maintains elements automatically in order using a balanced BST.

Multiset:
A multiset is like set but allows duplicate keys. Its special feature is storing multiple identical elements while keeping them sorted. The complexities are the same: O(log n) for search, insert, and erase.

Map:
A map is an ordered associative container that stores key-value pairs with unique keys in sorted order. Its specialty is fast lookup by key in O(log n). Insert, erase, and search all take O(log n). Access with [] is also O(log n).

Multimap:
A multimap is similar to map but allows duplicate keys. Keys are sorted, and multiple values can be stored for the same key. Operations like insert, search, and erase are all O(log n).

Unordered Set:
An unordered_set stores unique elements but does not maintain order. It is hash-based, so the special thing is that search, insert, and erase are O(1) on average, but can degrade to O(n) in worst case (hash collisions).

Unordered Multiset:
This is like unordered_set but allows duplicate elements. Special feature: average O(1) for search, insert, and erase, but worst case is O(n).

Unordered Map:
An unordered_map stores key-value pairs with unique keys, but the keys are not ordered. Its special thing is O(1) average lookup, insert, and erase using hashing. Worst case is O(n). Access with [] is also O(1) average.

Unordered Multimap:
This is like unordered_map but allows duplicate keys. It does not maintain any order, and operations are O(1) on average, O(n) worst-case.


- All the Unordered Stuffs are hash based containers while the other normal set , map are Balanced Binary search tree
implementation typically Red Black Tree.
