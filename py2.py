import sympy
from sympy import diff, integrate, cos, sin, tan

x = sympy.symbols('x')
y = sympy.symbols('y')
z = sympy.symbols('z')

#微分して、(x+1)を足し、積分する関数
#def sikihen(expr, var):
#    expr_1 = integrate((diff(expr)+(x+1)))
#    return expr_1.subs(x, var)

array_f = []
array_k = []
f = x**2+2*x+1
k = diff(f)

for value in range(0, 100):
    array_k.append(k.subs(x, value))
    array_f.append(f.subs(x, value))

print(array_f)
print(array_k)