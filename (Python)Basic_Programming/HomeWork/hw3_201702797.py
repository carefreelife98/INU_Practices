# 두 가지 조건 성립 :
# 1. if ring[0] < ring[len(ring) - 1] -> 제대로 정렬된 리스트.
#   - 이 경우, ring[0] 반환
# 2. else ring[0] > ring[len(ring) - 1] -> 탐색해야 하는 리스트.
#   - mid 요소 값이 첫번째 값보다 크면 -> 오른쪽 리스트에 존재.
#   - mid 요소 값이 첫번째 값보다 작으면 -> 왼쪽 리스트에 존재.
# 3. 과정2 반복 중 리스트 내의 요소가 2개가 되는 경우 -> 더 작은 요소 반환 : ring[1]
#
# 1억개 -> 대강 0.27초 , 2억 5천 -> 1.3초

import random
import time

def get_min_in_a_ring(ring: list) -> int:
    # 리스트의 첫번째 요소가 마지막 요소보다 작은 경우는 제대로 정렬되어 있는 경우 뿐이므로 ring[0] 즉각 반환.
    if ring[0] < ring[len(ring) - 1]:
        return ring[0]
    else:
        # 이분 탐색
        # 리스트의 범위를 줄여 탐색하는 것보다 리스트 자체의 길이를 줄이면 계산이 더 빠를 것이라 생각하여
        # 리스트의 길이를 줄여가며 탐색하였습니다.
        while True:
            # mid = ring의 중간 index
            mid = len(ring) // 2
            # low = ring의 첫번째 값
            low = ring[0]

            # ring의 길이가 2 이하가 되면 더 작은 값을 반환(종료)
            if len(ring) <= 2:
                if ring[0] > ring[1]:
                    return ring[1]
                return ring[0]

            # ring[mid] 값이 low 값보다 크면 떨어지는 구간은 mid 기준 오른쪽 리스트에 존재.
            elif ring[mid] > low:
                ring = ring[mid:]
            # ring[mid] 값이 low 값보다 작으면 떨어지는 구간은 왼쪽 리스트에 존재.
            else:
                ring = ring[:mid + 1]

def auto_test():

    rand = random.randint(1, 10**8)
    test_ring = list(range(1, 10**8 + rand*2 + 1))
    print(f'slicing 기준 정수 : {rand} 리스트의 길이 : {len(test_ring)}')

    test_ring = test_ring[rand:] + test_ring[:rand]
    print(f'ring[0]: {test_ring[0]}, ring[1]: {test_ring[1]}, ring[2]: {test_ring[2]}, ring[len(ring) - 1] = {test_ring[len(test_ring) - 1]}')
    return test_ring


if __name__ == '__main__':

    for i in range(5):
        print(f'---------------------test [{i}]---------------------')
        test = auto_test()
        start_t = time.time()
        print(get_min_in_a_ring(test))
        end_t = time.time() - start_t
        print(f'-----------실행 시간: [{end_t}]-----------\n')

    print(get_min_in_a_ring([12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]))
    print(get_min_in_a_ring([5, 7, 11, 13, 2]))











# 실패 알고리즘

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


# # 보간 탐색 -> 정렬되어 있지 않아 불가
# # 1. 만약 ring이 오름차순 정렬된 리스트라면 -> ring[0] 반환
# # 2. 아니라면, ring[0] 과 ring[1] 의 차 = 정렬된 리스트 요소간의 차이 값
# # 3. 리스트의 첫번째 요소와 마지막 요소의 차 = (요소 개수 - 1) * 차이 값
# # 4. key = 두 요소의 차가 (요소 개수 - 1) * 차이 값
# # 5. mid + high or mid + low 중 low가 더 크면
# def find_key(l):
#     differ = l[1] - l[0]
#
#     for i in range(len(l) - 1):
#         if abs(l[i] - l[i+1]) == (len(l) - 1) * abs(differ):
#             return l

