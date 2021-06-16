#%%
import matplotlib.pyplot as plt
import numpy as np

def f(t):
    zt = 0.7
    omg = 2
    beta = ((1-zt*zt)**0.5)*omg
    y = 1-np.e**(-zt*omg*t)*np.cos(beta*t)-((zt/(1-zt*zt)**0.5)*np.e**(-zt*omg*t))*np.sin(beta*t)
    return y
 
N = 300
xmin = -3
xmax = 3
p = np.linspace(xmin, xmax, N)
q = f(p)
plt.plot(p, q, c='b')
plt.show()
# %%
