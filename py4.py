
n = int(input())
t = input()

K =10**10
#110 110 110 110 110 110 110
# 1011
#10000000000
ans = -1
if t=='11' or t=='10' or t=='110' or t == '0':
    ans = K
elif t == '01':
    ans = (K-1)
elif t == '1':
    ans = (2*K)
elif t[0] == '0':
    if (n-1)%3 == 0:
        ans = (K-((n-1)//3))
    else:
        ans = (K-((n-1)//3+1))
elif t[0:2] == '11':
    if (n-3)%3 == 0:
        ans = (K-((n-3)//3))
    else:
        ans = (K-((n-3)//3+1))
elif t[0:2] == '10':
    if (n-2)%3 == 0:
        ans = (K-((n-2)//3))
    else:
        ans = (K-((n-2)//3+1))
print(int(ans))