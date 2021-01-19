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
train = pd.read_csv("graphic/kaggle/titanik/train.csv")
test = pd.read_csv("graphic/kaggle/titanik/test.csv")

train.head(3)
# %%
train.info()
#それぞれのコラムに891個のデータがあることが分かる
#Age,Cabin,Embarkedにnullがあることが分かる
# %%
train2 = train.replace("male", 0).replace("female", 1).replace("S", 0).replace("Q", 2).replace("C", 1)
test2 = test.replace("male", 0).replace("female", 1).replace("S", 0).replace("Q", 2).replace("C", 1)
#EmbarkedのSCQを数値に変換
test.head(10)
# %%

test2.head(10)
# %%
train2["Age"].fillna(train2.Age.mean(), inplace = True)
train2["Embarked"].fillna(train2.Embarked.mean(), inplace = True)
test2["Age"].fillna(test2.Age.mean(), inplace = True)
test2["Embarked"].fillna(test2.Embarked.mean(), inplace = True)
test2["Fare"].fillna(test2.Fare.mean(), inplace = True)
train2.info()
# %%
#Cabinの処理が面倒なのでカラムから消去
train2 = train2.drop(["Cabin", "Name", "Ticket"], axis=1)
test2 = test2.drop(["Cabin", "Name", "Ticket"], axis=1)

test2.head(10)
# %%
test2.head(10)
# %%
train2.info()
test2.info()

# %%
target_train = train2["Survived"]
feature_train = train2.drop("Survived", axis=1)

target_train

# %%
from sklearn import tree
from sklearn.ensemble import RandomForestClassifier
from sklearn import metrics

# %%
model = RandomForestClassifier()
model.fit(feature_train, target_train)
#%%
pred_train = model.predict(feature_train)
metrics.accuracy_score(target_train, pred_train)
# %%

pred_test = model.predict(test2)
# %%
pred_test
#%%
#予測結果をcsvファイルに保存する
my_prediction = pd.DataFrame(pred_test, test2["PassengerId"], columns=["Survived"])
my_prediction.to_csv("graphic/kaggle/titanik/my_prediction2.csv", index_label=["PassengerId"])
# %%
