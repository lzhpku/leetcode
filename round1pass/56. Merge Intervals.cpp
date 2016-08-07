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
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() <= 1)
            return intervals;
        vector<Interval> ret;
        sort(intervals.begin(), intervals.end(), cmp);
        Interval temp(intervals[0].start, intervals[0].end);
        for(int i = 1; i < intervals.size(); i ++) {
            if(intervals[i].start <= temp.end)
                temp.end = max(temp.end, intervals[i].end);
            else {
                ret.push_back(temp);
                temp.start = intervals[i].start;
                temp.end = intervals[i].end;
            }
        }
        ret.push_back(temp);
        return ret;
    }
    
    static bool cmp(Interval a, Interval b) {
        return a.start < b.start;
    }
};