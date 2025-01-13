#include <bits/stdc++.h>
using namespace std;

/*
Problem statement
You are given 'n' roses and you are also given an array 'arr' where 'arr[i]' denotes that the 'ith' rose will bloom on the 'arr[i]th' day.



You can only pick already bloomed roses that are adjacent to make a bouquet. You are also told that you require exactly 'k' adjacent bloomed roses to make a single bouquet.

Find the minimum number of days required to make at least 'm' bouquets each containing 'k' roses. Return -1 if it is not possible.

Example :
Input: n = 9,  arr = [ 1, 2, 1, 2, 7, 2, 2, 3, 1 ], k = 3, m = 2

Output: 3.

Explanation: This is because on the 3rd day: all the roses with 'arr[i]' less than equal to 3 have already bloomed, this means every rose except the 5th rose has bloomed. Now we can form the first bouquet from the first three roses and the second bouquet from the last three roses.
*/

int fnd_fn(vector<int> &arr, int mid, int k, int m)
{
    int cnt = 0, fcnt = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] <= mid)
        {
            cnt++;
        }
        else
        {
            cnt = 0;
        }

        if (cnt == k)
        {
            fcnt++;
            cnt = 0;
        }
    }

    return fcnt >= m ? 1 : 0;
}

int find_max(vector<int> &arr)
{
    int ans = 1;

    for (int i = 0; i < arr.size(); i++)
    {
        ans = max(ans, arr[i]);
    }

    return ans;
}

int roseGarden(vector<int> arr, int k, int m)
{

    int h = find_max(arr), l = 1;

    while (l <= h)
    {
        int mid = (l + h) / 2;

        if (fnd_fn(arr, mid, k, m) == 1)
        {
            h = mid - 1;
        }
        else if (fnd_fn(arr, mid, k, m) == 0)
        {
            l = mid + 1;
        }
    }

    if (fnd_fn(arr, l, k, m) == 1)
        return l;

    return -1;
}

signed main()
{
}