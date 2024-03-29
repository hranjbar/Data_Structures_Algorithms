/*
Given an array of integers a, return a new array b using the following guidelines:

For each index i in b, the value of bi is the index of 
the aj nearest to ai and is also greater than ai.
If there are two options for bi, put the leftmost one in bi.
If there are no options for bi, put -1 in bi.
Example

For a = [1, 4, 2, 1, 7, 6], the output should be
solution(a) = [1, 4, 1, 2, -1, 4].

for a[0], the nearest larger element is 4 at index a[1] -> b[0] contains the value 1.
for a[1], the nearest larger element is 7 at a[4] -> b[1] contains the value 4.
for a[2], the nearest larger element is 4 at a[1] (7 is also larger, 
but 4 has the minimal position) -> b[2] contains the value 1.
for a[3], the nearest larger element is 2 at a[2] (7 is also larger, 
but 2 has the minimal position) -> b[3] contains the value 2.
for a[4], there is no element larger than 7 -> b[4] contains the value -1.
for a[5], the nearest larger element is 7 at a[4] -> b[5] contains the value 4.
*/

vector<int> solution(vector<int> a) {
    stack<int> s;
    vector<int> b(a.size(), -1);
    for (int i=0; i<a.size(); i++) {
        while (!s.empty() && a[s.top()] < a[i]) {
            int j = s.top();
            s.pop();
            if (b[j]==-1 || i-j < j-b[j]) b[j]=i;
        }
        if (!s.empty()) {
            if (a[s.top()] > a[i]) b[i] = s.top();
            else b[i] = b[s.top()];
        }
        s.push(i);
    }
    return b;
}
