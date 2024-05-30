// https://leetcode.com/problems/longest-mountain-in-array/


#include <iostream>
#include <vector>

using namespace std;
int longestMountain(vector<int>& arr) {
    int largest = 0;

    for (int i = 1; i < arr.size() - 1;) {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            int count = 1;
            // count left
            int j = i;
            while (j >= 1 && arr[j - 1] < arr[j]) {
                j--;
                count++;
            }
            // count right
            while (i < arr.size() - 1 && arr[i] > arr[i + 1]) {
                i++;
                count++;
            }
            largest = max(largest, count);
        } else {
            i++;
        }
    }
    return largest;
}

int main() {
    vector<int> a{2,0,2,0};

    cout << longestMountain(a);
}