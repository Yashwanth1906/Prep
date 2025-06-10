#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};
    int n = arr.size();
    for(int i = 0; i < n-1;i++) {
        int min_ind = i;
        for(int j = i + 1; j < n;j++) {
            if(arr[j] < arr[min_ind]) {
                min_ind = j;
            }
        }
        swap(arr[i], arr[min_ind]);
    }
    for(auto it : arr) cout<<it<<" ";
    cout<<endl;
}


/* 

Selection Sort is a comparison-based sorting algorithm. It sorts an array by repeatedly selecting the smallest (or largest) element from the unsorted portion and swapping it with the first unsorted element. This process continues until the entire array is sorted.

First we find the smallest element and swap it with the first element. This way we get the smallest element at its correct position.
Then we find the smallest among remaining elements (or second smallest) and swap it with the second element.
We keep doing this until we get all elements moved to correct position.


Complexity Analysis of Selection Sort
Time Complexity: O(n2) ,as there are two nested loops:

One loop to select an element of Array one by one = O(n)
Another loop to compare that element with every other Array element = O(n)
Therefore overall complexity = O(n) * O(n) = O(n*n) = O(n2)
Auxiliary Space: O(1) as the only extra memory used is for temporary variables.

Advantages of Selection Sort
Easy to understand and implement, making it ideal for teaching basic sorting concepts.
Requires only a constant O(1) extra memory space.
It requires less number of swaps (or memory writes) compared to many other standard algorithms. Only cycle sort beats it in terms of memory writes. Therefore it can be simple algorithm choice when memory writes are costly.
Disadvantages of the Selection Sort
Selection sort has a time complexity of O(n^2) makes it slower compared to algorithms like Quick Sort or Merge Sort.
Does not maintain the relative order of equal elements which means it is not stable.


*/