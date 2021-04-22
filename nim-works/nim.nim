import sequtils, strutils, strformat, algorithm, math, sugar, complex
{.warning[UnusedImport]: off.}

var n, k: int
var a = newseq[int]()



proc dfs(i:int, sum:int): bool = 
    if i == n: return sum == k

    if dfs(i+1, sum): return true 
    if dfs(i+1, sum+a[i]): return true
    return false


n = stdin.readLine.parseInt()
a = stdin.readLine.split.map(parseInt)
k = stdin.readLine.parseInt()

if dfs(0, 0): echo "Yes"
else: echo "No"
echo a