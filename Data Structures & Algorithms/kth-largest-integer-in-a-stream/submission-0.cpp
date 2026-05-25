class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int total = 0;
public:
    KthLargest(int k, vector<int>& nums) {
        total = k;
        for(auto x: nums){
            pq.push(x);
            if(pq.size() > k){
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size() > total){
            pq.pop();
        }
        return pq.top();
    }
};
