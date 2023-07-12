class Node:
    def __init__(self, key=None, left=None, right=None) -> None:
        self.key = key
        self.left = left
        self.right = right
        self.height = 1

    def __repr__(self) -> str:
        n = f'{self.key and self.left}<-{self.key}->{self.key and self.right}'
        return n


class Avl:
    def __init__(self) -> None:
        self.root = None

    def insert(self, key):
        if not self.root:
            self.root = Node(key=key)
        else:
            self.root = self._insertNode(self.root, key)

    def _insertNode(self, node: Node, key):
        if not node:
            return Node(key=key)
        elif key < node.key:
            node.left = self._insertNode(node.left, key)
        else:
            node.right = self._insertNode(node.right, key)

nd = Node(key=8)
