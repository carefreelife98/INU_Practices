def isPrime(m):
    if m < 2:
        print('error -> 2 이상의 자연수를 입력하세요')
    else:
        # for i in range(2, m):
        i = 2
        while i < m:
            if m % i == 0:
                return False
            i += 1
        return True

N = int(input('2보다 큰 정수 N을 입력하시오: '))

if N <= 2:
    print('error: 2보다 큰 정수 N을 입력하세요: ')
else:
    x = 2
    while x != N:
        if isPrime(x):
            print(str(x), '')
        x += 1
