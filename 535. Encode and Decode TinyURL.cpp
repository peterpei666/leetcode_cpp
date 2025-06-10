#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int cnt=0;
    vector<string> list;
    
    string encode(const string& longUrl)
    {
        string shortUrl="http://tinyurl.com/";
        shortUrl+=to_string(cnt);
        list.push_back(longUrl);
        return shortUrl;
    }

    string decode(const string& shortUrl)
    {
        return list[stoi(shortUrl.substr(19))];
    }
};
