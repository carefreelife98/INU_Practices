# # find 함수 구현
# def find(tgt, pattn, start=0):
#     len_pattn = len(pattn)
#     for i in range(start, len(tgt)):
#
#         substr = tgt[i:i+len_pattn]
#         if substr == pattn:
#             return i
#     return -1
#
# if __name__ == '__main__':
#     a = input('문자열 입력: ')
#     b = input('탐색할 문자 입력: ')
#     c = input('탐색 시작 지점 입력: ')
#
#     if c == '':
#         c = 0
#     else:
#         c = int(c)
#
#     result = find(a, b, c)
#
#     if result != -1:
#         print(f'탐색 성공 : {result} 위치에 존재')
#     else:
#         print('탐색 실패')


# # 11_2_3
# import random
# def rand_sum_to_target(num, tgt):
#     l = list()
#     s = set()
#     while len(s) != num:
#         rand = random.randint(1, num * 2)
#         if rand in s:
#             continue
#         l.append(rand)
#         s.add(rand)
#
#     print(l)
#
#     for i in range(num):
#         for j in range(i, num):
#             if l[i] + l[j] == tgt:
#                 print(f'{i} 번째와 {j} 번째 요소')
#
# if __name__ == '__main__':
#
#     n = int(input('난수의 개수 입력: '))
#     tgt = int(input('목표 숫자 입력: '))
#     rand_sum_to_target(n, tgt)


# 11_3_2
import random
def longest_sequence(num):
    l = list()
    s = set()
    for i in range(num):
        rand = random.randint(1, 2 * num)
        l.append(rand)
        s.add(rand)
    print(f'리스트 : {l}')
    print(f'집합 : {s}')

    check = 1
    max = 0
    for i in range(len(s)):
        l[i] = s.pop()
        if i > 0 and l[i-1] == l[i] - 1:
            check = check + 1
        else:
            check = 1
        if max < check:
            max = check
    return max


if __name__ == '__main__':
    n = int(input('생성할 난수의 개수 입력: '))
    max = longest_sequence(n)
    print(f'최장 연속 순차 : {max}')
