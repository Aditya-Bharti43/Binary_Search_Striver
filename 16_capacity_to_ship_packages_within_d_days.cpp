#include <bits/stdc++.h>
using namespace std;

/*
Problem statement
You are the owner of a Shipment company. You use conveyor belts to ship packages from one port to another. The packages must be shipped within 'd' days.

The weights of the packages are given in an array 'weights'. The packages are loaded on the conveyor belts every day in the same order as they appear in the array. The loaded weights must not exceed the maximum weight capacity of the ship.

Find out the least-weight capacity so that you can ship all the packages within 'd' days.
*/

int arr_sum(vector<int> &arr, int mid, int d)
{
    int time = 1, load = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] + load > mid)
        {
            time++;
            load = arr[i];
        }
        else
        {
            load += arr[i];
        }
    }

    return time;
}

int leastWeightCapacity(vector<int> &weights, int d)
{
    int sum = 0;
    for (int i = 0; i < weights.size(); i++)
    {
        sum += weights[i];
    }

    int l = *max_element(weights.begin(), weights.end()), h = sum;

    while (l <= h)
    {
        int mid = (l + h) / 2;
        
        if (arr_sum(weights, mid, d) <= d)
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return l;
}

signed main()
{
}