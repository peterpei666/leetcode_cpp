#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        for (int i = 0; i < 9; i++)
        {
            bitset<9> found;
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    if (found.test(board[i][j] - '1'))
                    {
                        return false;
                    }
                    found.set(board[i][j] - '1');
                }
            }
        }
        for (int i = 0; i < 9; i++)
        {
            bitset<9> found;
            for (int j = 0; j < 9; j++)
            {
                if (board[j][i] != '.')
                {
                    if (found.test(board[j][i] - '1'))
                    {
                        return false;
                    }
                    found.set(board[j][i] - '1');
                }
            }
        }
        for (int i = 1; i < 9; i += 3)
        {
            for (int j = 1; j < 9; j += 3)
            {
                bitset<9> found;
                for (int dx = -1; dx <= 1; dx++)
                {
                    for (int dy = -1; dy <= 1; dy++)
                    {
                        if (board[i + dx][j + dy] != '.')
                        {
                            if (found.test(board[i + dx][j + dy] - '1'))
                            {
                                return false;
                            }
                            found.set(board[i + dx][j + dy] - '1');
                        }
                    }
                }
            }
        }
        return true;
    }
};
