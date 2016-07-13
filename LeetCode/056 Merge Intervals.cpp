//https://leetcode.com/problems/merge-intervals/
// This method is not a neat one. It works tho.

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
        multimap<int,int> data;
        vector<Interval> res;
        if(intervals.empty()) return res;
        for(auto a:intervals){
            data.insert(pair<int, int>(a.start,a.end));
        }
        int start=data.begin()->first,end=data.begin()->second;
        auto a=data.begin();
        for(++a; a!=data.end(); ++a){
            if(a->first <=end && a->second >end){
                end=a->second;
            }
            if(a->first > end){
                res.push_back(Interval(start,end));
                start=a->first;
                end=a->second;
            }
        }
        res.push_back(Interval(start,end));
        return res;
    }
};