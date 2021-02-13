from math import gcd, pi, cos, sin, tan, e
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations, combinations_with_replacement

L, R = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
ca = Counter(a)
cb = Counter(b)
c = ca&cb
ans = 0
for i in c:
    ans+=c[i]
print(ans)