# Begin Header {{{
from math import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations, combinations_with_replacement
# }}} End Header
# _________コーディングはここから！！___________
n, h = map(int, input().split())
A = list(map(int, input().split()))

ok = False
for x in A:
    if x%h == 0:
        ok = True
if ok:
    print("YES")
else:
    print("NO")
