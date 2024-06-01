// https://leetcode.com/problems/longest-consecutive-sequence/
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> map;
    int len = 0;
    for (int & num : nums) { // O(n)
        map.insert(num);
    }

    for (int & num : nums) {  // O(n)
        int head = num - 1;
        if (map.find(head) == map.end()) {
            int val = num + 1;
            int count = 1;

            while (map.find(val) != map.end()) { // O(1))
                val++;
                count++;
            }

            len = max(count, len);
        }
    }

    return len;
}

int main() {
    vector<int> a{1,9,3,0,18,5,2,4,10,7,12,6};

    cout << longestConsecutive(a);
    return 0;
};