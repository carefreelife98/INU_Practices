with open('chart.txt', 'r+') as fObj:
    fObj.write('x  sin x     cos x    tan x   ')
    fObj.write('==============================')
    for i in range(0, 86, 5):
        print(f'')