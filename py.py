#Begin Header {{{
from math import gcd, pi, cos, sin, e
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations, combinations_with_replacement
# }}} End Heade
# _________コーディングはここから！！___________

a, b, c = map(int, input().split())

sum = a+b+c
a_cnt = 100-a
b_cnt = 100-b
c_cnt = 100-c

#a
ansA = 1
ansB = 1
ansC = 1

for i in range(0, a_cnt):
    ansA*=(a+i)/(sum+i)

for i in range(0, b_cnt):
    ansB*=(b+i)/(sum+i)

for i in range(0, c_cnt):
    ansC*=(c+i)/(sum+i)

ans = a_cnt*ansA+b_cnt*ansB+c_cnt*ansC

print(ans)