'''
You are given a 2D integer array descriptions where 
descriptions[i] = [parenti, childi, isLefti] indicates 
that parenti is the parent of childi in a binary tree 
of unique values. Furthermore,

If isLefti == 1, then childi is the left child of parenti.
If isLefti == 0, then childi is the right child of parenti.
Construct the binary tree described by descriptions 
and return its root.

The test cases will be generated such that the binary 
tree is valid.

Example 1:
Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
Output: [50,20,80,15,17,19]
Explanation: The root node is the node with value 50 since it has no parent.
The resulting binary tree is shown in the diagram.

Example 2:
Input: descriptions = [[1,2,1],[2,3,0],[3,4,1]]
Output: [1,2,null,null,3,4]
Explanation: The root node is the node with value 1 since it has no parent.
The resulting binary tree is shown in the diagram.

Constraints:
1 <= descriptions.length <= 104
descriptions[i].length == 3
1 <= parenti, childi <= 105
0 <= isLefti <= 1
The binary tree described by descriptions is valid.
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        children = {n:p for p,n,_ in descriptions}
        # hash-map (child,parent)
        parents = {p:[0,0] for p,_,_ in descriptions}
        # find root: only node that's a parent but not a child
        for p,_ in parents.items():
            if not p in children:
                root = p
                break
        for des in descriptions:
            if des[2]==1:   # left child
                parents[des[0]][0]=des[1]
            else:           # right child
                parents[des[0]][1]=des[1]
        def dfs(val):
            if not val: # not a node
                return None
            if not val in parents:  # leaf node
                return TreeNode(val)
            return TreeNode(val, dfs(parents[val][0]), dfs(parents[val][1]))
        return dfs(root)
