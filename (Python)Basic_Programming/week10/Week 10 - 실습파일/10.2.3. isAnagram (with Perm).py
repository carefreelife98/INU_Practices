def isAnagram(a, b):
    len_a = len(a)
    len_b = len(b)

    if len_a != len_b:
        return False

    l = list(a)

    return checkPerm(b, l, 0, len_a)

def checkPerm(b, a, i, n):
    if i == n - 1:
        return b == ''.join(a)
    else:
        for j in range(i, n):
            a[i], a[j] = a[j], a[i]
            if checkPerm(b, a, i+1, n):
                return True
            a[i], a[j] = a[j], a[i]
            
        return False

if __name__ == '__main__':
    s1 = input('첫 번째 문자열 입력 : ')
    s2 = input('두 번째 문자열 입력 : ')
    if isAnagram(s1, s2):
        print('어구전철입니다.')
    else:
        print('어구전철이 아닙니다.')
