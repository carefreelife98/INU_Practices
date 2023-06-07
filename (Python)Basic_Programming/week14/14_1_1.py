import random

def bin_search(l, key):
    low = 0
    high = len(l) - 1
    while low <= high:
        mid = (high + low) // 2
        if key == l[mid]:
            return mid
        elif key < l[mid]:
            high = mid - 1
        else:
            low = mid + 1
    return None

n = int(input('데이터의 개수 N 입력:'))
l = list()
s = set()
while len(l) < n:
    num = random.randint(1, n * 2)
    if num in s:
        continue
    l.append(num)
    s.add(num)

l.sort()
print(l)
m = int(input('탐색할 정수 k 입력:'))
print(f'리스트의 {bin_search(l, m)}위치에서 탐색 키와 동일한 원소 발견!')

