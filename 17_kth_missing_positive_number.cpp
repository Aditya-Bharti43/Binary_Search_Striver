#include <bits/stdc++.h>
using namespace std;

/*
Problem statement
You are given a strictly increasing array 'vec' and a positive integer 'k'.

Find the 'kth' positive integer missing from 'vec'.

Example :
Input: vec = [2,4,5,7] , k = 3

Output: 6

Explanation :
In the given example, first missing positive integer is 1 second missing positive integer is 3, and the third missing positive integer is 6.
Hence the answer is 6.
*/

int missingK(vector<int> vec, int n, int k)
{

    int l = 0, h = n - 1;

    while (l <= h)
    {
        int mid = (l + h) / 2;

        if (vec[mid] - mid - 1 >= k)
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return l + k;
}

signed main()
{
}