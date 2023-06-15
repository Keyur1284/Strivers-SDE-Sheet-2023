// Problem Link :- https://www.codingninjas.com/codestudio/problems/k-max-sum-combinations_975322

// Solved using priority_queue
// Time Complexity :- O(nlogK + nlogn)
// Space Complexity :- O(n)

#include <bits/stdc++.h> 
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	
	sort (a.begin(), a.end());
	sort (b.begin(), b.end());

	priority_queue<pair<int, pair<int, int>>> pq;
	set<pair<int, int>> vis;
	vector<int> sumComb;

	pq.push({a[n - 1] + b[n - 1], {n - 1, n - 1}});
	vis.insert({n - 1, n - 1});

	while (k--)
	{
		auto it = pq.top();
		pq.pop();

		sumComb.emplace_back(it.first);

		auto pair = it.second;

		int index1 = pair.first - 1;
		int index2 = pair.second;

		if (vis.find({index1, index2}) == vis.end())
		{
			pq.push({a[index1] + b[index2], {index1, index2}});
			vis.insert({index1, index2});
		}

		index1 = pair.first;
		index2 = pair.second - 1;

		if (vis.find({index1, index2}) == vis.end())
		{
			pq.push({a[index1] + b[index2], {index1, index2}});
			vis.insert({index1, index2});
		}
	}

	return sumComb;
}