#include <iostream>
#include <vector>
using namespace std;
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> prefix(n);
    vector<int> suffix(n);
    prefix[0] = 1;
    suffix[n - 1] = 1;

    for(int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] * nums[i - 1];
    }

    for (int i = n - 2; i >= 0; i--) {
        suffix[i] = suffix[i + 1] * nums[i + 1];
    }
    vector<int> rs(n);

    for(int i = 0; i < n; i++) {
        rs[i] = prefix[i] * suffix[i];
    }

    return rs;
}

void print(vector<int> arr) {
    for(auto & n : arr) {
        cout << n << ",";
    }
}

int main() {
    vector<int> arr = {1,2,3,4};

    print(productExceptSelf(arr));


    return 0;
}