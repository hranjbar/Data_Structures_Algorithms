class Solution {
public:
    int partition(vector<int> & A, int l, int h){
        int i = l, j = h;
        int pivot = A[l];
        while (i < j){
            do {i++;} while (i < h && A[i] <= pivot);
            do {j--;} while (j > l && A[j] > pivot);
            if (i < j) swap(A[i], A[j]);
        }
        swap(A[j], A[l]);
        return j;
    }
    void quickSort(vector<int> & A, int l, int h){
        if (l < h){
            int j = partition(A, l, h);
            quickSort(A, l, j);
            quickSort(A, j+1, h);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size());
        return nums;
    }
};
