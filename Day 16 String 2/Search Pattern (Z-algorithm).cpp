// Problem Link :- https://practice.geeksforgeeks.org/problems/8dcd25918295847b4ced54055eae35a8501181c1/1

// Solved by KMP Algorithm
// Time Complexity :- O(n + m)
// Space Complexity :- O(m)

class Solution
{
public:
	vector <int> search(string pat, string txt)
	{
		int n = txt.size(), m = pat.size();
		
		vector<int> lps(m, 0);
		int len = 0;
		
		for (int i = 1; i < m; )
		{
			if (pat[i] == pat[len])
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
		
		vector<int> ans;
		
		for (int i = 0, j = 0; i < n; )
		{
			if (txt[i] == pat[j])
			{
				i++;
				j++;
				
				if (j == m)
				{
					ans.emplace_back(i - j + 1);
					j = lps[j - 1];
				}
			}
			
			else
			{
				if (j == 0)
					i++;
					
				else
					j = lps[j - 1];
			}
		}
		
		return ans;
	}
};



// Solved by Z Algorithm
// Time Complexity :- O(n + m)
// Space Complexity :- O(n + m)

class Solution
{
public:
	vector <int> search(string pat, string txt)
	{
		int patLen = pat.length();
		string s = pat + "$" + txt;
		int n = s.size();
		
		vector<int> z(n, 0);
		
		int left = 0, right = 0;
		
		for (int i = 1; i < n; i++)
		{
			if (right - i > 0)
				z[i] = min(right - i, z[i - left]);
				
			while (i + z[i] < n && s[z[i]] == s[i + z[i]])
				z[i]++;
				
			if (i + z[i] > right)
			{
				left = i;
				right = i + z[i];
			}
		}
		
		vector<int> ans;
		
		for (int i = 1; i < n; i++)
		{
			if (z[i] == patLen)
				ans.emplace_back(i - patLen);
		}
		
		return ans;
	}
	
};



/*
	// Conversion of Z to LPS

	for (int i = 1; i < n; i++)
	{
		lps[i + z[i] - 1] = max(lps[i + z[i] - 1], z[i]);
	}

	// Conversion of LPS to Z

	for (int i = 1; i < n; i++)
	{
		z[i - lps[i] + 1] = max(z[i - lps[i] + 1], lps[i]);
	}

*/