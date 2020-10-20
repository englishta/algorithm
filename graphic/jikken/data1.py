import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
y = [-0.002286416]+[0.3, 0.4, 0.5, 0.6]
x = [0]+[0.591, 0.768, 0.972, 1.167]
func = np.poly1d(np.polyfit(x, y, 1))#(x, y)を線形近似する
y2 = func(x)
plt.plot(x, y2, color='g', ls='-', label='0.5172x-0.00229 : Approximate straight line')
a, b = np.polyfit(x, y, 1)
plt.scatter(x, y, color='fuchsia', label='Actually data')
plt.xlabel( 'Gf (kg/h)' )
plt.ylabel( 'Pme (MPa)' )
plt.title("Uiransline graph", size=10)
plt.axvline(0, color = 'y', ls='-', label='x=0')
plt.plot(0, -0.00229, 'ms', ms=7, label='Pmf point(0, -0.00229)')
plt.legend()
plt.show()