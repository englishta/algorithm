from py2 import func

d = {'hens' : 3, 'x' : 4}

s = "int t = (hens*x)/(2-hens+5);"

print(d)
func(s, d)
print(d)