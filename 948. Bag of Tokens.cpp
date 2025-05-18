#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int bagOfTokensScore(vector<int>& tokens, int power)
    {
        int n=(int)tokens.size();
        sort(tokens.begin(),tokens.end());
        int i=0,j=n-1,m=0,score=0;
        while(i<=j)
        {
            while(i<=j&&power>=tokens[i])
            {
                power-=tokens[i];
                i++;
                score++;
            }
            m=max(m,score);
            if(score==0||i>=j)
            {
                break;
            }
            score--;
            power+=tokens[j];
            j--;
        }
        return m;
    }
};
