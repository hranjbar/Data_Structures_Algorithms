/*
Design a class to find the kth largest element in a stream. 
Note that it is the kth largest element in the sorted order
, not the kth distinct element.

Implement KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with 
the integer k and the stream of integers nums.
int add(int val) Appends the integer val to the stream and
returns the element representing the kth largest element 
in the stream.
*/

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : k_(k){
        for (int& num : nums) add(num);
    }
    int add(int val) {
        minHeap_.push(val);
        if (minHeap_.size() > k_) minHeap_.pop();
        return minHeap_.top();
    }
private:
    priority_queue<int, vector<int>, greater<int>> minHeap_;
    size_t k_;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
