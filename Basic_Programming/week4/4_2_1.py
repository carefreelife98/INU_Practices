a = int(input('정수 a 입력: '))
b = int(input('정수 b 입력: '))
tmpA = 0
tmpB = 0

if a > b:
    for i in range(1, 100, 1):
        tmpA = a * i
        for j in range(1, 100, 1):
            tmpB = b * j
            if tmpA == tmpB:
                break
        if tmpA == tmpB:
            break
        j = 1
    print("a 와 b 의 최소 공배수는: " + str(tmpA))

elif a < b:
    for i in range(1, 100, 1):
        tmpB = b * i
        for j in range(1, 100, 1):
            tmpA = a * j
            if tmpA == tmpB:
                break
        if tmpA == tmpB:
            break
        j = 1
    print('a 와 b 의 최소 공배수는: ' + str(tmpA))

elif a == b:
    print("a 와 b 가 같습니다." + str(a))
