# Trees

Binary search tree has two children for each node.
The root is greater than or equal to the left child nodes,
and is less than the right nodes.

A Tree is:
- empty, or
- a node with:
    - a key, and
    - a list of child trees.

Node contains:
- key
- children: list of children nodes
- (optional) parent

For binary tree: node contains:
- key
- letf
- right
- (optional) parent

Height(tree)
if tree = nil:
    return 0
return 1 + Max(Height(tree.left), Height(tree.right))

Size(tree)
if tree = nil;
    return 0
return 1 + Size(tree.left) + Size(tree.right)

## Tree Traversal

Often we want to visit the nodes of a tree in a
particular order.
- Depth-first: we completely traverse one sub-tree before
exploring a sibling sub-tree.
- Breadth-first: we traverse all nodes at one level before
progressing to the next level.

### Depth-first

// To be used with a binary search tree
InOrderTravesal(tree)
if tree = nill:
    return
InOrderTraversal(tree.left)
print(key)
InOrderTraversal(tree.right)

PreOrderTraversal(tree)
if tree = nil:
    return
print(tree.key)
PreOrderTraversal(tree.left)
PreOrderTraversal(tree.right)

PostOrderTraversal(tree)
if tree = nil:
    return
PostOrderTraversal(tree.left)
PostOrderTraversal(tree.right)
print(tree.key)

### Breadth-first

LevelTraversal(tree)
if tree = nil:
    return
Queue q
q.Enqueue(tree)
while not q.Empty():
    node <- q.Dequeue()
    print(node)
    if node.left != nil:
        q.Enqueue(node.left)
    if node.right != nil:
        q.Enqueue(node.right)

