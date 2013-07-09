
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ret;
        if(strs.empty())
            return ret;
        int n = strs.size();
        map<string,vector<string> > hash;
        for(int i = 0; i < n; i++)
        {
            string tem = strs[i];
            sort(tem.begin(),tem.end());
            if(!hash.count(tem))
                hash.insert(make_pair(tem,vector<string>()));
             hash[tem].push_back(strs[i]);
        }
        for(map<string,vector<string> >::iterator iter = hash.begin(); iter != hash.end(); iter++)
        {
            vector<string> vec = iter->second;
            if(vec.size() > 1)
            {
                for(int i = 0; i < vec.size(); i++)
                    ret.push_back(vec[i]);
            }
        }
        return ret;
    }
};