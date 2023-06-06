// Problem Link :- https://www.codingninjas.com/codestudio/problems/count-inversions_615

// Solved by adding some lines in code of Merge Sort
// Time Complexity - O(nlogn)
// Space Complexity - O(n)

#include <bits/stdc++.h>

long long merge (long long *nums, int start, int mid, int end)
{
    int left = start, right = mid + 1, size = end - start + 1, index = 0;
    long long inversions = 0;
    long long *temp = new long long[size];

    while (left <= mid && right <= end)
    {
        if (nums[left] <= nums[right])
            temp[index++] = nums[left++];

        else if (nums[left] > nums[right])
        {
            inversions += mid + 1 - left;
            temp[index++] = nums[right++];
        }
    }

    while (left <= mid)
        temp[index++] = nums[left++];

    while (right <= end)
        temp[index++] = nums[right++];

    for (int i = 0; i < size; i++)
        nums[start + i] = temp[i];

    return inversions;
}

long long mergeSort (long long *nums, int left, int right)
{
    long long mid, inversions = 0;

    if (left < right)
    {
        mid = (left + right) >> 1;

        inversions += mergeSort (nums, left, mid);
        inversions += mergeSort (nums, mid + 1, right);
        inversions += merge (nums, left, mid, right);
    }

    return inversions;
}

long long getInversions(long long *arr, int n){
    
    long long *nums = arr;
    long long inversions = mergeSort (nums, 0, n - 1);
    
    return inversions;
}