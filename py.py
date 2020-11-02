# Begin Header {{{
from math import gcd, pi, cos, sin
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations, combinations_with_replacement
# }}} End Heade\
# _________コーディングはここから！！___________
n = int(input())
<<<<<<< HEAD
for i in range(n):
    if 2**i > 1e9+7:
        print("Oh!!big!!")
        exit()
    print("2^", i, "=", 2**i)
=======
if n%2 == 0:
    print("White")
else:
    print("Black")

>>>>>>> test
