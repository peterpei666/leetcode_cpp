#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        int n=(int)word1.size();
        if(n!=word2.size())
        {
            return false;
        }
        int m1=0,m2=0;
        int list1[26]={0};
        int list2[26]={0};
        for(int i=0;i<n;i++)
        {
            list1[word1[i]-'a']++;
            list2[word2[i]-'a']++;
            m1|=1<<(word1[i]-'a');
            m2|=1<<(word2[i]-'a');
        }
        if(m1!=m2)
        {
            return false;
        }
        sort(list1,list1+26);
        sort(list2,list2+26);
        return !memcmp(list1,list2,sizeof(list1));
    }
};
