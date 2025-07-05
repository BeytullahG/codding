# import random
# def bubble_sort(arr):
#     n = len(arr)
#     for i in range(n):
#         for j in range(0, n - i - 1):
#             if arr[j] > arr[j + 1]:
#                 arr[j], arr[j + 1] = arr[j + 1], arr[j]
#     return arr

# arr = [random.randint(1, 30) for _ in range(30)]
# print("Неотсортированный массив: ", arr)
# bubble_sort(arr)
# print("Отсортированный массив: ", arr)



# def calculate_sum(line):
#     return sum(map(int, line.split()))

# def bubl_sort_by_sum(lines):
#     n = len(lines)
#     for i in range(n):
#         for j in range(n - i - 1):
#             if (calculate_sum(lines[j]) > calculate_sum(lines[j+1])):
#                 lines[j], lines[j+1] = lines[j+1], lines[j]
                
#     return lines 

# lines = [
#     "0 4 6 2 6 ",
#     "3 6 72 111",
#     "64 21 65 77 45",
#     "1 1 1 1 1"
# ]

# bubl_sort_by_sum(lines)
# for i in lines:
#     print(i)





# def comparing(line):
#     s = line.split()
#     for i in range(3):
#         if s[i]
    



# lines = [
#     "0 4 6 2 6 ",
#     "3 6 72 111",
#     "64 21 65 77 45",
#     "1 1 1 1 1"
# ]


# print(comparing(lines[0])[0])



# def first_three(line):
#     return tuple(map(int, line.split()[:3]))

# def bubl_sort_by_first_three(lines):
#     n = len(lines)
#     for i in range(n):
#         for j in range(n-i-1):
#             if (first_three(lines[j]) > first_three(lines[j + 1])):
#                 lines[j], lines[j+1] = lines[j+1], lines[j]
#     return lines

# lines = [
#     "0 4 6 2 6 ",
#     "3 6 72 111",
#     "64 21 65 77 45",
#     "1 1 1 1 1"
# ]

# bubl_sort_by_first_three(lines)
# for i in lines:
#     print(i)




def calculate_sum(line):
    return sum(map(int, line.split()))

def bubl_sort_by_sum(lines):
    n = len(lines)
    for i in range(n):
        for j in range(n - i - 1):
            if (calculate_sum(lines[j]) > calculate_sum(lines[j+1])):
                lines[j], lines[j+1] = lines[j+1], lines[j]
                
    return lines 

lines = [
    "0 4 6 2 6 ",
    "3 6 72 111",
    "64 21 65 77 45",
    "1 1 1 1 1"
]

bubl_sort_by_sum(lines)
for i in lines:
    print(i)

