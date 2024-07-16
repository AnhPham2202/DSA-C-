#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void swap(int i, int j, vector<int>& nums) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void sortColors(vector<int>& nums) {
    int n = nums.size();
    int l = 0;
    int r = n - 1;

    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            swap(i, l, nums);
            l++;
        }


    }

    for (int i = r; i >= 0; i--) {

        if (nums[i] == 2) {
            swap(i, r, nums);
            r--;
        }
    }
}


int main() {
    vector<int> a = {2,0,2,1,1,0};
    sortColors(a);
    return 0;
}