def expr(s, i):
  val = term(s, i)
  while s[i] == '+' or s[i] == '-':
    op = s[i]
    i+=1
    val2 = term(s, i)
    if op == '+': val += val2
    else: val -= val2
    return val
 

def term(s, i):
  val = factor(s, i)
  while s[i] == '*' or s[i] == '/':
    op = s[i]
    i+=1
    val2 = factor(s, i)
    if op == '*': val *= val2
    else: val /= val2
    return val

def factor(s, i):
  if s[i].isdigit(): return number(s, i)
  i+=1
  ret = expr(s, i)
  i+=1
  return ret


def number(s, i):
  n = ord(s[i])
  i+=1
  while s[i].isdigit():
    n = n*10 + int(s[i])
    i+=1
  return n


def solve():
  n = int(input())
  for i in range(n):
    s = str(input())
    i = 0
    print(expr(s, i))

def Main():
  str = "1+2*6/(10-7)"
  i = 0
  print(str, " = ", expr(str, i))


	

if __name__ == "__main__":
  Main()