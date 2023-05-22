# 1.
# dept = input('학과: ')
# name = input('이름: ')
# print('저는', dept, '에 재학 중인 ', name, '입니다.')

# 2.
# mile = input('mile: ')
# print('km:', float(mile) * 1.609344)

# 3.
print('정수 a, b, c 입력')
a = int(input('a ='))
b = int(input('b ='))
c = int(input('c ='))

print('정렬 전:', a, b, c)

if a > b:
    a, b = b, a
if b > c:
    b, c = c, b
if a > b:
    a, b = b, a
print('정렬 후:', a, b, c)
