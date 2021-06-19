from py2 import func

# d = {'hens' : 3, 'x' : 4}
# s = "int t = hens+2.2;"
# s = "int a=3, b=2;"

# print(d)
# func(s, d)
# print(d)
d = {'a' : 2, 'b' : 3}
s = "int c = a+b, d, h = 2*c, x=d*2;"
func(s, d)
print(d)
