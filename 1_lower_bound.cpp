#include <bits/stdc++.h>
using namespace std;

// The lower bound returns the lowest index such that arr[i]>=target


int lowerBound(vector<int> arr, int size, int target)
{

    int l = 0, h = size - 1, ans = size;

    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (arr[mid] >= target)
        {
            ans = mid;
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return ans;
}

signed main()
{
    int n,target;
    cout<<"Enter size of array"<<endl;
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the elements of the array"<<endl;

    for(int i=0;i<n;i++)cin>>arr[i];

    cout<<"Enter the element whose lower bound you want to find"<<endl;
    cin>>target;

    int ans=lowerBound(arr,n,target);

    cout<<ans<<endl;


    
}