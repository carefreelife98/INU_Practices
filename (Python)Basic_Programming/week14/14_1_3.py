def b_search_root(n):
    num = 1
    while True:
        if num * num >= n > (num - 1) * (num - 1):
            return num
        elif num * num >= n and (num - 1) * (num - 1) >= n:
            num = num - 1
        else:
            num = num * 2

n = int(input('1 ~ 1,000,000 사이의 정수 입력: '))

print(f'최소 정수 : {b_search_root(n)}')
