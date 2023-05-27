from time import time
sum = 0
N = int(input("자연수 N 입력: "))
start = time()
for i in range(1, N+1):
    sum += i*i
end = time() - start
print("합계: ", sum)
print("실행 시간:", end)