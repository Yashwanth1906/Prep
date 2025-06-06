# DSA

1. HEAP: (**complete binary tree**)

→ A [**heap**](https://www.tutorialspoint.com/data_structures_algorithms/heap_data_structure.htm) is a [**tree-based data structure**](https://www.tutorialspoint.com/data_structures_algorithms/tree_data_structure.htm) that follows a specific rule called the heap property. It is always a **complete binary tree**, meaning all levels are fully filled, except possibly the last one, which is filled from left to right.

- **Max Heap:** In a **max heap**, the value of each **parent node** is **greater than or equal** to the values of its **children**. This ensures that the **largest element** is always at the **root**.
- **Min Heap:** In a **min heap**, the value of each **parent node** is **less than or equal to** the values of its **children**. This ensures that the **smallest element** is always at the **root**.
- For any node at **index i**, the **left child** is at index **2i + 1** and the **right child** is at index **2i + 2**.

Implementation of Min - Heap:

```cpp
#include <bits/stdc++.h>
using namespace std;

class MinHeap {
    private:
        vector<int> heap;

        void heapify(int ind) {
            int leftChild = 2 * ind + 1;
            int rightChild = 2 * ind + 2;
            int smallest = ind;
            if(leftChild < heap.size() && heap[leftChild] < heap[smallest]) smallest = leftChild;
            if(rightChild < heap.size() && heap[rightChild] < heap[smallest]) smallest = rightChild;
            if(smallest != ind) {
                swap(heap[ind], heap[smallest]);
                heapify(smallest);
            }
        }

        void heapifyUp(int ind) {
            while(ind > 0) {
                int parent = (ind - 1)  / 2;
                if(heap[ind] < heap[parent]) {
                    swap(heap[ind], heap[parent]);
                    ind = parent;
                } else break;
            }
        }
    public:
        MinHeap() {
            heap = {};
        }
        void push(int val) {
            heap.push_back(val);
            heapifyUp(heap.size() - 1);
        }
        int top() {
            if(heap.size() > 1) return heap[0];
            return -1;
        }
        bool pop() {
            if(heap.size()<1) return false;
            heap[0] = heap.back();
            heap.pop_back();
            heapify(0);
            return true;
        }
        void display() {
            for(auto it : heap) cout<<it<<' ';
            cout<<endl;
        }
};

int main() {
    MinHeap pq;
    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.push(-1);
    pq.display();
    cout<<pq.top()<<endl;
    pq.pop();
    pq.display();
}
```

**Time Complexity:** O(log n), due to the **heapify-up** process.

**Space Complexity:** O(n), because we store the elements in the **heap array**.

Implementation of Max - Heap:

```
#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
    private:
        vector<int> heap;

        void heapify(int ind) {
            int leftChild = 2 * ind + 1;
            int rightChild = 2 * ind + 2;
            int largest = ind;
            if(leftChild < heap.size() && heap[leftChild] > heap[largest]) largest = leftChild;
            if(rightChild < heap.size() && heap[rightChild] > heap[largest]) largest = rightChild;
            if(largest != ind) {
                swap(heap[ind], heap[largest]);
                heapify(largest);
            }
        }

        void heapifyUp(int ind) {
            while(ind > 0) {
                int parent = (ind - 1)  / 2;
                if(heap[ind] > heap[parent]) {
                    swap(heap[ind], heap[parent]);
                    ind = parent;
                } else break;
            }
        }
    public:
        MaxHeap() {
            heap = {};
        }
        void push(int val) {
            heap.push_back(val);
            heapifyUp(heap.size() - 1);
        }
        int top() {
            if(heap.size() > 1) return heap[0];
            return -1;
        }
        bool pop() {
            if(heap.size()<1) return false;
            heap[0] = heap.back();
            heap.pop_back();
            heapify(0);
            return true;
        }
        void display() {
            for(auto it : heap) cout<<it<<' ';
            cout<<endl;
        }
};

int main() {
    MaxHeap pq;
    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.push(-1);
    pq.display();
    cout<<pq.top()<<endl;
    pq.pop();
    pq.display();
}
```

**Time Complexity:** O(log n), because we need to **heapify** the **tree** after removal.

**Space Complexity:** O(1), as no extra space is needed for **heapifying**.

Problems : 

**215. Kth Largest Element in an Array**

**23. Merge k Sorted Lists**

**621. Task Scheduler**

**846. Hand of Straights**

**1942. The Number of the Smallest Unoccupied Chair (Practice)**

**295. Find Median from Data Stream**

**347. Top K Frequent Elements**

**355. Design Twitter**

**703. Kth Largest Element in a Stream**

1. Union Find:

```cpp
class UnionFind {
public:
vector<int> parent;
vector<int> rank;

UnionFind(int n) {
    parent.resize(n);
    rank.resize(n, 0);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
}

int find(int i) {
    if (parent[i] != i) {
        parent[i] = find(parent[i]); // Path compression
    }
    return parent[i];
}

void unionByRank(int i, int j) {
    int irep = find(i);
    int jrep = find(j);
    if (irep == jrep) return;
    if (rank[irep] < rank[jrep]) {
        parent[irep] = jrep;
    } else if (rank[irep] > rank[jrep]) {
        parent[jrep] = irep;
    } else {
        parent[jrep] = irep;
        rank[irep]++;
    }
}
};
```

RABIN KARP:

Don’t forget to learn……