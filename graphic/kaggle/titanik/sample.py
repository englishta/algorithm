# %%
import pandas as pd 
import numpy as np

train = pd.read_csv("train.csv")
test = pd.read_csv("test.csv")

#データの欠損を表示するする関数
def kesson_table(df): 
        null_val = df.isnull().sum()
        percent = 100 * df.isnull().sum()/len(df)
        kesson_table = pd.concat([null_val, percent], axis=1)
        kesson_table_ren_columns = kesson_table.rename(
        columns = {0 : '欠損数', 1 : '%'})
        return kesson_table_ren_columns

print(train.describe())
print(test.describe())

print(kesson_table(train))
print(kesson_table(test))
# %%

train["Age"] = train["Age"].fillna(train["Age"].median())
train["Embarked"] = train["Embarked"].fillna("S")
# %%
print(kesson_table(train))
print(kesson_table(test))
# %%

#文字列を数値に変換する
train["Sex"][train["Sex"] == "male"] = 0
train["Sex"][train["Sex"] == "female"] = 1
train["Embarked"][train["Embarked"] == "S"] = 0
train["Embarked"][train["Embarked"] == "C"] = 1
train["Embarked"][train["Embarked"] == "Q"] = 2

train.head(10)
# %%
