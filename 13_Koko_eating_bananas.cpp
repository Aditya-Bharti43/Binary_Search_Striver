#include <bits/stdc++.h>
using namespace std;

/*
Problem statement
A monkey is given ‘n’ piles of bananas, where the 'ith' pile has ‘a[i]’ bananas. An integer ‘h’ is also given, which denotes the time (in hours) in which all the bananas should be eaten.

Each hour, the monkey chooses a non-empty pile of bananas and eats ‘m’ bananas. If the pile contains less than ‘m’ bananas, then the monkey consumes all the bananas and won’t eat any more bananas in that hour.

Find the minimum number of bananas ‘m’ to eat per hour so that the monkey can eat all the bananas within ‘h’ hours.

Example:

Input: ‘n’ = 4, ‘a’ =  [3, 6, 2, 8] , ‘h’ = 7

Output: 3

Explanation: If ‘m’ = 3, then
The time taken to empty the 1st pile is 1 hour.
The time taken to empty the 2nd pile is 2 hour.
The time taken to empty the 3rd pile is 1 hour.
The time taken to empty the 4th pile is 3 hour.
Therefore a total of 7 hours is taken. It can be shown that if the rate of eating bananas is reduced, they can’t be eaten in 7 hours.
*/

#include <bits/stdc++.h>
int find_max(vector<int> &v)
{
    int ans = INT_MIN;

    for (int i = 0; i < v.size(); i++)
    {
        ans = max(ans, v[i]);
    }

    return ans;
}
long long eat_ban(int val, vector<int> &v)
{
    long long sum = 0;

    for (int i = 0; i < v.size(); i++)
    {
        sum += ceil(double(v[i]) / double(val));
    }

    return sum;
}

int minimumRateToEatBananas(vector<int> v, int h)
{
    int l = 1, hi = find_max(v);

    while (l <= hi)
    {
        int mid = l + (hi - l) / 2;

        long long hoursNeeded = eat_ban(mid, v); // Store the result

        if (hoursNeeded > h)
        {
            l = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    return l;
}

signed main()
{
}