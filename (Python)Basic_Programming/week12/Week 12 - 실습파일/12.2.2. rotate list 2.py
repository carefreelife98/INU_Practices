

N = input('원소의 개수: ')
k = input('회전 단계 수: ')

try:
    N = int(N)
    k = int(k)

    l = list(map(lambda x:x+1, range(N)))
    
    if N <= 0 or k <= 0:
        print('잘못된 입력입니다')
    else:
        while k > 0:
            for idx in range(len(l)-1, 0, -1):
                l[idx-1], l[idx] = l[idx], l[idx-1] # swap!
            
            k -= 1

        print(l)
except Exception as e:
    print(e)
    print('잘못된 입력입니다')

