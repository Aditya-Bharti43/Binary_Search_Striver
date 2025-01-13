#include <bits/stdc++.h>
using namespace std;

/*
Problem statement
You are given a sorted array ‘arr’ of ‘n’ numbers such that every number occurred twice in the array except one, which appears only once.

Return the number that appears once.

Example:
Input: 'arr' = [1,1,2,2,4,5,5]

Output: 4

Explanation:
Number 4 only appears once the array.
Note :
Exactly one number in the array 'arr' appears once.
*/

int singleNonDuplicate(vector<int> &arr)
{
    // handling edge cases
    int n = arr.size();
    if (arr.size() == 1)
    {
        return arr[0];
    }

    if (arr[0] != arr[1])
    {
        return arr[0];
    }
    if (arr[n - 1] != arr[n - 2])
    {
        return arr[n - 1];
    }

    int l = 1, h = arr.size() - 2, ans = -1;

    while (l <= h)
    {
        int mid = (l + h) / 2;

        if (arr[mid - 1] != arr[mid] && arr[mid + 1] != arr[mid])
        {
            ans = arr[mid];
            return ans;
        }

        if ((mid % 2 == 1 && arr[mid - 1] == arr[mid]) || (mid % 2 == 0 && arr[mid + 1] == arr[mid]))
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
}

signed main()
{
}