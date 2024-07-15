#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> set;
    for (auto & n : nums) {
        set.insert(n);
    }

    int maxV = 0;

    for (auto & n : nums) {
        int head = n - 1;
        if (set.find(head) == set.end()) {
            int count = 0;
            int val = n;
            while (set.find(val) != set.end()) {
                count++;
                val++;
            }
            maxV = max(maxV, count);
        }

    }

    return maxV;
}

int main() {

    vector<int> a = {100,4,200,1,3,2};

    longestConsecutive(a);

    return 0;
}