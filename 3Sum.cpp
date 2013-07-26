
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        if(num.empty())
            return ret;
        int n = num.size();
        sort(num.begin(),num.end());
        vector<int> vec(3);
        for(int k = 0; k < n; k++)
        {
            if(k >= 1 && num[k-1] == num[k])
                continue;
            int i = k+1; 
            int j = n-1;
            while(i < j)
            {
                int total = num[k] + num[i] + num[j];
                if(total > 0)
                    j--;
                else if(total < 0)
                    i++;
                else
                {
                    vec[0] = num[k];
                    vec[1] = num[i];
                    vec[2] = num[j];
                    ret.push_back(vec);
                    while(i+1 < n && num[i] == num[i+1])
                        i++;
                    i++;
                    while(j-1 >= 0 && num[j] == num[j-1])
                        j--;
                    j--;
                
                }
            
            }
        }
        return ret;
    }
};