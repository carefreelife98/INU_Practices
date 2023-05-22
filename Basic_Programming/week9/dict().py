# # 사전 자료형의 정의
# carefreelife = dict()
# carefreelife['care'] = 75
# carefreelife['free'] = 2
# carefreelife['life'] = 23
# carefreelife[True] = 'good' # key값 간의 자료형이 달라도 되며 어떠한 자료형도 사용 가능.
#
# programming = dict()
# programming[1] = 'learn'
# # key 값으로 dict() 자료형도 사용 가능. 다중 dict() 자료형 사용이 가능해 보인다.
# carefreelife[programming[1]] = 'do your best'
#
# print(carefreelife)
# print(carefreelife['free'])
# print(carefreelife[1]) # 1 == True로 인식하여 반환.
#
# # 사전 자료형의 사용 1
# carefreelife['care'] = carefreelife['care'] - 70 # 데이터 수정
# carefreelife['life'] = carefreelife['life'] + 70 # 데이터 수정
# print(carefreelife)
#
# # 다른 사전 자료형과의 연산
# programming[0] = carefreelife[True] + programming[1]
# if carefreelife[True] != programming[0]:
#     print(carefreelife[True], 'is not same to', programming[0])
#
# # 사전 자료형의 사용 2
# carefreelife = carefreelife['care'] + carefreelife['free'] + carefreelife['life']
# print('My life =', carefreelife)


# # 사전 자료형의 자료 존재 여부 검사
# counts = dict()
# names = ['care', 'free', 'life', 'free']
# for name in names:
#     if name not in counts:
#         counts[name] = 1
#     else:
#         counts[name] = counts[name] + 1
# print('초기 counts: ', counts)
#
# # 사전 자료형 관련 내장 메소드의 사용
# # get(key) : key에 대응하는 value를 반환.
# free = counts.get('free')
# print('get key(free) : ', free) # 2
#
# # items() : (key, value)를 하나의 요소로 정의하여 전체 요소를 반환.
# items = counts.items()
# print('items() : ', items) # dict_items([('care', 1), ('free', 2), ('life', 1)])
#
# # keys() : 사전 자료형의 모든 key들을 반환.
# keys = counts.keys()
# print('keys : ', keys) # dict_keys(['care', 'free', 'life'])
#
# # values() : 사전 자료형의 모든 value들을 반환.
# values = counts.values()
# print('values : ', values) # dict_values([1, 2, 1])
#
# # pop(key) : 주어진 key에 대한 value를 반환하고 해당 key 값을 제거.
# # Stack에서의 pop()과 같다.
# pop = counts.pop('free')
# print('pop : ', pop, ' after pop : ', items) # 2, dict_items([('care', 1), ('life', 1)])
#
# # 주어진 새로운 사전 자료의 key, value 값을 추가.
# # 만약 기존 데이터와 동일한 key 값을 가진다면 수정.
# new = dict() # 새로운 사전 자료형 new 선언
# new['free'] = 2 # new에 {key = free, value = 2}데이터 삽입
# new['care'] = 3
# # 기존 사전 자료형 counts에 new 사전 자료형에 있는 데이터를 추가(free, 2) 및 수정(care, 3)
# counts.update(new)
# print('after update : ', counts.items()) # update()된 counts 출력

# # Counter
# from collections import Counter
# a = Counter('Programming for Carefree Life !')
# print(a)


# Concatenation
c = ord('A') - 1 # A에 해당하는 아스키 코드의 숫자로 변환 후 -1
s = '' # 빈 문자열 생성
for i in range(26): # 영대문자의 개수
    c += 1  # A의 아스키코드 부터 시작.
    s += chr(c)  # c에 담겨 있는 아스키 코드를 문자로 변환하여 빈 문자열 s에 추가.
print(s) # 출력



