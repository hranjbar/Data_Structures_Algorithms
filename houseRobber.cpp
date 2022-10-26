// int helper(vector<int> & rest, int ix_st, const int & N){
//     if (ix_st>=N) return 0;
//     int a = rest[ix_st] + helper(rest, ix_st+2, N);
//     int b = helper(rest, ix_st+1, N);
//     return a>b?a:b;
// }
int solution(vector<int> nums) {
    // return helper(nums, 0, nums.size());     // recursive solution (not so fast!)
    int back=0,front=0;
    for (int g : nums){
        if (g+back>front) std::swap(back+=g,front);
        else back=front;
    }
    return front;
}
