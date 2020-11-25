# %%

import numpy as np
x = np.array([[1,2,3], [4,5,6]])
print("x:\n{}".format(x))

# %%
from scipy import sparse
#対角成分が1でそれ以外が0の2次元numpy配列を作る

eye = np.eye(4)
print('eye:\n{}'.format(eye))

# %%
