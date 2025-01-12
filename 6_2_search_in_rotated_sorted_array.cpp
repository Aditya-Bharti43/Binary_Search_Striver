#include<bits/stdc++.h>
using namespace std;

/*
Problem statement
You are given a rotated sorted array 'a' of length 'n' and a 'key'. You need to determine if the 'key' exists in the array 'a'.

The given sorted array is rotated from an unknown index 'x'. Such that after rotation the array became [a[x], a[x+1]...., a[n-1], a[1]..., a[x-1]], (0-based indexing). For example, if the array is [1, 2, 3, 4, 5] and x = 2 then the rotated array will be [3, 4, 5, 1, 2, 3].

Return True if the 'key' is found in 'a'. Otherwise, return False.

Note: Array ‘a’ may contain duplicate elements.
Example:

Input: a = [6, 10, 1, 3, 5], key = 3

Output: True

Explanation: The array 'a' contains the 'key' = 3, so we return True.
*/

bool searchInARotatedSortedArrayII(vector<int> &A, int key) {

  int l = 0, h = A.size()-1;

  while (l <= h) {
    int mid = (l + h) / 2;

    if (A[mid] == key)
      return 1;

    //    identifying sorted half
// trim down search space if duplicates

    if (A[l] == A[mid] && A[mid] == A[h]) {
      l = l + 1;
      h = h - 1;
      continue;
    }

    if(A[l]<=A[mid])
    {
        if (A[l] <= key && key <= A[mid]) {
      h = mid - 1;
    } else {
      l = mid + 1;
    }
    }
    else{
      if(A[mid]<=key && key<=A[h])
      {
        l=mid+1;
      }
      else{
        h=mid-1;
      }

    }
    
  }

  return 0;
}


signed main()
{

}