# 리스트 회전 (1)

# enumerate 사용하기
def list_controller(n, k):
    l = []
    for i in range(1, n+1, 1):
        l.append(i)
    print(f'처음 list: {l}')
    for i in range(k):
        l.append(l.pop(n-1))
    print(f'결과: {l}')

a = int(input('입력: '))
k = int(input('입력: '))

list_controller(a, k)