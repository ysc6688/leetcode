/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 bool cmp(const Interval& a, const Interval& b) {
     return a.start < b.start;
 }
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() <= 0) return intervals;
        sort(intervals.begin(),intervals.end(),cmp);
        vector<Interval> res;
        int index = 0;
        while(index < intervals.size() - 1)
        {
            if(intervals[index].end >= intervals[index+1].start )
            {
                intervals[index+1].start = intervals[index].start;
                intervals[index+1].end = (intervals[index+1].end > intervals[index].end) ? intervals[index+1].end : intervals[index].end;
                index++;
            }
            else
            {
                res.push_back(intervals[index]);
                index++;
            }
        }
        res.push_back(intervals[index]);
        return res;
    }
};
