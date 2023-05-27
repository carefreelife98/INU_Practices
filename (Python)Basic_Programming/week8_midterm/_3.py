# 1.
# N = int(input('자연수 N 입력: '))
# i = 1
# nSum = 0
# while i <= N:
#     nSum = nSum + i
#     i = i + 1
# print('1부터 ', N, '까지의 합은: ', nSum, '입니다.')

# 2.
# N = int(input('자연수 N 입력: '))
# i = 1
# while i <= N:
#     if i % 2 != 0:
#         print(i, end=' ')
#     i = i + 1

# 3.
N = int(input('자연수 N을 입력: '))
if type(N) != int or N <= 0:
    print(N, '은/는 자연수가 아닙니다.')
else:
    i = 1
    while i <= N:
        if N % i == 0:
            print(i, end=' ')
        i = i + 1
