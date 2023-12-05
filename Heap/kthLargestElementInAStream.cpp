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
        int n=nums.size();
        for (int i=0; i<n; i++) add(nums[i]);
    }
    
    int add(int val) {
        if (minHeap.size() < k_) minHeap.push(val);
        else if (val > minHeap.top()) {
            minHeap.pop();
            minHeap.push(val);
        }
        return minHeap.top();
    }
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k_;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
