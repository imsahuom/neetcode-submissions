class MedianFinder {
    priority_queue<int> mini;// a max-heap
    priority_queue<int, vector<int>, greater<int>> maxi; // a min-heap
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (mini.empty()) mini.push(num);
        else if (maxi.size() == mini.size()){
            if (maxi.top() >= num) mini.push(num);
            else{
                mini.push(maxi.top());
                maxi.pop();
                maxi.push(num);
            }
        }else{
            if (mini.top() >= num){
                //num goes to mini
                maxi.push(mini.top());
                mini.pop();
                mini.push(num);
            }else{
                maxi.push(num);
            }
        }
    }
    
    double findMedian() {
        if (mini.size() == maxi.size()){
            return (mini.top() + maxi.top())/2.0;
        }else{
            return mini.top();
        }
    }
};
