a = int(input('정수 n 입력: '))
b = int(input('정수 m 입력: '))

def isDivisor(x,y):
    if y%x==0:
        print(x, '는 ', y, '의 약수 입니다.')
    else:
        print(x, '는 ', y, '의 약수가 아닙니다.')

isDivisor(a, b)
