#include <bits/stdc++.h>
using namespace std;

/*
Problem statement
You are given two positive integers 'n' and 'm'. You have to return the 'nth' root of 'm', i.e. 'm(1/n)'. If the 'nth root is not an integer, return -1.

Note:
'nth' root of an integer 'm' is a number, which, when raised to the power 'n', gives 'm' as a result.

Example:
Input: ‘n’ = 3, ‘m’ = 27
Output: 3
Explanation:
3rd Root of 27 is 3, as (3)^3 equals 27.

*/

int NthRoot(int n, int m)
{

    int l = 1, h = m;

    while (l <= h)
    {
        int mid = (l + h) / 2;

        if (pow(mid, n) == m)
        {
            return mid;
        }

        if (pow(mid, n) < m)
        {
            l = mid + 1;
        }
        else if (pow(mid, n) > m)
        {
            h = mid - 1;
        }
    }

    if (pow(h, n) == m)
        return h;
    else
        return -1;
}

signed main()
{
}