// Problem Link :- https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

// Solved using inbuilt STL function
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int strStr(string haystack, string needle) {

        int index = haystack.find(needle);        
        return index;
    }
};



// Solved using Brute Force (Sliding Window Approach)
// Time Complexity :- O(n*m)
// Space Complexity :- O(1)

class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int n = haystack.size();
        int m = needle.size();
        int i = 0, j = 0;

        while (i < n && j < m)
        {
            if (haystack[i] == needle[j])
                i++, j++;

            else
            {
                i = i - j + 1;
                j = 0;
            }
        }
        
        if (j == m)
            return i - j;

        return -1;
    }
};

class Solution {
public:
    int strStr(string haystack, string needle) {

        int n = haystack.size();
        int m = needle.size();

        for (int start = 0; start <= n - m; start++)
        {
            for (int i = 0; i < m; i++)
            {
                if (needle[i] != haystack[start + i])
                    break;

                if (i == m - 1)
                    return start;
            }
        }

        return -1;
    }
};



// Solved using Rabin Karp Algorithm (Single Hash)
// Worst Case Time Complexity :- O(n*m)
// Best Case Time Complexity :- O(n + m)
// Space Complexity :- O(1)

class Solution {
public:

    long long radix = 256, MOD = INT_MAX, maxwt;

    long long getHash (string &s, int m)
    {
        long long hash = 0;

        for (int i = 0; i < m; i++)
        {
            hash = (radix * hash + s[i]) % MOD;
        }

        return hash;
    }

    long long updateHash (long long hash, string &s, int remove, int add)
    {
        return (radix * (hash - s[remove] * maxwt) + s[add]) % MOD;
    }

    int strStr(string haystack, string needle) {
        
        int n = haystack.size(), m = needle.size();
        maxwt = 1;

        for (int i = 0; i < m - 1; i++)
            maxwt = (maxwt * radix) % MOD;

        long long hayHash = getHash(haystack, m);
        long long needHash = getHash(needle, m);

        for (int i = 0; i <= n - m; i++)
        {
            if (hayHash == needHash)
            {
                bool flag = true;

                for (int j = 0; j < m; j++)
                {
                    if (haystack[i + j] != needle[j])
                    {
                        flag = false;
                        break;
                    }
                }

                if (flag)
                    return i;
            }

            if (i + m < n)
                hayHash = updateHash (hayHash, haystack, i, i + m);

            if (hayHash < 0)
                hayHash += MOD;
        }

        return -1;
    }
};



// Solved using Rabin Karp Algorithm (Double Hash)
// Time Complexity :- O(n + m)
// Space Complexity :- O(1)

class Solution {
public:

    long long radix = 256, MOD = INT_MAX, maxwt;
    long long radix2 = 26, MOD2 = 1e9 + 7, maxwt2;

    pair<long long, long long> getHash (string &s, int m)
    {
        pair<long long, long long> hash = {0, 0};

        for (int i = 0; i < m; i++)
        {
            hash.first = (radix * hash.first + s[i]) % MOD;
            hash.second = (radix2 * hash.second + s[i]) % MOD2;
        }

        return hash;
    }

    long long updateHash (long long hash, string &s, int remove, int add, long long radix, long long maxwt, long long MOD)
    {
        return (radix * (hash - s[remove] * maxwt) + s[add]) % MOD;
    }

    int strStr(string haystack, string needle) {
        
        int n = haystack.size(), m = needle.size();
        maxwt = 1, maxwt2 = 1;

        for (int i = 0; i < m - 1; i++)
        {
            maxwt = (maxwt * radix) % MOD;
            maxwt2 = (maxwt2 * radix2) % MOD2;
        }

        pair<long long, long long> hayHash = getHash(haystack, m);
        pair<long long, long long> needHash = getHash(needle, m);

        for (int i = 0; i <= n - m; i++)
        {
            if (hayHash.first == needHash.first && hayHash.second == needHash.second)
            {
                return i;
            }

            if (i + m < n)
            {
                hayHash.first = updateHash (hayHash.first, haystack, i, i + m, radix, maxwt, MOD);
                hayHash.second = updateHash (hayHash.second, haystack, i, i + m, radix2, maxwt2, MOD2);

                if (hayHash.first < 0)
                    hayHash.first += MOD;

                if (hayHash.second < 0)
                    hayHash.second += MOD2;
            }
        }

        return -1;
    }
};



// Solved using Knuth–Morris–Pratt (KMP) Algorithm
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:

    vector<int> makeLPS (string &needle)
    {
        int m = needle.size();
        
        // Longest Proper Prefix that is also a Suffix,  π-table, or Prefix Table

        vector<int> lps(m, 0);
        int len = 0;

        for (int i = 1; i < m;)
        {
            if (needle[i] == needle[len])
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

        return lps;
    }

    int KMP (string &haystack, string &needle, vector<int> &lps)
    {
        int n = haystack.size(), m = needle.size();

        for (int it1 = 0, it2 = 0; it1 < n;)
        {
            if (haystack[it1] == needle[it2])
            {
                it1++;
                it2++;

                if (it2 == m)
                    return it1 - it2;
            }

            else
            {
                if (it2 == 0)
                    it1++;

                else
                    it2 = lps[it2 - 1];
            }
        }

        return -1;
    }

    int strStr(string haystack, string needle) {
        
        int n = haystack.size(), m = needle.size();

        vector<int> lps = makeLPS (needle);

        int ans = KMP (haystack, needle, lps);

        return ans;
    }
};