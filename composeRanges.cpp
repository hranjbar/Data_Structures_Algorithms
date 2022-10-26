vector<string> solution(vector<int> nums) {
    if (nums.size()==0) return {};
    vector<string> ret;
    int st=0,end=0;
    int n=nums.size();
    for (int ix=1;ix<n;ix++){
        if (nums[ix]<(nums[end]+2)) end++;
        else {
            if (end>st) ret.push_back(to_string(nums[st])+"->"+to_string(nums[end]));
            else ret.push_back(to_string(nums[end]));
            st=end=ix;
        }
    }
    if (end>st) ret.push_back(to_string(nums[st])+"->"+to_string(nums[end]));
    else ret.push_back(to_string(nums[end]));
    return ret;
}
