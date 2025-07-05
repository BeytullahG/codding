# def shell_sort(arr):
#     n = len(arr)
#     gap = n // 2 

#     while gap > 0:
#         for i in range(gap, n):
#             temp = arr[i]
#             j = i

#             while j >= gap and arr[j - gap] > temp:
#                 arr[j] = arr[j - gap]
#                 j -= gap

#             arr[j] = temp

#         gap //= 2  

# arr = [8, 5, 3, 7, 6, 2, 4, 1]
# shell_sort(arr)
# print("Отсортировано:", arr)





# import random

# def shell_sort(arr):
#     n = len(arr)
#     gap = n // 2 

#     while gap > 0:
#         for i in range(gap, n):
#             temp = arr[i]
#             j = i

#             while j >= gap and arr[j - gap] > temp:
#                 arr[j] = arr[j - gap]
#                 j -= gap

#             arr[j] = temp

#         gap //= 2  

# arr = [random.randint(30, 80) for _ in range(30)]
# print("Неотсортированный массив: ", arr)
# shell_sort(arr)
# print("Отсортированный массив: ", arr)



# def shell_sort_strings(arr):
#     n = len(arr)
#     gap = n // 2

#     while gap > 0:
#         for i in range(gap, n):
#             temp = arr[i]
#             j = i

#             while j >= gap and arr[j - gap].lower() > temp.lower():
#                 arr[j] = arr[j - gap]
#                 j -= gap

#             arr[j] = temp

#         gap //= 2

# cities_input = input("Введите список городов через запятую: ")
# cities = [city.strip() for city in cities_input.split(",")]

# print("\nИсходный список городов:")
# print(cities)

# shell_sort_strings(cities)

# print("\nОтсортированный список городов по алфавиту:")
# print(cities)


# import random

# def shell_sort(arr):
#     n = len(arr)
#     gap = n // 2 

#     while gap > 0:
#         for i in range(gap, n):
#             temp = arr[i]
#             j = i

#             while j >= gap and arr[j - gap] < temp:
#                 arr[j] = arr[j - gap]
#                 j -= gap

#             arr[j] = temp

#         gap //= 2  

# arr = [random.randint(1, 30) for _ in range(30)]
# print("Неотсортированный массив: ", arr)
# shell_sort(arr)
# print("Отсортированный массив: ", arr)

# import random

# def shell_sort(arr):
#     n = len(arr)
#     gap = n // 2 

#     while gap > 0:
#         for i in range(gap, n):
#             temp = arr[i]
#             j = i

#             while j >= gap and arr[j - gap] > temp:
#                 arr[j] = arr[j - gap]
#                 j -= gap

#             arr[j] = temp

#         gap //= 2  

# arr = [random.randint(30, 80) for _ in range(30)]
# print("Неотсортированный массив: ", arr)
# shell_sort(arr)
# print("Отсортированный массив: ", arr)


def shell_sort_strings(arr):
    n = len(arr)
    gap = n // 2

    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i

            while j >= gap and arr[j - gap].lower() > temp.lower():
                arr[j] = arr[j - gap]
                j -= gap

            arr[j] = temp

        gap //= 2

cities_input = input("Введите список городов через запятую: ")
cities = [city.strip() for city in cities_input.split(",")]

print("\nИсходный список городов:")
print(cities)

shell_sort_strings(cities)

print("\nОтсортированный список городов по алфавиту:")
print(cities)
