import sys
sys.setrecursionlimit(10**6)


class Node:
    def __init__(self, key, day, month, year, nSunspot) -> None:
        self.key = key
        self.left = None
        self.right = None
        self.height = 1
        self.day = day
        self.month = month
        self.year = year
        self.nSunspot = nSunspot

    def __repr__(self) -> str:
        data = f'Key: {self.key} --- '\
            f'{self.day}/{self.month}/{self.year} -> Spots: {self.nSunspot}'
        return data


class Avl:
    def __init__(self) -> None:
        self.node = None

    def insert(self, key, day, month, year, nSunspot):
        if not self.node:
            self.node = Node(key, day, month, year, nSunspot)
        else:
            self.node = self._insertNode(
                self.node, key, day, month, year, nSunspot
            )

    def _insertNode(self, node: Node, key, day, month, year, nSunspot) -> Node:
        if not node:
            return Node(key, day, month, year, nSunspot)
        elif key < node.key:
            node.left = self._insertNode(
                node.left, key, day, month, year, nSunspot
            )
        else:
            node.right = self._insertNode(
                node.right, key, day, month, year, nSunspot
            )

        node.height = 1 + max(
            self._height(node.left), self._height(node.right)
        )
        balance = self.balanceFactor(node)

        if balance > 1 and key < node.left.key:
            return self._rotationRight(node)
        if balance < -1 and key > node.right.key:
            return self._rotationLeft(node)
        if balance > 1 and key > node.left.key:
            node.left = self._rotationLeft(node.left)
            return self._rotationRight(node)
        if balance < -1 and key < node.right.key:
            node.right = self._rotationRight(node.right)
            return self._rotationLeft(node)

        return node

    def _height(self, node: Node) -> int:
        if not node:
            return 0
        return node.height

    def balanceFactor(self, node: Node) -> int:
        if not node:
            return 0
        return self._height(node.left) - self._height(node.right)

    def _rotationRight(self, nodeX: Node) -> Node:
        nodeY: Node = nodeX.left
        nodeZ: Node = nodeY.right

        nodeY.right = nodeX
        nodeX.left = nodeZ

        nodeX.height = 1 + max(
            self._height(nodeX.left), self._height(nodeX.right)
        )
        nodeY.height = 1 + max(
            self._height(nodeY.left), self._height(nodeY.right)
        )
        return nodeY

    def _rotationLeft(self, nodeX: Node) -> Node:
        nodeY: Node = nodeX.right
        nodeZ: Node = nodeY.left

        nodeY.left = nodeX
        nodeX.right = nodeZ

        nodeX.height = 1 + max(
            self._height(nodeX.left), self._height(nodeX.right)
        )
        nodeY.height = 1 + max(
            self._height(nodeY.left), self._height(nodeY.right)
        )
        return nodeY

    def inorderItertive(self):
        if self.node is None:
            return

        stack: list = []
        node: Node = self.node

        while True:
            if node is not None:
                stack.append(node)
                node = node.left

            elif stack:
                node = stack.pop()
                print(node)
                node = node.right

            else:
                break

    def preorderIterative(self) -> None:
        if self.node is None:
            return

        stack: list = []
        stack.append(self.node)

        while stack:
            node: Node = stack.pop()
            print(node)

            if node.right is not None:
                stack.append(node.right)
            if node.left is not None:
                stack.append(node.left)

    def searchKey(self, key) -> Node | None:
        currentNode = self.node

        while currentNode is not None:
            if key == currentNode.key:
                return currentNode
            elif key < currentNode.key:
                currentNode = currentNode.left
            else:
                currentNode = currentNode.right

    def inorderRecursive(self, node: Node) -> None:
        if node is not None:
            self.inorderRecursive(node.left)
            print(node)
            self.inorderRecursive(node.right)

    def searchRecursiveKey(self, node: Node, key: int) -> None:
        if node.key == key or node is None:
            return node
        elif key < node.key:
            return self.searchRecursiveKey(node.left, key)
        else:
            return self.searchRecursiveKey(node.right, key)

    def minimum(self) -> Node:
        currentNode: Node = self.node
        while currentNode.left is not None:
            currentNode = currentNode.left
        return currentNode

    def maximum(self) -> Node:
        currentNode: Node = self.node
        while currentNode.right is not None:
            currentNode = currentNode.right
        return currentNode

    # def sucessor(self)