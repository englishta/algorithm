# %%
import numpy as np 
import pandas as pd
import matplotlib.pyplot as plt
from scipy import stats

x1 = [86, 71, 42, 62, 96, 39, 50, 78, 51, 89] 
x2 = [79, 75, 43, 58, 97, 33, 53, 66, 44, 92]
x3 = [67, 78, 39, 98, 61, 45, 64, 52, 76, 93]
x4 = [68, 84, 44, 95, 63, 50, 72, 47, 72, 91]


x1h = (x1-np.mean(x1))/np.std(x1, ddof=1)
x2h = (x2-np.mean(x2))/np.std(x2, ddof=1)
x3h = (x3-np.mean(x3))/np.std(x3, ddof=1)
x4h = (x4-np.mean(x4))/np.std(x4, ddof=1)

COV = np.cov([x1h, x2h, x3h, x4h])
L, A = np.linalg.eig(COV)

z1 = A[0,0] * (x1h-np.mean(x1h)) + A[1,0] * (x2h-np.mean(x2h)) + A[2,0] * (x3h-np.mean(x3h)) + A[3,0] * (x4h-np.mean(x4h))
z2 = A[0,1] * (x1h-np.mean(x1h)) + A[1,1] * (x2h-np.mean(x2h)) + A[2,1] * (x3h-np.mean(x3h)) + A[3,1] * (x4h-np.mean(x4h))


frame = pd.DataFrame({'X1' : x1, 'X2' : x2, 'x3' : x3, 'x4' : x4, 'x1h':x1h, 'x2h':x2h, 'x3h':x3h, 'x4h':x4h, 'z1':z1, 'z2':z2})
frame = frame.assign(z1_order=len(frame.z1) - stats.mstats.rankdata(frame.z1)+1)
print("L=", L)
print("A=", A)
plt.plot(z1, z2, '.', color = 'red')

# %%
frame

# %%
frame2 = frame.drop(columns = ['X1', 'X2', 'x3', 'x4', 'z1', 'z2', 'z1_order'])
frame2
# %%
pd.plotting.scatter_matrix(frame2, alpha=0.5, figsize=(8, 8))
# %%
