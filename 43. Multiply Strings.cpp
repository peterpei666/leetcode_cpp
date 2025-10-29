#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    const int BASE = 1000000000;
    const int BASE_DIGITS = 9;
    
    vector<int> stringToBigInt(const string& s) {
        vector<int> result;
        for (int i = (int)s.size(); i > 0; i -= BASE_DIGITS) {
            int start = std::max(0, i - BASE_DIGITS);
            result.push_back(stoi(s.substr(start, i - start)));
        }
        return result;
    }
    
    string bigIntToString(const vector<int>& v) {
        if (v.empty())
        {
            return "0";
        }
        string s = to_string(v.back());
        for (int i = (int)v.size() - 2; i >= 0; --i) {
            std::string temp = to_string(v[i]);
            s += string(BASE_DIGITS - temp.size(), '0') + temp;
        }
        return s;
    }
    
    vector<int> vec_multiply(const vector<int>& num1, const vector<int>& num2) {
        vector<int> result(num1.size() + num2.size(), 0);
        for (int i = 0; i < num1.size(); i++)
        {
            for (int j = 0; j < num2.size(); j++)
            {
                long long product = (long long)num1[i] * num2[j] + result[i + j];
                result[i + j] = product % BASE;
                result[i + j + 1] += product / BASE;
            }
        }
        while (result.size() > 1 && result.back() == 0) {
            result.pop_back();
        }
        return result;
    }
    
public:
    string multiply(const string& num1, const string& num2)
    {
        vector<int> a = stringToBigInt(num1);
        vector<int> b = stringToBigInt(num2);
        vector<int> result(a.size() + b.size(), 0);
        for (int i = 0; i < a.size(); i++)
        {
            for (int j = 0; j < b.size(); j++)
            {
                long long product = (long long)a[i] * b[j] + result[i + j];
                result[i + j] = product % BASE;
                result[i + j + 1] += product / BASE;
            }
        }
        while (result.size() > 1 && result.back() == 0)
        {
            result.pop_back();
        }
        return bigIntToString(result);
    }
};
