// Problem Link :- https://practice.geeksforgeeks.org/problems/minimum-characters-to-be-added-at-front-to-make-string-palindrome/1

// Solved by KMP Algorithm
// Time Complexity :- O(m + m)
// Space Complexity :- O(m)

class Solution {
public:
    int minChar(string str){
        
        int m = str.size();
        
        string s = str + "$";
        reverse(str.begin(), str.end());
        s += str;
        
        int n = s.size();
        
        vector<int> lps (n, 0);
        int len = 0;
        
		for (int i = 1; i < n; )
		{
			if (s[i] == s[len])
			{
				len++;
				lps[i] = len;
				i++;
			}
			
			else
			{
				if (len == 0)
					i++;
					
				else
					len = lps[len - 1];
			}
		}
		
		return m - lps.back();
    }
};
