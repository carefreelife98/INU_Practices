# 두 가지 조건 성립 :
# 1. if ring[0] < ring[len(ring) - 1] -> 제대로 정렬된 리스트.
#   - 이 경우, ring[0] 반환
# 2. else ring[0] > ring[len(ring) - 1] -> 탐색해야 하는 리스트.
#   - mid 요소 값이 첫번째 값보다 크면 -> 오른쪽 리스트에 존재.
#   - mid 요소 값이 첫번째 값보다 작으면 -> 왼쪽 리스트에 존재.
# 3. 과정2 반복 중 리스트 내의 요소가 2개가 되는 경우 -> 두번째 요소 반환 : ring[1]
#
#
# 1억개 -> 대강 2.1초
#
# 3분 탐색?
# or 보간 탐색?

import random
import time

def get_min_in_a_ring(ring: list) -> int:
    if ring[0] < ring[len(ring) - 1]:
        return ring[0]
    else:
        while True:
            mid = len(ring) // 2
            low = ring[0]

            if len(ring) <= 2:
                return ring[1]
            elif ring[mid] > low:
                ring = ring[mid:]
            else:
                ring = ring[:mid + 1]

def test(idx):
    test_ring = list(range(3466, 10**8 + 1237))
    test_ring = test_ring[idx:] + test_ring[:idx]
    return test_ring

def auto_test():
    # rand = random.randint(1, 10**8)
    # test_ring = list(range(rand, 10**8 + rand*2))
    rand = random.randint(1, 10**8)
    test_ring = list(range(1, 10**8 + 1))
    print(f'가장 작은 정수 : {rand} 리스트의 길이 : {len(test_ring)}')
    print(f'ring[0]: {test_ring[0]}, ring[1]: {test_ring[1]}, ring[2]: {test_ring[2]}')

    test_ring = test_ring[rand:] + test_ring[:rand]
    return test_ring

if __name__ == '__main__':
    # index = random.randint(3466, 10**8 + 1236)
    # testlist = test(index)
    for i in range(5):
        print(f'---------------------test [{i}]---------------------')
        start_t = time.time()
        print(get_min_in_a_ring(auto_test()))
        end_t = time.time() - start_t
        print(f'-----------실행 시간: [{end_t}]-----------\n')

    # print(get_min_in_a_ring([12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]))
    # print(get_min_in_a_ring([5, 7, 11, 13, 2]))

# def find_min_value(l):
#     min_value = 0
#     for i in l:
#         if i < min_value:
#             min_value = i
#     return min_value

# # 삽입정렬 : 기존에 리스트가 정렬되어 있을 경우 가장 빠른 속도.
# # 삽입정렬로 정렬 후 ring[0]을 반환하면 끝?
# # 삽입 정렬을 이분으로 구현?
# def insert_sorted_list(num, sorted_list):
#     index = 0
#     for i in range(len(sorted_list)):
#         if sorted_list[i] > num:
#             break
#         index += 1
#     sorted_list.append(None)
#     for i in range(len(sorted_list)-1, index, -1):
#         sorted_list[i] = sorted_list[i-1]
#     sorted_list[index] = num
#     return sorted_list
#
# def isort(s):
#     if s != []:
#         return insert_sorted_list(s[0], isort(s[1:]))
#     else:
#         return []
#
# # 이분 탐색: 세가지 경우의 수 존재.
# # 1. 왼쪽 리스트에서 떨어지는 구간 발생
# # 2. 오른쪽 리스트에서 떨어지는 구간 발생
# # 3. 양 리스트에서 떨어지는 구간 발생 x -> 마지막 값과 처음 숫자 사이 구간이 떨어지는 구간.
# def is_drop(l):
#     for i in range(len(l) - 1):
#         if l[i] > l[i+1]:
#             return True
#         return False

# # 재귀 이분 탐색 :
# # 1. 순환 조건:
# # 2. 종료 조건: 리스트 내의 요소가 오름차순 정렬되어 있지 않은 경우
# def get_min_in_a_ring_v1(ring: list) -> int:
#
#     mid = len(ring) // 2
#     temp = ring[len(ring) - 1]
#     if is_drop(ring[:mid]):
#         return get_min_in_a_ring(ring[:mid])
#     elif is_drop(ring[mid:]):
#         return get_min_in_a_ring(ring[mid:])
#     else:
#         if not is_drop(ring):
#             print("찾을 수 없음")
#             return temp
#         return is_drop(ring)


