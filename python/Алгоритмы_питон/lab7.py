# Алгоритм Прима (нахождение минимального остовного дерева)
import heapq

def prim(graph):
    n = len(graph)
    key = [float('inf')] * n      
    parent = [-1] * n              
    in_mst = [False] * n            
    
    key[0] = 0
    heap = [(0, 0)]                
    
    while heap:
        weight, u = heapq.heappop(heap)
        if in_mst[u]:
            continue
        in_mst[u] = True
        
        for v, w in graph[u]:
            if not in_mst[v] and w < key[v]:
                key[v] = w
                parent[v] = u
                heapq.heappush(heap, (w, v))
    
    mst = []
    for v in range(1, n):
        mst.append((parent[v], v, key[v]))
    return mst

graph = [
    [(1, 10), (2, 6), (3, 5)],  
    [(0, 10), (3, 15)],          
    [(0, 6), (3, 4), (4,10)],           
    [(0, 5), (1, 15), (2, 4), (4,8)],   
    [(3, 8), (2, 10)]
]

mst = prim(graph)
print("Минимальное остовное дерево (родитель, вершина, вес):")
for edge in mst:
    print(edge)













# import heapq

# def prim(graph):
#     n = len(graph)
#     key = [float('inf')] * n       # Минимальные веса рёбер
#     parent = [-1] * n               # Родители вершин в MST
#     in_mst = [False] * n            # Вершины, уже в MST
    
#     # Начинаем с вершины 0
#     key[0] = 0
#     heap = [(0, 0)]                 # Куча: (key, вершина)
    
#     while heap:
#         weight, u = heapq.heappop(heap)
#         if in_mst[u]:
#             continue
#         in_mst[u] = True
        
#         # Обновляем ключи соседей
#         for v, w in graph[u]:
#             if not in_mst[v] and w < key[v]:
#                 key[v] = w
#                 parent[v] = u
#                 heapq.heappush(heap, (w, v))
    
#     # Формируем MST: (parent[v], v, вес)
#     mst = []
#     for v in range(1, n):
#         mst.append((parent[v], v, key[v]))
#     return mst

# # Пример графа (список смежности)
# graph = [
#     [(1, 10), (2, 6), (3, 5)],  # Вершина 0
#     [(0, 10), (3, 15)],          # Вершина 1
#     [(0, 6), (3, 4), (4,10)],            # Вершина 2
#     [(0, 5), (1, 15), (2, 4), (4,8)],   # Вершина 3
#     [(3, 8), (2, 10)]
# ]

# mst = prim(graph)
# print("Минимальное остовное дерево (родитель, вершина, вес):")
# for edge in mst:
#     print(edge)


