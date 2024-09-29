#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> map;

    int sum = 0, result = 0;
    map[sum] = 1;

    for (int n : nums) {
        sum += n;
        result += map[sum - k];
        map[sum]++;
    }

    return result;
}
int main() {
    vector<int> a = {1,1,1,-3,3};
    subarraySum(a, 3);

    return 0;
}