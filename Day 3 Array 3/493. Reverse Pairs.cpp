// Problem Link :- https://leetcode.com/problems/reverse-pairs/

// Solved by adding some lines in code of Merge Sort
// Time Complexity - O(nlogn)
// Space Complexity - O(n)

class Solution {
public:

    int merge (vector<int> &arr, int start, int mid, int end)
    {
        int left = start, right = mid + 1, size = end - start + 1, index = 0, pairs = 0;
        vector<int> temp (size);
        
        int j = right;

        for (int i = left; i <= mid; i++)
        {
            while (j <= end && arr[i] > 2LL * arr[j])
                j++;

            pairs += (j - (mid + 1));
        }

        while (left <= mid && right <= end)
            temp[index++] = (arr[left] < arr[right]) ? arr[left++] : arr[right++];

        while (left <= mid)
            temp[index++] = arr[left++];

        while (right <= end)
            temp[index++] = arr[right++];

        for (int i = 0; i < size; i++)
            arr[start + i] = temp[i];

            return pairs; 
    }

    int mergeSort (vector<int> &arr, int left, int right)
    {
        int mid, pairs = 0;

        if (left < right)
        {
            mid = (left + right) >> 1;

            pairs += mergeSort (arr, left, mid);
            pairs += mergeSort (arr, mid + 1, right);
            pairs += merge (arr, left, mid, right);
        }

        return pairs;
    }

    int reversePairs(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> arr = nums;

        int pairs = mergeSort (arr, 0, n - 1);

        return pairs;
    }
};