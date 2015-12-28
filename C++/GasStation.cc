// There are N gas stations along a circular route, where the amount of gas at
// station i is gas[i].

// You have a car with an unlimited gas tank and it costs cost[i] of gas to travel
// from station i to its next station (i+1). You begin the journey with an empty
// tank at one of the gas stations.

// Return the starting gas station's index if you can travel around the circuit
// once, otherwise return -1.

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int remain = 0;
        int index = 0;
        int total_gas = 0;
        int total_cost = 0;
        for (int i = 0; i < gas.size(); i++) {
            remain += gas[i] - cost[i];
            total_gas += gas[i];
            total_cost += cost[i];
            if (remain < 0) {
                reamin = 0;
                index = i + 1;
            }
        }
        return total_cost > total_gas ? -1 : index;
    }
};
