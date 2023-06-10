def perm(a, i, n):
    if i == n - 1:  # termination condition
        for i in range(n): print(a[i], end='')
        print(end=' ')
    else:
        for j in range(i, n):
            a[i], a[j] = a[j], a[i]
            perm(a, i+1, n)
            a[i], a[j] = a[j], a[i]

if __name__ == '__main__':
    s = input('문자열 입력 : ')
    N = len(s)
    l = list(s)
    perm(l, 0, N)
