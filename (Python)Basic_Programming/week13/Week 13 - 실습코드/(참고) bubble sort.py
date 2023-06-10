

N = input('원소의 개수: ')
k = input('회전 단계 수: ')

try:
    N = int(N)

    l = list(map(lambda x:x+1, range(N)))
    #l = sorted(l, reverse=True)
    
    if N <= 0:
        print('잘못된 입력입니다')
    else:
        for k in range(len(l)):
            for idx in range(len(l)-1, k, -1):
                if l[idx] < l[idx-1]:
                    l[idx-1], l[idx] = l[idx], l[idx-1] # swap!

        print(l)
except Exception as e:
    print(e)
    print('잘못된 입력입니다')

