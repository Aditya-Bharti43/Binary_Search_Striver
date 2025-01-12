#include<bits/stdc++.h>
using namespace std;

/*
Problem statement
You are given an array 'arr' of size 'n' having unique elements that has been sorted in ascending order and rotated between 1 and 'n' times which is unknown.

The rotation involves shifting every element to the right, with the last element moving to the first position. For example, if 'arr' = [1, 2, 3, 4] was rotated one time, it would become [4, 1, 2, 3].


Your task is to find the minimum number in this array.



Note :
All the elements in the array are distinct. 


Example :
Input: arr = [3,4,5,1,2]

Output: 1

Explanation: The original array was [1,2,3,4,5] and it was rotated 3 times
*/

// the point is -the minimum element can be either in left half or right half
// in every itereation we find the sorted half and calculate the minimum and move as in binary search
 
int findMin(vector<int>& arr)
{
	int l=0,h=arr.size()-1,ans=INT_MAX;

	while(l<=h)
	{
		int mid=(l+h)/2;

		// identifying the sorted half

		if(arr[l]<=arr[mid])
		{
			// left half is sorted
			ans=min(ans,arr[l]);
			l=mid+1;
		}
		else if(arr[mid]<=arr[h])
		
		{
			ans=min(ans,arr[mid]);
			h=mid-1;
		}
	}

	return ans;
}

signed main()
{

}