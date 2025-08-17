#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    vector<int> maxsub(vector<int>& nums,int k)
    {
        vector<int> stk;
        int drop=(int)nums.size()-k;
        for(int i:nums)
        {
            while(drop&&!stk.empty()&&stk.back()<i)
            {
                stk.pop_back();
                drop--;
            }
            stk.push_back(i);
        }
        return vector<int>(stk.begin(),stk.begin()+k);
    }
    
    vector<int> merge(const vector<int>& seq1,const vector<int>& seq2)
    {
        int m=(int)seq1.size(),n=(int)seq2.size();
        int i=0,j=0;
        vector<int> ans;
        while(i<m||j<n)
        {
            if(lexicographical_compare(seq1.begin()+i,seq1.end(),seq2.begin()+j, seq2.end()))
            {
                ans.push_back(seq2[j]);
                j++;
            }
            else
            {
                ans.push_back(seq1[i]);
                i++;
            }
        }
        return ans;
    }
    
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k)
    {
        int m=(int)nums1.size(),n=(int)nums2.size();
        vector<int> ans;
        for(int i=max(0,k-n);i<=min(k,m);i++)
        {
            vector<int> seq1=maxsub(nums1,i);
            vector<int> seq2=maxsub(nums2,k-i);
            vector<int> temp=merge(seq1,seq2);
            if(temp>ans)
            {
                ans=temp;
            }
        }
        return ans;
    }
};
