/*
You have an unsorted array arr of non-negative integers and a number s. 
Find a longest contiguous subarray in arr that has a sum equal to s. 
Return two integers that represent its inclusive bounds. 
If there are several possible answers, return the one with the smallest 
left bound. 
If there are no answers, return [-1].
Your answer should be 1-based, meaning that the first position of the 
array is 1 instead of 0.

Examples
For s = 12 and arr = [1, 2, 3, 7, 5], the output should be
solution(s, arr) = [2, 4].
The sum of elements from the 2nd position to the 4th position (1-based) 
is equal to 12: 2 + 3 + 7.

For s = 15 and arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], the output should be
solution(s, arr) = [1, 5].
The sum of elements from the 1st position to the 5th position (1-based) 
is equal to 15: 1 + 2 + 3 + 4 + 5.

For s = 15 and arr = [1, 2, 3, 4, 5, 0, 0, 0, 6, 7, 8, 9, 10], the output 
should be solution(s, arr) = [1, 8].
The sum of elements from the 1st position to the 8th position (1-based) 
is equal to 15: 1 + 2 + 3 + 4 + 5 + 0 + 0 + 0.

Input/Output
[execution time limit] 0.5 seconds (cpp)
[memory limit] 1 GB
[input] integer s
The sum of the subarray that you are searching for.
Guaranteed constraints:
0 ≤ s ≤ 109.
[input] array.integer arr
The given array.
Guaranteed constraints:
1 ≤ arr.length ≤ 105,
0 ≤ arr[i] ≤ 104.
[output] array.integer
An array that contains two elements that represent the left and 
right bounds of the subarray, respectively (1-based). 
If there is no such subarray, return [-1].
*/

// 1 - two-pointer solution
vector<int> solution(int s, vector<int> arr) {
    int cum = 0, l = 0, r = 0, L = -1, R = -2;
    for (int r = 0; r < arr.size(); r++){
        cum += arr[r];
        if (cum == s && (R-L < r-l)) {R = r; L = l;}
        else if (cum > s) {
            while(cum > s) cum -= arr[l++];
            if (cum == s && (R-L < r-l)) { R = r; L = l;}
        }
    }
    if (R >= 0 && L >= 0) return {L + 1, R + 1};
    else return {-1};
}

// 2 - alternative solution using hash-map, thus extra space
vector<int> solution(int s, vector<int> arr) {
    unordered_map<int, int> hmap;
    hmap[0] = -1;
    int l = -1, r = -2, cur_sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        cur_sum += arr[i];
        if (hmap.count(cur_sum-s) > 0) {
            if ((i-hmap[cur_sum-s]) > (r-l+1)) {
                l = hmap[cur_sum-s] + 1;
                r = i;
            }
        }
        if (hmap.count(cur_sum) == 0) hmap[cur_sum] = i;
    }
    if ((r-l+1) > 0) return {l + 1, r + 1};
    else return {-1};
}
