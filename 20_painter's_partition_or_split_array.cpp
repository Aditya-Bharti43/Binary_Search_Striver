#include <bits/stdc++.h>
using namespace std;

/*
    Problem statement
Given an array/list of length ‘n’, where the array/list represents the boards and each element of the given array/list
represents the length of each board. Some ‘k’ numbers of painters are available to paint these boards. Consider that each
 unit of a board takes 1 unit of time to paint.


You are supposed to return the area of the minimum time to get this job done of painting all the ‘n’ boards under a constraint
 that any painter will only paint the continuous sections of boards.

Example :
Input: arr = [2, 1, 5, 6, 2, 3], k = 2

Output: 11

Explanation:
First painter can paint boards 1 to 3 in 8 units of time and the second painter can paint boards 4-6 in 11 units of time.
 Thus both painters will paint all the boards in max(8,11) = 11 units of time. It can be shown that all the boards can't
 be painted in less than 11 units of time.
*/

int pos_fn(vector<int> boards, int mid, int k)
{
    int cnt = 0;

    for (int i = 0; i < boards.size(); i++)
    {
        if (cnt + boards[i] <= mid)
        {
            cnt += boards[i];
        }
        else
        {
            cnt = 0;
            k--;
            cnt = boards[i];
        }

        if (k == 0)
            break;
    }

    return k == 0 ? 1 : 0;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int l = *max_element(boards.begin(), boards.end()), h = 0;

    for (int i = 0; i < boards.size(); i++)
    {
        h += boards[i];
    }

    while (l <= h)
    {
        int mid = (l + h) / 2;

        if (pos_fn(boards, mid, k) == 1)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }

    return l;
}

signed main()
{
}