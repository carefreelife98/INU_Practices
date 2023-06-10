
import random

N = input('N = ')

try:
    N = int(N)
    l = []

    while len(l) < N:
        number = random.randint(1, N)
        l.append(number)

    s = set(l)
    print(f's = {s}')

    print('집합에 없는 원소: ', end='')
    for i in range(1, N+1): # 1 <= ele <= N
        if i not in s:
            print(f'{i}', end=' ')
    print('')


except Exception as e:
    print(e)
    print('잘못된 입력입니다')

