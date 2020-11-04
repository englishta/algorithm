import strutils
let read = iterator: string {.closure.} =
  while true:
    for s in stdin.readLine.split:
      yield s
proc scan() : int =read().parseInt
proc scanf() : float =read().parseFloat

var sum = 0
let N = scan() 

for i in 0..<N:
    var a, b = scan() 
    sum += (a+b)*(b-a+1)div 2
echo sum
