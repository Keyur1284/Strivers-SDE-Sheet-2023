// Problem Link :- https://leetcode.com/problems/powx-n/

// Solved by Binary Exponentiation
// Time Complexity :- O(logn)
// Space Complexity :- O(1)

class Solution {
public:
    double myPow(double x, int n) {
        
        long exp = n;
        double res = 1;

        if (n < 0)
            exp *= -1;

        while (exp)
        {
            if (exp % 2)
            {
                res = res * x;
                exp--;
            }

            else
            {
                x = x * x;
                exp /= 2;
            }
        }

        return (n > 0) ? res : 1.0/res;
    }
};



class Solution {
public:
    double myPow(double x, int n) {
        
        long exp = n;
        double res = 1;

        if (n < 0)
            exp *= -1;

        while (exp)
        {
            if (exp % 2)
                res = res * x;

            exp /= 2;
            x = x * x;
        }

        return (n > 0) ? res : 1.0/res;
    }
};