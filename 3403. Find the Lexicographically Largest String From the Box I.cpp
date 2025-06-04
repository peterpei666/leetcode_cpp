#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string last(const string& word)
    {
        int i=0,j=1;
        int n=(int)word.size();
        while(j<n)
        {
            int k=0;
            while(j+k<n&&word[i+k]==word[j+k])
            {
                k++;
            }
            if(j+k<n&&word[i+k]<word[j+k])
            {
                int temp=i;
                i=j;
                j=max(j+1,temp+k+1);
            }
            else
            {
                j=j+k+1;
            }
        }
        return word.substr(i,n-i);
    }
    
    string answerString(const string& word, int n)
    {
        if(n==1)
        {
            return word;
        }
        string temp=last(word);
        int m1=(int)word.size();
        int m2=(int)temp.size();
        return temp.substr(0,min(m1-n+1,m2));
    }
};
