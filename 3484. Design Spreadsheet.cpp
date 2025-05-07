#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Spreadsheet
{
public:
    unordered_map<string,int> mp;
    
    Spreadsheet(int rows)
    {
        ;
    }
    
    void setCell(string cell, int value)
    {
        mp[cell]=value;
    }
    
    void resetCell(string cell)
    {
        mp[cell]=0;
    }
    
    int getValue(string formula)
    {
        int i,a,b;
        if(formula[1]<='Z'&&formula[1]>='A')
        {
            string key="";
            i=1;
            while(formula[i]!='+')
            {
                key+=formula[i];
                i++;
            }
            a=mp[key];
        }
        else
        {
            a=formula[1]-'0';
            i=2;
            while(formula[i]!='+')
            {
                a*=10;
                a+=formula[i]-'0';
                i++;
            }
        }
        i++;
        if(formula[i]<='Z'&&formula[i]>='A')
        {
            string key="";
            while(i<formula.size())
            {
                key+=formula[i];
                i++;
            }
            b=mp[key];
        }
        else
        {
            b=formula[i]-'0';
            i++;
            while(i<formula.size())
            {
                b*=10;
                b+=formula[i]-'0';
                i++;
            }
        }
        return a+b;
    }
};
