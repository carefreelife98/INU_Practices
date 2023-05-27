def isPerfect(m):
    if m <= 0:
        print('error -> 양의 정수를 입력하세요')
    else:
        sum = 0
        for i in range(1, m):
            if m % i == 0:
                sum += i
                if sum == m:
                    print(m, '은(는) 완전수 입니다.')
        print(m, '은(는) 완전수가 아닙니다.')

a = int(input('양의 정수를 입력하시오: '))
isPerfect(a)