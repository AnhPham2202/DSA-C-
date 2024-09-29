#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int arrayPairSum(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int sum = 0;

    for (int i = 0; i < n; i+=2) {
        sum += nums[i];
    }

    return sum;
}

int arrayPairSumOn(vector<int>& nums) {
    //bucket sort
    int maxNumberAllowed = 10000; //given in question -10^4 <= nums[i] <= 10^4
    vector<int> bucket(2 * maxNumberAllowed + 1); //we will create double size bucket since we have to handle negative numbers also

    //fill bucket
    for(int num: nums){
        bucket[10000 + num]++;
    }

    int count = 0;
    for(int num: bucket) {
        if (num != 0) {
            cout << count << " =>";
            cout << num << endl;
        }
        count++;
    }

    //iterate bucket
    bool shouldPick = true;
    int sum = 0;
    for(int i=0;i<= 20000;i++){
        //pick one and skip one in sorted order array
        while(bucket[i] > 0){
            if(shouldPick){
                sum+= (i - 10000);
            }
            shouldPick = !shouldPick; //flip the sign
            bucket[i]--;
        }
    }

    return sum;
}

int main() {
    vector<int> a = {6,2,6,5,1,2};
    arrayPairSumOn(a);
    return 0;
}