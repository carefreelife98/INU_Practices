
import random

N = input('리스트의 원소 개수 입력 : ')

try:
    N = int(N)
    l = []

    for i in range(N):
        number = random.randint(1, 2*N)
        l.append(number)
    print(l)

    k = int(input('목표값 입력: '))

    print(f'두 수의 합이 {k}인 원소 쌍')

    for i in range(N):
        for j in range(i+1, N):
            if l[i]+l[j] == k:
                print(f'{i+1}번째와 {j+1}번째 원소')

except Exception as e:
    print(e)
    print('잘못된 입력입니다')

