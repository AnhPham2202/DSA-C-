#include <iostream>
#include <vector>
using namespace std;


void combination(int i, int t, vector<int>& arr, vector<vector<int>>& rs, vector<int>& ds) {
    // all index are loop already
    if (i == arr.size()) {
        if (t == 0) {
            rs.push_back(ds);
        }
        return;
    }

    // pick case
    if (arr[i] <= t) {
        ds.push_back(arr[i]);
        combination(i, t - arr[i], arr, rs, ds);
        //backtrack
        ds.pop_back();
    }
    combination(i + 1, t, arr, rs, ds);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> rs;
    vector<int> ds;
    combination(0, target, candidates, rs, ds);
    return rs;
}

int main () {
    vector<int> a = {2,3, 6, 7};
    combinationSum(a, 7);
    return 0;
}