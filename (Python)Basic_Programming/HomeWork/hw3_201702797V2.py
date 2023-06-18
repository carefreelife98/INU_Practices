# 보간 탐색
# 1. 만약 ring이 오름차순 정렬된 리스트라면 -> ring[0] 반환
# 2. 아니라면, ring[0] 과 ring[1] 의 차 = 정렬된 리스트 요소간의 차이 값
# 3. 리스트의 첫번째 요소와 마지막 요소의 차 = (요소 개수 - 1) * 차이 값
# 4. key = 두 요소의 차가 (요소 개수 - 1) * 차이 값
# 5. mid + high or mid + low 중 low가 더 크면
# 12 14 0 2 4 6 8 10
# 4 6 8 10 12 14 0 2
import random
import time

def interpolation_search(ss):
    low = 0
    high = len(ss) -1

    while low <= high:
        a = int((high-low)*(key - ss[low])/(ss[high]-ss[low]))
        mid = low + a

        print(f'탐색 요소: {ss[mid]}')
        if key == ss[mid]:
            return mid
        elif key < ss[mid]:
            high = mid - 1
        else:
            low = mid+1
    return None

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