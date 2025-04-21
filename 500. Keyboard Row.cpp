#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    string row1="qwertyuiop";
    string row2="asdfghjkl";
    string row3="zxcvbnm";

    int row(char c)
    {
        if(row1.find(c)!=string::npos)
        {
            return 1;
        }
        if(row2.find(c)!=string::npos)
        {
            return 2;
        }
        return 3;
    }
    
    vector<string> findWords(vector<string>& words)
    {
        vector<string> ret;
        for(string& w:words)
        {
            int r=-1,f=1;
            for(char c:w)
            {
                if(c>='A'&&c<='Z')
                {
                    c+='a'-'A';
                }
                if(r==-1)
                {
                    r=row(c);
                }
                else
                {
                    if(r!=row(c))
                    {
                        f=0;
                        break;
                    }
                }
            }
            if(f)
            {
                ret.push_back(w);
            }
        }
        return ret;
    }
};
