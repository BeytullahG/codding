import random
import turtle

class AVLNode:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
        self.height = 1

class AVLTree:
    def __init__(self):
        self.root = None

    def insert(self, key):
        self.root = self._insert(self.root, key)

    def _insert(self, node, key):
        if not node:
            return AVLNode(key)
        elif key < node.key:
            node.left = self._insert(node.left, key)
        else:
            node.right = self._insert(node.right, key)

        node.height = 1 + max(self._get_height(node.left), self._get_height(node.right))
        balance = self._get_balance(node)

        # Малый правый поворот (Left-Left)
        if balance > 1 and key < node.left.key:
            return self._right_rotate(node)

        # Малый левый поворот (Right-Right)
        if balance < -1 and key > node.right.key:
            return self._left_rotate(node)

        # Большой правый поворот (Left-Right)
        if balance > 1 and key > node.left.key:
            node.left = self._left_rotate(node.left)
            return self._right_rotate(node)

        # Большой левый поворот (Right-Left)
        if balance < -1 and key < node.right.key:
            node.right = self._right_rotate(node.right)
            return self._left_rotate(node)

        return node

    def _left_rotate(self, z):
        y = z.right
        T2 = y.left

        y.left = z
        z.right = T2

        z.height = 1 + max(self._get_height(z.left), self._get_height(z.right))
        y.height = 1 + max(self._get_height(y.left), self._get_height(y.right))

        return y

    def _right_rotate(self, z):
        y = z.left
        T3 = y.right

        y.right = z
        z.left = T3

        z.height = 1 + max(self._get_height(z.left), self._get_height(z.right))
        y.height = 1 + max(self._get_height(y.left), self._get_height(y.right))

        return y

    def _get_height(self, node):
        if not node:
            return 0
        return node.height

    def _get_balance(self, node):
        if not node:
            return 0
        return self._get_height(node.left) - self._get_height(node.right)

    def inorder(self):
        self._inorder(self.root)
        print()

    def _inorder(self, node):
        if node:
            self._inorder(node.left)
            print(node.key, end=" ")
            self._inorder(node.right)

def draw_tree(tree):
    def _draw_node(node, x, y, dx):
        if node:
            turtle.penup()
            turtle.goto(x, y)
            turtle.pendown()
            turtle.circle(20)
            turtle.penup()
            turtle.goto(x, y + 10)
            turtle.write(str(node.key), align="center", font=("Arial", 12, "normal"))

            if node.left:
                turtle.penup()
                turtle.goto(x - 10, y - 10)
                turtle.pendown()
                turtle.goto(x - dx + 10, y - 60)
                _draw_node(node.left, x - dx, y - 80, dx / 2)

            if node.right:
                turtle.penup()
                turtle.goto(x + 10, y - 10)
                turtle.pendown()
                turtle.goto(x + dx - 10, y - 60)
                _draw_node(node.right, x + dx, y - 80, dx / 2)

    turtle.speed(0)
    turtle.hideturtle()
    turtle.title("AVL Tree Visualization")
    _draw_node(tree.root, 0, 200, 100)
    turtle.done()

if __name__ == "__main__":
    avl = AVLTree()
    keys = [50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45, 55, 65, 75, 85]


    for key in keys:
        avl.insert(key)

    print("Inorder traversal:")
    avl.inorder()

    draw_tree(avl)
