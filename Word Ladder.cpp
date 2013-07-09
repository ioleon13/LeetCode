
class Solution {
public:
    vector<string> getNext(const string& str, unordered_set<string> &dict)
    {
        vector<string> ret;
        if(str.empty())
            return ret;
        int n = str.size();
        for(int i = 0; i < n; i++)
            for(char ch = 'a'; ch <= 'z'; ch++)
            {
                string tem = str;
                if(tem[i] != ch)
                {
                    tem[i] = ch;
                        if(dict.count(tem))
                            ret.push_back(tem);
                }    
            }
        return ret;
    }
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(start.empty() || end.empty())
            return 0;
        queue<string> que;
        que.push(start);
        set<string> hash;
        int currentLevel = 1;
        int nextLevel = 0;
        int total = 1;
        while(!que.empty())
        {
            string top = que.front();
            if(top == end)
                return total;
            que.pop();
            currentLevel--;
            
            vector<string> vec = getNext(top,dict);
            for(int i = 0; i < vec.size(); i++)
            {   
                if(!hash.count(vec[i]))
                {
                    que.push(vec[i]);  
                    hash.insert(vec[i]);
                    nextLevel++;  
                }              
            }
            if(currentLevel == 0)
            {
                currentLevel = nextLevel;
                nextLevel = 0;
                total++;
            }
        }
        return 0;
    }
};


class Solution {
public:
    vector<string> getNext(const string& str, unordered_set<string>& dict)
    {
        vector<string> ret;
        if(str.empty())
            return ret;
        int n = str.size();
        for(int i = 0; i < n; i++)
            for(char ch = 'a'; ch <= 'z'; ch++)
            {
                string tem = str;
                if(tem[i] != ch)
                {
                    tem[i] = ch;
                    if(dict.count(tem))
                        ret.push_back(tem);
                }
            }
        return ret;
    
    }
    void traverseDFS(string current, string end, int len, int& minLen, unordered_set<string>& dict, set<string>& hash)
    {
        if(current == end)
        {
            if(len + 1 < minLen)
                minLen = len + 1;
            hash.clear();
            return;
        }
        vector<string> vec = getNext(current,dict);
        for(int i = 0; i < vec.size(); i++)
        {
            if(!hash.count(vec[i]))
            {
                hash.insert(vec[i]);
                traverseDFS(vec[i],end,len+1,minLen,dict,hash);
            }
        }    
    }
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(start.empty() || end.empty())
            return 0;
        int minLen = INT_MAX;
        set<string> hash;
        traverseDFS(start,end,1,minLen,dict,hash);
        return minLen;
    }
};
