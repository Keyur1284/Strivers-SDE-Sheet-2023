// Problem Link :- https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1

// Time Complexity :- O((m + n )* log(m + n))
// Space Complexity :- O(1)

class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            for (int i = n - 1, j = 0; i >= 0 && j < m; i--, j++)
            {
                if (arr1[i] > arr2[j])
                    swap(arr1[i], arr2[j]);
                    
                else
                    break;
            }
            
            sort (arr1, arr1 + n);
            sort (arr2, arr2 + m);
        } 
};


// Solved by Gap Method

class Solution{
    public:
        //Function to merge the arrays.
        
        int nextGap (int gap)
        {
            if (gap <= 1)
                return 0;
                
            return gap / 2 + gap % 2;
        }
        
        void checkSwap (long long arr1[], long long arr2[], int ind1, int ind2)
        {
            if (arr1[ind1] > arr2[ind2])
                swap (arr1[ind1], arr2[ind2]);
        }
        
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            int len = m + n;
            int gap = nextGap(len);
            
            while (gap > 0)
            {
                int left = 0;
                int right = left + gap;
                
                while (right < len)
                {
                    if (left < n && right < n)
                        checkSwap (arr1, arr1, left, right);
                        
                    else if (left < n && right  >= n)
                        checkSwap (arr1, arr2, left, right - n);
                        
                    else if (left >= n && right >= n)
                        checkSwap (arr2, arr2, left - n, right - n);
                        
                    left++, right++;
                }
                
                gap = nextGap(gap);
            }
        } 
};