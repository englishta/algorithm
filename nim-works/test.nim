{.warning[UnusedImport]: off.}
import os
block:
  var f : File = open("a.c", FileMode.fmRead)
  defer :
    close(f)
    echo "closed"
  while f.endOfFile == false:
    echo f.readLine()