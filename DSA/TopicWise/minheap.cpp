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
                heapifyUp(smallest);
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