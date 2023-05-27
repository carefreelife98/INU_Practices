def primenumber(N):
    i = 2
    while i < N:
        if N % i == 0:
            return False
        i += 1
    return True

def printarr(arr):
    e = 0
    for e in arr:
        if arr[e] != 0:
            print(arr[e])

def genarr(n):
    arr = list(range(n+1))
    return arr

N = int(input('2 이상의 자연수 N 입력: '))
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
else:
    print('2이상의 자연수 입력: ')

