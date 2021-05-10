#include <string>
#include <iostream>
#include <vector>
using namespace std;

typename std::hash<std::string> Hash;
vector<size_t> RKSearch(string &str, string j)
{
    vector<size_t> result;
    auto tempHash = Hash(j);
    for (size_t i = 0; i < str.length() && (i + j.length()) < str.length(); i++)
    {
        auto substr = str.substr(i, j.length());
        if (tempHash == Hash(substr))
        {
            bool qually = false;
            for (size_t k = 0; k < j.length(); k++)
            {
                qually = substr[k] == j[k];
            }
            if (qually)
                result.push_back(i);
        }
    }
    return result;
}

vector<size_t> BMSearch(std::string string, std::string substring)
{
    int sl, ssl;
    int res = -1;
    sl = string.length();
    ssl = substring.length();
    vector<size_t> result;
    int i, Pos;
    int BMT[256];
    for (i = 0; i < 256; i++)
        BMT[i] = ssl;
    for (i = ssl - 1; i >= 0; i--)
        if (BMT[(short)(substring[i])] == ssl)
            BMT[(short)(substring[i])] = ssl - i - 1;
    Pos = ssl - 1;
    while (Pos < sl)
        if (substring[ssl - 1] != string[Pos])
            Pos = Pos + BMT[(short)(string[Pos])];
        else
            for (i = ssl - 2; i >= 0; i--)
            {
                if (substring[i] != string[Pos - ssl + i + 1])
                {
                    Pos += BMT[(short)(string[Pos - ssl + i + 1])] - 1;
                    break;
                }
                else if (i == 0)
                {
                    result.push_back(Pos - ssl + 1);
                    Pos = Pos + BMT[(short)(string[Pos])] + 1;
                    break;
                }
            }
    return result;
}

vector<size_t> KMPSearch(string& S, const string pattern)
{
	vector<int> pf(pattern.length());
    vector<size_t> result; 
	pf[0] = 0;
	for (int k = 0, i = 1; i < pattern.length(); ++i)
	{
		while ((k > 0) && (pattern[i] != pattern[k]))
			k = pf[k - 1];

		if (pattern[i] == pattern[k])
			k++;

		pf[i] = k;
	}

	for (int k = 0, i = 0; i < S.length(); ++i)
	{
		while ((k > 0) && (pattern[k] != S[i]))
			k = pf[k - 1];

		if (pattern[k] == S[i])
			k++;

		if (k == pattern.length())
			result.push_back(i - pattern.length() + 1);
		
	}

	return result;
}