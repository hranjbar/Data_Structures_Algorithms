constexpr int limit = 1'000'000'000 + 7;
int helper(string & message, int ix, vector<int> & memo){
    if (ix == message.size()) return 1;
    if (memo[ix] > 0) return memo[ix];
    int count = 0;
    if (message[ix] != '0'){
        count = helper(message, ix + 1, memo);
        if (ix < message.size()-1){
            string twoDigit = string()+ message[ix]+message[ix+1];
            if (stoi(twoDigit)<=26) count = (count + helper(message, ix+2, memo))%limit;
        }
    }
    memo[ix]=count;
    return count;
}
int solution(string message) {
    vector<int> memo(message.size(),0);
    return helper(message, 0, memo);
}
