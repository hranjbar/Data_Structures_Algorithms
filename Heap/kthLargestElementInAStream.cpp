/*
Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Implement KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in the stream.
*/

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minq;
    priority_queue<int> maxq;
    KthLargest(int k, vector<int>& nums) {
        for (int n : nums) maxq.push(n);
        for (int i=0; i<k; i++) {
            if (!maxq.empty()){
                minq.push(maxq.top());
                maxq.pop();
            }
            else minq.push((0x1<<31)); // make sure minq has at least k elements
        }
    }
    
    int add(int val) {
        if (val > minq.top()){
            minq.push(val);
            minq.pop();
        }
        return minq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
