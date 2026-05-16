class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<>> large;
    priority_queue<int> small;

    MedianFinder() {
        this->small;
        this->large;
    }
    
    void addNum(int num) {
        if (small.empty()) small.push(num);
        else if (small.top() >= num) small.push(num);
        else large.push(num);

        int s = small.size();
        int l = large.size();

        if (abs(s-l) > 1) {
            if (l>s) {small.push(large.top());large.pop();}
            else {large.push(small.top());small.pop();}
        }
    }
    
    double findMedian() {
        int med = small.top();
        if (small.size() < large.size()) med = large.top();
        if (small.size() == large.size()) return (double(small.top()) + double(large.top())) /2.0;
        return med;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */