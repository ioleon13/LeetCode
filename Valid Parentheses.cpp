
class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.empty())
            return true;
        int n = s.size();
        stack<char> sta;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                sta.push(s[i]);
            else if(sta.empty())
                return false;
            else if( (s[i] == ')' && sta.top() == '(') || (s[i] == ']' && sta.top() == '[') || (s[i] == '}' && sta.top() == '{'))
                sta.pop();
            else return false;
        }
        return sta.empty() ? true : false;
    }
};

