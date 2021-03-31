import sequtils, strutils, strformat, algorithm, math, sugar, complex
# let inps = iterator: string {.closure.} =
#   while true: (for s in stdin.readLine.split: yield s)
# proc inp: int{.used.} = inps().parseInt()
# template newSeqWith(y, x: int, p: untyped): untyped{.used.} =
#   newSeqWith(y, newSeqWith(x, p))
{.warning[UnusedImport]: off.}

let 
    n = stdin.readLine.parseInt()
    A = stdin.readLine.split.map(parseInt)
var ans:int64 = 10000000000000000

for bit in 0..<(1 shl (n-1)):
    # var vec = newSeq[int]()
    var xorSum:int64 = 0
    var orSum:int64 = A[0]
    for i in 0..<(n-1):
        if(bit and (1 shl i)) != 0:
            xorSum = (xorSum xor orSum)
            orSum = A[i+1]
            if i == n-2: xorSum=(xorSum xor A[n-1])
        else:
            orSum=(orSum or A[i+1])
            if i == n-2: xorSum=(xorsum xor orSum)
    if xorSum<ans: ans = xorSum

if n == 1: echo A[0]
else: echo ans


