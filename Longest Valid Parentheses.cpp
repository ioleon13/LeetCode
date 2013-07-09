
class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.empty())
            return 0;
        int n = s.size();
        int leftCnt = 0;
        int totalCnt = 0;
        int maxLeftCnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(')
            {
                leftCnt++;
                totalCnt++;
            }    
            if(s[i] == ')')
            {
                leftCnt--;
                totalCnt++;
            }
            if(leftCnt == 0 && totalCnt > maxLeftCnt)
                maxLeftCnt = totalCnt;
            if(leftCnt < 0)
            {
                leftCnt = 0;
                totalCnt = 0;
            }
        }
        int rightCnt = 0;
        totalCnt = 0;
        int maxRightCnt = 0;
        for(int i = n-1; i >= 0; i--)
        {
            if(s[i] == ')')
            {
                rightCnt++;
                totalCnt++;
            }
            if(s[i] == '(')
            {
                rightCnt--;
                totalCnt++;
            }
            if(rightCnt == 0 && totalCnt > maxRightCnt)
                maxRightCnt = totalCnt;
            if(rightCnt < 0)
            {
                rightCnt = 0;
                totalCnt = 0;
            }

        }
        return max(maxLeftCnt,maxRightCnt);
    }
};
