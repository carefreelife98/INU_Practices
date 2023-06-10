# # map
#
# a = [1, 2, 3, 4, 5]
# print(a)
#
# a = list(map(str, a))
# print(a)
#
# a = list(map(int, a))
# print(a)
#
# print(a)
#
# a = list(map(lambda x: x+1, a))

# # filter
# a = [1, 2, 3, 4, 5]
# print(a)
#
# a = list(filter(lambda x: x < 4, a))
# print(a)
#
# b = [('care', 'free', 'life'), ('free', 'life'), ('care', 'life')]
# b = list(filter(lambda x: len(x) == 2, b))
# print(b)

# # zip
# a = ['A', 'B', 'C', 'D']
# b = [4.0, 3.0, 2.0, 1.0]
#
# for ele_A, ele_B in zip(a, b):
#     print(ele_A, ele_B)
#
# c = [1, 2, 3, 4, 5]
# d = ['1', '2', '3']
# for ele_C, ele_D in zip(c, map(int, d)):
#     print(f'ele_C({ele_C}) + ele_D({ele_D}) = {ele_C + ele_D}')

# # reduce
# from functools import reduce
#
# a = ['care', 'free', 'life', '98']
# b = [20170, 27, 97]
#
# a = reduce(lambda x, y: x + y, a)
# b = reduce(lambda x, y: int((x + y) / 3), b)
# print(a, b)
# a = ['care', 'free', 'life', 98]
# for idx, element in enumerate(a):
#     print(idx, element)

# # 제곱의 평균 구하기 - map / reduce
# def mean_square(l):
#     from functools import reduce
#     l = list(map(lambda x: x * x, l))
#     print(l)
#     result = reduce(lambda x, y: x + y, l) / len(l)
#     return result
#
# def dot(l1, l2):
#     print(f'l1 : {l1} , l2: {l2}')
#     sum = 0
#     for ele_1, ele_2 in zip(l1, l2):
#         sum += ele_1 * ele_2
#     return sum
#
# if __name__ == '__main__':
#     print(f'벡터의 내적 값은 : {dot([1, 2, 3, 4], [2, 3, 4, 5])}')
#
#
#     a = [1, 2, 3, 4, 5]
#     print(f'리스트의 제곱의 평균은 {mean_square(a)} 입니다.')

# # 12_3
# fout = open('output.txt', 'w')
# for c in range(0, 51, 10):
#     f = int(c*9/5 + 32)
#     out = '섭씨 온도 : %d, 화씨 온도 : %d\n' % (c, f) fout.write(out)
# fout.close()

min(3, 2)

print(f'abs(10) = {abs(10)}')
print(f'abs(-10) = {abs(-10)}')
print(f'max(2, 3, 4, 1, 4) = {max(2, 3, 4, 1, 4)}')
print(f'max([2, 3, 5, 1, 4]) = {max([2, 3, 5, 1, 4])}')
print(f'min(2, 3, 5, 1, 4) = {min(2, 3, 5, 1, 4)}')
print(f'min([2, 3, 5, 1, 4]) = {min([2, 3, 5, 1, 4])}')
print(f'round(2.6) = {round(2.6)}')
print(f'sum([2, 3, 5, 1, 4]) = {sum([2, 3, 5, 1, 4])}')
print(f'pow(2, 10) = {pow(2, 10)}')
