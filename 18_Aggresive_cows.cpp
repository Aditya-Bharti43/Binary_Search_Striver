#include <bits/stdc++.h>
using namespace std;

/*
Problem statement
You are given an array 'arr' consisting of 'n' integers which denote the position of a stall.

You are also given an integer 'k' which denotes the number of aggressive cows.

You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.

Print the maximum possible minimum distance.
Example:
Input: 'n' = 3, 'k' = 2 and 'arr' = {1, 2, 3}

Output: 2

Explanation: The maximum possible minimum distance will be 2 when 2 cows are placed at positions {1, 3}. Here distance between cows is 2.
*/

int pos_fn(vector<int> stalls, int mid, int k)
{
    int cnt = 0;
    for (int i = 0; i < stalls.size(); i++)
    {
        if (i == 0)
        {
            k--;
            continue;
        }

        if (cnt >= mid)
        {
            cnt = 0;
            k--;
        }
        else
        {
            cnt += stalls[i] - stalls[i - 1];

            if (cnt >= mid)
            {
                cnt = 0;
                k--;
            }
        }

        if (k == 0)
            break;
    }

    return k == 0 ? 1 : 0;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());

    int l = 1, h = *max_element(stalls.begin(), stalls.end());

    while (l <= h)
    {
        int mid = (l + h) / 2;

        if (pos_fn(stalls, mid, k) == 1)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }

    return h;
}

signed main()
{
}