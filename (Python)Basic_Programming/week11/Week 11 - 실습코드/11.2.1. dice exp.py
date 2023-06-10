
import random

N = input('N: ')

try:
    N = int(N)
    l = [0]*6

    for i in range(N):
        number = random.randint(1, 6)
        l[number-1] += 1

    l = list(map(lambda x:x/N*100.0, l))
    for idx, item in enumerate(l):
        print(f'{idx+1}\t{item:.1f}%')
        
except Exception as e:
    print(e)
    print('잘못된 입력입니다')

