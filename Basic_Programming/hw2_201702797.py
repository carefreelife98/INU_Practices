
def list_to_str(str_list):
    result = ""
    for s in str_list:
        result += str(s) + ""
    return result.strip()

# 소수점 아래 마지막 부터 0 제거
def delete_zero(str_list):
    for i in range(len(str_list)-1, -1, -1):
        if str_list[i] == 0:
            str_list.pop(i)
        else:
            break

# '0' 과 '.' 을 제외한 str과 진법이 입력되면 곱셈 연산 실행.
def multiple_number(list_str, n, rs):
    result = []
    carry = 0

    # 입력된 정수를 문자열로 변환하여 각 자릿수에 접근
    for i in range(len(list_str) - 1, -1, -1):
        # print(f'i = {i}')
        # 한 자리수와 곱셈 연산
        product = int(list_str[i]) * n + carry
        # print(f'product = {product}')

        # 현재 자릿수의 결과를 저장
        result.append(product % 10)
        # print(f'result = {result}')
        # 다음 자릿수로 넘어갈 carry 계산
        carry = product // 10
        # print(f'carry = {carry}')

    if carry > 0:
        # carry가 남아있다면 마지막 자릿수로 추가
        while carry > 0:
            print(f'carry = {carry}')
            rs.append(carry % 10)
            carry //= 10
    else:
        rs.append(0)

    # 결과를 역순으로 반환
    i = len(result)-1
    while i >= 0:
        result.append(result.pop(i))
        i -= 1

    return result

def convert_to_n_ary(in_str: str, to_ary: int) -> str:
    print(f"{in_str}을 {to_ary}진법으로 변환 시작:")
    # 문자열 배열로 저장
    list_str = list(in_str)
    list_str.pop(0) # '0' 삭제
    list_str.pop(0) # '.' 삭제

    rs = []
    while len(rs) != 1000:
        # print(f'생성된 list: {list_str}')
        list_str = multiple_number(list_str, to_ary, rs)
        # print(f'변환된 list: {list_str}')
        # print('--------------------------')
    delete_zero(rs)
    return f"0.{list_to_str(rs)}"

if __name__ == '__main__':
    # Please write here to test your function
    print(convert_to_n_ary('0.8125', 2))
    # print('--------------------------')
    # print(convert_to_n_ary('0.25', 8))
    # print('--------------------------')
    # print(convert_to_n_ary('0.25', 7))
    # print('--------------------------')
    # print(convert_to_n_ary('0.7', 8))
    # print('--------------------------')
    # print(convert_to_n_ary('0.5', 4))
    # print('--------------------------')
    # print(convert_to_n_ary('0.1', 2))
    # print('--------------------------')
    # print(convert_to_n_ary('0.1', 3))
    # print('--------------------------')
    # print(convert_to_n_ary('0.2', 3))
    # print('--------------------------')
    # print(convert_to_n_ary('0.45', 4))
    # print(convert_to_n_ary('0.123', 2))
    # print(convert_to_n_ary('0.97531', 9))
    # print(convert_to_n_ary('0.456', 4))