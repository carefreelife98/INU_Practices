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

a = int(input('a 를 입력하세요: '))
if isPrime(a):
    print(a, '는 소수입니다')
else:
    print(a, '은 소수가 아닙니다.')