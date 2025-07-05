# def countdown(i):
#     if i <= 0:
#         return
#     else:
#         print(i)
#         countdown(i-1)
# countdown(3)




# book = {}
# book["Апельсин"] = 0.67
# book['молоко'] = 1.49
# book['авокадо'] = 2.49
# print(book['авокадо'])



# voted = {}

# def check_voter(name):
#     if voted.get(name):
#         print(f"{name}, иди нахер, ты голосовал")
#     else: 
#         voted[name] = True
#         print(f'{name} допущен к голосованию')
#     print(voted)

# check_voter('Beytullah')
# check_voter('Ali')
# check_voter('Ali')



# voted = {}
# def check_voter(name):
#     if voted.get(name):
#         print("Выгнать его!")
#     else:
#         voted[name] = True
#         print("Допустить к голосованию!")


#поиск в ширину

from collections import deque
graph = {}
graph["you"] = ["Алиса", "Боб", "Клэр"]
graph["Боб"] = ["Анудж", "Пегги"]
graph["Алиса"] = ["Пегги"]
graph["Клэр"] = ["Том", "Джонни"]
graph["Анудж"] = []
graph["Пегги"] = []
graph["Том"] = []
graph["Джонни"] = []

def is_seller(person):
    return "ж" in person.lower()

def search(name):
    search_queue = deque()
    search_queue += graph[name]
    searched=[]
    while search_queue:
        person = search_queue.popleft()
        if not person in searched:
            if is_seller(person):
                print(f"{person} is seller")
                return True
            else:
                search_queue += graph[person]
                searched.append(person)
    return False
search("you")








