#include <iostream>
#include <algorithm>
#include <regex>
using namespace std;

class Solution
{
public:
    string complexNumberMultiply(const string& num1,const string& num2)
    {
        regex pattern(R"(([-]?\d+)\+([-]?\d+)i)");
        smatch match;
        regex_match(num1,match,pattern);
        int r1=stoi(match[1]);
        int i1=stoi(match[2]);
        regex_match(num2,match,pattern);
        int r2=stoi(match[1]);
        int i2=stoi(match[2]);
        int r=r1*r2-i1*i2;
        int i=r1*i2+r2*i1;
        return to_string(r)+"+"+to_string(i)+"i";
    }
};
