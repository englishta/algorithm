from py2 import Calculate
import re


d = {}
s = "int var = (8*4)/(3+5);"
var = ""
s = s.replace(" ", "").replace(";", "")
for e in re.sub(r"(int|double)", "", s):
    if e == '=': break
    var+=e
d[var] = Calculate(re.sub(r"(int|double).+=", '', s))

print(d)