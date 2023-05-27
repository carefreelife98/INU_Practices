print("정수 a,b,c 입력")
a = int(input('a = '))
b = int(input('b = '))
c = int(input('c = '))

def max3(x, y, z):
    max = x
    if y > max:
        max = y
    if z > max:
        max = z
    print("최대값: ", max)

max3(a, b, c)


