class MedianFinder {
public:
priority_queue<int,vector<int>,greater<int>>minHeap;
priority_queue<int>maxHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.size() == 0 and minHeap.size() == 0)
        maxHeap.push(num);
        else if(num > maxHeap.top())
        minHeap.push(num);
        else
        maxHeap.push(num);

        if (maxHeap.size() > minHeap.size() + 1) {
			minHeap.push(maxHeap.top());
			maxHeap.pop();
		} else if (minHeap.size() > maxHeap.size() + 1) {
			maxHeap.push(minHeap.top());
			minHeap.pop();
		}

    }
    
    double findMedian() {
        if(minHeap.size() == maxHeap.size()){
            return (minHeap.top()+maxHeap.top())/2.0;
        }
        
        else if(minHeap.size() > maxHeap.size())
        return minHeap.top();
        else
        return maxHeap.top();        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */