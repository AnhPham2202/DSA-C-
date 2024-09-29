#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void reverse(vector<int>& nums, int l, int r) {
    while (l < r) {
        int temp = nums[l];
        nums[l] = nums[r];
        nums[r] = temp;
        l++;
        r--;
    }
}

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    reverse(nums, n - k, n - 1);
    reverse(nums, 0, n - k -1);
    reverse(nums, 0, n - 1);
}


int main() {
    vector<int> a = {-1};
    rotate(a, 3);
    return 0;
}