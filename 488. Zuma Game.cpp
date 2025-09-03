#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution
{
private:
    string update(string board, int idx)
    {
        if (idx < 0)
        {
            return board;
        }
        int l = idx, r = idx;
        while (l > 0 && board[l] == board[l - 1])
        {
            l--;
        }
        while (r < board.length() && board[r] == board[r + 1])
        {
            r++;
        }
        if (r - l + 1 >= 3)
        {
            return update(board.substr(0, l) + board.substr(r + 1), l - 1);
        }
        else
        {
            return board;
        }
    }
    
public:
    int findMinStep(string board, string hand)
    {
        sort(hand.begin(), hand.end());
        queue<string> bq;
        queue<string> hq;
        queue<int> stepq;
        unordered_set<string> mp;
        bq.push(board);
        hq.push(hand);
        stepq.push(0);
        mp.insert(board + "/" + hand);
        while (!stepq.empty())
        {
            string curb = bq.front();
            string curh = hq.front();
            int cur = stepq.front();
            bq.pop();
            hq.pop();
            stepq.pop();
            for (int i = 0; i < curb.size(); i++)
            {
                for (int j = 0; j < curh.size(); j++)
                {
                    if (j > 0 && curh[j] == curh[j - 1])
                    {
                        continue;
                    }
                    if (i > 0 && curb[i - 1] == curh[j])
                    {
                        continue;
                    }
                    bool worth = false;
                    if (curb[i] == curh[j])
                    {
                        worth = true;
                    }
                    else if (i > 0 && curb[i] == curb[i - 1] && curb[i] != curh[j])
                    {
                        worth = true;
                    }
                    if (worth)
                    {
                        string newb = update(curb.substr(0, i) + curh[j] + curb.substr(i), i);
                        if (newb == "")
                        {
                            return cur + 1;
                        }
                        string newh = curh.substr(0, j) + curh.substr(j + 1);
                        if (!mp.count(newb + "/" +newh))
                        {
                            bq.push(newb);
                            hq.push(newh);
                            stepq.push(cur + 1);
                            mp.insert(newb + "/" +newh);
                        }
                    }
                }
            }
        }
        return -1;
    }
};
