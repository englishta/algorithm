# Begin Header {{{
from math import gcd, pi, cos, sin
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations, combinations_with_replacement
# }}} End Header
# _________コーディングはここから！！___________

n = int(input())
for a in range(1, 1000):
    k = n-3**a
    if k <= 0:
        print(-1)
        exit()
    for b in range(1, 1000):
        if 5**b == k:
            print(a, b)
            exit()
        if 5**b > k:
            break

