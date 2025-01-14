#include <bits/stdc++.h>
using namespace std;

/*
Problem statement
You are given an array of integers 'arr' and an integer 'limit'.

Your task is to find the smallest positive integer divisor, such that upon dividing all the elements of the given array by it, the sum of the division's result is less than or equal to the given integer's limit.

Note:
Each result of the division is rounded to the nearest integer greater than or equal to that element. For Example, 7/3 = 3.
*/


int ut_fn(vector<int> &arr, int mid)
{
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += ceil((double)(arr[i]) / (double)(mid));
    }

    return sum;
}

int smallestDivisor(vector<int> &arr, int limit)
{
    int l = 1, h = *max_element(arr.begin(), arr.end());

    while (l <= h)
    {
        int mid = l + (h - l) / 2;

        if (ut_fn(arr, mid) <= limit)
        {
            h = mid - 1;
        }
        else if (ut_fn(arr, mid) > limit)
        {
            l = mid + 1;
        }
    }

    return l;
}
signed main()
{
}
