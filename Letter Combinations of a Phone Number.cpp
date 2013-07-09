
class Solution {
public:
     
    void generate(vector<string>& ret, string digits, int pos, int n, string& str, int* counts, char* letter)
    {
        if(pos == n)
        {
            ret.push_back(str);
            return;  
        }
        int idx = digits[pos] - '0';
        for(int i = 0; i < counts[idx]; i++)
        {
            str[pos] = letter[idx] + i;
            generate(ret,digits,pos+1,n,str,counts,letter);
        }    
    }
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ret;
        if(digits.empty())
        {    
            ret.push_back("");
            return ret;
        }
        int n = digits.size();
        string str(n,' ');
        int counts[] = {0, 0, 3, 3, 3, 3, 3, 4, 3, 4};  
        char letter[] = {'0', '0', 'a', 'd', 'g', 'j', 'm', 'p', 't', 'w'};
        generate(ret,digits,0,n,str,counts,letter);
        return ret;
    }
};