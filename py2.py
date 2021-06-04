import re
s = "void f(int x, int y){"
j = "int a=(2+3);"
t = "aa__bb__cc__dd"
k = "aa"

j = re.sub(r"(int|double|void) .*\((int|double|void).*\)", "Func", j)
s = re.sub(r"(int|double|void) .*\((int|double|void).*\)", "Func", s)
t = re.sub(r"(aa|bb|cc)", "xx", t)
print(j)
print(s)
