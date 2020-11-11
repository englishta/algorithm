import sympy

x = sympy.symbols('x')
y = sympy.symbols('y')

expr = x**2+y+1
print(expr)
#x**2+y+1
print(expr.subs(x, 1))
# y+2
print(expr.subs(x, y))
# y**2+y+1
print(expr.subs([(x, 1), (y, 2)]))
# 4

expr = (x+1)**2
print(expr)

expr_ex = sympy.expand(expr)#式の展開
print(expr_ex)

expr_ex = x**2+2*x+1
expr = sympy.factor(expr_ex)#因数分解
print(expr)

print(sympy.factor(x**3-x**2-3*x+3))
print(sympy.factor(x*y+x+y+1))


expr1 = 3*x+5*y-29
expr2 = x+y-7
print(sympy.solve([expr1, expr2]))
#rennrituhouteisiki
#{x: 3, y: 4}

print(sympy.diff(x**3+2*x**2+x))
#bibunn
#3*x**2 + 4*x + 1

expr = x**3+y**2-y
print(sympy.diff(expr, x))
#hennbibunn(x)
#3*x**2

print(sympy.integrate(3*x**2+4*x+1))
#sekibunn
#x**3+2*x**2+x

import sympy
from sympy import sin, cos, tan, integrate, diff
from math import pi
