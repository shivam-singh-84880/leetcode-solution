class MedianFinder {
    priority_queue<int> lmaxpq;
    priority_queue<int,vector<int>,greater<int>> rminpq;
public:
    MedianFinder() {}
    
    void addNum(int num) {
        if(lmaxpq.empty() || lmaxpq.top() > num){
            lmaxpq.push(num);
        }
        else{
            rminpq.push(num);
        }
        
        if(rminpq.size() > lmaxpq.size()){
            lmaxpq.push(rminpq.top());
            rminpq.pop();
        }
        else if(lmaxpq.size() > rminpq.size() + 1){
            rminpq.push(lmaxpq.top());
            lmaxpq.pop();
        }

    }
    
    double findMedian() {
        if(lmaxpq.size() == rminpq.size()){
            return double((lmaxpq.top() + rminpq.top())/2.0);
        }
        else{
            return lmaxpq.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */