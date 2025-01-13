#include<bits/stdc++.h>
using namespace std;

/*
Problem statement
You are given an array 'arr' of length 'n'. Find the index(0-based) of a peak element in the array. If there are multiple peak numbers, return the index of any peak number.

Peak element is defined as that element that is greater than both of its neighbors. If 'arr[i]' is the peak element, 'arr[i - 1]' < 'arr[i]' and 'arr[i + 1]' < 'arr[i]'.

Assume 'arr[-1]' and 'arr[n]' as negative infinity.

Note:
1.  There are no 2 adjacent elements having same value (as mentioned in the constraints).
2.  Do not print anything, just return the index of the peak element (0 - indexed).
3. 'True'/'False' will be printed depending on whether your answer is correct or not.

Example:
Input: 'arr' = [1, 8, 1, 5, 3]

Output: 3
Explanation: There are two possible answers. Both 8 and 5 are peak elements, so the correct answers are their positions, 1 and 3.
*/

// NOTE:If we have multiple peaks we need to return any peak


int findPeakElement(vector<int> &arr) {
  // Write your code here
  int l = 1, h = arr.size() - 2;
  int n = arr.size();
  if (n == 1)
    return 0;

  if (arr[0] > arr[1])
    return 0;

  if (arr[n - 1] > arr[n - 2])
    return n - 1;

  while (l <= h) {
    int mid = (l + h) / 2;

    if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
      return mid;

    if (arr[mid] < arr[mid - 1]) {
      h = mid - 1;
    } else if (arr[mid] > arr[mid - 1]) {
      l = mid + 1;
    } else {
      l = mid + 1; 
    //   h=mid-1; // we can also use this statemnt instead of l=mid+1;
    }
  }

  return -1;
}


signed main()
{

}