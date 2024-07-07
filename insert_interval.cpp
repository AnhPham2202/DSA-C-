
#include <iostream>
#include<vector>
#include <limits.h>

using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    // check most left part
    int i = 0;
    vector<vector<int>> rs;
    while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
        rs.push_back(intervals[i++]);
    }

    int min = INT_MAX;
    int max = INT_MIN;
    while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
        min = std::min(min, intervals[i][0]);
        max = std::max(max, intervals[i][1]);
        i++;
    }
    max = std::max(newInterval[1], max);
    min = std::min(newInterval[0], min);
    vector temp = {min, max};
    rs.push_back(temp);

    while (i < intervals.size()) {
        rs.push_back(intervals[i]);
        i++;
    }

    return rs;
}

//int main() {
//    vector<vector<int>> i = {{1, 3}, {6, 9}};
//    vector<int> newIntervals = {2, 5};
//
//    insert(i, newIntervals);
//
//    return 0;
//}