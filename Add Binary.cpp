class Solution {
public:
    bool isAllZero(const string& str)
    {
        if(str.empty())
            return false;
        int n = str.size();
        for(int i = 0; i < n; i++)
            if(str[i] != '0')
               return false;
        return true;  
    }
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(isAllZero(b))
            return a;
        int m = a.size();
        int n = b.size();
        string stra = a;
        string strb = b;
        int dif = abs(m-n);
        if(m > n)
        {  
            while(dif-- > 0)
                strb.insert(0,"0");
        }
        else 
        {
            while(dif-- > 0)
                stra.insert(0,"0");
        }
        int len = max(m,n);
        string carry(len,' ');
        string total(len,' ');
        for(int i = 0; i < len; i++)
        {
            if(stra[i] == strb[i])
                total[i] = '0';
            else total[i] = '1';
            if(stra[i] == '1' && strb[i] == '1')
                carry[i] = '1';
            else carry[i] = '0';
        }
        int i = 0;
        while(i < carry.size() && carry[i] == '0')
            i++;
        carry = carry.substr(i,carry.size()-i+1);
        carry += '0';
        return addBinary(total,carry);
    }
};