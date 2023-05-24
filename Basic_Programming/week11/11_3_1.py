import random
def find_missing_num(n):
    num_set = []
    for i in range(n):
        num_set.append(random.randint(1, n))

    s = set(num_set)
    print(f"집합의 원소 : {s}")

    print('없는 요소: ')
    for i in range(1, n+1):
        if i not in s:
            print(f'{i}')

n = int(input('num 입력: '))
find_missing_num(n)
