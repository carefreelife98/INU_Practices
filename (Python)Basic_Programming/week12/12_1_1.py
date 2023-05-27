from functools import reduce
# def average(new_list):
#     a = list(map(*new_list, new_list))
#     # reduce(lambda a, b : a + b, new_list, 0)
#     print(reduce(lambda a, b : a + b, new_list, 0))
#
# i = int(input('입력'))
# a = []
# for i in range(a):

def min_square(l):
    len_l = len(l)
    list(map(lambda x: x * x, l))

    return reduce(lambda x, y: x + y,) / len_l

def dot(l1, l2):
    total = 0
    for i1, i2 in zip(l1, l2):
        total += i1 * i2

    return total
