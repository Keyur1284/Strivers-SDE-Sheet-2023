// Problem Link :- https://leetcode.com/problems/repeated-string-match/

// Solved using s.find() inbuilt function
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        
        int n = a.size(), m = b.size(), count = 1;

        string s = a;

        while (s.size() < m)
        {
            s += a;
            count++;
        }

        if (s.find(b) != -1)
            return count;

        s += a;
        count++;

        if (s.find(b) != -1)
            return count;

        return -1;
    }
};



// Solved by Rabin Karp's Algorithm
// Time Complexity :- O(m + n)
// Space Complexity :- O(1)

class Solution {
public:

    int Rabin_Karp (string &text, string &pat)
    {
        int n = text.size(), m = pat.size();
        long long k = 256, MOD = INT_MAX, expo = 1, textHash = 0, patHash = 0;

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
                textHash = (k * (textHash - text[i] * expo) + text[i + m]) % MOD;

                if (textHash < 0)
                    textHash += MOD;
        }

        return -1;
    }

    int repeatedStringMatch(string a, string b) {
        
        int n = a.size(), m = b.size(), count = 1;

        string s = a;

        while (s.size() < m)
        {
            s += a;
            count++;
        }

        if (s == b)
            return count;

        if (Rabin_Karp(s, b) != -1)
            return count;

        s += a;

        if (Rabin_Karp(s, b) != -1)
            return count + 1;

        return -1;
    }
};