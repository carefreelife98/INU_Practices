def isPalindromWithoutSpace(s):
    s = s.lower()
    mid_index = int(len(s)/2)
    for i in range(mid_index):
        if s[i] != s[-i-1]:
            return False
    return True

def palindrom2(s):
    # s = s.split(' ', ',', '!', '?', '"')
    s = s.split(',')
    s = s.split('!')
    s = s.split('?')
    s = s.split('"')

    print(s)
    if isPalindromWithoutSpace(s):
        print('회문 입니다')
    else:
        print('회문이 아닙니다.')


s = str(input('문자열을 입력하시오: '))
palindrom2(s)

#사진 찍어 놓은 것 확인 할 것