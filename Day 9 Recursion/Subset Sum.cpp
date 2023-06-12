// Problem Link :- https://www.codingninjas.com/codestudio/problems/subset-sum_3843086

// Solved by Recursion
// Time Complexity :- O(2^n + nlogn)
// Space Complexity :- O(2^n)

#include <bits/stdc++.h> 

void solve (int index, int sum, int &n, vector<int> &ans, vector<int> &num)
{
    if (index == n)
    {
        ans.emplace_back(sum);
        return;
    }

    solve (index + 1, sum + num[index], n, ans, num);
    solve (index + 1, sum, n, ans, num);
}

vector<int> subsetSum(vector<int> &num)
{
    int n = num.size();
    vector<int> ans;

    solve (0, 0, n, ans, num);

    sort (ans.begin(), ans.end());

    return ans;
}