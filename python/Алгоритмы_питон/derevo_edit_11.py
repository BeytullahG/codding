import turtle

class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

class BinarySearchTree:
    def __init__(self):
        self.root = None

    def insert(self, key):
        new_node = Node(key)
        if self.root is None:
            self.root = new_node
            return
        current = self.root
        while True:
            if key < current.key:
                if current.left is None:
                    current.left = new_node
                    return
                current = current.left
            elif key > current.key:
                if current.right is None:
                    current.right = new_node
                    return
                current = current.right
            else:
                return

    def delete(self, key):
        self.root = self._delete_recursive(self.root, key)

    def _delete_recursive(self, node, key):
        if node is None:
            return node
        if key < node.key:
            node.left = self._delete_recursive(node.left, key)
        elif key > node.key:
            node.right = self._delete_recursive(node.right, key)
        else:
            if node.left is None:
                return node.right
            elif node.right is None:
                return node.left
            temp_node = node.right
            while temp_node.left is not None:
                temp_node = temp_node.left
            node.key = temp_node.key
            node.right = self._delete_recursive(node.right, temp_node.key)
        return node

    def draw_tree(self):
        turtle.clearscreen()
        turtle.speed(0)
        turtle.hideturtle()
        turtle.title("BST Visualization")
        self._draw_node(self.root, 0, 200, 100)
        turtle.exitonclick()  # Ждём клик мышкой и закрываем окно

    def _draw_node(self, node, x, y, dx):
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
                self._draw_node(node.left, x - dx, y - 80, dx / 2)
            if node.right:
                turtle.penup()
                turtle.goto(x + 10, y - 10)
                turtle.pendown()
                turtle.goto(x + dx - 10, y - 60)
                self._draw_node(node.right, x + dx, y - 80, dx / 2)

if __name__ == "__main__":
    elements_to_insert = [50, 35, 65, 5, 40, 60, 80, 45, 1, 48, 75, 100]

    # # ============ a) После добавления всех узлов ============
    # bst = BinarySearchTree()
    # for el in elements_to_insert:
    #     bst.insert(el)
    # print("a) После добавления всех узлов:")
    # bst.draw_tree()

    # ============ b) После удаления 5 и 35 ============
    # bst = BinarySearchTree()
    # for el in elements_to_insert:
    #     bst.insert(el)
    # bst.delete(5)
    # bst.delete(35)
    # print("b) После удаления 5 и 35:")
    # bst.draw_tree()

    # ============ c) После удаления 45 ============
    # bst = BinarySearchTree()
    # for el in elements_to_insert:
    #     bst.insert(el)
    # bst.delete(5)
    # bst.delete(35)
    # bst.delete(45)
    # print("c) После удаления 45:")
    # bst.draw_tree()

    # ============ d) После удаления 50 ============
    # bst = BinarySearchTree()
    # for el in elements_to_insert:
    #     bst.insert(el)
    # bst.delete(5)
    # bst.delete(35)
    # bst.delete(45)
    # bst.delete(50)
    # print("d) После удаления 50:")
    # bst.draw_tree()
