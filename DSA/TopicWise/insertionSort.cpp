#include <bits/stdc++.h>
using namespace std;


int main() {
  vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
  int n = arr.size();
  for(int i = 1; i < n;i++) {
    int key = arr[i];
    int j = i - 1;
    while(j >= 0 && arr[j] > key) {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = key;
  }
  for(auto it : arr) cout<<it<<" ";
  cout<<endl;
}


/*Insertion sort is a simple sorting algorithm that works by iteratively inserting each element of an unsorted list into its correct position in a sorted portion of the list. It is like sorting playing cards in your hands. You split the cards into two groups: the sorted cards and the unsorted cards. Then, you pick a card from the unsorted group and put it in the right place in the sorted group.

We start with the second element of the array as the first element is assumed to be sorted.
Compare the second element with the first element if the second element is smaller then swap them.
Move to the third element, compare it with the first two elements, and put it in its correct position
Repeat until the entire array is sorted.
Complexity Analysis of Insertion Sort
Time Complexity

Best case: O(n), If the list is already sorted, where n is the number of elements in the list.
Average case: O(n2), If the list is randomly ordered
Worst case: O(n2), If the list is in reverse order
Space Complexity

Auxiliary Space: O(1), Insertion sort requires O(1) additional space, making it a space-efficient sorting algorithm.
Please refer Complexity Analysis of Insertion Sort for details.

Advantages and Disadvantages of Insertion Sort
Advantages

Simple and easy to implement.
Stable sorting algorithm.
Efficient for small lists and nearly sorted lists.
Space-efficient as it is an in-place algorithm.
Adoptive. the number of inversions is directly proportional to number of swaps. For example, no swapping happens for a sorted array and it takes O(n) time only.
Disadvantages

Inefficient for large lists.
Not as efficient as other sorting algorithms (e.g., merge sort, quick sort) for most cases.

*/
