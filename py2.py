import re
# s = "void f(int x, int y){"
# j = "int a=(2+3);"
# t = "aa__bb__cc__dd"
# k = "aa"

# j = re.sub(r"(int|double|void) .*\((int|double|void).*\)", "Func", j)
# s = re.sub(r"(int|double|void) .*\((int|double|void).*\)", "Func", s)
# t = re.sub(r"(aa|bb|cc)", "xx", t)
# print(j)
# print(s)

# s = 'if(n%2 == 0) {'
# s = "aaabb{b;"
s = 'for (int i=0; i<=n; i++)       {'
s = s.replace(" ", "")
s = re.sub(r"(if|for)\s*\(.*\)\s*[^\{;]+", "(if|for)() do", s)
# s = re.sub(r"[^\{;]", "_", s)
print(s)
