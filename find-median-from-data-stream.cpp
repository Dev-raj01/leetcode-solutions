//https://leetcode.com/problems/find-median-from-data-stream/submissions/1567057476/
//hard
//can be optimised




class MedianFinder {
    priority_queue<int, vector<int>, less<int>> smallHeap; 
    priority_queue<int, vector<int>, greater<int>> largeHeap;

public:
    MedianFinder() {}

    void addNum(int num) {
        smallHeap.push(num);
        if (!largeHeap.empty() && smallHeap.top() > largeHeap.top()) {
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        if (smallHeap.size() > largeHeap.size() + 1) {
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        if (largeHeap.size() > smallHeap.size() + 1) {
            smallHeap.push(largeHeap.top());
            largeHeap.pop();
        }
    }

    double findMedian() {
        if (smallHeap.size() == largeHeap.size()) {
            return (largeHeap.top() + smallHeap.top()) / 2.0;
        } else if (smallHeap.size() > largeHeap.size()) {
            return smallHeap.top();
        } else {
            return largeHeap.top();
        }
    }
};


//optimised 

class MedianFinder {
 public:
  void addNum(int num) {
    if (maxHeap.empty() || num <= maxHeap.top())
      maxHeap.push(num);
    else
      minHeap.push(num);
    if (maxHeap.size() < minHeap.size())
      maxHeap.push(minHeap.top()), minHeap.pop();
    else if (maxHeap.size() - minHeap.size() > 1)
      minHeap.push(maxHeap.top()), maxHeap.pop();
  }

  double findMedian() {
    if (maxHeap.size() == minHeap.size())
      return (maxHeap.top() + minHeap.top()) / 2.0;
    return maxHeap.top();
  }

 private:
  priority_queue<int> maxHeap;
  priority_queue<int, vector<int>, greater<>> minHeap;
};
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */