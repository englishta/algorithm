#%%
import numpy as np
data = np.array([9, 2, 3, 4, 10, 6, 7, 8, 1, 5])
data


# %%
data.dtype
# %%
print('次元数', data.ndim)
print('要素数', data.size)
# %%
data*2
# %%
print('掛け算', np.array([1, 2, 3, 4, 5, 6, 7, 8, 9, 10])*np.array([10, 9, 8, 7, 6, 5, 4, 3, 2, 1]))
print('累乗', np.array([1, 2, 3, 4, 5, 6, 7, 8, 9, 10])**2)
print('割り算', np.array([1, 2, 3, 4, 5, 6, 7, 8, 9, 10])/np.array([10, 9, 8, 7, 6, 5, 4, 3, 2, 1]))

# %%
print('そのまま', data)
data.sort()
print('ソート後', data)
# %%
data = np.array([9, 2, 3, 4, 10, 6, 7, 8, 1, 5])
print(sorted(data))
print(data)
data.sort()

# %%
# numpy配列の降順ソート
data[::-1].sort()
data

# %%
print(data.min()) #最小値
print(data.max()) #最大値
print(data.sum()) #総和
print(data.cumsum()) #累積和の配列
print(data.cumsum()/data.sum()) #積み上げ割合

# %%
# 乱数
import numpy.random as random
random.seed(0)
