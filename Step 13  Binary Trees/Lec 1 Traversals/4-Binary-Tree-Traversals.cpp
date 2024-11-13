/*


Binary Tree Traversal : Inorder Preorder Postorder



Traversals in hierarchical data structures like Binary Trees can be broadly classified into two categories: Depth-First Search (DFS) and Breadth-First Search (BFS). Each of them utilises a different strategy to visit the nodes within the tree.


Depth-First Search (DFS) 

Breadth-First Search (BFS) 



        Inorder Traversal is the type of Depth First Traversal where nodes are visited in the order: Left, Root, Right.

        Preorder Traversal is the type of Depth First Traversal where nodes are visited in the order: Root, Left then Right.

        Postorder Traversal is the type of Depth First Traversal where nodes are visited in the order: Left, Right then Root.



Procedure of Level Order Traversal:

Visit Nodes at Each Level: Starting from the root node, visit all nodes at level 0.
Move to Next Level: After visiting all nodes at level 0, move to level 1 and visit all nodes at this level from left to right.
Continue Level-wise: Repeat this process for subsequent levels, visiting nodes at each level from left to right until all levels are visited.



*/