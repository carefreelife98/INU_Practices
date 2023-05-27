print('주어진 자연수 이하의 약수 출력')
N = int(input('자연수 입력: '))
i = 1
if N >= 1:
    print(N, '의 모든 약수: ')
    for i in range(i, N+1, 1):
        if N % i == 0:
            print(i)

else:
    print(N, '은 자연수가 아닙니다.')