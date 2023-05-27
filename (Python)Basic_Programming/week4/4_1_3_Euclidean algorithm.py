print("유클리드 호제법을 이용한 최대공약수 구하기.")

# a = 0
# b = 0

a = int(input("숫자 a 입력: "))
b = int(input("숫자 b 입력: "))

# r = 1
# while r != 0:
#     r = a % b
#     a = b
#     b = r
# print("두 숫자의 최대 공약수는 " + str(a) + " 입니다.")


# 답:
try:
    # a = int(a)
    # b = int(b)

    if a <= 0 or b <= 0:
        print("두 숫자의 최대 공약수는 " + str(a) + " 입니다.")
    else:
        while b > 0:
            a, b = b, a % b
        print(a)
except:
    print("잘못된 입력입니다.")
