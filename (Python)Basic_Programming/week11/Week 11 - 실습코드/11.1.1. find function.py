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
    print(find("abcde", "f"))
    print(find("abcde", "a"))
    print(find("abcde", "a", 1))
    print(find("abcde", "c", 2))
    print(find("abcde", "c", 3))
            
