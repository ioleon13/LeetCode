
class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(x <= 0)
            return 0;
        double val = x;
        double prev;
        do{
            prev = val;
            val = (val + x/val)/2;
        }while(abs(prev-val) > 0.00001);
        return val;
        
    }
};