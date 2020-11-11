#Begin Header {{{
from math import gcd, pi, cos, sin, e
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations, combinations_with_replacement
# }}} End Heade
# _________コーディングはここから！！___________
def deg(shita):
    return shita*pi/180
subans = (e**(0.25*deg(220))+1)/(e**(0.25*deg(220))-1)
print(4671*subans)

r2v = (11342*860+1795*790+15000*120)/980
print("r2v", r2v)
r1v = (11342*120+1795*190+15000*860)/980
print("r1v",)
