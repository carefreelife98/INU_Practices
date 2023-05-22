print('0이 아닌 세 정수를 입력하시오.')
a = int(input('정수 a 입력: '))
b = int(input('정수 b 입력: '))
c = int(input('정수 c 입력: '))
temp = 0

if a != 0 and b != 0 and c != 0:
    while b != 0:
        (a, b) = (b, a % b)
    print('두 수의 최대공약수 : ' + str(a))
    temp = a

    while temp != 0:
        (c, temp) = (temp, c % temp)
    print('세 수의 최대공약수 : ' + str(c))
else:
    print('0이 입력 되었습니다')
