
import random

N = input('N = ')

try:
    N = int(N)
    l = []

    while len(l) < N:
        number = random.randint(1, 2*N)
        l.append(number)

    s = set(l)
    print(f'리스트: {l}')
    print(f'집합: {s}')

    new_l = sorted(s)

    start_idx = 0
    longest_cons_seq = 1
    
    for idx in range(1, len(new_l)):
        if new_l[idx-1]+1 != new_l[idx]:
            cons_seq = new_l[start_idx:idx]
            longest_cons_seq = max(len(cons_seq), longest_cons_seq)
            start_idx = idx

    cons_seq = new_l[start_idx:]
    longest_cons_seq = max(len(cons_seq), longest_cons_seq)
    

    print(f'최장 연속 순차의 길이 : {longest_cons_seq}')


except Exception as e:
    print(e)
    print('잘못된 입력입니다')

