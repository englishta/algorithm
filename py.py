from py2 import func

d = {'hens' : 2, 'a' : 3, 'aa' : 4}
# s = "int x = aa*2;"
s = "int x, y=2*x;"
func(s, d)
print(d)
