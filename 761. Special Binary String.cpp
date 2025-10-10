#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string makeLargestSpecial(string s)
    {
        int n = (int)s.size();
        int cnt = 0, l = 0;
        vector<string> temp;
        for (int r = 0; r < n; r++)
        {
            if (s[r] == '1')
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
            if (cnt == 0)
            {
                temp.push_back('1' + makeLargestSpecial(s.substr(l + 1, r - l - 1)) + '0');
                l = r + 1;
            }
        }
        sort(temp.begin(), temp.end(), greater<>());
        string ans;
        for (auto& t : temp)
        {
            ans += t;
        }
        return ans;
    }
};
