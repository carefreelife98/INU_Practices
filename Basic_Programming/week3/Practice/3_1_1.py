N = int(input('자연수 입력 :'))
i = int(1)
s = int(0)
while i <= N:
    print(i)
    s += i
    i = i + 1
print('합계: ')
print(s)

print("For 문 시작 ")
s = 0
for i in range(1, N+1):
    print(i)
    s += i
    i = i + 1
print('합계: ')
print(s)