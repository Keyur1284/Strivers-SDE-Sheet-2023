// Problem Link :- https://www.codingninjas.com/codestudio/problems/873366

// Solved by Math
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	long long sumn = 1LL * n * (n + 1)/2;
	long long sumn2 = 1LL * n * (n + 1) * (2 * n + 1) / 6;

	long long arrsum = 0, arrsum2 = 0;

	for (int i = 0; i < n; i++)
	{
		arrsum += arr[i];
		arrsum2 += 1LL * arr[i] * arr[i];
	}
	
	long long diff = arrsum - sumn;
	long long diff2 = arrsum2 - sumn2;

	long long add = diff2/diff;

	long long repeat = (add + diff)/2;
	long long missing = repeat - diff;

	return {missing, repeat};
}



// To get first set bit from right i.e. LSB we can do
// int bit = (num & ~(num - 1));

// To get the value of the least significant bit that is on (first from the right):
// int value = (num & (-num));

// To get first set bit from right i.e. LSB we can do
// int bit = 1 + __builtin_ctz(num);		(__builtin_ctz(num) -> count the trailing zeros)

// To get first set bit from left i.e. MSB we can do
// int bit = 31 - __builtin_clz(num);		(__builtin_clz(num) -> count the leading zeros)

// Solved by XOR (Bit Manipulation)
// Time Complexity :- O(n)
// Space Complexity :- O(1)

#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int xorVal = 0;

	for (auto &it : arr)
		xorVal ^= it;

	for (int i = 1; i <= n; i++)
		xorVal ^= i;

	int num = xorVal;
	bitset<32> bs(num);
	int bit;

	for (bit = 0; bit < 32; bit++)
	{
		if (bs[bit])
			break;
	}

	int mask = (1 << bit);
	int zero = 0, one = 0;

	for (auto &it : arr)
	{
		if (mask & it)
			one ^= it;

		else
			zero ^= it;
	}

	for (int i = 1; i <= n; i++)
	{
		if (mask & i)
			one ^= i;

		else	
			zero ^= i;
	}

	int count = 0;

	for (auto &it : arr)
	{
		count += (it == zero);
	}
	
	if (count == 2)
		return {one, zero}; 
		
	else
		return {zero, one};
}
