def isPerfect(m):
    sum = 0
    j = 0
    if m <= 0:
        print('error -> 양의 정수를 입력하세요')
    else:
        while m-1 != j:
            if m % j == 0:
                sum += j
                return sum == m


N = int(input('2보다 큰 자연수 N 입력: '))
if N < 2:
    print('error: 2보다 큰 자연수 N 을 입력하세요.')
else:
    i = 1
    while i != N:
        if isPerfect(i):
            print(i, '')
            i += 1


