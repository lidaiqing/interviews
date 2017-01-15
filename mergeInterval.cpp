/*tion for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

class Solution {
// sort interval base on its starting point, udate end point until no intersetion
public:

    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() == 0) return {};
        sort(intervals.begin(), intervals.end(), [](Interval& l, Interval& r){return l.start < r.start;});
        vector<Interval> res;
        int l = intervals[0].start, r = intervals[0].end;
        int i = 1;
        while (i < intervals.size())
        {
            if (intervals[i].start <= r) r = max(r, intervals[i].end);
            else {
                res.emplace_back(l, r);
                l = intervals[i].start;
                r = intervals[i].end;
            }
            i++;
        }
        res.emplace_back(l, r);
        return res;
    }
};
