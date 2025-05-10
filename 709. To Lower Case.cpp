#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution
{
public:
    string toLowerCase(string s)
    {
        for(char& c:s)
        {
            if(c<='Z'&&c>='A')
            {
                c=c-'A'+'a';
            }
        }
        return s;
    }
};
