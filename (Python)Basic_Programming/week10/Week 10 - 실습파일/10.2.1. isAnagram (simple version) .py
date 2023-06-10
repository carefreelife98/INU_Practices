def isAnagramSorted(a, b):
    
    a = ''.join(c for c in a if c.isalnum()).lower()
    b = ''.join(c for c in b if c.isalnum()).lower()
    
    len_a = len(a)
    len_b = len(b)

    if len_a != len_b:
        return False

    sort_a = list(a); sort_a.sort() # in-place sort!
    sort_b = list(b); sort_b.sort()
    #sort_a = sorted(a)         #return sorted list
    #sort_b = sorted(b)

    return sort_a == sort_b

def isAnagramCounter(a, b):
    from collections import Counter
    
    a = ''.join(c for c in a if c.isalnum()).lower()
    b = ''.join(c for c in b if c.isalnum()).lower()

    return Counter(a) == Counter(b)


if __name__ == '__main__':
    s1 = input('첫 번째 문자열 입력 : ')
    s2 = input('두 번째 문자열 입력 : ')
    print('V1', end='-')
    if isAnagramSorted(s1, s2):
        print('어구전철입니다.')
    else:
        print('어구전철이 아닙니다.')

        
    print('V2', end='-')
    if isAnagramCounter(s1, s2):
        print('어구전철입니다.')
    else:
        print('어구전철이 아닙니다.')
