import random
import math
import matplotlib.pyplot as plt  # Для визуализации маршрута (это единственное, что придется поставить)

# 1. Генерируем случайные координаты для 10 городов
N = 10  # количество городов
cities = []
for i in range(N):
    x = random.randint(0, 100)
    y = random.randint(0, 100)
    cities.append((x, y))

print("Координаты городов:")
for i, (x, y) in enumerate(cities):
    print(f"Город {i}: ({x}, {y})")

# 2. Строим матрицу расстояний
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

# 3. Жадный алгоритм
start_city = 0  # начнем с города 0 (можно выбрать любой)
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

# Возвращаемся в начальный город
route.append(start_city)

print("\nМаршрут обхода городов (по номерам):")
print(route)

# 4. Визуализируем маршрут
x_coords = [cities[i][0] for i in route]
y_coords = [cities[i][1] for i in route]

plt.figure(figsize=(8, 6))
plt.plot(x_coords, y_coords, marker='o')
for i, (x, y) in enumerate(cities):
    plt.text(x, y+2, str(i), color='red', fontsize=12)
plt.title('Маршрут коммивояжёра (жадный алгоритм)')
plt.xlabel('X')
plt.ylabel('Y')
plt.grid()
plt.show()

# 5. Рассчитываем длину маршрута
total_length = 0
for i in range(len(route) - 1):
    total_length += dist_matrix[route[i]][route[i+1]]
print("\nДлина маршрута: {:.2f}".format(total_length))
