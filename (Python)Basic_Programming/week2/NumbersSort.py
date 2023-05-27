# dept = input('학과: ')
# name = input('이름: ')
# print('저는 ' + dept + '에 재학 중인 ' + name + '입니다.')

# logic = 1.609344;
# mile = input('마일= ')
# mile = int(mile)
# print(mile, '마일은 ', mile*logic, ' 킬로미터 입니다')

print('세 개의 정수 입력')
a = input()
b = input()
c = input()
# a, b, c = input()

rs = [a, b, c]

# print('숫자 리스트 정렬: ')
# list_num = [a, b, c]
# list_num.sort()
# print(list_num)

# if a > b:
#     (a, b) = (b, a)
#
# if b > c:
#     (b, c) = (c, b)
#
# if a > b:
#     (a, b) = (b, a)
# print(a, b, c)

i = 0

for i in range(i < 3):
    if rs[i] > rs[i+1]:
        rs[i], rs[i+1] = rs[i+1], rs[i]
    i+1

print(a, b, c)


