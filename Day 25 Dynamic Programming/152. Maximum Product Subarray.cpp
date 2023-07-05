// Problem Link :- https://leetcode.com/problems/maximum-product-subarray/

// Solved by calculating product from front and back
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        int maxLeft = nums[0], maxRight = nums.back(), prod = 1;
        bool isZero = false;

        for (auto &it : nums)
        {
            prod *= it;

            if (it == 0)
            {
                isZero = true;
                prod = 1;
                continue; 
            }

            maxLeft = max(maxLeft, prod);
        }

        prod = 1;

        for (int right = n - 1; right >= 0; right--)
        {
            prod *= nums[right];

            if (nums[right] == 0)
            {
                isZero = true;
                prod = 1;
                continue; 
            }

            maxRight = max(maxRight, prod);
        }

        if (isZero)
            return max({0, maxLeft, maxRight});

        else
            return max(maxLeft, maxRight);
    }
};



class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        int maxProd = nums[0], prod = 1;

        for (auto &it : nums)
        {
            prod *= it;
            maxProd = max(maxProd, prod);

            if (it == 0)
                prod = 1;
        }

        prod = 1;

        for (int right = n - 1; right >= 0; right--)
        {
            prod *= nums[right];
            maxProd = max(maxProd, prod);

            if (nums[right] == 0)
                prod = 1;
        }

        return maxProd;
    }
};



class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        int pref = 0, suff = 0, maxProd = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            pref = (pref ? pref : 1) * nums[i];
            suff = (suff ? suff : 1) * nums[n - 1 - i];

            maxProd = max({maxProd, pref, suff});
        }

        return maxProd;
    }
};