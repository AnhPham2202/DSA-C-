#include <iostream>
#include <vector>
using namespace std;

int backtrack(int idx, int tank, vector<int>& gas, vector<int>& cost, int n) {

}


int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    vector<int> diff;
    int sum = 0;
    for (int i = 0; i < gas.size(); i++) {
        diff.push_back(gas[i] - cost[i]);
        sum += (gas[i] - cost[i]);
    }

    if (sum < 0) return -1;
    int tank = 0;
    int rs = 0;
    for (int i = 0; i < n; i++) {
        tank += diff[i];

        if (tank < 0) {
            rs = i + 1;
            tank = 0;
        }
    }

    return rs;
}



int main() {
    vector<int> gas = {3,1,1};
    vector<int> cost = {1,2,2};

    cout << canCompleteCircuit(gas, cost);
    return 0;
}