
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 bool isLess(const Interval& left, const Interval& right)
 {
    return left.start < right.start;
 }
class Solution {
public:
    
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Interval> ret;
        if(intervals.empty())
            return ret;
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),isLess);
        Interval prev = intervals[0];
        for(int i = 1; i < n; i++)
        {
            if(intervals[i].start > prev.end)
            {
                ret.push_back(prev);
                prev = intervals[i];
            }
            else 
                prev = Interval(prev.start,max(prev.end,intervals[i].end));
        }
        ret.push_back(prev);
        return ret;
    }
};
