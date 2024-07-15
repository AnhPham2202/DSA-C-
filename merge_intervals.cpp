#include <iostream>
#include <vector>

using namespace std;


vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n = intervals.size();
    vector<vector<int>> rs;
    int lastEnd = -1;
    int start;
    for (int i = 0; i < n; i++) {

        if (lastEnd >= intervals[i][0]) {

        } else {
            vector<int> subRs(2);
            subRs[0] = start;
            subRs[1] = lastEnd;
            start = intervals[i][0];
        }

        lastEnd = intervals[i][1];
    }

    return rs;
}

int main() {

    vector<vector<int>> a = {{1,3},{2,6},{8,10},{15,18}};
    merge(a);

    return 0;
}