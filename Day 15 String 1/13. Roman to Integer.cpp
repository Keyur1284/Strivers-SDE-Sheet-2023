// Problem Link :- https://leetcode.com/problems/roman-to-integer/

// Solved using unordered_map
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int romanToInt(string s) {
        
        int len = s.length(), val = 0;
        unordered_map<char, int> mp = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

        int i = 0;
        
        while (i < len)
        {
            if (s[i] == 'I')
            {
                if (i + 1 < len && s[i + 1] == 'V')
                {
                    val += 4;
                    i++;
                }

                else if (i + 1 < len && s[i + 1] == 'X')
                {
                    val += 9;
                    i++;
                }

                else
                    val += mp[s[i]];
            }

            else if (s[i] == 'X')
            {
                if (i + 1 < len && s[i + 1] == 'L')
                {
                    val += 40;
                    i++;
                }

                else if (i + 1 < len && s[i + 1] == 'C')
                {
                    val += 90;
                    i++;
                }

                else
                    val += mp[s[i]];
            }

            else if (s[i] == 'C')
            {
                if (i + 1 < len && s[i + 1] == 'D')
                {
                    val += 400;
                    i++;
                }

                else if (i + 1 < len && s[i + 1] == 'M')
                {
                    val += 900;
                    i++;
                }

                else
                    val += mp[s[i]];
            }

            else
               val += mp[s[i]];

            i++; 
        }

        return val;
    }
};



// Easier Implementation

class Solution {
public:
    int romanToInt(string s) {
        
        int len = s.length(), val = 0;
        unordered_map<char, int> mp = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

        for (int i = 0; i < len; i++)
        {
            if (i + 1 < len && mp[s[i]] < mp[s[i + 1]])
                val -= mp[s[i]];

            else
                val += mp[s[i]];
        }
        
        return val;
    }
};
