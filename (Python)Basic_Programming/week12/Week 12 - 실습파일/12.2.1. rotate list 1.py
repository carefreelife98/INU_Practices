

N = input('원소의 개수: ')
k = input('회전 단계 수: ')

try:
    N = int(N)
    k = int(k)

    l = list(map(lambda x:x+1, range(N)))
    len_l = len(l)
    rst =[0]*len_l
    
    if N <= 0 or k <= 0:
        print('잘못된 입력입니다')
    else:
        for idx, item in enumerate(l):
            rst[(idx+k)%len_l] = item

        print(rst)
except Exception as e:
    print(e)
    print('잘못된 입력입니다')

