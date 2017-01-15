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
// use pq to store the earliest end meeting, if there is no overlap, remove it
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](Interval& l, Interval& r) { return l.start < r.start;});
        priority_queue<int, vector<int>, greater<int> > pq;
        for (int i = 0; i < intervals.size(); i++)
        {
            if (!pq.empty() && intervals[i].start >= pq.top()) {
                pq.pop();
                pq.emplace(intervals[i].end);
            } else {
                pq.emplace(intervals[i].end);
            }
        }
        return pq.size();
    }
};
