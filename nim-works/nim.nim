import sequtils, strutils, strformat, algorithm, math, sugar
# let inps = iterator: string {.closure.} =
#   while true: (for s in stdin.readLine.split: yield s)
# proc inp: int{.used.} = inps().parseInt()
# template newSeqWith(y, x: int, p: untyped): untyped{.used.} =
#   newSeqWith(y, newSeqWith(x, p))
{.warning[UnusedImport]: off.}


# let s = stdin.readLine
# echo s[1..2] & s[0]

var
  h, w, x, y, ans: int

(h, w, x, y) = stdin.readLine.split.map(parseInt)
let s = (0..<h).mapIt(stdin.readLine)

x-=1
y-=1
ans = 0

if s[x][y]=='.': ans+=1

for j in y+1..<w:
  if s[x][j]=='#': break
  else: ans+=1

for j in 1..y:
  if s[x][y-j]=='#': break
  else: ans+=1

for i in x+1..<h:
  if s[i][y]=='#': break
  else: ans+=1

for i in 1..x:
  if s[x-i][y]=='#': break
  else: ans+=1

echo ans

