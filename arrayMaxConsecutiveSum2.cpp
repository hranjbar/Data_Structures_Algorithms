/*Given an array of integers, find the maximum possible sum you can get from one of its contiguous subarrays. 
The subarray from which this sum comes must contain at least 1 element.*/

int solution(vector<int> inputArray) {
    int cum=0,max=INT_MIN;
    for (auto x:inputArray){
        cum+=x;
        cum = cum>x?cum:x;
        max=cum>max?cum:max;
    }
    return max;
}
