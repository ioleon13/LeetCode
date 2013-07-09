
class Solution {
public:
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(num1.empty() || num2.empty())
            return string("");
        int m = num1.size();
        int n = num2.size();
        vector<int> vec(m+n,0);
        for(int i = 0; i < m; i++)
        {
            int carry = 0;
            for(int j = 0; j < n; j++)
            {    
                int digit1 = num1[m-1-i] - '0';
                int digit2 = num2[n-1-j] - '0';
                int total = digit1 * digit2 + carry + vec[i+j];
                vec[i+j] = total % 10;
                carry = total / 10;
            } 
            if(carry)
                vec[i+n] += carry;
        }
        int i = m+n-1;
        while(i >= 0 && vec[i] == 0)
            i--;
        if(i < 0)
            return string(1,'0');
        string ret = "";
        for(int j = i; j >= 0; j--)
            ret += vec[j] + '0';
        return ret;
    }
};
