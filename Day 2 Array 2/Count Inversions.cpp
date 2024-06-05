// Problem Link :- https://www.codingninjas.com/codestudio/problems/count-inversions_615

// Solved by modifying code of Merge Sort
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

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
            inversions += mid - left + 1;
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



#include <bits/stdc++.h>

long long merge (long long *nums, int start, int mid, int end)
{
    int left = start, right = mid + 1, size = end - start + 1, index = 0;
    long long inversions = 0;
    long long *temp = new long long[size];

    int j = right;

    for (int i = left; i <= mid; i++)
    {
        while (j <= end && nums[i] > nums[j])
            j++;

        inversions += (j - mid - 1);
    }

    while (left <= mid && right <= end)
        temp[index++] = (nums[left] < nums[right]) ? nums[left++] : nums[right++];

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



// Solved using BIT
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

#include <bits/stdc++.h>
using namespace std;

class BIT {

    int n;
    vector<int> bit;

public:

    BIT (int n)
    {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void update (int id, int val)
    {
        while (id <= n)
        {
            bit[id] += val;
            id += (id & -id);
        }
    }

    int query (int id)
    {
        int sum = 0;

        while (id > 0)
        {
            sum += bit[id];
            id -= (id & -id);
        }

        return sum;
    }
};

long long getInversions(long long *arr, int n)
{
    long long inversions = 0;
    vector<pair<long long, int>> nums(n);

    for (int i = 0; i < n; i++)
        nums[i] = {arr[i], i + 1};

    sort(nums.begin(), nums.end());

    BIT bit(n);

    for (int i = n - 1; i >= 0; i--)
    {
        inversions += bit.query(nums[i].second - 1);
        bit.update(nums[i].second, 1);
    }

    return inversions;
}



// Solved using ordered set
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename type, typename comp = less<type>> 
using ordered_set = tree<type, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;

long long getInversions(long long *arr, int n)
{
    long long inversions = 0;
    ordered_set<pair<long long, int>> nums;

    for (int i = 0; i < n; i++)
        nums.insert({arr[i], i});

    for (int i = 0; i < n; i++)
    {
        inversions += nums.order_of_key({arr[i], i});
        nums.erase({arr[i], i});
    }

    return inversions;
}



#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename type, typename comp = less<type>> 
using ordered_set = tree<type, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;

long long getInversions(long long *arr, int n)
{
    long long inversions = 0;
    ordered_set<long long> nums;

    for (int i = 0; i < n; i++)
        nums.insert(arr[i]);

    for (int i = 0; i < n; i++)
    {
        inversions += nums.order_of_key(arr[i]);
        nums.erase(arr[i]);
    }

    return inversions;
}