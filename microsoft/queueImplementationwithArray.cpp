#include <iostream>
#include <vector>
using namespace std;

class Queue {
public:
  vector<int> arr;
  int frontPtr , backPtr;
  Queue () {
    frontPtr = -1;
    backPtr = -1;
  }

  void push(int ele) {
    if(arr.size() == 0) {
      frontPtr = 0;
      backPtr = 0;
    }
    arr.push_back(ele);
    backPtr = arr.size() - 1;
  }

  void pop() {
    frontPtr+=1;
  }

  int front() {
    return arr[frontPtr];
  }

  int back() {
    return arr[backPtr];
  }

  int size() {
    return backPtr - frontPtr + 1;
  }

  int empty() {
    return backPtr - frontPtr + 1 == 0;
  }

  ~Queue () {
    arr.clear();
    frontPtr = -1;
    backPtr = -1;
  }
};




int main() {
  Queue q; // This is statically allocated objects in which the memory is allocated in the stack space
  // during the compilation itself. It is used when the size of the object is known.
  q.push(1);
  q.push(2);
  q.pop();
  cout<<q.front()<<endl;
  cout<<q.back()<<endl;
  cout<<q.empty()<<endl;
  cout<<q.size()<<endl;
  Queue* q1 = new Queue(); // This type of class allocation is called Dynamically allocated objects.
  // The memory is occupied in the run time in the heap and it is used only when the object memory 
  // space might exceed the stack size or simply when the memory size is unknown. 
  q1->push(2);
  q1->push(3);
  cout<<q1->front()<<endl;
  delete q1;  // Mannual memory clearance is required.
  cout<<q1->size()<<endl;
}
