// Given an array containing N integers, and an number S denoting a target sum
// Find all distinct integers that can add up to form target sum. The numbers in each triplet should be ordered in asc order,
// and triplets should be ordered too.
// Return empty array if no such triplet exists.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> triplets(vector<int> a, int n) {
    sort(a.begin(), a.end());
    int size = a.size();
    vector<vector<int>> res;
    for (int i = 0; i < size - 2; i++) {
        int j = i + 1;
        int k = size - 1;

        while (j < k) {
            int currentSum = a[k] + a[j] + a[i];
            if (currentSum == n) {
                res.push_back({a[i], a[j], a[k]});
                k--;
            } else if (currentSum > n) {
                k--;
            } else {
                j++;
            }


        }
    }
    return res;
}

int main() {

    vector<int> a = {1,2,3,4,5,6,7,8,9,15};

    vector<vector<int>> rs = triplets(a, 18);
    for (auto & r : rs) {
        cout << "[";
        for (int j : r) {
            cout << " " << j << " ";
        }
        cout << "]" << endl;
    }


    return 0;
}
