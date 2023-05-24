from functools import reduce
def change(f_list):
    f_list = []
    len_f = len(f_list)
    for i in range(len_f):
        reduce(lambda x, y: (y, x), f_list)
    print(f'change 끝: {f_list}')

def change_list(n, k):
    l = [n]
    for i in range(1, n+1, 1):
        l.append(i)
    for i in range(k-1):
        change(n)
    print(f'change list 끝: {change_list()}')

a = int(input('입력:'))
b = int(input('입력:'))

change_list(a, b)
