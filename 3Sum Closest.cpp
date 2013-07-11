class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(num.empty())
            return 0;
        int n = num.size();
        assert(n >= 3);
        sort(num.begin(),num.end());
        int minDist = INT_MAX;
        int ret = 0;
        for(int k = 0; k < n; k++)
        {
            int i = k+1;
            int j = n-1;
            while(i < j)
            {
                int candi = num[i] + num[j] + num[k];
                int dist = abs(candi - target);
                if(dist < minDist)
                {
                    minDist = dist;
                    ret = candi;
                }
                if(candi > target)
                    j--;
                else if(candi < target)
                    i++;
                else break;
            }   
        }
        return ret;
    }
};