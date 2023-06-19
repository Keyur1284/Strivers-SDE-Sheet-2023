// Problem Link :- https://practice.geeksforgeeks.org/problems/implement-strstr/1

// Implemented using Rabin Karp Algorithm
// Time Complexity :- O(n + m)
// Space Complexity :- O(1)


//Function to locate the occurrence of the string x in the string s.
int strstr(string text, string pat)
{
    int n = text.size(), m = pat.size();
    int MOD = INT_MAX;
    int k = 256, expo = 1;
    int patHash = 0, textHash = 0;
    
    for (int i = 0; i < m - 1; i++)
        expo = (expo * k) % MOD;
        
    for (int i = 0; i < m; i++)
    {
        patHash = (k * patHash + pat[i]) % MOD;
        textHash = (k * textHash + text[i]) % MOD;
    }
    
    for (int i = 0; i <= n - m; i++)
    {
        if (patHash == textHash)
        {
            bool flag = true;
            
            for (int j = 0; j < m; j++)
            {
                if (text[i + j] != pat[j])
                {
                    flag = false;
                    break;
                }
            }
            
            if (flag)
                return i;
        }
        
        if (i + m < n)
        {
            textHash = (k * (textHash - text[i] * expo) + text[i + m]) % MOD;
            
            if (textHash < 0)
                textHash += MOD;
        }
    }
    
    return -1;
}