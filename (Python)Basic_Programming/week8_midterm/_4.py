# 1.
# a = int(input('0이 아닌 정수 a를 입력하시오: '))
# b = int(input('0이 아닌 정수 b를 입력하시오: '))
# try:
#     a / b  # NullPointerException 유도하여 a, b 중 하나라도 0이 입력되면 예외가 발생
#     b / a  # NullPointerException 유도하여 a, b 중 하나라도 0이 입력되면 예외가 발생
#     if (a > 0 and b > 0) or (a < 0 and b < 0):
#         print('같다')
#     else:
#         print('다르다')
# except:
#     print('0을 입력 했습니다.')
#
# 2.
# a = int(input('0이 아닌 정수 a를 입력하시오: '))
# b = int(input('0이 아닌 정수 b를 입력하시오: '))
# try:
#     a = int(a)
#     b = int(b)
#     i = 1
#     gcd = 0
#     while i <= a:
#         if a % i == 0:
#             if b % i == 0:
#                 gcd = i
#         i = i + 1
#     print(a, '와', b, '의', '최대 공약수는', gcd, '입니다.')
# except:
#     print('0이 입력되었습니다.')
# 3.
# a = int(input('0이 아닌 정수 a를 입력하시오: '))
# b = int(input('0이 아닌 정수 b를 입력하시오: '))
# try:
#     a = int(a)
#     b = int(b)
#     if a < b:
#         a, b = b, a
#     while a % b != 0:
#         a, b = b, a % b
#     print('유클리드 호제법을 사용해 구한 최대공약수는: ', b)
# except:
#     print('0이 입력되었습니다.')
# 4.
# a = int(input('0이 아닌 정수 a를 입력하시오: '))
# b = int(input('0이 아닌 정수 b를 입력하시오: '))
# c = int(input('0이 아닌 정수 c를 입력하시오: '))
# try:
#     a = int(a)
#     b = int(b)
#     c = int(c)
#     while a % b != 0:
#         a, b = b, a % b
#         if a%b == 0:
#             while b % c != 0:
#                 b, c = c, b % c
#     print('세 정수의 최대 공약수는: ', c)
# except:
#     print('0이 입력되었습니다.')

# 4_2_1.
# a = int(input('0이 아닌 정수 a를 입력하시오: '))
# b = int(input('0이 아닌 정수 b를 입력하시오: '))
# try:
#     a = int(a)
#     b = int(b)
#
#     A = a
#     B = b
#
#     while A != B:
#         if A > B:
#             B += b
#         else:
#             A += a
# except:
#     print('0이 입력되었습니다.')
# print('최소 공배수는 ', A, "입니다")

# 4_2_2
# a = int(input('0이 아닌 정수 a를 입력하시오: '))
# b = int(input('0이 아닌 정수 b를 입력하시오: '))
# c = int(input('0이 아닌 정수 c를 입력하시오: '))
# try:
#     a = int(a)
#     b = int(b)
#     c = int(c)
#
#     A = a
#     B = b
#     C = c
#     if a <= 0 or b <= 0 or c <= 0:
#         print('잘못된 입력입니다')
#     else:
#         # sort, a, b, c
#         if a > b:
#             a, b = b, a
#         if b > c:
#             b, c = c, b
#         if a > b:
#             a, b = b, a
#
#         # Here, c is the largest number
#         lcm = c
#         while lcm % a != 0 or lcm % b != 0:
#             lcm += c
#         print('최소공배수 : ', lcm)
# except:
#     print('0이 입력되었습니다.')

