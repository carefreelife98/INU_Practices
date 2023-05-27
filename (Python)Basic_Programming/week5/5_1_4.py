
a = int(input('정수 a 입력: '))
b = int(input('정수 b 입력: '))
c = int(input('정수 c 입력: '))

def gcd2(x, y):
    while y > 0:
        (x, y) = (y, x % y)
    return x

def lcm2(x, y):
    return x * y / gcd2(x, y)

rs = a * lcm2(b, c) / gcd2(a, lcm2(b, c))

print('세 정수 a, b, c 의 최소 공배수는 : ', int(rs))

