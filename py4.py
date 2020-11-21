n = int(input())
s = input()

t = ""
    
for i in range(len(s)):
    t+=s[i]
    if len(t)>=3 and t[-3:] == 'fox':
        t = t[:-3]

print(len(t))    

    
        
    