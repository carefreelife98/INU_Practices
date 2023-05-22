a = int(input('정수 a 입력: '))
b = int(input('정수 b 입력: '))
c = int(input('정수 c 입력: '))

A = a
B = b
C = c
while A != C:
    while A != B:
        if A < B:
            A = A + a
        else:
            B = B + b
    if A < C:
        A = A + a
    else:
        C = C + c
print("a, b, c의 최소 공배수: " + str(A))
