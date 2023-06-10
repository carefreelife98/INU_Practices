
import random

def find_sroot_integer(low, high):
    
    while True:
        mid = (high+low) //2

        if mid == low and mid == high: # mid == low == high
            break

        verf_rst = verification(mid)
        if verf_rst: # need lower search (including 'mid' value)
            high = mid   
        else: # q^2 < N
            low = mid+1

        #print(high, low, mid)
        
    return mid

def verification(q): # q^2 >= N ?
    return q*q >= N

    
N = input('N 입력 :')

try:
    N = int(N)
    start = 1; end = 1000 # fix range! (1, 1000)
    q = find_sroot_integer(start, end)

    print(f'q = {q}')


except Exception as e:
    print(e)
    print('잘못된 입력입니다')

