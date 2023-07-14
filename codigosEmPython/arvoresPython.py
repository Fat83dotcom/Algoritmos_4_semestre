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
        data = f'{self.day}/{self.month}/{self.year} -> Spots: {self.nSunspot}'
        return data


class Avl:
    def __init__(self) -> None:
        self.root = None

    def insert(self, key, day, month, year, nSunspot):
        if not self.root:
            self.root = Node(key, day, month, year, nSunspot)
        else:
            self.root = self._insertNode(
                self.root, key, day, month, year, nSunspot
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

    def _rotationRight(self, nodeZ: Node) -> Node:
        nodeY: Node = nodeZ.left
        nodeT3: Node = nodeY.right

        nodeY.right = nodeZ
        nodeZ.left = nodeT3

        nodeZ.height = 1 + max(
            self._height(nodeZ.left), self._height(nodeZ.right)
        )
        nodeY.height = 1 + max(
            self._height(nodeY.left), self._height(nodeY.right)
        )
        return nodeY

    def _rotationLeft(self, nodeZ: Node) -> Node:
        nodeY: Node = nodeZ.right
        nodeT2: Node = nodeY.left

        nodeY.left = nodeZ
        nodeZ.right = nodeT2

        nodeZ.height = 1 + max(
            self._height(nodeZ.left), self._height(nodeZ.right)
        )
        nodeY.height = 1 + max(
            self._height(nodeY.left), self._height(nodeY.right)
        )
        return nodeY

    def inorder(self):
        if self.root is None:
            return

        stack = []
        current = self.root

        while True:
            if current is not None:
                stack.append(current)
                current = current.left

            elif stack:
                current = stack.pop()
                print(current)
                current = current.right

            else:
                break


class ExecuteMain:
    def __init__(self, path: str) -> None:
        self.path = path

    def run(self) -> None:
        try:
            dataTree = Avl()
            with open(self.path, 'r', encoding='utf-8') as file:
                for n, x in enumerate(file.readlines()):
                    if int(x[21:24]) >= 0:
                        dataTree.insert(
                            n,
                            year=int(x[:4].strip()),
                            month=int(x[5:8].strip()),
                            day=int(x[8:10].strip()),
                            nSunspot=int(x[21:24].strip())
                        )
            dataTree.inorder()
        except Exception as e:
            print(e)


if __name__ == '__main__':
    _exec = ExecuteMain('SN_d_tot_V2.0.txt')
    _exec.run()
