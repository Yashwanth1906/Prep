#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int left, int right) {
  int pivot = arr[right];
  int i = left - 1;
  for(int j = left;j < right;j++) {
    if(arr[j] < pivot) {
      i++;
      swap(arr[j], arr[i]);
    }
  }
  swap(arr[i+1], arr[right]);
  return i + 1;
}

void quickSort(vector<int>& arr, int left, int right) {
  if(left >= right) return;
  int pivot = partition(arr,left, right);
  quickSort(arr, left, pivot - 1);
  quickSort(arr, pivot + 1, right);
}



int main() {
  vector<int> arr = {45, 10, 7, 65, 54, 78, 53};
  int n = arr.size();
  quickSort(arr, 0, n -1);
  for(auto it : arr) cout<<it<<" ";
  cout<<endl;
}


/*QuickSort is a sorting algorithm based on the Divide and Conquer that picks an element as a pivot and partitions the given array around the picked pivot by placing the pivot in its correct position in the sorted array.

It works on the principle of divide and conquer, breaking down the problem into smaller sub-problems.

There are mainly three steps in the algorithm:

Choose a Pivot: Select an element from the array as the pivot. The choice of pivot can vary (e.g., first element, last element, random element, or median).
Partition the Array: Rearrange the array around the pivot. After partitioning, all elements smaller than the pivot will be on its left, and all elements greater than the pivot will be on its right. The pivot is then in its correct position, and we obtain the index of the pivot.
Recursively Call: Recursively apply the same process to the two partitioned sub-arrays (left and right of the pivot).
Base Case: The recursion stops when there is only one element left in the sub-array, as a single element is already sorted.

Complexity Analysis of Quick Sort
Time Complexity:

Best Case: (Ω(n log n)), Occurs when the pivot element divides the array into two equal halves.
Average Case (θ(n log n)), On average, the pivot divides the array into two parts, but not necessarily equal.
Worst Case: (O(n²)), Occurs when the smallest or largest element is always chosen as the pivot (e.g., sorted arrays).
Auxiliary Space: O(n), due to recursive call stack

Please refer Time and Space Complexity Analysis of Quick Sort for more details.

Advantages of Quick Sort
It is a divide-and-conquer algorithm that makes it easier to solve problems.
It is efficient on large data sets.
It has a low overhead, as it only requires a small amount of memory to function.
It is Cache Friendly as we work on the same array to sort and do not copy data to any auxiliary array.
Fastest general purpose algorithm for large data when stability is not required.
It is tail recursive and hence all the tail call optimization can be done.
Disadvantages of Quick Sort
It has a worst-case time complexity of O(n2), which occurs when the pivot is chosen poorly.
It is not a good choice for small data sets.
It is not a stable sort, meaning that if two elements have the same key, their relative order will not be preserved in the sorted output in case of quick sort, because here we are swapping elements according to the pivot's position (without considering their original positions).



*/
