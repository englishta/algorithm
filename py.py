from py2 import Scan1

d = {'hens' : 2, 'a' : 3, 'aa' : 4}
# s = "int x = aa*2;"
s = "int x, y=2*x, t = aa;"
Scan1(s, d)
print(d)