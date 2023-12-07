'''
Given an array of integers preorder, which represents the preorder
traversal of a BST (i.e., binary search tree), construct the 
tree and return its root.

It is guaranteed that there is always possible to find a binary 
search tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any 
descendant of Node.left has a value strictly less than Node.val,
and any descendant of Node.right has a value strictly greater 
than Node.val.

A preorder traversal of a binary tree displays the value of the
node first, then traverses Node.left, then traverses Node.right.
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> Optional[TreeNode]:
        if len(preorder)==0:
            return None
        root = TreeNode(preorder[0])
        i=1
        while i<len(preorder) and preorder[i]<preorder[0]:
            i += 1
        root.left = self.bstFromPreorder(preorder[1:i])
        root.right = self.bstFromPreorder(preorder[i:])
        return root
