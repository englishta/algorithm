import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
y = [0.3, 0.4, 0.5, 0.6]
x = [0.591, 0.768, 0.972, 1.167]
func = np.poly1d(np.polyfit(x, y, 1))
y2 = func(x)
plt.plot(x, y2)
a, b = np.polyfit(x, y, 1)
print("katamuki=", a)
print("seppenn=", b)
plt.scatter(x, y)
plt.xlabel( 'Gf' )
plt.ylabel( 'Pme' )
plt.title("Uiransline graph", size=10)
plt.show()