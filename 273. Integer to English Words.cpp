#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    const vector<string> belowTen={"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    const vector<string> tenToTwenty={"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    const vector<string> ten={"","Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    
    string dfs(int num)
    {
        if(num<10)
        {
            return belowTen[num];
        }
        if(num<20)
        {
            return tenToTwenty[num-10];
        }
        if(num<100)
        {
            return ten[num/10]+(num%10?" "+belowTen[num%10]:"");
        }
        if(num<1000)
        {
            return dfs(num/100)+" Hundred"+(num%100?" "+dfs(num%100):"");
        }
        if(num<1000000)
        {
            return dfs(num/1000)+" Thousand"+(num%1000?" "+dfs(num%1000):"");
        }
        if(num<1000000000)
        {
            return dfs(num/1000000)+" Million"+(num%1000000?" "+dfs(num%1000000):"");
        }
        return dfs(num/1000000000)+" Billion"+(num%1000000000?" "+dfs(num%1000000000):"");
    }
    
public:
    string numberToWords(int num)
    {
        if(num==0)
        {
            return "Zero";
        }
        return dfs(num);
    }
};
