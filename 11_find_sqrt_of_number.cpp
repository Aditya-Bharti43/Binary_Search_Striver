#include<bits/stdc++.h>
using namespace std;

int floorsqrt(int n)
{
    int low=1,high=n;

    while(l<=h)
    {
        int mid=(low+high)/2;

        if(pow(mid,2)==n) return mid;

        if(pow(mid,2)<n)
        {
            low=mid+1;
        }
        else if(pow(mid,2)>n)
        {
            high=mid-1;
        }
    }

    return high;
}


signed main()
{

}