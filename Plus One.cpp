
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(digits.empty())
            return vector<int>();
        int n = digits.size();
        vector<int> vec(n,0);
        int carry = 1;
        for(int i = n-1; i >= 0; i--)
        {
            int total = digits[i] + carry;
            vec[i] = total % 10;
            carry = total / 10;
            
        }
        if(carry)
            vec.insert(vec.begin(),carry);
        return vec;
        
    }
};