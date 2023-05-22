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
    origin = float(in_str)

    # rs = 진법 변환 후 소수점 아래 부분이 될 문자열
    rs = ""

    # test = rs에 문자가 추가 되는 순간 해당 시점 까지의 문자열을 set() 형태로 저장.
    test = set()

    # subset = 중복 문자 발생 시 중복 문자의 첫 저장 부터 중복 발생 시점 전까지의 문자열을 집합 형태로 저장.
    subset = {}

    # 반환 문자열의 소수점 아래 자릿수를 최대 1000자로 제한.
    max_result = 0

    while origin != 0:
        print('origin = ', origin)
        # 정수 부분 추가.
        # "입력된 정수 x 진법" 의 정수 부분 추출 후 str 자료형인 rs에 추가
        rs += (str(int(origin * to_ary // 1)))
        print("rs = ", rs)
        # 중복을 검사하기 위한 교집합을 검사할 set 자료형인 test에 현재까지의 rs를 추가.
        test.add(rs)
        print(test)
        # origin 을 나머지로 초기화
        origin = origin * to_ary % 1
        # 반환 값 1 증가
        max_result += 1
        print("max 증가")
        if max_result == 1000:
            print(f"반환 값이 소수점 아래 1000 자리가 되었으므로 반환합니다.(소수점 아래 길이 : {max_result}):")
            break

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

# git 추가가 안돼......

if __name__ == '__main__':
    # Please write here to test your function
    print(convert_to_n_ary('0.25', 2))
    print('--------------------------')
    print(convert_to_n_ary('0.25', 8))
    print('--------------------------')
    print(convert_to_n_ary('0.25', 7))
    print('--------------------------')
    print(convert_to_n_ary('0.7', 8))
    print('--------------------------')
    print(convert_to_n_ary('0.5', 4))
    print('--------------------------')
    print(convert_to_n_ary('0.1', 2))
    # print('--------------------------')
    # print(convert_to_n_ary('0.1', 3))
