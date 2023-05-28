# ------------------노트--------------------------
# candy_counts = [a1, a2, a3, ... a(n)]
# a1,a2,a3.. 는 개수이니까
# = 개수를 다 더해서 가장 작은 값의 개수로 나누면 몇 개씩인지 나온다.
# 그 후 전체 갯수 / 위에서 구한 패키지당 개수 = 패키지의 수.
# 사탕의 종류는 1~1000 종류 / 종류당 개수는 1~10000

# ------------------설명--------------------------

# 1. len() 을 사용, 리스트의 길이를 구해 처음부터 끝까지의 모든 원소를 꺼내 candies 에 합한다.
# 2. candies (총 사탕 개수) 를 리스트에서
#       가장 작은 값인 min 으로 나눠 구한 package 당 사탕의 개수 candy 를 구한다.
# 3. candies (사탕의 총 개수) 를 candy (패키지 당 캔디의 개수) 로 나눈다.
# 4. 3에서 나온 package 수와 candy per package 를 반환한다.
# 5. 조건문 사용하여 기준 범위를 넘는 입력은 예외 처리.
# 6. 만약 캔디 개수가 소수인 종류가 있거나 캔디가 남는 다면, 패키지는 1개 , 패키지당 개수는 모든 사탕의 개수이다.

# ------------------함수 구현--------------------------

# def candy_count_per_package(candy_counts):
#     try:
#         if 1 <= len(candy_counts) <= 1000:
#             candies = 0
#             min = candy_counts[0]
#             for i in range(len(candy_counts)):
#                 if 1 <= candy_counts[i] <= 10000:
#                     candies += candy_counts[i]
#                     # 가장 적은 수의 캔디종 찾기
#                     if candy_counts[i] < min:
#                         min = candy_counts[i]
#                 else:
#                     print("사탕의 개수가 지정된 수(1 <= X <= 10000)와 다름.")
#                     break
#             # print("사탕 종류 중 최소 개수: ", min) 확인용
#             candy = candies / min
#             package = candies / candy
#
#             # candy 가 남는지 확인
#             if candies % package == 0:
#                 return int(package), int(candy)
#             # candy 가 남는 다면 캔디의 종류 중 소수인 종류가 있는지 판별
#             else:
#                 for i in range(1, len(candy_counts)):
#                     a = candy_counts[i]
#                     # 소수 판별
#                     while i < a:
#                         if a % i == 0:
#                             break
#                         i += 1
#                     return 1, int(candies)
#         else:
#             print("사탕의 종류가 지정된 수(1 <= X <= 1000)와 다름.")
#     except:
#         print("사탕의 종류나 개수가 지정된 수와 맞지 않습니다. 다시 입력해주세요.")


if __name__ == '__main__':
    # Please write here to test your function
    # See the following examples
    def candy_count_per_package(candy_counts):
        try:
            if 1 <= len(candy_counts) <= 1000:
                candies = 0
                min = candy_counts[0]
                for i in range(len(candy_counts)):
                    if 1 <= candy_counts[i] <= 10000:
                        candies += candy_counts[i]
                        # 가장 적은 수의 캔디종 찾기
                        if candy_counts[i] < min:
                            min = candy_counts[i]
                    else:
                        print("사탕의 개수가 지정된 수(1 <= X <= 10000)와 다름.")
                        break
                # print("사탕 종류 중 최소 개수: ", min) 확인용
                candy = candies / min
                package = candies / candy

                # candy 가 남는지 확인
                if candies % package == 0:
                    return int(package), int(candy)
                # candy 가 남는 다면 캔디의 종류 중 소수인 종류가 있는지 판별
                else:
                    for i in range(1, len(candy_counts)):
                        a = candy_counts[i]
                        # 소수 판별
                        while i < a:
                            if a % i == 0:
                                break
                            i += 1
                        return 1, int(candies)
            else:
                print("사탕의 종류가 지정된 수(1 <= X <= 1000)와 다름.")
        except:
            print("사탕의 종류나 개수가 지정된 수와 맞지 않습니다. 다시 입력해주세요.")


print(candy_count_per_package([10, 20, 30]))
print(candy_count_per_package([16, 8, 24]))
print(candy_count_per_package([1, 1, 1]))
print(candy_count_per_package([2, 2, 2]))
print(candy_count_per_package([12, 48, 96]))
print(candy_count_per_package([12, 2, 48]))
