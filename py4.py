
n = int(input())
t = input()

K = 1e10
ans = -1

if t[0] == 0:
    if (n-1)%3 == 0:
        ans = K-((n-1)//3)
    else:
        ans = K-((n-1)//3+1)
elif t[0:2] == '11':
    if (n-2)%3 == 0:
        ans = K-((n-2)//3)
    else:
        ans = K-((n-2)//3+1)
elif t[0:2] == '10':
    if (n-3)%3 == 0:
        ans = K-((n-3)//3)
    else:
        ans = K-((n-3)//3+1)
print(int(ans))
    