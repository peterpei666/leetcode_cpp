#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minimumDeletions(const string& word, int k)
    {
        int list[26]={0};
        int n=(int)word.size();
        for(int i=0;i<n;i++)
        {
            list[word[i]-'a']++;
        }
        sort(&list[0],&list[0]+26,greater<int>());
        for(int i=0;i<26&&list[i]>0;i++)
        {
            int temp=0;
            for(int j=0;j<i;j++)
            {
                temp+=max(0,list[j]-k-list[i]);
            }
            for(int j=i+1;j<26&&list[j]>0;j++)
            {
                temp+=list[j];
            }
            n=min(temp,n);
        }
        return n;
    }
};
