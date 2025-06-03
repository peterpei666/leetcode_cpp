#include <iostream>
#include <algorithm>
#include <random>
using namespace std;

class Solution
{
public:
    vector<int> origin;
    vector<int> current;
    int randomInt(int l,int r)
    {
        static mt19937 gen(random_device{}());
        uniform_int_distribution<> dist(l,r);
        return dist(gen);
    }
    
    Solution(vector<int>& nums)
    {
        origin=nums;
        current=nums;
    }
    
    vector<int> reset()
    {
        current=origin;
        return current;
    }
    
    vector<int> shuffle()
    {
        int n=(int)current.size();
        for(int i=n-1;i>0;i--)
        {
            int j=randomInt(0,i);
            swap(current[i],current[j]);
        }
        return current;
    }
};
