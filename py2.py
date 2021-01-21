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
#%%
#Cabinのデータを頭文字で置き換える
all_df["Cabin"]=all_df["Cabin"].str[:1]
#%%
all_df = pd.concat([all_df, pd.get_dummies(all_df["Cabin"], prefix="Cabin")], axis=1).drop(columns=["Cabin"])
#%%
#名前から敬称を取り出す
all_df["Name"] = all_df["Name"].str.extract(' ([A-Za-z]+)\.', expand = False)
#%%
all_df["Name"].value_counts()
#敬称ごとの出現数を表示する
#%%
all_df["Name"].replace(["Capt", "Col", "Dr", "Major", "Rev"], "Officer", inplace = True)
all_df["Name"].replace(["Countess", "Don", "Dona", "Jonkheer", "Lady", "Sir"], "Royalty", inplace = True)
all_df["Name"].replace("Mlle", "Miss", inplace=True)
all_df["Name"].replace(["Mme", "Ms"], "Mrs", inplace=True)
# all_df["Ticket"].replace(["CA 2144", "CA. 2343"], "CA", inplace=True)
all_df["Name"].value_counts()

#%%
#ダミー変数へ変換する
all_df = pd.concat([all_df, pd.get_dummies(all_df["Name"], prefix="Name")], axis=1).drop(columns=["Name"])
all_df.head(10)

#%%
all_df["Ticket"].value_counts()
# %%
all_df = all_df.drop(["Ticket"], axis=1)
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
model = RandomForestClassifier()
model.fit(feature_train, target_train)
pred_test = model.predict(feature_test)
#%%
#予測結果をcsvファイルに保存する
my_prediction = pd.DataFrame(pred_test, feature_test["PassengerId"], columns=["Survived"])
my_prediction.to_csv("graphic/kaggle/titanik/my_prediction2.csv", index_label=["PassengerId"])
# %%

