n, h = map(int, input().split())
A = list(map(int, input().split()))

ok = False
for x in A:
    if x%h == 0:
        ok = True
if ok:
    print("YES")
else:
    print("NO")