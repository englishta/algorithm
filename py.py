import re
f = open("a.c", 'r', encoding='UTF-8')
data = f.read()
list = data.split('\n')
rev = []
coment_out = False

for i in range(len(list)):

    list[i] = re.sub(r'/\*.*\*/', "", list[i]) # /*～*/を削除
    list[i] = re.sub(r'//.*', "", list[i]) # //～を削除
    s = re.sub(r'/\*.*', "", list[i]) #/*～を削除
    s = re.sub(r'.*\*/', "", s) #～*/を削除
    s = s.rstrip().lstrip() # 先頭と末尾の空白文字を削除
    end = len(s)-1

    if list[i].count("*/"): coment_out = False
    if s != "" and s != "#include<stdio.h>" and not coment_out:
        if s[end] != ';' and s[end] !='{' and s[end] !='}' and s[:3] != "for" and s[:2] != "if":
            rev.append(str(i+1)+"行目：セミコロンなし")
        if s.count("　"):
            rev.append(str(i+1)+"行目:全角スペース")
        if (s[:3] == "for" or s[:2] == "if") and s[end] != '{':
            rev.append(str(i+1)+"行目:'{'なし")
    if list[i].count("/*"): coment_out = True

if not len(rev):
    print("問題ありません")
else:
    print("----TypeError----\n")
    for x in rev:
        print(x)

f.close()