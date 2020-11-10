# Begin Header {{{
from math import gcd, pi, cos, sin
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations, combinations_with_replacement
# }}} End Heade
# _________コーディングはここから！！___________

s = [0, 1, 2, 3, 4, 5, 6]
even = s[::2]
odd = s[1::2]
print(even)
print(odd)
print(s[::-1])