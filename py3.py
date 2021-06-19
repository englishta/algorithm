import re
a = 'a_'
if bool(re.search(r'[_]', a)): print("Yes")
else: print("No")