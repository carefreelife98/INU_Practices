
s = 'abcdefghijklmnopqrstuvwxyz '

def cipher(m, k):
    l = []
    for c in m:
        current_idx = s.find(c)
        cipher_idx = (current_idx+k)%len(s)
        cipher_char = s[cipher_idx]
        l.append(cipher_char)
    return ''.join(l)

def decipher(m, k):
    l = []
    for c in m:
        current_idx = s.find(c)
        cipher_idx = (current_idx-k)%len(s)
        cipher_char = s[cipher_idx]
        l.append(cipher_char)
    return ''.join(l)

def decipher_easy(m, k):
    return cipher(m, len(s)-k)


if __name__ == '__main__':
    m = input('평문 입력 :')
    k = int(input('k 값 입력(1~26) :'))
    
    print('암호문 : ', end='[')
    print(cipher(m, k), end='')
    print(']')
    print('복호화 된 평문 : ', end='[')
    print(decipher_easy(cipher(m, k), k), end='')
    print(']')
    
