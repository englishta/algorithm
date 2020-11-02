a, b, c = map(int, input().split())
array = []
mod = 998244353
for i in range(1, b+1):
    for j in range(1, c+1):
        array.append(i*j)

ans = 0
for k in range(1, a+1):
    for i in range(len(array)):
        ans+=k*array[i]
        ans%=mod
print(ans)