from py2 import func

d = {'hens' : 3, 'x' : 4}
s = "double t = (hens*x)/(hens+2);"

print(d)
func(s, d)
print(d)