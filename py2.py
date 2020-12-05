#%%
#癌の陽性,陰性データ
from sklearn.datasets import load_breast_cancer
cancer = load_breast_cancer()
cancer.keys()

# %%
print("Shape of cancer data : {}".format(cancer.data.shape))

# %%
import numpy as np
{n:v for n, v in zip(cancer.target_names, np.bincount(cancer.target))}
#クラスごとのサンプルの個数
#悪性212, 良性357 
# %%
cancer.feature_names
# %%
