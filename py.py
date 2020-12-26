#Begin Header {{{
import sys
input = sys.stdin.readline
from math import gcd, pi, cos, sin, e
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations, combinations_with_replacement
# }}} End Heade
# _________コーディングはここから！！___________

a, b, c = map(int, input().split())
a_, b_, c_ = map(int, input().split())
s1 = (a//a_) * (b//b_) * (c//c_)
s2 = (a//a_) * (b//c_) * (c//b_)
s3 = (a//b_) * (b//a_) * (c//c_)
s4 = (a//b_) * (b//c_) * (c//a_)
s5 = (a//c_) * (b//a_) * (c//b_)
s6 = (a//c_) * (b//b_) * (c//a_)

print(max(s1, s2, s3, s4, s5, s6))

