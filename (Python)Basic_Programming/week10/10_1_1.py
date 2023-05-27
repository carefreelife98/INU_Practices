# # 10_1_1. 문자열 치환
# # 사전 자료형을 사용하지 않고 영문자 a부터 z까지를 1~26으로, A부터 Z까지를 27~52로 변환.
# # 변환된 정수 값을 반환해주는 함수 convertCharacter1(c) 작성
#
# def convert_character1(c):
#     try:
#         if (65 <= ord(c) <= 90) or (97 <= ord(c) <= 122):
#             # 대문자
#             if ord(c) <= 90:
#                 # 대문자의 아스키 코드는 65(A) ~
#                 return ord(c) - 38
#             # 소문자
#             else:
#                 # 소문자 a의 아스키 코드는 97(a) ~
#                 return ord(c) - 96
#     except:
#         print('잘못된 입력입니다.')
#
# x = ''
# while x != '=':
#     x = str(input('소문자 a 부터 대문자 Z중 하나를 입력하시오: '))
#     print(convert_character1(x))
#
# def convert_character1_(c):
#     i = ord(c)
#
#     if ord('a') <= i <= ord('z'):
#         return i-ord('a') + 1
#     elif ord('A') <= i <= ord('Z'):
#         return i-ord('A') +27 #range 27~52
#
#     return -1  #error
#
# def convert_character2(c):
#     d = {}
#     for i in range(26):
#         d[chr(ord('a')+i)] = i+1
#
#     for character in 'ABCDEFGHIJKLMNOPQRSTUVWXYZ':
#         d[character] = ord(character)-ord('A')+27
#
#     return d[c]
#
# if __name__ == '__main__':
#     print()
#
#
#
# # 10_1_2,3. 시저 암호화 및 복호화 함수 작성
# # 영문 소문자로 이루어진 문자열과 k 값을 입력 받아 암호문으로 변환하는 프로그램 작성.
# # 문자열의 각 문자에 대응하는 ASCII코드 + k 의 ASSCII 코드로 문자열의 전체 문자를 변환.
# # 암호화 전 기존 문자열로 변환하는 복호화 함수 작성.
#
# # 시저 암호화 함수
# def cipher(string, k):
#     # 암호화 된 문자열이 저장될 빈 문자열 rs 생성
#     rs = ''
#     try:
#         # string 이 문자열 인지, k 의 범위가 맞는지 검사
#         if (str(type(string)) == "<class 'str'>") and (1 <= k <= 26):
#             # 문자열 내 전체 문자 검사
#             for char in string:
#                 # 기존 문자의 아스키 코드 + k 된 아스키 코드를 구한다.
#                 # 해당 아스키 코드에 대응하는 문자로 변환하여 빈 문자열 rs에 저장.
#                 rs += chr(ord(char) + k)
#             return rs
#     except:
#         print('잘못된 입력입니다.')
#
# # 복호화 함수
# def decipher(string, k):
#     # 복호화 된 문자열이 저장될 빈 문자열 rs 생성
#     rs = ''
#     try:
#         # string 이 문자열 인지, k 의 범위가 맞는지 검사
#         if (str(type(string)) == "<class 'str'>") and (1 <= k <= 26):
#             # 문자열 내 전체 문자 검사
#             for char in string:
#                 # 암호화 된 문자의 아스키 코드 - k 된 아스키 코드를 구한다.
#                 # 해당 아스키 코드에 대응하는 문자로 변환하여 빈 문자열 rs에 저장.
#                 rs += chr(ord(char) - k)
#             return rs
#     except:
#         print('잘못된 입력입니다.')
#
# # 메인 함수
# m = ''
# while m != '=':
#     m = str(input('문자열 입력: '))
#     k = int(input('1~26 사이의 정수 k 입력: '))
#
#     # 암호화
#     cip = cipher(m, k)
#
#     print('시저 암호화 된 문자열:', '[' + cip + ']')
#     print('복호화 된 문자열:', '[' + decipher(cip, k) + ']')
#
# # 10_2_2. 순열 출력 함수
# # an = {n!개 나온다. 출력은 a[i] + a[i]를 제외한 나머지 중 하나 + a[i]를 제외한 나머지 중 하나를 제외한 나머지 중 하나..}
# # 일반 재귀 사용
# def permutation(string):
#     list(string)
#     n = len(string) # n! 번 실행
#     if n > 0:
#         # print(string[n])
#         permutation(string)
#     else:
#         return 0
#
# def perm(a):
#     string_list = list(a)
#     length = len(a)
#     if length == 1:
#         return [a]
#     else:
#         result = ''
#         for i in string_list:
#             b = string_list.copy()
#             b.remove(i)
#             b.sort()
#             for j in perm(b):
#                 j.insert(0, i)
#         return result
#
# a = "lk67h"
# print(perm(a))
#
# input_list = "lk67h"
# input_list = list(input_list)
# used = [0]*len(input_list)
#
# print(used)
#
# def perm(arr, n):
#     if n == len(input_list):
#         print(arr)
#         return
#     for i in range(len(input_list)):
#         if not used[i]:
#             used[i] = 1
#             arr.append(input_list[i])
#             perm(arr, n+1)
#             arr.pop()
#             used[i] = 0
#
# perm([], 0)


