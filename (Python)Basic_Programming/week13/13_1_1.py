import random
def merge(ls1, ls2):
    s = set()
    for i in range(len(ls1)):
        s.add(ls1.pop())
    for j in range(len(ls2)):
        s.add(ls2.pop())

    result = []
    for x in range(len(s)):
        result.append(s.pop())

    result.sort()

    return result

a = int(input('첫번째 원소 개수 입력:'))
b = int(input('두번째 원소 개수 입력:'))

l1 = []
l2 = []
for i in range(a):
    l1.append(random.randint(1, 100))
print(l1)
for i in range(b):
    l2.append(random.randint(1, 100))
print(l2)

print(merge(l1, l2))


# 정답
def merge_solution(l1, l2):
    i1 = 0; i2 = 0;
    len_l1 = len(l1); len_l2 = len(l2)

    merged = []

    while i1 < len_l1 or i2 < len_l2:
        # the case whe only a list has ....
        if i1 >= len_l1 or i2 >= len_l2:
            merged += l1[i1:] + l2[i2:]
            break
        if l1[i1] <= l2[i2]:
            merged.append(l1[i1])
            i1 += 1
        else:
            merged.append(l2[i2])
            i2 += 1
    return merged