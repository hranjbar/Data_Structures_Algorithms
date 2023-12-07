'''
Serialization is converting a data structure or object into a sequence of 
bits so that it can be stored in a file or memory buffer, or transmitted 
across a network connection link to be reconstructed later in the same 
or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. 
There is no restriction on how your serialization/deserialization 
algorithm should work. You need to ensure that a binary search tree
can be serialized to a string, and this string can be deserialized
to the original tree structure.

The encoded string should be as compact as possible.
'''
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root: Optional[TreeNode]) -> str:
        """Encodes a tree to a single string.
        """
        if not root:
            return ""
        ser = str(root.val)
        if root.left:
            ser += "." + self.serialize(root.left)
        if root.right:
            ser += "." + self.serialize(root.right)
        return ser

    def deserialize(self, data: str) -> Optional[TreeNode]:
        """Decodes your encoded data to tree.
        """
        if not data:
            return None
        pre = data.split('.')
        root , i = TreeNode(int(pre[0])), 1
        while i < len(pre) and int(pre[i]) < int(pre[0]):
            i += 1
        root.left = self.deserialize(".".join(pre[1:i]))
        root.right = self.deserialize(".".join(pre[i:]))
        return root
        

# Your Codec object will be instantiated and called as such:
# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# tree = ser.serialize(root)
# ans = deser.deserialize(tree)
# return ans
