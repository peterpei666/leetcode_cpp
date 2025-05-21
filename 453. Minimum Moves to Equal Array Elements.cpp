#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int minMoves(vector<int>& nums)
	{
		int m=INT_MAX;
		for(int n:nums)
		{
			m=min(m,n);
		}
		int sum=0;
		for(int n:nums)
		{
			sum+=n-m;
		}
		return sum;
	}
};
