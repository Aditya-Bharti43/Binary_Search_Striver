#include <bits/stdc++.h>
using namespace std;

/*
    Problem statement
You are given an array 'arr' having 'n' distinct integers sorted in ascending order. The array is right rotated 'r' times
Find the minimum value of 'r'.

Right rotating an array means shifting the element at 'ith' index to (‘i+1') mod 'n' index, for all 'i' from 0 to ‘n-1'.

Example:
Input: 'n' = 5 , ‘arr’ = [3, 4, 5, 1, 2]

Output: 3

Explanation:
If we rotate the array [1 ,2, 3, 4, 5] right '3' times then we will get the 'arr'. Thus 'r' = 3.
*/

// NOTE: For finding how many times an array has been rotated we need to find the index of the minimum value in array.


int findKRotation(vector<int> &arr)
{
    // Write your code here.

    int l = 0, h = arr.size() - 1;
    int ans = INT_MAX, idx = -1;
    while (l <= h)
    {
        int mid = (l + h) / 2;

        // identifying the sorted half

        if (arr[mid] >= arr[l])
        {
            // left half is sorted
            if (arr[l] <= ans)
            {
                idx = l;
                ans = arr[l];
            }
            l = mid + 1;
        }
        else if (arr[mid] <= arr[h])
        {
            // right half is sorted
            if (arr[mid] <= ans)
            {
                idx = mid;
                ans = arr[mid];
            }
            h = mid - 1;
        }
    }
    return idx;
}

signed main()
{
}