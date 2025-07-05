# Лаба 9 (дерево)

class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

class BinarySearchTree:  # Дерево поиска
    def __init__(self):
        self.root = None

    # Вспомогательная функция для поиска узла (поиск по дереву)
    def _search_node(self, node, key):
        if node is None or node.key == key:
            return node
        if key < node.key:
            return self._search_node(node.left, key)
        else:
            return self._search_node(node.right, key)

    # 1. Поиск элемента по ключу
    def search_key(self, key):
        node = self._search_node(self.root, key)
        return node.key if node else None

    # 2. Минимальный элемент
    def find_min(self):
        """
        Находит минимальный элемент в BST.
        """
        if self.root is None:
            return None
        node = self.root
        while node.left is not None:
            node = node.left
        return node.key

    # 3. Максимальный элемент
    def find_max(self):
        """
        Находит максимальный элемент в BST.
        """
        if self.root is None:
            return None
        node = self.root
        while node.right is not None:
            node = node.right
        return node.key

    # 4. Поиск предшественника (предыдущего по значению)
    def find_predecessor(self, key):
        """
        Находит предшественника для заданного ключа в BST.
        """
        node_found = self._search_node(self.root, key)
        if node_found is None:
            return None  # Элемент не найден

        # Если есть левый потомок, предшественник - максимум в левом поддереве
        if node_found.left:
            current = node_found.left
            while current.right:
                current = current.right
            return current.key
        # Иначе ищем среди предков
        else:
            predecessor = None
            current = self.root
            while current:
                if key > current.key:
                    predecessor = current.key
                    current = current.right
                elif key < current.key:
                    current = current.left
                else:  # Нашли узел
                    break
            return predecessor

    # 5. Поиск преемника (следующего по значению)
    def find_successor(self, key):
        """
        Находит преемника для заданного ключа в BST.
        """
        node_found = self._search_node(self.root, key)
        if node_found is None:
            return None  # Элемент не найден

        # Если есть правый потомок, преемник - минимум в правом поддереве
        if node_found.right:
            current = node_found.right
            while current.left:
                current = current.left
            return current.key
        # Иначе ищем среди предков
        else:
            successor = None
            current = self.root
            while current:
                if key < current.key:
                    successor = current.key
                    current = current.left
                elif key > current.key:
                    current = current.right
                else:  # Нашли узел
                    break
            return successor

    # 6. Вставка элемента
    def insert(self, key):
        """
        Вставляет новый элемент в BST.
        """
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
            else:  # Ключ уже существует
                return

    # 7. Удаление элемента
    def delete(self, key):
        """
        Удаляет элемент из BST.
        """
        self.root = self._delete_recursive(self.root, key)

    def _delete_recursive(self, node, key):
        if node is None:
            return node

        if key < node.key:
            node.left = self._delete_recursive(node.left, key)
        elif key > node.key:
            node.right = self._delete_recursive(node.right, key)
        else:
            # Узел с одним потомком или без потомков
            if node.left is None:
                return node.right
            elif node.right is None:
                return node.left

            # Узел с двумя потомками: берём инфиксного преемника
            temp_node = node.right
            while temp_node.left is not None:
                temp_node = temp_node.left

            node.key = temp_node.key
            node.right = self._delete_recursive(node.right, temp_node.key)
        return node

    # Инфиксный обход (для печати дерева)
    def inorder_traversal(self):
        elements = []
        self._inorder_recursive(self.root, elements)
        return elements

    def _inorder_recursive(self, node, elements):
        if node:
            self._inorder_recursive(node.left, elements)
            elements.append(node.key)
            self._inorder_recursive(node.right, elements)


# --- Пример использования ---
if __name__ == "__main__":
    bst = BinarySearchTree()
    elements_to_insert = [50, 30, 70, 20, 40, 60, 80, 25, 35, 75, 85]

    for el in elements_to_insert:
        bst.insert(el)

    print("Инфиксный обход BST:", bst.inorder_traversal())
    print("Минимальный элемент:", bst.find_min())
    print("Максимальный элемент:", bst.find_max())

    key_for_ps = 50
    print(f"Предшественник {key_for_ps}: {bst.find_predecessor(key_for_ps)}")
    print(f"Преемник {key_for_ps}: {bst.find_successor(key_for_ps)}")

    print("BST до удаления:", bst.inorder_traversal())

    key_to_delete = 20  # Листовой узел
    print(f"Удаляем {key_to_delete}...")
    bst.delete(key_to_delete)
    print("BST после удаления:", bst.inorder_traversal())

    key_to_delete = 70  # Узел с двумя потомками
    print(f"Удаляем {key_to_delete}...")
    bst.delete(key_to_delete)
    print("BST после удаления:", bst.inorder_traversal())

    key_to_delete = 30  # Узел с одним потомком
    print(f"Удаляем {key_to_delete}...")
    bst.delete(key_to_delete)
    print("BST после удаления:", bst.inorder_traversal())
