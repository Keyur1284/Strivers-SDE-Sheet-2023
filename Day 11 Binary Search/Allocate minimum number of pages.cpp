// Problem Link :- https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

// Solved by Binary Search
// Time Complexity = O(NlogN)
// Space Complexity = O(1)

//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    
    bool check (int pages, int arr[], int n, int m)
    {
        int students = 1, curr = 0;
        
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > pages)
                return false;
                
            if (curr + arr[i] > pages)
            {
                students++;
                curr = arr[i];
                
                if (students > m)
                    return false;
            }
            
            else
                curr += arr[i];
        }
        
        return true;
    }
    
    int findPages(int arr[], int n, int m) 
    {
        if (m > n)
            return -1;
        
        int low = *min_element(arr, arr + n);
        int high = accumulate(arr, arr + n, 0);
        int mid, ans = -1;
        
        while (low <= high)
        {
            mid = (low + high) >> 1;
            
            if (check(mid, arr, n, m))
            {
                ans = mid;
                high = mid - 1;
            }
            
            else
                low = mid + 1;
        }
        
        return ans;
    }
};