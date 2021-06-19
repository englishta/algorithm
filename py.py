from py2 import func

d = {'hens' : 2, 'b' : 3}
s = "int x = hens*2+3, t = x*x, n"
func(s, d)
print(d)
