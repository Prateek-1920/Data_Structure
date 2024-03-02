class Node:
    def __init__(self,key):
        self.right=None
        self.left = None
        self.val = key

class BST:
    def __init__(self):
        self.root = None

    def insert(self,root,key):
        if not root:
            return Node(key)
        else:
            if root.val<key:
                root.right = self.insert(root.right,key)
            else:
                root.left = self.insert(root.left,key)
        return root
    
    def preorder(self,node):
        if node!=None:
            print(node.val, end=' ')
            self.preorder(node.left)
            self.preorder(node.right)

if __name__=='__main__':
    bst =BST()
    x=0
    while x!=-1:
        x=int(input("1.insert 2.show"))
        if x==1:
            a=int(input("Enter element"))
            bst.root=bst.insert(bst.root,a)
        if x==2:
            bst.preorder(bst.root)
        