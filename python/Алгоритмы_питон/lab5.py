# def merge_sort(arr):
#     if len(arr) == 1:
#         return arr;

#     mid = len(arr)//2
#     left = merge_sort(arr[:mid])
#     right = merge_sort(arr[mid:])

#     return merge(left, right)

# def merge(left, right):
#     result = []
#     i = j = 0
#     while i < len(left) and j<len(right):
#         if left[i] <= right[j]:
#             result.append(left[i])
#             i += 1
#         else:
#             result.append(right[j])
#             j+= 1
#     result.extend(left[i:])
#     result.extend(right[j:])
#     return result

# arr = [5, 2, 9, 1, 5, 6]
# n = len(arr)
# sorted_arr = merge_sort(arr)
# print(f"неотсортированный: {arr}")
# print(f"отсортированный: {sorted_arr}")




#Естественное слияние
# def find_runs(arr):
#     runs = []
#     n = len(arr)
#     i = 0
#     while i < n:
#         start = i
#         while i + 1 < n and arr[i] <= arr[i + 1]:
#             i += 1
#         runs.append((start, i + 1))
#         i += 1
#     return runs

# def merge(left, right):
#     result = []
#     i = j = 0
#     while i < len(left) and j < len(right):
#         if left[i] <= right[j]:
#             result.append(left[i])
#             i += 1
#         else:
#             result.append(right[j])
#             j += 1
#     result.extend(left[i:])
#     result.extend(right[j:])
#     return result

# def natural_merge_sort(arr):
#     arr = arr[:]
#     while True:
#         runs = find_runs(arr)
#         if len(runs) == 1:
#             break
#         new_arr = []
#         i = 0
#         while i < len(runs):
#             run1 = arr[runs[i][0]:runs[i][1]]
#             if i + 1 < len(runs):
#                 run2 = arr[runs[i + 1][0]:runs[i + 1][1]]
#                 merged = merge(run1, run2)
#                 new_arr.extend(merged)
#                 i += 2
#             else:
#                 new_arr.extend(run1)
#                 i += 1
#         arr = new_arr
#     return arr

# data = [1, 3, 5, 2, 4, 8, 0, 7]
# print("До:", data)
# sorted_data = natural_merge_sort(data)
# print("После:", sorted_data)




























# def new_func():
#     def merge_sort(arr):
#         if len(arr) <= 1:
#             return arr
    
#         mid = len(arr) // 2
#         left = merge_sort(arr[:mid])
#         right = merge_sort(arr[mid:])

#         return merge(left, right)

#     def merge(left, right):
#         result = []
#         i = j = 0

#         while i<len(left) and j<len(right):
#             score_left, score_right = left[i][1], right[j][1]
#             name_left, name_right = left[i][0], right[j][0]

#             if score_left > score_right:
#                 result.append(left[i])
#                 i += 1
#             elif score_left < score_right:
#                 result.append(right[j])
#                 j += 1
#             else:
#                 if name_left < name_right:
#                     result.append(left[i])
#                     i+=1
#                 else:
#                     result.append(right[j])
#                     j+=1 

#         result.extend(left[i:])
#         result.extend(right[j:])
#         return result


# name = ["Anton", "Emil", "Timofey", "Nikita", "Beytullah", "Ruslan", "Egor"]
# score = [77, 75, 90, 92, 72, 72, 65]

# participants = list(zip(name, score))
# sorted_participants = merge_sort(participants)
# for name, score in sorted_participants:
#     print(name, score)


def merge_sort(arr):
    if len(arr) <= 1:
        return arr

    mid = len(arr) // 2
    left = merge_sort(arr[:mid])
    right = merge_sort(arr[mid:])

    return merge(left, right)

def merge(left, right):
    result = []
    i = j = 0

    while i < len(left) and j < len(right):
        score_left, score_right = left[i][1], right[j][1]
        name_left, name_right = left[i][0], right[j][0]

        if score_left > score_right:
            result.append(left[i])
            i += 1
        elif score_left < score_right:
            result.append(right[j])
            j += 1
        else:
            if name_left < name_right:
                result.append(left[i])
                i += 1
            else:
                result.append(right[j])
                j += 1

    result.extend(left[i:])
    result.extend(right[j:])
    return result

name = ["Anton", "Emil", "Timofey", "Nikita", "Beytullah", "Ruslan", "Egor"]
score = [77, 75, 90, 92, 72, 72, 65]

participants = list(zip(name, score))
sorted_participants = merge_sort(participants)
for name, score in sorted_participants:
    print(name, score)



















