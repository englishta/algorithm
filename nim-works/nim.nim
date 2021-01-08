import sequtils, strutils, strformat, algorithm, math, sugar
let inps = iterator: string {.closure.} =
  while true: (for s in stdin.readLine.split: yield s)
proc inp: int{.used.} = inps().parseInt()
template newSeqWith(y, x: int, p: untyped): untyped{.used.} =
  newSeqWith(y, newSeqWith(x, p))
{.warning[UnusedImport]: off.}

echo 2*2




