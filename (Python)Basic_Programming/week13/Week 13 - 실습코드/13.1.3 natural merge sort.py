
import random


def merge_from_sorted(l1, l2):

    i1 = 0; i2 = 0
    len_l1 = len(l1); len_l2 = len(l2)

    merged = []
    while i1 < len_l1 or i2 < len_l2:
        if i1 >= len_l1 or i2 >= len_l2:
            merged += l1[i1:] + l2[i2:]
            break
        
        if l1[i1] <= l2[i2]:
            merged.append(l1[i1])
            i1 += 1
        else:
            merged.append(l2[i2])
            i2 += 1

    return merged


def generate_runs(l):
    if len(l) <= 1:
        return l

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


def natural_merge_sort(runs):
    len_runs = len(runs)

    if len_runs <= 1:
        return runs

    while len_runs > 1:
        rst = []
        for i in range(0, len_runs, 2):
            if i == len_runs-1:
                rst.append(runs[i])
            else:
                rst.append(merge_from_sorted(runs[i], runs[i+1]))

        print(f'합병된 Runs: {rst}')
        runs = rst
        len_runs = len(runs)
                           
    return rst[0]
        
    
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

    print(f'최초 리스트 : {l}')    

    runs = generate_runs(l)
    print(f'초기 Run 생성 : {runs}')

    rst = natural_merge_sort(runs)
    print(f'정렬된 리스트 : {rst}')


except Exception as e:
    print(e)
    print('잘못된 입력입니다')

