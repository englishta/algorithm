# Begin Header {{{
from math import gcd, pi, cos, sin
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations, combinations_with_replacement
# }}} End Heade\
# _________コーディングはここから！！___________
n = int(input())
for i in range(n):
    if i%2 == 0:
        print(i)