import random

def interpolate_search(l, k):
    low = 0
    high = len(l) - 1

    while low <= high:
        a = int((high - low) * (k - l[low]) / (l[high] - l[low]))
        mid = low + a
        if l[mid] == k:
            return mid
        elif l[mid] > k:
            high = mid - 1
        else:
            low = mid + 1
    return None

n = int(input('데이터의 개수 N 입력:'))
l = list()

while len(l) < n:
    num = random.randint(1, 2 * n)
    if num in l:
        continue
    l.append(num)

l.sort()
print(l)
k = int(input('탐색할 정수 k 를 입력:'))

print(f'리스트의 {interpolate_search(l, k)}번째 위치에서 탐색 키{k}와 동일한 원소 발견!')


