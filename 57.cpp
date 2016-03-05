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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int sz = intervals.size();  
        vector<Interval> res;  
          
        for(int i=0; i<sz; i++) {  
            if(intervals[i].end < newInterval.start) {  
                res.push_back( intervals[i]);  
            } else if( intervals[i].start > newInterval.end) {  
                res.push_back( newInterval);  
                res.insert(res.end(), intervals.begin()+i, intervals.end() );  
                return res;  
            } else {  
                newInterval.start = min(newInterval.start, intervals[i].start);  
                newInterval.end = max(newInterval.end, intervals[i].end);  
            }  
        }  
        res.push_back(newInterval);   
        return res;  
    }
};
