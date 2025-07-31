#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth)
    {
        int n=(int)words.size();
        int i=0;
        vector<string> ans;
        while(i<n)
        {
            int j=i;
            int len=0,chrs=0;
            while(j<n&&len+words[j].size()+(j-i)<=maxWidth)
            {
                len+=words[j].size();
                chrs+=words[j].size();
                j++;
            }
            int space=maxWidth-chrs;
            int gap=j-i-1;
            string line;
            if(j==n||gap==0)
            {
                for(int k=i;k<j;k++)
                {
                    line+=words[k];
                    if(k!=j-1)
                    {
                        line+=" ";
                    }
                }
                while(line.size()<maxWidth)
                {
                    line+=" ";
                }
            }
            else
            {
                int each=space/gap;
                int extra=space%gap;
                for(int k=i;k<j;k++)
                {
                    line+=words[k];
                    if(k!=j-1)
                    {
                        line+=string(each+(extra>0?1:0),' ');
                        extra--;
                    }
                }
            }
            ans.push_back(line);
            i=j;
        }
        return ans;
    }
};
