import sequtils, strutils, strformat, algorithm, math, sugar, complex
{.warning[UnusedImport]: off.}

type
    Matrix[T; M, N: static[int]] = array[1..M, array[1..N, T]]

proc `+`[T, I, J](a: Matrix[T, I, J], b: T): Matrix[T, I, J]=
    var c: Matrix[T, I, J]
    for i in 1..I:
        for j in 1..J:
            c[i][j] = a[i][j]+b
    result = c

proc `-`[T, I, J](a: Matrix[T, I, J], b: T): Matrix[T, I, J]=
    result = a+(-b)
    
proc `*`[T, I, J](a: Matrix[T, I, J], b: T): Matrix[T, I, J] =
  var c: Matrix[T, I, J]
  for i in 1..I:
    for j in 1..J:
      c[i][j] = a[i][j] * b
  result = c

# 行列の加法
proc `+`[T, I, J](a, b: Matrix[T, I, J]): Matrix[T, I, J] = 
    var c: Matrix[T, I, J]
    for i in 1..I:
        for j in 1..J:
            c[i][j] = a[i][j]+b[i][j]
    result = c
# 行列の減法
proc `-`[T, I, J](a, b: Matrix[T, I, J]): Matrix[T, I, J] = 
    var c: Matrix[T, I, J]
    for i in 1..I:
        for j in 1..J:
            c[i][j] = a[i][j]-b[i][j]
    result = c

# 行列の乗法
proc `*`[T, I, K, J](a: Matrix[T, I, K], b: Matrix[T, K, J]): Matrix[T, I, J]= 
    var c: Matrix[T, I, J]
    for i in 1..I:
        for j in 1..J:
            for k in 1..K:
                c[i][j] += a[i][k]*b[k][j]
    result = c



var g: Matrix[int, 2, 3] = [[2, 3, 4], [2, 5, 1]]
var mat: Matrix[float, 2, 2]
var mat2 = `+`(mat, 2.0)
var mat3 = `-`(mat, 2.0)
var mat4 = `*`(mat3, 5.0)
var mat5 = `+`(mat2, mat4)
var G = `+`(g, 3)

echo G[2] 
echo mat5