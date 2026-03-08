#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Encrypter
{
private:
    int arr[26];
    unordered_map<string, int> cnt;
    vector<string> mp;
    
public:
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary)
    {
        memset(arr, -1, sizeof(arr));
        for (int i = 0; i < keys.size(); i++)
        {
            arr[keys[i] - 'a'] = i;
        }
        mp = values;
        for (auto& s : dictionary)
        {
            cnt[encrypt(s)]++;
        }
    }
    
    string encrypt(const string& word1)
    {
        string ans;
        for (char c : word1)
        {
            if (arr[c - 'a'] == -1)
            {
                return "";
            }
            ans += mp[arr[c - 'a']];
        }
        return ans;
    }
    
    int decrypt(const string& word2)
    {
        return cnt[word2];
    }
};
