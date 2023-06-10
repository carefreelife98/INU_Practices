
import random

def bin_search(ss, key):
    low = 0
    high = len(ss) -1

    while low <= high:
        mid = (high+low) //2
        if key == ss[mid]:
            return mid
        elif key < ss[mid]:
            high = mid - 1
        else:
            low = mid+1
    return None
    
    
N = input('데이터의 개수 입력 :')


try:
    N = int(N)

    s = set()
    l = []    
    while len(l) < N:
        number = random.randint(1, 2*N)

        if number in s:
            continue
        
        l.append(number)
        s.add(number)

    sorted_l = sorted(l)
    print(f'리스트 :{sorted_l}')
    K = int(input('탐색 키 입력 :'))
    rst = bin_search(sorted_l, K)

    if rst is not None:
        print(f'리스트의 {rst+1} 번째 위치에서 탐색 키와 동일한 원소 발견')
    else:
        print('탐색 키와 동일한 원소가 없습니다.')



except Exception as e:
    print(e)
    print('잘못된 입력입니다')

