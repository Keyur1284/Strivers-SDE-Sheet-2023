// Problem Link :- https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

// Solved by sorting value/weight ratio in descending order
// Time Complexity :- O(nlogn)
// Space Complexity :- O(1)

//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    
    static bool comp (Item &it1, Item &it2)
    {
        double val1 = it1.value * 1.0 / it1.weight;
        double val2 = it2.value * 1.0 / it2.weight;
        
        return val1 > val2;
    }
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort (arr, arr + n, comp);
        
        int i = 0;
        double maxValue = 0;
        
        while (W && i < n)
        {
            int wt = min(W, arr[i].weight);
            maxValue += wt * (arr[i].value * 1.0/arr[i].weight);
            W -= wt;
            i++;
        }
        
        return maxValue;
    }        
};