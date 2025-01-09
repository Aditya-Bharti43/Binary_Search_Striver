#include<bits/stdc++.h>
using namespace std;

/*
Problem statement
You're given a sorted array 'a' of 'n' integers and an integer 'x'.

Find the floor and ceiling of 'x' in 'a[0..n-1]'.

Note:
Floor of 'x' is the largest element in the array which is smaller than or equal to 'x'.
Ceiling of 'x' is the smallest element in the array greater than or equal to 'x'.

Example:
Input: 
n=6, x=5, a=[3, 4, 7, 8, 8, 10]   

Output:
4

Explanation:
The floor and ceiling of 'x' = 5 are 4 and 7, respectively.



*/

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
  // {floor , ceil}

  int ce = lower_bound(a.begin(), a.end(), x) - a.begin();

  
  
  int l = 0, h = a.size()-1, ans = INT_MAX;

  while (l <= h) {
    int mid = (l + h) / 2;

    if (a[mid] <= x) {
      ans = mid;
      l = mid + 1;
    } else {
      h = mid - 1;
    }
  }
    
  pair<int, int> p;
  if(ans==INT_MAX)ans=-1;

  
  p={ans==-1?-1:a[ans],ce==a.size()?-1:a[ce]};



 

  return p;
}

signed main()

{

}