

def find(tgt, pattn, start=0):
    if start != 0:
        rst = find(tgt[start:], pattn)
        if rst == -1:
            return rst
        return start+rst

    len_pattn = len(pattn)
    for i in range(len(tgt)):
        substr = tgt[i:i+len_pattn]

        if substr == pattn:
            return i

    return -1


if __name__ == '__main__':
    tgt = input('텍스트 :')
    pattn = input('패턴 입력 :')

    idx = find(tgt, pattn)

    while idx > -1:
        print(f'패턴을 발견한 위치 : {idx:3d}')
        idx = find(tgt, pattn, idx+1)

    print('문자열 탐색 완료.')
