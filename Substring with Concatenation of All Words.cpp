
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        if(S.empty() || L.empty())
            return ret;
        int n = S.size();
        int wordCnt = L.size();
        int wordLen = L[0].size();
        map<string,int> hash;
        for(int i = 0; i < wordCnt; i++)
            hash[L[i]]++;
        for(int i = 0; i <= n-wordCnt*wordLen; i++)
        {
            map<string,int> tem;
            int j = 0;
            for(; j < wordCnt; j++)
            {
                string word = S.substr(i+wordLen*j,wordLen);
                if(!hash.count(word))
                    break;
                else
                {
                    tem[word]++;
                    if(tem[word] > hash[word])
                        break;
                }
            }
            if(j == wordCnt)
                ret.push_back(i);
        }
        return ret;
    }
};