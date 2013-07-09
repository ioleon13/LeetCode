/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Interval> ret;
        if(intervals.empty())
        {
            ret.push_back(newInterval);
            return ret;
        }
        int n = intervals.size();
        for(int i = 0; i < n; i++)
        {
            if(newInterval.start > intervals[i].end)
                ret.push_back(intervals[i]);
            else if(newInterval.end < intervals[i].start)
            {
                ret.push_back(newInterval);
                while(i < n)
                    ret.push_back(intervals[i++]); 
                return ret;
            }
            else
            {
                newInterval.start = min(newInterval.start,intervals[i].start);
                newInterval.end = max(newInterval.end,intervals[i].end);
            }
            
        }
        ret.push_back(newInterval);
        return ret;
        
    }
};
