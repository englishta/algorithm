import re
s = "if(a == 2) print(3) /*こんにちは，*/"
k = "aaaaaaaaa*/ for i in range(n)"
t = re.sub(r'/\*.*\*/', "", s)
k = re.sub(r'.*\*/', "", k)
print(k)
# print(t)