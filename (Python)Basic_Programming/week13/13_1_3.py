import random
def print_rising(n):
    ls = []
    s = set()

    while len(ls) != n:
        rand = random.randint(1, 100)
        if rand in s:
            continue
        ls.append(rand)
        s.add(rand)

    print(ls)

    if len(ls) <= 1:
        return ls

    # initial settings
    len_ls = len(ls)
    prev_item = ls[0]
    runs = []
    run = [prev_item]
    i = 1

    while i < len_ls:
        # 이전 아이템이 더 큰 경우
        if prev_item > ls[i]:
            # 현재까지 저장
            runs.append(run)
            # 리스트 새로 시작.
            run = [ls[i]]
        else:
            run.append(ls[i])
        prev_item = ls[i]
        i += 1
    # add last run
    runs.append(run)

    return runs

def natural_merge_sort(l):

    temp = []
    i = 0
    while len(temp) != 1:
        if i == len(l) - 1:
            for i in range(len(l[i])):
                temp.append(l[i])
        else:
            for i in range(len(l[i])):
                temp.append(l[i].pop())

n = int(input('n 입력'))
print(natural_merge_sort(print_rising(n)))