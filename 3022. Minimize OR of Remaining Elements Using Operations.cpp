#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int minOrAfterOperations(vector<int>& nums,int k)
	{
		int mask=0;
		for(int i=29;i>=0;i--)
		{
			mask|=1<<i;
			int need=0;
			int res=0;
			for(int x:nums)
			{
				if(res)
				{
					res&=x;
					need++;
				}
				else if(x&mask)
				{
					res=x&mask;
				}
			}
			if(res)
			{
				need++;
			}
			if(need>k)
			{
				mask-=1<<i;
			}
		}
		return (1<<30)-mask-1;
	}
};
