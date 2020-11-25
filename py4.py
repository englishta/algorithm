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
#numpy配列をSciPyのCSRの疎行列に変換する
#非ゼロ要素だけが格納される
eye[0, 2] = 5
print(eye)
sparse_matrix = sparse.csr_matrix(eye)
print('sparse_matrix:\n{}'.format(sparse_matrix))
# %%
data = np.ones(4)
row_idices = np.arange(4)
col_indices = np.arange(4)
print(data)
print(row_idices)
print(col_indices)

# %%
eye_coo = sparse.coo_matrix((data, (row_idices, col_indices)))
print(eye_coo)
# %%
