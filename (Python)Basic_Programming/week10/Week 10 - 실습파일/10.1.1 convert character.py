def convertCharacter1(c):
    i = ord(c)

    if ord('a') <= i <= ord('z'):
        return i-ord('a')+1   # 'a' => ord('a')-ord('a')+1 = 97-97+1 = 1
    elif ord('A') <= i <= ord('Z'):
        return i-ord('A')+27  # range 27 ~ 52

    return -1 # error

def convertCharacter2(c):
    d = {}

    for i in range(26):     #'abcdef...z'
        d[chr(ord('a')+i)] = i+1
        
    for character in 'ABCDEFGHIJKLMNOPQRSTUVWXYZ':
        d[character] = ord(character)-ord('A')+27

    return d[c]

if __name__ == '__main__':
    print(convertCharacter1('a'))
    print(convertCharacter1('z'))
    print(convertCharacter1('A'))
    print(convertCharacter1('Z'))
    
    print(convertCharacter2('a'))
    print(convertCharacter2('z'))
    print(convertCharacter2('A'))
    print(convertCharacter2('Z'))
    
