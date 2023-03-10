/*
You have an unsorted array arr of non-negative integers and a number s. 
Find a longest contiguous subarray in arr that has a sum equal to s. 
Return two integers that represent its inclusive bounds. 
If there are several possible answers, return the one with the smallest left bound. 
If there are no answers, return [-1].
Your answer should be 1-based, meaning that the first position of the array is 1 instead of 0.
*/

vector<int> solution(int s, vector<int> arr) {
    int cum=0,l=0,r=0,L=-1,R=-2,N=arr.size();
    while(r<N){
        cum+=arr[r];
        if (cum==s){
            if(R-L<r-l){
                R=r;
                L=l;
            }
        }
        else if(cum>s){
            while(cum>s){
                cum-=arr[l];
                l++;
            }
            if (cum==s){
                if (R-L<r-l){
                    R=r;
                    L=l;
                }
            }
        }
        r++;
    }
    if (R>=0 && L>=0) return {L+1,R+1};
    else return {-1};
}
