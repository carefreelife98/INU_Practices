import random


# def rand():
#      {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}}
#     n = int(input("주사위 몇 번? :"))
#     for i in range(n + 1):
#         num = random.randint(1, 6)
#         if num==sum(num):
#


# # 11.2.2
# n = int(input('리스트 길이 N 입력: '))
# rand_list = n*[0]
# for i in rand_list:
#     num = random.randint(1, n * 2)
#     rand_list.append(num)
# print(rand_list)
#
# k = int(input('정수 k 입력: '))
#
# for i in range(n):
#     for j in range(j+1, n):
#         if rand_list[i] + rand_list[j] == k:
#             print(i+1, ' 번째 와 ', j+1, ' 번째 원소')

# 11.2.3

n = int(input('set 길이 N 입력: '))
l = []
ran_set = set()
while len(l) < n:
    number = random.randint(1, n * 2)
    if number not in ran_set:
        l.append(number)
        ran_set.add(number)
print(ran_set)

l = sorted(l)
print(l)

k = int(input('목표값 k 입력: '))
i = 0
j = n - 1
while i < j:
    total = l[i] + l[j]
    if total == k:
        print(i+1, ', ', j+1)
        i = i + 1
        j = j - 1
    elif total < k:
        i = i + 1
    else:
        j = j - 1


