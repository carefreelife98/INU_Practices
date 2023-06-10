# def selection_sort(l):
#     while l != []:
#         smallest = min(l)
#         l.remove(smallest)
#         return [smallest] + selection_sort(l)
#     if l == []:
#         return []
#
# if __name__ == '__main__':
#     print(selection_sort([1, 5, 6, 7, 3, 5, 6, 4]))
import random

# l = [1, 2, 3, 4, 5]
# k = 3
# while k > 0:
#     for idx in range(len(l)-1, 0, -1):
#         l[idx - 1], l[idx] = l[idx], l[idx - 1]
#         print(l);
#
#     k -= 1

for i in range(10+1):
    print(random.randrange(1, 3))

