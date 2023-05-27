N = int(input('자연수 입력: '))
i = int(1)

while i <= N:
    if i % 2 != 0:
        print(i)
    i = i + 1

print('For 문 시작')
for i in range(1, N):
    if i % 2 != 0:
        print(i)
