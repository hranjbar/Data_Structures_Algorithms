/*
There are n friends that are playing a game. The friends are sitting in a circle and are numbered from 1 to n in clockwise order. More formally, moving clockwise from the ith friend brings you to the (i+1)th friend for 1 <= i < n, and moving clockwise from the nth friend brings you to the 1st friend.

The rules of the game are as follows:

Start at the 1st friend.
Count the next k friends in the clockwise direction including the friend you started at. The counting wraps around the circle and may count some friends more than once.
The last friend you counted leaves the circle and loses the game.
If there is still more than one friend in the circle, go back to step 2 starting from the friend immediately clockwise of the friend who just lost and repeat.
Else, the last friend in the circle wins the game.
Given the number of friends, n, and an integer k, return the winner of the game.
*/

class Solution {
public:
    struct Node {
        int val;
        Node * next;
        Node() {val=0; next=nullptr;}
        Node(int v) {val=v; next=nullptr;}
    };
    Node * makeTable(int n){
        Node * dummy = new Node();
        Node * node = dummy;
        for (int i=0; i<n; i++, node=node->next) node->next = new Node(i+1);
        node->next = dummy->next; // make circular
        return dummy;
    }
    int findTheWinner(int n, int k) {
        Node * player = makeTable(n);
        int left = n;
        while (left > 1){
            for (int i=0; i<k-1; i++) player = player->next;
            player->next = player->next->next;
            left--;
        }
        return player->next->val;
    }
};
