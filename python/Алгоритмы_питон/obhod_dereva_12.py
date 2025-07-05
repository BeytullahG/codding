class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

def build_sample_tree():
    A = Node('A')
    B = Node('B')
    C = Node('C')
    D = Node('D')
    E = Node('E')
    F = Node('F')
    H = Node('H')
    I = Node('I')

    A.left = D
    A.right = B
    D.left = C
    D.right = E
    C.left = H
    C.right = F
    H.left = I

    return A

def preorder(node, result):  # прямой
    if node:
        result.append(node.key)
        preorder(node.left, result)
        preorder(node.right, result)

def inorder(node, result):  # симметричный
    if node:
        inorder(node.left, result)
        result.append(node.key)
        inorder(node.right, result)

def postorder(node, result):  # обратный
    if node:
        postorder(node.left, result)
        postorder(node.right, result)
        result.append(node.key)

if __name__ == "__main__":
    root = build_sample_tree()

    pre, ino, post = [], [], []

    preorder(root, pre)
    inorder(root, ino)
    postorder(root, post)

    print("Прямой обход (preorder):      ", ''.join(pre))
    print("Симметричный обход (inorder): ", ''.join(ino))
    print("Обратный обход (postorder):   ", ''.join(post))
















# def preorder(node, result):  # прямой
#     if node:
#         result.append(node.key)         # Сначала узел
#         preorder(node.left, result)     # потом левый
#         preorder(node.right, result)    # потом правый

# def inorder(node, result):  # симметричный
#     if node:
#         inorder(node.left, result)      # Сначала левый
#         result.append(node.key)         # потом узел
#         inorder(node.right, result)     # потом правый

# def postorder(node, result):  # обратный
#     if node:
#         postorder(node.left, result)    # Сначала левый
#         postorder(node.right, result)   # потом правый
#         result.append(node.key)         # потом узел
