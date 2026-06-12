class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0, final = 0;
        int start = 0;
        int n = gas.size();
        for(int i=0; i<n; i++){
            final += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if(total < 0){
                start = i+1;
                total = 0;
            }
        }
        if (final < 0) return -1;
        return start;
    }
};
