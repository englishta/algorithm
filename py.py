#Begin Header {{{
from math import gcd, pi, cos, sin, e
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations, combinations_with_replacement
# }}} End Heade
# _________コーディングはここから！！___________

s = input()
k = int(input())

if len(s)==1:
    print(k//2)
    exit()

s+=s[0]
n = len(s)
cnt = 0
a = False 
for i in range(1, n):
    if a:
        a = False
        continue
    if s[i] == s[i-1]: 
        a = True
        cnt+=1
a = False
cnt1 = 0
for i in range(1, n-1):
    if a:
        a = False
        continue
    if s[i] == s[i-1]: 
        a = True
        cnt1+=1

s+=s[1]
if s[-1]==s[-2] and s[-1]==s[-3] and s[-2]==s[-3]:
    print(cnt1*k)
    exit()


if cnt1<cnt:
    print(k*cnt1+(k-1))
else:
    print(k*cnt)
