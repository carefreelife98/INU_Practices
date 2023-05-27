def palindrom():
    a = str(input('문자열을 입력하시오: '))
    b = f'{a}'
    for i in range(int(len(b)/2)):
        if b[i] == b[len(b) - i - 1]:
            return 1
        else:
            return 0


def isPalindromWithoutSpace(s):
    s = s.lower()
    mid_index = int(len(s)/2)
    for i in range(mid_index):
        if s[i] != s[-i-1]:
            return False
    return True
