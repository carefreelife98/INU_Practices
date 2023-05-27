# 5_1_1
# def max3(x, y, z):
#     if x > y:
#         x, y = y, x
#     if y > z:
#         y, z = z, y
#     if x > z:
#         x, z = z, x
#     return z
#
# a, b, c = 10, 4, 7
# print(a, ',', b, ',', c, '중 최대값:', max3(a, b, c))

# 5_1_2
# def isDivisor(n, m):
#     return m % n == 0
#
# a = input('자연수 a 입력: ')
#
# try:
#
#     a = int(a)
#
#     if a <= 0:
#         print('잘못된 입력입니다')
#     else:
#         print(a, '의 모든 약수 :', end=' ')
#         for i in range(1, a + 1):  # 1 <= i <= a
#             if isDivisor(i, a):
#                 print(i, end=' ')
#         print('')
# except:
#     print('잘못된 입력입니다')

# 5_1_3
# def gcd2(x, y):
#     if x <= 0 and y <= 0:
#         print('입력이 올바르지 않습니다')
#     else:
#         i = 1
#         while x >= i and y >= i:
#             if x % i == 0 and y % i == 0:
#                 gcd = i
#             i = i + 1
#     return gcd
#
#
# a = int(input('정수 a 입력: '))
# b = int(input('정수 b 입력: '))
# c = int(input('정수 c 입력: '))
#
# print('세 정수의 최대 공약수는:', gcd2(gcd2(a, b), c))

# 5_1_4
# def gcd2(x, y): // 이거 좀 고쳐야 작동할 듯
#     if x <= 0 and y <= 0:
#         print('입력이 올바르지 않습니다')
#     else:
#         i = 1
#         while x >= i and y >= i:
#             if x % i == 0 and y % i == 0:
#                 gcd = i
#             i = i + 1
#     return gcd
#
# def lcm2(x, y):
#     i = 1
#     while x * y == gcd2(x, y) * i:
#         i = i + 1
#     return i
#
# a = int(input('정수 a 입력: '))
# b = int(input('정수 b 입력: '))
# c = int(input('정수 c 입력: '))
#
# print('세 정수의 최소 공배수는:', lcm2(lcm2(a, b), c))

# 5_2_1
# def isPerfect(m):
#     i = 1
#     sum = 0
#     while m > i:
#         if m % i == 0:
#             sum += i
#         i = i + 1
#     if sum == m:
#         return True
#     else:
#         return False
#
# a = int(input('정수 a 입력: '))
# try:
#     a = int(a)
#     if a <= 0:
#         print('0 이상 정수 입력')
#     else:
#         if isPerfect(a):
#             print(a, "는 완전수 입니다.")
#         else:
#             print(a, '는 완전수가 아닙니다.')
# except:
#     print('입력 오류')

# 5_2_2
# def isPerfect(m):
#     i = 1
#     sum = 0
#     while m > i:
#         if m % i == 0:
#             sum += i
#         i = i + 1
#     if sum == m:
#         return True
#     else:
#         return False
# N = int(input('2보다 큰 자연수 N 입력: '))
#
# if N <= 2:
#     print('2보다 큰 자연수 입력')
# else:
#     try:
#         N = int(N)
#         i = 3
#         while N >= i:
#             if isPerfect(i):
#                 print(i)
#             i = i + 1
#     except:
#         print('입력 오류')

b = [10, 'abc', True, 3.5]
print(b[::-3])