h, w = map(int, input().split())
dx = [1, 0, 0, -1]
dy = [0, 1, -1, 0]
s = [['.']*w]*h
for i in range(h):
    t = input()
    for j in range(w):
        s[i][j] = t[j]


ans = 0
for i in range(h):
    for j in range(w):
        if s[i][j] == '.':
            for k in range(4):
                if i+dx[k]<0 or i+dx[k] >=w or j+dy[k]<0 or j+dy[k] >= h:
                    continue
                else:
                    if s[i+dx[k]][j+dy[k]]  == '.':
                        ans+=1
        s[i][j]='#'
print(ans)
        