
s = input()
n = len(s)
if s == 'keyence':
    print("YES")
    exit()

for i in range(n):
    for k in range(i+1, n):
        new = s[0:i]+s[k:n]
        if new == 'keyence':
            print("YES")
            exit()
print("NO")
