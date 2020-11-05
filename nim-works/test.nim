import strutils
let read = iterator: string {.closure.} =
  while true:
    for s in stdin.readLine.split:
      yield s
proc scan() : int =read().parseInt
#proc scanf() : float =read().parseFloat
#-----------------------------------------------------------------------------------#
var
  n = scan()
  x = newseq[int](n)
  y = newseq[int](n)

for i in 0..<n:
  (x[i], y[i]) = (scan(), scan())

for i in 0..<n:
  for j in i+1..<n:
    for k in j+1..<n:
      let
        x2 = x[j]-x[i]
        y2 = y[j]-y[i] 
        x3 = x[k]-x[i]
        y3 = y[k]-y[i] 
      if (x2*y3 == x3*y2):
          echo "Yes"
          quit()
echo "No"