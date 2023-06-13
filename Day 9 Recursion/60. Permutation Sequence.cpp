// Problem Link :- https://leetcode.com/problems/permutation-sequence/

// Solved by inbuilt next_permutation function
// Time Complexity :- O(n * n!)
// Space Complexity :- O(n)

class Solution {
public:
    string getPermutation(int n, int k) {
        
        string s = "";

        for (int c = 1; c <= n; c++)
            s += to_string(c);

        do
        {
            k--;

        } while (k && next_permutation(s.begin(), s.end()));

        return s;
    }
};



// Solved by Optimized Approach
// Time Complexity :- O(n^2)
// Space Complexity :- O(n)

class Solution {
public:
    string getPermutation(int n, int k) {

        vector<int> fact(n);
        fact[0] = 1;

        for (int i = 1; i < n; i++)
            fact[i] = i * fact[i - 1];

        string ans = "";
        k--;
        vector<bool> vis (n + 1, false);

        for (int i = 1; i <= n; i++)
        {
            int rem = n - i;
            int next = k / fact[rem];

            int val = 1;

            while (true)
            {
                if (!vis[val])
                {
                    if (next == 0)
                        break;
                    
                    next--;
                }

                val++;
            }

            vis[val] = true;
            ans += val + '0';
            k %= fact[rem];
        }

        return ans;
    }
};
