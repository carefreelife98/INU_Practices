# def find(tgt, pattern, start=0):
#     if pattern in tgt:
#         i = start
#         for i in tgt:
#             if pattern == i:
#                 return i
#
#
#         return
#     else:
#         return -1

# def find(tgt, pattern, start=0):
#     if start != 0:
#
#         rst = find(tgt[start:], pattern)
#         if rst == -1:
#             return rst
#         return start + rst
#
#     len_pattern = len(pattern)
#     for i in range(len(tgt)):
#         substr = tgt[i:i+len_pattern]
#     if substr == pattern:
#         return i
#     else:
#         return -1

def find(tgt, pattern, start=0):
    if start != 0:

        rst = find(tgt[start:], pattern)
        if rst == -1:
            return rst
        return start + rst

    len_pattern = len(pattern)
    for i in range(len(tgt)):
        substr = tgt[i:i + len_pattern]
    if substr == pattern:
        return i
    else:
        return -1

a = input("문자열 입력: ")
b = input("태펀 입력")

idx = find(a, b)

while idx > -1:
    idx = find()

