#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
private:
    int eval(const string& exp, int& pos, unordered_map<string, int>& mp)
    {
        pos++;
        int end = (int)exp.find(' ', pos);
        string op = exp.substr(pos, end - pos);
        pos = end + 1;
        int res;
        if (op == "add" || op == "mult")
        {
            int v1 = parse(exp, pos, mp);
            int v2 = parse(exp, pos, mp);
            res = op == "add" ? v1 + v2 : v1 * v2;
        }
        else
        {
            unordered_map<string, int> next = mp;
            while (exp[pos] != '(')
            {
                end = pos;
                while (exp[end] != ' ' && exp[end] != ')')
                {
                    end++;
                }
                if(exp[end] == ')')
                {
                    break;
                }
                string var = exp.substr(pos, end - pos);
                pos = end + 1;
                int val = parse(exp, pos, next);
                next[var] = val;
            }
            res = parse(exp, pos, next);
        }
        pos++;
        return res;
    }
    
    int parse(const string& exp, int& pos, unordered_map<string, int>& mp)
    {
        int res;
        if (exp[pos] == '(')
        {
            res = eval(exp, pos, mp);
            if (exp[pos] == ' ')
            {
                pos++;
            }
        }
        else
        {
            int end = pos;
            while (exp[end] != ' ' && exp[end] != ')')
            {
                end++;
            }
            if (exp[pos] == '-' || (exp[pos] >= '0' && exp[pos] <= '9'))
            {
                res = stoi(exp.substr(pos, end - pos));
            }
            else
            {
                res = mp.at(exp.substr(pos, end - pos));
            }
            pos = exp[end] == ' ' ? end + 1 : end;
        }
        return res;
    }
    
public:
    int evaluate(const string& expression)
    {
        unordered_map<string, int> mp;
        int pos = 0;
        return eval(expression, pos, mp);
    }
};
