
import random

N = input('리스트의 원소 개수 입력 : ')

try:
    N = int(N)
    l = []
    s = set()

    while len(l) < N:
        number = random.randint(1, 2*N)

        if number not in s:
            l.append(number)
            s.add(number)

    l.sort() # sorts the list in ascending order
    print(l)

    k = int(input('목표값 입력: '))

    print(f'두 수의 합이 {k}인 원소 쌍')
    
    i = 0; j = N-1
    while i < j:
        total = l[i] + l[j]

        if total == k:
            print(f'{i+1}번째와 {j+1}번째 원소')
            i += 1; j -= 1
        elif total < k:
            i += 1
        else:
            j -= 1


except Exception as e:
    print(e)
    print('잘못된 입력입니다')

