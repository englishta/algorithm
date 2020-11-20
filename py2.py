# %%
#numpyの練習
import numpy as np

data = np.random.randn(2, 3)
data
# %%
data*10
# %%
data+data
# %%

data+2*data

# %%
data.shape

# %%
data.dtype
# %%
data1 = [6, 7.5, 8, 0, 1]
arr1 = np.array(data1)
print(arr1)

data2 = [[1, 2, 3, 4], [5, 6, 7, 8]]
arr2 = np.array(data2)
print(arr2)

print(arr2.ndim)
# %%
#zeroで初期化
a = np.zeros(10)
# %%
np.zeros((3, 6))
np.ones((3, 6))
# %%
np.empty((3,6))
# %%
array = np.arange(15)
# %%
print(*array*2)

# %%
arr1 = np.array([1.2, 2.3, 3.2], dtype=np.float64)
arr2 = np.array([1, 2, 3], dtype=np.int64)
print(arr1)
print(arr2)

# %%
#型キャスト
int_array = arr1.astype(np.int64)
print(int_array)

float_array = arr2.astype(np.float64)
print(float_array)


# %%
array = np.array(['6.4', '2.3', '3.5'], dtype=np.string_)
array

# %%
array.astype(np.float64)
print(array)
# %%


seq1 = np.array(['6.4', '2.3', '3.5'], dtype=np.float64)
seq2 = np.array(['5.4', '3.3', '3.5'], dtype=np.float64)

array = seq1 > seq2
array

# %%
#listの練習


# %%
seq = [1, 2, 3, 4]
seq.insert(1, 5)
print(seq)
seq.pop(1)
print(seq)
seq.remove(2)
seq
# %%
seq = [1, 2, 3, 4]
seq[1:3] = [0, 0]
seq
aa = seq[:]
aa.append(500)
print(aa)
print(seq)
# %%
for i, value in enumerate(seq):
    print(i, value)

# %%
import pandas as pd

