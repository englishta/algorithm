import sequtils, strutils, strformat, algorithm, math, sugar
let inps = iterator: string {.closure.} =
  while true: (for s in stdin.readLine.split: yield s)
proc inp: int{.used.} = inps().parseInt()
template newSeqWith(y, x: int, p: untyped): untyped{.used.} =
  newSeqWith(y, newSeqWith(x, p))
{.warning[UnusedImport]: off.}

let n: int64 = inp()
var v = newseq[int64](n+1)
for i in 1..<n+1:
  for j in countup(i, n, i):
    v[j]+=1
  
var sum: int64 = 0
for i in 1..<n+1:
  sum+=i*v[i]
echo sum











