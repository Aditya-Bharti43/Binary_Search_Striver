#include<bits/stdc+.h>
using namespace std;

/*
Problem statement
You have been given a sorted array/list 'arr' consisting of ‘n’ elements. You are also given an integer ‘k’.

Now, your task is to find the first and last occurrence of ‘k’ in 'arr'.

Note :
1. If ‘k’ is not present in the array, then the first and the last occurrence will be -1. 
2. 'arr' may contain duplicate elements.


Example:
Input: 'arr' = [0,1,1,5] , 'k' = 1

Output: 1 2

Explanation:
If 'arr' = [0, 1, 1, 5] and 'k' = 1, then the first and last occurrence of 1 will be 1(0 - indexed) and 2.
*/

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    

    int focc=n,locc=n;

    focc=lower_bound(arr.begin(),arr.end(),k)-arr.begin();
    locc=upper_bound(arr.begin(),arr.end(),k)-arr.begin();
    
    // if lower_bound==n then the number does not exist in the array
    if(focc==n || locc==0)
    {
        focc=-1;
        locc=-1;
    }

    if(arr[focc]!=k || arr[locc-1]!=k)
    {
        focc=-1;
        locc=-1;
    }

    int fans,lans;
    fans=focc==-1?-1:focc;
    lans=locc==-1?-1:locc-1;

    pair<int,int>p={fans,lans};

    return p;

}


signed main()
{

}