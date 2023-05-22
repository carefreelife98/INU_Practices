a = int(input('정수 a 입력: '))
b = int(input('정수 b 입력: '))
if a != 0 and b != 0:
    if a >= 1 and b >= 1:
        print("같다")
    elif a >= 1 and b < 0:
        print("다르다")
    elif a < 0 and b >= 1:
        print("다르다")
    elif a < 0 and b < 0:
        print("같다")
else:
   print("a와 b중 0이 포함되어 있습니다")

