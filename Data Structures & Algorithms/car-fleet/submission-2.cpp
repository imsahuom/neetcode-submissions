class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        
        vector<pair<int, double>> cars(n);
        for (int i = 0; i < n; i++) {
            double time_taken = (double)(target - position[i]) / speed[i];
            cars[i] = {position[i], time_taken};
        }
        sort(cars.begin(), cars.end());
        stack<double> st;
        for (int i = n - 1; i >= 0; i--) {
            double current_time = cars[i].second;
            if (st.empty()) {
                st.push(current_time);
            }
            else if (current_time > st.top()) {
                st.push(current_time);
            }
        }
        return st.size();
    }
};