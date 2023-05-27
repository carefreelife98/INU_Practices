# (문자열, 진법)
# 0.0 < float(in_str) < 1.0
# 0 <= len(in_str) <= 1000
# 1 < to_ary < 10
def list_to_str(str_list):
    result = ""
    for s in str_list:
        result += s + ""
    return result.strip()

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
