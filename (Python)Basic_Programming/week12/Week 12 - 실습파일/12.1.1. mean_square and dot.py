from functools import reduce
def mean_square(l):
    len_l = len(l)
    return reduce(lambda x, y:x+y, list(map(lambda x:x*x, l))) / len_l


def dot(l1, l2):
    total = 0

    for i1, i2 in zip(l1, l2):
        total += i1*i2

    return total



print(mean_square([2, 3]))
print(mean_square([1, 2, 3, 4]))
print(dot([1, 0], [0, 1]))
print(dot([1, 2, 3, 4], [2, 3, 4, 5]))
    
