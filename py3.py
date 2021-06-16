import numpy as np
p = np.array([[0.8, 0.05, 0.1, 0.05],
		[0.1, 0.6, 0.2, 0.1],
		[0.3, 0.095, 0.6, 0.005],
		[0.2, 0.1, 0.001, 0.699]])
p6 = np.linalg.matrix_power(p, 6)
now = np.array([0.5, 0.2, 0.2, 0.1])
S = np.dot(now, p6)
print(p6)
print(S)


