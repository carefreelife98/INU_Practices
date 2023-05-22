a = int(input('정수 a 입력: '))
b = int(input('정수 b 입력: '))
c = int(input('정수 c 입력: '))


def gcd2(x, y):
    if x <= 0 or y <= 0:
        print('두 수의 최대 공약수는 ', x, '입니다')
    else:
        while y > 0:
            (x, y) = (y, x % y)
        print('두 수의 최대 공약수는 ', x, '입니다.')



if a <= 0 or b <= 0 or c <= 0:
    print('두 수의 최대 공약수는 ', a, '입니다')
else:
    gcd2(gcd2(a, b), c)


