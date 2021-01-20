#%%
import pandas as pd
import numpy as np
train = pd.read_csv("graphic/kaggle/titanik/train.csv")
test = pd.read_csv("graphic/kaggle/titanik/test.csv")

# %%
print(train.shape)
print(test.shape)
#trainは、(891x12)
#testは、(418x11)
#Age,Cabin,Embarkedにnullがあることが分かる
#%%
train["is_train"]=1
test["is_train"]=0
all_df = pd.concat([train.drop(columns=["Survived"]), test])
all_df

# %%
all_df = all_df.replace("male", 0).replace("female", 1).replace("S", 0).replace("Q", 2).replace("C", 1)
#EmbarkedのSCQを数値に変換
test.head(10)

# %%
all_df["Age"].fillna(all_df.Age.mean(), inplace = True)
all_df["Embarked"].fillna(all_df.Embarked.mean(), inplace = True)
all_df["Fare"].fillna(all_df.Fare.mean(), inplace = True)
#%%
#Cabinの欠損値をUnknownのUで置き換える
all_df["Cabin"].fillna('U', inplace=True)
all_df.head(10)
all_df.info()
#%%
#Cabinのデータを頭文字で置き換える
all_df["Cabin"]=all_df["Cabin"].str[:1]
#%%
all_df = pd.concat([all_df, pd.get_dummies(all_df["Cabin"], prefix="Cabin")], axis=1).drop(columns=["Cabin"])
all_df.head(10)

# %%
all_df = all_df.drop(["Name", "Ticket"], axis=1)
# %%
target_train = train["Survived"]
feature_train = all_df[all_df["is_train"]==1].drop(["is_train"], axis=1)
feature_test = all_df[all_df["is_train"]==0].drop(["is_train"], axis=1)
feature_test.head(10)
#%%
print(feature_train.shape)
print(feature_test.shape)
# %%
from sklearn.ensemble import RandomForestClassifier
from sklearn import metrics

# %%
model = RandomForestClassifier()
model.fit(feature_train, target_train)
#%%
pred_train = model.predict(feature_train)
metrics.accuracy_score(target_train, pred_train)
# %%
pred_test = model.predict(feature_test)
# %%
pred_test
#%%
#予測結果をcsvファイルに保存する
my_prediction = pd.DataFrame(pred_test, feature_test["PassengerId"], columns=["Survived"])
my_prediction.to_csv("graphic/kaggle/titanik/my_prediction2.csv", index_label=["PassengerId"])
# %%
