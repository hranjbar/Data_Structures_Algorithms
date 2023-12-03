/*
You are the head zookeeper at a large zoo. You've been contacted by schools in the area that 
want to bring in classes so that students can feed the animals. The animals can only be fed
once a day, so no two classes can come on the same day if they want to feed the same animals.

You have a list classes, such that classes[i] is a list of animals that the ith class wants 
to feed. Classes i and j cannot come on the same day if an animal in classes[i] also appears 
in classes[j] (for i ≠ j). Your job is to determine the minimum number of days you would
need to have all the classes come to feed the animals if they can all come within 5 days.
If it isn't possible for all the classes to come within 5 days, return -1 instead.

Example

For classes = [["Tiger", "Lima", "Frog"], ["Tiger", "Zebra","Lion"], ["Tiger", "Rabbit"],
["Emu", "Zebra", "Rabbit"]], the output should be
solution(classes) = 3.
Classes 0, 1, and 2 all want to feed the Tiger, so they have to come on different days. 
Class 3 cannot come on the same day as class 1 (because of the Zebra) or class 2 
(because of the Rabbit), but they can come on the same day as class 0. Therefore it only takes 3 days for all the classes to visit the zoo.

For classes = [["Tiger", "Lima", "Frog"], ["Tiger", "Zebra", "Lion"],
["Tiger", "Rabbit"], ["Lima", "Zebra", "Rabbit"]], the output should be
solution(classes) = 4.
Each class has to come on a separate day, because every pair of classes
has at least one animal in common.

For classes = [["Lion", "Emu"], ["Giraffe", "Peacock"], ["Lima"], 
["Tiger", "Cheetah", "Slugs"], ["Snakes", "Sealion"]], the output should be
solution(classes) = 1.
No classes have animals in common, so they can all come on the same day.
*/

bool canSchedule(int i, int day, vector<int>& cal, vector<vector<int>>& g)
{
    for (int j=0; j<g.size(); j++) {
        if (g[i][j]==1 && cal[j]==day) return false;
    }
    return true;
}
bool bt(int i, int days, vector<int>& cal, vector<vector<int>>& g)
{
    if (i==g.size()) return true;
    for (int d=1; d<=days; d++) {
        if (canSchedule(i, d, cal, g)) {
            cal[i]=d;
            if (bt(i+1, days, cal, g)) return true;
            cal[i]=0;   // reset schedule for class[i]
        }
    }
    return false;
}
int solution(vector<vector<string>> classes) {
    int n = classes.size();
    vector<unordered_set<string>> cl_sets(n);
    for (int i=0; i<n; i++) {
        for (string ani : classes[i]) cl_sets[i].insert(ani);
    }
    
    vector<vector<int>> g(n, vector<int>(n));
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++){
            for (string ani : classes[i]) {
                if (cl_sets[j].count(ani)) { 
                    g[i][j]=1;
                    g[j][i]=1;  // class [i] adjacent to class[j]
                    break;
                }
            }
        }
    }
    vector<int> calendar(n);
    for (int d=1; d<=5; d++) {
        if (bt(0, d, calendar, g)) return d;
    }
    return -1;
}

// color graph problem
/*
The solution is based on finding minimum number colors required to color nodes of a graph
given that no adjacent nodes have the same color. In the above problem, nodes are classes
and two classes are adjacent if they have an animal in common. Accordingly, coloring a node
with a certain color is equivalent to schedule a class on a certain day.
*/
