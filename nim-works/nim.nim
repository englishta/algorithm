import sequtils, strutils, strformat, algorithm, math, sugar, complex
{.warning[UnusedImport]: off.}


proc f(n: int) =
    if n mod 2 == 0:
        echo "Even"
    else:
        echo "Odd"


var t = stdin.readLine.parseInt()
f(t)

    

