from math import gcd, pi, cos, sin, tan, e
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations, combinations_with_replacement

n = int(input())
t=n*n
s=(n-1)*(n-1)
print(t/s/2 if n%2==0 else 2*t/s)
