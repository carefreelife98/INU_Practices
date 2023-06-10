
import random

def merge(l1, l2):
    
    i1 = 0; i2 = 0
    len_l1 = len(l1); len_l2 = len(l2)


    merged = []
    while i1 < len_l1 or i2 < len_l2:
        if i1 >= len_l1 or i2 >= len_l2: # the case when only a list has the data to sort
            merged += l1[i1:] + l2[i2:]
            break
        
        if l1[i1] <= l2[i2]:
            merged.append(l1[i1])
            i1 += 1
        else:
            merged.append(l2[i2])
            i2 += 1

    return merged


    
N1 = input('첫 번째 리스트의 원소 개수 입력 :')
N2 = input('두 번째 리스트의 원소 개수 입력 :')

try:
    N1 = int(N1); N2 = int(N2)

    s = set()
    l1 = []    
    while len(l1) < N1:
        number = random.randint(1, 100)
        if number in s:
            continue        
        l1.append(number)
        s.add(number)

        
    l2 = []    
    while len(l2) < N2:
        number = random.randint(1, 100)
        if number in s:
            continue        
        l2.append(number)
        s.add(number)


    sorted_l1 = sorted(l1)
    sorted_l2 = sorted(l2)

    print(f'정렬된 첫 번째 리스트 : {sorted_l1}')
    print(f'정렬된 두 번째 리스트 : {sorted_l2}')
    
    merged = merge(sorted_l1, sorted_l2)

    print(f'합병된 리스트 : {merged}')


except Exception as e:
    print(e)
    print('잘못된 입력입니다')

