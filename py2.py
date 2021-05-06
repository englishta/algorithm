from collections import deque

s = input()
n = len(s)
dq = deque()
rev = False
for i in range(n):
    if s[i] == 'R':
        flag = not flag 
    elif not dq: 
        dq.append(s[i])
    elif flag:
        if dq[-1] == s[i]:
            dq.pop()
        else:
            dq.append(s[i])

    else:
        if dq[0] == s[i]:
            dq.popleft()
        else:
            dq.appendleft(s[i])

if not flag:
    s = reversed(s)

print("".join(s))
    