from time import time

def primenumber(N):
    i = 2
    while i < N:
        if N % i == 0:
            return False
        i += 1
    return True

def printarr(arr):
    e = 0
    count = 0
    for e in arr:
        if arr[e] != 0:
            count += 1
    print('소수의 개수는: ', count, '개 입니다.')

def genarr(n):
    arr = list(range(n+1))
    return arr

N = int(input('2 이상의 자연수 N 입력: '))
start = time()
if N >= 2:

    arr = genarr(N)
    arr[1] = 0

    i = 2

    while i*i <= N:
        if arr[i] != 0 and primenumber(i):
            for j in range(i*2, N+1, i):
                arr[j] = 0
        i += 1
    print(arr)
    printarr(arr)
    execute = time() - start
    print('실행 시간은: ', execute, '초 입니다.')
else:
    print('2이상의 자연수 입력: ')

