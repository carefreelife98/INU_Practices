# (문자열, 진법)
# 0.0 < float(in_str) < 1.0
# 0 <= len(in_str) <= 1000
# 1 < to_ary < 10
def list_to_str(str_list):
    result = ""
    for s in str_list:
        result += s + ""
    return result.strip()

# 방법 1
# 정수 부분을 rs에 추가하기 전 해당 값을 기존 rs와 비교.
# 만약 같은 값이 존재 하면, 해당 값 직전 까지의 rs 요소를 temp 에 복사 후 해당 값도 마저 rs에 추가.
# 소수점 아래 자리수인 max_result가 1000되기 전까지 실행.

# 방법 2
# 집합으로 비교. (교집합이 존재하는지?)

def convert_to_n_ary(in_str: str, to_ary: int) -> str:
    print(f"{in_str}을 {to_ary}진법으로 변환 시작:")
    origin = float(in_str)

    # rs = 진법 변환 후 소수점 아래 부분이 될 문자열
    rs = ""

    # test = rs에 문자가 추가 되는 순간 해당 시점 까지의 문자열을 set() 형태로 저장.
    test = []

    # 반환 문자열의 소수점 아래 자릿수를 최대 1000자로 제한.
    max_result = 0

    # is_same : 중복 검사용 set()
    is_same = set()

    while origin != 0:
        print('origin = ', origin)
        if max_result != 1000:
            # 정수 부분 추가.
            # "입력된 정수 x 진법" 의 정수 부분 추출 후 str 자료형인 rs에 추가
            # rs += (str(int(origin * to_ary // 1)))
            # print("rs = ", rs)
            # # 중복 확인용 test 리스트에도 추가.
            # test += (str(int(origin * to_ary // 1)))
            # origin 을 나머지로 초기화
            # origin = origin * to_ary % 1
            # # 반환 값 1 증가
            # max_result += 1
            # print("max 증가")
        # 최소 하나의 문자가 저장 되어 있을 때 중복 검사.
        # else:
        #     # 1. 소수점 아래 한 자리수를 구한다.
        #     num = (str(int(origin * to_ary // 1)))
        #     # 해당 자리 수가 test 리스트에 존재 여부 먼저 확인 한다.
        #     if num in test:
        #         print(f"현재 test : {test} num : {num}")
        #
        #         # 만약 기존에 존재하는 문자라면, 해당 중복 문자의 index를 구한다.
        #         same = test.index(num)
        #         print(f"중복 문자 발견! : {num}, index : {same}")
        #
        #         test = ''.join(test[same:])
        #         print(f"test = {test}")
        #         # 중복 문자의 index 를 사용하여 해당 중복 문자 부터 끝까지의 문자열을 구해 set에 넣는다.
        #         test_set = set()
        #         test_set.add(test)
        #         print(f"test_set : {test_set}")
        #
        #         # is_same set에 완성된 예상 중복 문자열을 삽입.
        #         is_same.add(test)
        #         print(f"is_same : {is_same}")
        #
        #         # 만약 기존에 저장되었던 예상 중복 문자열이 한번 더 set으로 들어오게 되면 break.
        #         if test_set.issubset(is_same) and len(test_set) > 1:
        #             print(f"중복 문자열 감지 : {test_set}")
        #             break

            # 정수 부분 추가.
            # "입력된 정수 x 진법" 의 정수 부분 추출 후 str 자료형인 rs에 추가
            rs += (str(int(origin * to_ary // 1)))
            print("rs = ", rs)
            # test += (str(int(origin * to_ary // 1)))
            # origin 을 나머지로 초기화
            origin = origin * to_ary % 1
            # 반환 값 1 증가
            max_result += 1
            print("max 증가")
            if max_result == 1000:
                print(f"반환 값이 소수점 아래 1000 자리가 되었으므로 반환합니다.(소수점 아래 길이 : {max_result}):")
                break

    # break 후 최종 문자열 반환.
    # 숫자의 끝에 0이 있는 경우 제외
    rs = f"0.{rs}"
    float(rs)

    str(rs)
    print(in_str, "을", to_ary, "진법으로 변환:")
    return list_to_str(rs)

# def convert_to_n_ary(m, n):
#     result = ''
#     precision = 1000
#
#     m = float(m)
#     while m > 0 and precision > 0:
#         m *= n
#         digit = int(m)
#         result += str(digit)
#         m -= digit
#         precision -= 1
#     return result

if __name__ == '__main__':
    # Please write here to test your function
    print(convert_to_n_ary('0.8125', 2))
    print('--------------------------')
    print(convert_to_n_ary('0.25', 8))
    print('--------------------------')
    print(convert_to_n_ary('0.25', 7))
    print('--------------------------')
    print(convert_to_n_ary('0.7', 8))
    print('--------------------------')
    print(convert_to_n_ary('0.5', 4))
    # print('--------------------------')
    # print(convert_to_n_ary('0.1', 2))
    # print('--------------------------')
    # print(convert_to_n_ary('0.1', 3))
    # print('--------------------------')
    # print(convert_to_n_ary('0.2', 3))
    # print('--------------------------')
    # print(convert_to_n_ary('0.45', 4))
