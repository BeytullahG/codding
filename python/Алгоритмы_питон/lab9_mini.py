import random
import math

N = 10
cities = []
for i in range(N):
    x = random.randint(0, 100)
    y = random.randint(0, 100)
    cities.append((x, y))

print("Координаты городов:")
for i, (x, y) in enumerate(cities):
    print(f"Город {i}: ({x}, {y})")

def distance(a, b):
    return math.sqrt((a[0] - b[0])**2 + (a[1] - b[1])**2)

dist_matrix = []
for i in range(N):
    row = []
    for j in range(N):
        row.append(distance(cities[i], cities[j]))
    dist_matrix.append(row)

print("\nМатрица расстояний:")
for row in dist_matrix:
    print(["{:.1f}".format(d) for d in row])

start_city = 0
visited = [False] * N
route = [start_city]
visited[start_city] = True
current_city = start_city

for _ in range(N - 1):
    nearest_city = None
    nearest_dist = float('inf')
    for city in range(N):
        if not visited[city] and dist_matrix[current_city][city] < nearest_dist:
            nearest_city = city
            nearest_dist = dist_matrix[current_city][city]
    route.append(nearest_city)
    visited[nearest_city] = True
    current_city = nearest_city

route.append(start_city)

print("\nМаршрут обхода городов (по номерам):")
print(route)

total_length = 0
for i in range(len(route) - 1):
    total_length += dist_matrix[route[i]][route[i+1]]
print("\nДлина маршрута: {:.2f}".format(total_length))
