#include <bits/stdc++.h>
using namespace std;

/*
Problem statement
You have been given a sorted array/list 'arr' consisting of ‘n’ elements. You are also given an integer ‘k’.

Now the array is rotated at some pivot point unknown to you.
For example, if 'arr' = [ 1, 3, 5, 7, 8], then after rotating 'arr' at index 3, the array will be 'arr' = [7, 8, 1, 3, 5].

Now, your task is to find the index at which ‘k’ is present in 'arr'.

Note :
1. If ‘k’ is not present in 'arr', then print -1.
2. There are no duplicate elements present in 'arr'.
3. 'arr' can be rotated only in the right direction.

Example:
Input: 'arr' = [12, 15, 18, 2, 4] , 'k' = 2

Output: 3

Explanation:
If 'arr' = [12, 15, 18, 2, 4] and 'k' = 2, then the position at which 'k' is present in the array is 3 (0-indexed).
*/

int search(vector<int> &arr, int n, int k)
{

    int l = 0, h = n - 1;

    while (l <= h)
    {
        int mid = (l + h) / 2;

        if (arr[mid] == k)
            return mid;

        if (arr[mid] >= arr[l])
        {
            // left half is sorted

            if (arr[l] <= k && k <= arr[mid])
            {
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        else
        {
            // right half is sorted
            
            if (arr[mid] <= k && k <= arr[h])
            {
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }
    }
    return -1;
}

signed main()
{
}