# # 어구전철(Anagram) 여부 확인 함수(1)
# # - 두 개의 문자열을 입력 받아 어구전철인지 여부를 출력하는 프로그램 작성
# #   - V1) list의 내장 메소드 "sort" 사용
# def is_anagram_v1(str1, str2):
#     x = str1
#     y = str2
#     if len(x) == len(y):
#         x = ''.join(c for c in x if c.isalnum()).lower()
#         y = ''.join(c for c in y if c.isalnum()).lower()
#
#         x = list(x)
#         x.sort()
#         y = list(y)
#         y.sort()
#         for i in range(len(x)):
#             if x[i] == y[i]:
#                 i += 1
#             else:
#                 return False
#                 break
#         return True
#
#
# a = input('첫 번째 문자열 입력: ')
# b = input('두 번째 문자열 입력: ')
# if is_anagram_v1(a, b):
#     print('어구전철 입니다.')
# else:
#     print('어구전철이 아닙니다.')


# # 10_2_1. 어구전철(Anagram) 여부 확인 함수(2)
# # - 두 개의 문자열을 입력 받아 어구전철인지 여부를 출력하는 프로그램 작성
# #   - V2) Counter 모듈 사용
# def is_anagram_v2(str1, str2):
#     from collections import Counter
#
#     a = Counter(str1).copy()
#     b = Counter(str2).copy()
#
#     print(a.items())
#     print(b.items())
#
#     if a.items() == b.items():
#         return True
#     else:
#         return False
#
# a = str(input('문자열 A 입력: '))
# b = str(input('문자열 B 입력: '))
# if is_anagram_v2(a, b):
#     print('어구 전철 입니다.')
# else:
#     print('어구 전철이 아닙니다.')

# input_list = "lk67h"
# input_list = list(input_list)
# used = [0]*len(input_list)
#
# print(used)
#
# def perm(arr, n):
#     if n == len(input_list):
#         print(arr)
#         return
#     for i in range(len(input_list)):
#         if not used[i]:
#             used[i] = 1
#             arr.append(input_list[i])
#             perm(arr, n+1)
#             arr.pop()
#             used[i] = 0
#
# perm([], 0)


# 알고리즘
# 문자열 길이 중 각 자리에 어떤 것이 출력될지 결정하여 출력
# 끝까지(n-1까지) 결정이 되었으면 마지막 자리에는 n만큼 넣은 후 출력. (종료 조건)

# a == 입력 문자열
# n == 입력 문자열의 길이
# i == 현재 자리
def perm(a, i, n):
    if i == n-1:
        for i in range(n):
            print(a[i], end='')
        print(end='\n')
    else:
        for j in range(i, n):
            a[i], a[j] = a[j], a[i]
            perm(a, i+1, n)
            a[i], a[j] = a[j], a[i]

string = input('문자열 입력: ')
length = len(string)
listed = list(string)
perm(listed, 0, length)


