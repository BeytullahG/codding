#1
# import random
# def Selection_Sort(arr):
#     for i in range(0, len(arr)):
#         current_arr = arr[i:]
#         min_elem = min(current_arr)
#         min_index = arr.index(min_elem, i)
#         arr[i], arr[min_index] = arr[min_index], arr[i]

# arr = [random.randint(1, 100) for _ in range(100)]
# print(arr)
# Selection_Sort(arr)
# print("отсортированный", arr)


#2 
# import random
# def Selection_sort(arr):
#     for i in range(0, len(arr)):
#         current_arr = arr[i:]
#         c_max = max(current_arr)
#         min_index = arr.index(c_max, i)
#         arr[i], arr[min_index] = arr[min_index], arr[i]

# arr = [random.randint(20, 30) for _ in range(10)]
# Selection_sort(arr)
# print('сортированный', arr)


# def Selection_Sort(arr):
#     for i in range(0, len(arr)):
#         current_arr = arr[i:]
#         min_elem = min(current_arr, key=lambda x: x[1])
#         min_index = arr.index(min_elem, i)
#         arr[i], arr[min_index] = arr[min_index], arr[i]

# group_info =[
#     ["Иванов Иван", 3],
#         ["Петров Петр",2],
#         ["Сидоров Сергей",5],
#         ["Кузнецова Анна",1],
#         ["Смирнова Елена",4],
#         ["Попов Дмитрий",8],
#         ["Васильева Ольга",6],
#         ["Михайлов Андрей",7],
#         ["Федорова Мария",9]
#     ]

# print( "До сортировки\n",group_info)
# Selection_Sort(group_info)
# student = input("Введите ФИ:\n")
# flag = False
# for i in range(len(group_info)):
#     if group_info[i][0] == student:
#         print("Есть такой в группе", group_info[i])
#         flag = True
#         break

# if (flag == False):
#     print("Такого нет")


#лаб 3
import random
def snacker_sort(arr):
    left = 0
    right = len(arr) - 1
    while (left < right):
        for i in range(left, right):
            if arr[i] > arr[i + 1]:
                arr[i], arr[i+1] = arr[i+1], arr[i]
        right -= 1
    

        for i in range(right, left, -1):
            if arr[i-1] > arr[i]:
                arr[i-1], arr[i] = arr[i], arr[i-1]
        left += 1


arr = [random.randint(1, 50) for _ in range(50)]
print("неотсортированный массив: ", arr)
snacker_sort(arr)
print("сортированный массив: ", arr)


#задания 3 лабы
#1
# import random
# def snacker_sort(arr):
#     left = 0
#     right = len(arr) - 1
#     while (left < right):
#         for i in range(left, right):
#             if arr[i] > arr[i + 1]:
#                 arr[i], arr[i+1] = arr[i+1], arr[i]
#         right -= 1


# arr = [random.randint(1, 30) for _ in range(30)]
# print("неотсортированный массив: ", arr)
# snacker_sort(arr)
# print("сортированный массив: ", arr)


#2
# import random
# def snacker_sort(arr):
#     left = 0
#     right = len(arr) - 1
#     while (left < right):
#         for i in range(left, right):
#             if arr[i] > arr[i + 1]:
#                 arr[i], arr[i+1] = arr[i+1], arr[i]
#         right -= 1


# arr = [random.randint(1, 30) for _ in range(30)]
# print("неотсортированный массив: ", arr)
# snacker_sort(arr)
# print("сортированный массив: ", arr)





