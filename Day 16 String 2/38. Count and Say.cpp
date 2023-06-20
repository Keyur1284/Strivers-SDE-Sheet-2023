// Problem Link :- https://leetcode.com/problems/count-and-say/

// Solved by Recursion Approach
// Time Complexity :- O(n^2)
// Space Complexity :- O(n)

class Solution {
public:
    string countAndSay(int n) {
        
        if (n == 1)
            return "1";

        string say = countAndSay(n - 1);
        int count = 1, len = say.size();
        string ans = "";

        for (int i = 0; i < len; i++)
        {
            if (i + 1 < len && say[i] == say[i + 1])
                count++;

            else
            {
                ans += to_string(count) + say[i];
                count = 1;
            }
        }

        return ans;
    }
};



// Solved by Iteration Approach
// Time Complexity :- O(n^2)
// Space Complexity :- O(n)

class Solution {
public:
    string countAndSay(int n) {
        
        string ans = "1";
        
        for(int i = 2; i <= n; i++)
        {
            string temp = "";
            int count = 1, len = ans.size();
            
            for(int j = 0; j < len; j++)
            {
                if(j + 1 < len && ans[j] == ans[j + 1])
                    count++;
                
                else
                {
                    temp += to_string(count) + ans[j];
                    count = 1;
                }
            }
            
            ans = temp;
        }
        
        return ans;
    }
};