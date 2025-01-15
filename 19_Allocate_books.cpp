#include <bits/stdc++.h>
using namespace std;

/*
    Problem statement
Given an array ‘arr’ of integer numbers, ‘arr[i]’ represents the number of pages in the ‘i-th’ book.

There are ‘m’ number of students, and the task is to allocate all the books to the students.
Allocate books in such a way that:

1. Each student gets at least one book.
2. Each book should be allocated to only one student.
3. Book allocation should be in a contiguous manner.

You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum.

If the allocation of books is not possible, return -1.

Example:
Input: ‘n’ = 4 ‘m’ = 2
‘arr’ = [12, 34, 67, 90]

Output: 113
*/

int pos_fn(vector<int> arr, int mid, int m)
{
    int cnt = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (cnt + arr[i] <= mid)
        {
            cnt += arr[i];
        }
        else
        {
            cnt = 0;
            m--;
            cnt = arr[i];
        }

        if (m == 0)
            break;
    }

    return m == 0 ? 1 : 0;
}

int findPages(vector<int> &arr, int n, int m)
{

    int l = *max_element(arr.begin(), arr.end()), h = 0;

    for (int i = 0; i < n; i++)
    {
        h += arr[i];
    }

    if (m > arr.size())
        return -1;

    while (l <= h)
    {
        int mid = (l + h) / 2;

        if (pos_fn(arr, mid, m) == 1)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }

    return l;
}

signed main()
{
}