#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {
        int c=0;
        for(char m:s)
        {
            if(m=='1')
            {
                c++;
            }
        }
        fill(s.begin(),s.end(),'0');
        s[s.size()-1]='1';
        fill(s.begin(),s.begin()+c-1,'1');
        return s;
    }
};
