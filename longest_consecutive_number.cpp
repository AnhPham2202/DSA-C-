#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> set;
    for (auto & n : nums) {
        set.insert(n);
    }

    int maxV = INT_MIN;

    for (auto & n : nums) {
        int pre = n - 1;
        int count = 1;
        while (set.find(pre) != set.end()) {
            count++;
        }
        maxV = max(maxV, count);
    }

    return maxV;
}

int main() {

    vector<int> a = {100,4,200,1,3,2};

    longestConsecutive(a);

    return 0;
}