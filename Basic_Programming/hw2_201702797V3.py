# (문자열, 진법)
# 0.0 < float(in_str) < 1.0
# 0 <= len(in_str) <= 1000
# 1 < to_ary < 10
def list_to_str(str_list):
    result = ""
    for s in str_list:
        result += s + ""
    return result.strip()

# 알고리즘
# 10 진수 소수의 진법 변환: 해당 소수 X 진법 시 정수 부분을 추출.
# 정수 부분을 0. 밑으로 붙힌다.
# 0.0<float(in_str)<1.0
# 0≤len(in_str)≤1,000
# 1<to_ary<10
# 반환값: 소수점 1000자리 까지 계산,이하 자리는 버림,1000자리 미만으로 계산될 시, 해당 자리까지만 계산
#
# 문제점: float 변환시 소수점 아래 부분 부정확
#
def convert_to_n_ary(in_str: str, to_ary: int) -> str:
    print(f"{in_str}을 {to_ary}진법으로 변환 시작:")
    # 문자열 배열로 저장
    list_str = list(in_str)
    # 정수 부분을 담을 배열 생성
    list_rs = []
    print(f'생성된 list: {list_str}')
    plus = False

    while len(list_rs) != 1000 and list_str.count("0") != len(list_str) - 2:
        # 문자열 in_str 의 길이 만큼 각 자릿수에 대해 가장 뒷 자리수 부터 진법을 곱한다.('0.~'의 소수점 아래 부분만)
        # for 문에서 소수점 아래 첫째 자리까지 곱한 결과로 정수 부분(1)이 발생하면 break하여 rs에 추가.
        # 발생하지 않으면 0 추가 후 다시 루프.

        for i in range(len(list_str) - 1, 1, -1):
            print(f'i = {i}')
            print(list_str[i])
            # 가장 마지막 자리부터 곱해오며 만약 10이 넘어갈 시
            # 현재 자리에는 10으로 나눈 나머지, 이전 자리에 + 1
            if int(list_str[i]) * to_ary >= 10:
                plus = True
                print('plus + 1')
                print('(10보다 같거나 큼)', int(list_str[i]), '*', to_ary, '=', int(list_str[i]) * to_ary)
                # 몫 temp2 에 저장
                temp2 = str(int(list_str[i]) * to_ary // 10)
                # 나머지를 temp 에 저장
                temp = int(list_str[i]) * to_ary % 10
                # 현재 자리에 나머지를 int 로 저장.
                print(f'나머지 {temp} 현재 위치인 {i}에 저장')
                list_str[i] = str(temp)
                # 이전 자리에 + 1
                # 만약 이전 자리에 1 추가해야 하는데 '.' 이 있으면 0이 아닌 정수 부분이 나온 것 이므로 추출 후 다음 while 루프.
                # 만약 소수점 아래가 전부 0 이거나 1000자를 넘을 시 종료
                if list_str[i-1] == '.':
                    print('소수점 아래 첫째 자리 도달, 정수 발생. 정수  추출')
                    list_str[i-2] = temp2
                    print(f'rs에 추가 : {temp2}')
                    list_rs.append(str(temp2))
                    list_str[i-2] = "0"

                    # 정수 부분이 발생하여 1을 추가한 후 list_str 의 소수점 아래 부분이 전부 '0'이면 종료.
                    # 변환 결과의 소수점 아래 부분을 저장한 list_rs의 길이가 1000이 되어도 종료.
                    if list_str[i-2] == "1" and list_str.count("0") == len(list_str) - 2:
                        print('2진법 종료')
                        break
            # 10이 넘어 가지 않을 시 현재 위치에 그대로 저장
            else:
                list_str[i] = str(int(list_str[i]) * to_ary)
                if plus:
                    list_str[i] = str(int(list_str[i]) + 1)
                plus = False
            # 소수 X 진법이 끝났을 때(i == 2) 정수가 반환되지 않으면 rs에 0 추가 후 다음 while loop.
            if i == 2:
                print(f'{i} == 2 소수점 아래 첫 자리 곱인데 정수가 반환되지 않았으므로 list_rs에 0 추가.')
                list_rs.append("0")
            print(f'소수 X 진법 한 턴 종료 후 list: {list_str}')
            print(f'소수 X 진법 한 턴 종료 후 rs: {list_rs}')

    print(f'변환 결과: 0.{list_to_str(list_rs)}')

if __name__ == '__main__':
    # Please write here to test your function
    # print(convert_to_n_ary('0.8125', 2))
    # print('--------------------------')
    # print(convert_to_n_ary('0.25', 8))
    # print('--------------------------')
    print(convert_to_n_ary('0.25', 2))
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
