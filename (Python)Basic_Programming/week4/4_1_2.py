a = int(input('정수 a 입력: '))
b = int(input('정수 b 입력: '))

for i in range(1, a + 1, 1):
    if a % i == 0:
        if b % i == 0:
            fin = i
print('a와 b의 최대 공약수는: ' + str(fin))
