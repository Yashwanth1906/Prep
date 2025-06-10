#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int left, int mid,int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;
  vector<int> leftArr(n1), rightArr(n2);
  for(int i = 0; i < n1;i++) leftArr[i] = arr[left + i];
  for(int i = 0; i < n2;i++) rightArr[i] = arr[mid + i + 1];
  int i = 0, j = 0, k = left;
  while(i < n1 && j < n2) {
    if(leftArr[i] <= rightArr[j]) arr[k++] = leftArr[i++];
    else arr[k++] = rightArr[j++];
  }
  while(i < n1) arr[k++] = leftArr[i++];
  while(j < n2) arr[k++] = rightArr[j++];
}


void mergeSort(vector<int>& arr,int left, int right) {
  if(left >= right) return;
  int mid = left + (right - left) / 2;
  mergeSort(arr, left, mid);
  mergeSort(arr, mid+1, right);
  merge(arr, left, mid, right);
}


int main() {
  vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
  int n = arr.size();
  mergeSort(arr, 0, n - 1);
  for(auto it : arr) cout<<it<<" ";
  cout<<endl;
}



/*How does Merge Sort work?
Here's a step-by-step explanation of how merge sort works:

Divide:  Divide the list or array recursively into two halves until it can no more be divided. 
Conquer:  Each subarray is sorted individually using the merge sort algorithm. 
Merge:  The sorted subarrays are merged back together in sorted order. The process continues until all elements from both subarrays have been merged. 



The recurrence relation of merge sort is:
T
(
n
)
=
{
Θ
(
1
)
if 
n
=
1
2
T
(
n
2
)
+
Θ
(
n
)
if 
n
>
1
T(n)={ 
Θ(1)
2T( 
2
n
​
 )+Θ(n)
​
  
if n=1
if n>1
​
 

T(n) Represents the total time time taken by the algorithm to sort an array of size n.
2T(n/2) represents time taken by the algorithm to recursively sort the two halves of the array. Since each half has n/2 elements, we have two recursive calls with input size as (n/2).
O(n) represents the time taken to merge the two sorted halves
Complexity Analysis of Merge Sort
Time Complexity:
Best Case: O(n log n), When the array is already sorted or nearly sorted.
Average Case: O(n log n), When the array is randomly ordered.
Worst Case: O(n log n), When the array is sorted in reverse order.
Auxiliary Space: O(n), Additional space is required for the temporary array used during merging.


*/
