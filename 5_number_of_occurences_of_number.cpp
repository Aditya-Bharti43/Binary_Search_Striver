#include<bits/stdc++.h>
using namespace std;

/*
Problem statement
You have been given a sorted array/list of integers 'arr' of size 'n' and an integer 'x'.

Find the total number of occurrences of 'x' in the array/list.

Example:
Input: 'n' = 7, 'x' = 3
'arr' = [1, 1, 1, 2, 2, 3, 3]

Output: 2

Explanation: Total occurrences of '3' in the array 'arr' is 2.
*/


int count(vector<int>& arr, int n, int x) {
	// Write Your Code Here

	int lb=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
	int ub=upper_bound(arr.begin(),arr.end(),x)-arr.begin();

	

	if(lb==n) return 0;

	return ub-lb;
}


signed main ()
{

}