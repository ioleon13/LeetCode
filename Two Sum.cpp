

typedef pair<int,int> Pair; // idx,val
bool isLess(const Pair& left, const Pair& right)
{
    return left.second < right.second;
}
class Solution {
public:
    
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if(numbers.empty())
            return vector<int>();
        int n = numbers.size();
        vector<Pair> vec(n);
        for(int i = 0; i < n; i++)
            vec[i] = Pair(i+1,numbers[i]);
        sort(vec.begin(),vec.end(),isLess);
        int i = 0;
        int j = n-1;
        vector<int> ret(2,-1);
        while(i < j)
        {
            int total = vec[i].second + vec[j].second;
            if(total > target)
                j--;
            else if(total < target)
                i++;
            else 
            {
                ret[0] = vec[i].first < vec[j].first ? vec[i].first : vec[j].first;
                ret[1] = vec[i].first > vec[j].first ? vec[i].first : vec[j].first;
                return ret;
            }
        }
        
    }
};