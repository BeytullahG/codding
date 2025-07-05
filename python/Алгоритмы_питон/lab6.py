import sys

graph = {
    1: [(2, 100), (3, 30)],
    2: [(4, 15), (5, 200)],
    3: [(4, 10), (5, 60)],
    4: [(5, 50), (2, 15)],  
    5: []
}

N = 5

def dijkstra(graph, start):
    dist = {i: float('inf') for i in range(1, N+1)}
    prev = {i: None for i in range(1, N+1)}  
    dist[start] = 0  

    visited = set()
    while len(visited) < N:
        min_node = None
        min_dist = float('inf')
        for node in range(1, N+1):
            if node not in visited and dist[node] < min_dist:
                min_dist = dist[node]
                min_node = node
        if min_node is None:
            break  

        visited.add(min_node)

       
        for neighbor, weight in graph[min_node]:
            if dist[neighbor] > dist[min_node] + weight:
                dist[neighbor] = dist[min_node] + weight
                prev[neighbor] = min_node

    return dist, prev




start = 1
dist, prev = dijkstra(graph, start)

print("Кратчайшие расстояния от узла 1:")
for node in range(1, N+1):
    print(f"До узла {node}: {dist[node]}")


