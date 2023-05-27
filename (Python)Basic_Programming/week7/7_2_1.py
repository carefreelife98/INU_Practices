x = int(input('구구단 몇 단?: '))
for i in range(1, 9+1):
    print(f'{x:2} * {i:-^10} = {i * x:>2}')

