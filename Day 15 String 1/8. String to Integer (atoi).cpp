// Problem Link :- https://leetcode.com/problems/string-to-integer-atoi/

// Solved by handling all the edge cases
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int myAtoi(string s) {
        
        int n = s.size(), i = 0, num = 0, sign = 1;

        while (i < n && s[i] == ' ')
            i++;

        if (s[i] == '-' || s[i] == '+')
        {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        while (i < n && s[i] >= '0' && s[i] <= '9')
        {
            if (num > INT_MAX/10 || (num == INT_MAX/10 && (s[i] - '0' > (INT_MAX % 10))))
            {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            num = num * 10 + (s[i] - '0');
            i++;
        }

        return sign * num;
    }
};



class Solution {
public:
    int myAtoi(string s) {
        
        int n = s.size(), i = 0, sign = 1;
        long long num = 0;

        while (i < n && s[i] == ' ')
            i++;

        if (s[i] == '-' || s[i] == '+')
        {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        while (i < n && s[i] >= '0' && s[i] <= '9')
        {
            num = num * 10 + (s[i] - '0');

            if (num > INT_MAX)
            {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            i++;
        }

        return sign * num;
    }
};