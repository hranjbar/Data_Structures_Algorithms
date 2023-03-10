/*
You have an array of integers nums and an array queries,
where queries[i] is a pair of indices (0-based). 
Find the sum of the elements in nums from the indices at queries[i][0] to queries[i][1] (inclusive) for each query, 
then add all of the sums for all the queries together. Return that number modulo 109 + 7.
*/

const int limit=7+1e9;
int solution(vector<int> nums, vector<vector<int>> queries) {
    int sum=0;
    std::vector<int> accum(nums.size(),0);
    for (int i=0;i<nums.size();i++){
        sum+=nums[i];
        accum[i]=sum;
    }
    sum=0;
    for (vector<int> & q : queries){
        if(q[0]==0) sum+=accum[q[1]];
        else {
            sum+= accum[q[1]]-accum[q[0]-1];
        }
        if(sum<0) sum+=limit;
        else if (sum>limit) sum=sum%limit;
    }
    return sum;
}
