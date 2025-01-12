#include <bits/stdc++.h>
using namespace std;

// In this problem we need to find the smallest element in the array which has been rotated and the array also contains duplicates

int find_min_duplicates(vector<int> &arr)
{
    int ans = INT_MAX;

    int l = 0, h = arr.size() - 1;
    while (l <= h)
    {
        int mid = (l + h) / 2;

        if (arr[l] == arr[mid] && arr[mid] == arr[h])
        {
            l++;
            h--;
            continue;
        }

        if (arr[l] <= arr[mid])
        {
            ans = min(ans, arr[l]);
            l = mid + 1;
        }
        else if (arr[mid] <= arr[h])
        {
            ans = min(ans, arr[mid]);
            h = mid - 1;
        }
    }
    return ans;
}

signed main()
{
    int n;
    cout << "ENTER SIZE OF ARRAY" << endl;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }

    int ans = find_min_duplicates(arr);

    cout << ans << endl;
}