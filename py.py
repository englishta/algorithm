#Begin Header {{{
from math import gcd, pi, cos, sin, e
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations, combinations_with_replacement
# }}} End Heade
# _________コーディングはここから！！___________

#%%
import pandas as pd
import numpy as np

path_train = '/mnt/c/MinGW/prog2/graphic/kaggle/titanik/train.csv'
path_test = '/mnt/c/MinGW/prog2/graphic/kaggle/titanik/test.csv'

train = pd.read_csv(path_train)
test = pd.read_csv(path_test)

train["is_train"] = 1
test["is_train"] = 0
data = pd.concat([train.drop(columns=["Survived"]), test])

# %%
data["Age"] = data["Age"].fillna(data["Age"].median())
data["Embarked"] = data["Embarked"].fillna("S")
data = pd.concat([data, pd.get_dummies(data["Embarked"], prefix="Embarked")], axis=1).drop(columns=["Embarked"])
data["Sex"] = pd.get_dummies(data["Sex"], drop_first=True)


# %%

feature_columns =["Pclass", "Sex", "Age", "Embarked_C", "Embarked_Q", "Embarked_S"]
feature_train = data[data["is_train"] == 1].drop(columns=["is_train"])[feature_columns]
feature_test = data[data["is_train"] == 0].drop(columns=["is_train"])[feature_columns]

feature_train
# %%

feature_test
# %%
