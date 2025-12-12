#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> countMentions(int n, vector<vector<string>>& events)
    {
        vector<int> cnt(n);
        vector<int> next(n);
        sort(events.begin(), events.end(),
        [&](const vector<string>& a, const vector<string>& b)
        {
            int at = stoi(a[1]);
            int bt = stoi(b[1]);
            return at == bt ? b[0] == "MESSAGE" : at < bt;
        });

        for (auto&& e : events)
        {
            int cur = stoi(e[1]);
            if (e[0] == "MESSAGE")
            {
                if (e[2] == "ALL")
                {
                    for (int i = 0; i < n; i++)
                    {
                        cnt[i]++;
                    }
                }
                else if (e[2] == "HERE")
                {
                    for (int i = 0; i < n; i++)
                    {
                        if (next[i] <= cur)
                        {
                            cnt[i]++;
                        }
                    }
                }
                else
                {
                    int idx = 0;
                    for (int i = 0; i < e[2].size(); i++)
                    {
                        if (isdigit(e[2][i]))
                        {
                            idx = idx * 10 + (e[2][i] - '0');
                        }
                        if (i + 1 == e[2].size() || e[2][i + 1] == ' ')
                        {
                            cnt[idx]++;
                            idx = 0;
                        }
                    }
                }
            }
            else
            {
                int idx = stoi(e[2]);
                next[idx] = cur + 60;
            }
        }
        return cnt;
    }
};
