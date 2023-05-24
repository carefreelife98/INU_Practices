# import random
# def find_sequence(n):
#     num_set = [n]
#     for i in range(n):
#         num_set.append(random.randint(1, n*2))
#
#     s = set(num_set)
#     print(f"집합의 원소 : {s}")
#
#     long = []
#     for i in range(len(s)):
#         long[i] = set.pop()
#     long.sort()
#
#     i = 1
#     while i <= len(s):
#         if long[i] == long[i+1]:
#             long.append(i)
#         i += 1
#     print(f"최장 연속 순차 : {long}")
#
# a = int(input('정수 입력: '))
# find_sequence(a)

import random
def find_sequence(n):
    num_set = [n]
    for i in range(n):
        num_set.append(random.randint(1, n*2))
    s = set(i)
    print(f'list : {num_set}')
    print(f'set : {s}')

    new_l = sorted(s)

    start_idx = 0
    longest_cons_seq = 1

    for idx in range(1, len(new_l)):
        if new_l[idx - 1] + 1 != new_l[idx]:
            cons_seq = new_l[start_idx:idx]
            longest_cons_seq = max(len(cons_seq), longest_cons_seq)
            start_idx = idx

    # for문에서 처리되지 않은 리스트의 마지막까지 처리
    cons_seq = new_l[start_idx:]
    longest_cons_seq = max(len(cons_seq), longest_cons_seq)

    print(f'최장 연속 순차열 : {longest_cons_seq}')

a = int(input('정수 입력: '))
find_sequence(a)
