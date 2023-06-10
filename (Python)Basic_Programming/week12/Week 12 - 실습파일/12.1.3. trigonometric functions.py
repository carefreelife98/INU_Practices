import math
 
print('{0:^3}\t{1:^6}\t{2:^6}\t{3:^6}'.format('x', 'sin x', 'cos x', 'tan x'))
print('===================================')
for i in range(0, 85+1, 5):
    sinx = math.sin(math.pi * (i / 180))
    cosx = math.cos(math.pi * (i / 180))
    tanx = math.tan(math.pi * (i / 180))
    print(f"{i:>3d}\t{sinx:>6.4f}\t{cosx:>6.4f}\t{tanx:>6.4f}")
print('===================================')
