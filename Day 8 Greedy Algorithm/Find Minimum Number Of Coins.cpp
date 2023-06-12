// Problem Link :- https://www.codingninjas.com/codestudio/problems/975277

// Solved by greedy approach as coins have standard denominations
// Had it not been the case, we would have to solve by DP
// Time Complexity :- O(n)
// Space Complexity :- O(1)

#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int count = 0, i = 8;
    
    while (i >= 0 && amount)
    {
        if (amount >= coins[i])
        {
            int temp = amount/coins[i];
            count += temp;
            amount -= temp * coins[i];
        }

        i--;
    }

    return count;
}
