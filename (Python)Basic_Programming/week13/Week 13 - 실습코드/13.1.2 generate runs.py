
import random


def generate_runs(l):
    if len(l) <= 1:
        return l

    # initial settings
    len_l = len(l)
    prev_item  = l[0]
    runs = []; run = [prev_item]
    i = 1

    while i < len_l:
        if prev_item > l[i]:
            runs.append(run)
            run = [l[i]]
        else:
            run.append(l[i])

        prev_item = l[i]
        i += 1

    runs.append(run) # add last run

    return runs
        
    
N = input('리스트의 원소 개수 입력 :')

try:
    N = int(N)

    s = set()
    l = []    
    while len(l) < N:
        number = random.randint(1, 100)

        if number in s:
            continue
        
        l.append(number)
        s.add(number)

    print(l)

    runs = generate_runs(l) #[[1, 7], [6, 10], [4], ...]

    for idx, item in enumerate(runs):
        print(f'run{idx+1} : {item}')


except Exception as e:
    print(e)
    print('잘못된 입력입니다')

