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

    # temp = list()
    # for i in range(0, len(ls)):
    #     if ls[i] < ls[i + 1]:
    #         temp.append(ls[i])
    #         if ls[i+1] > ls[i + 2]:
    #             temp.append(ls[i+1])
    #     else:
    #         print(temp)
    #         temp.clear()

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


n = int(input('리스트 원소 개수 입력:'))
print(print_rising(n))

