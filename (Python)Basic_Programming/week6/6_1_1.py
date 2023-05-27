arr = []
n = 0
while n != 999:
    n = int(input("정수를 입력하시오: 종료:999 "))
    if n == 999:
        print("999입력, 종료.")
        print(arr)
        break
    else:
        arr.append(n)
        if arr.count(n) >= 2:
            arr.remove(n)


