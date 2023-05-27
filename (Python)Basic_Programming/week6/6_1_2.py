N = int(input("정수 N 입력: "))
m = int(input("전수 m 입력: "))
r = range(1, N, m)
for i in range(1, N, m):
    print(i, '')
#version1
for i in range(m, N+1, m):
    print(i, end='')

#version2
L = list(range(m, N+1, m))
for i in L:
    print(i, end='')