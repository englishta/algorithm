#%%
import pandas as pd
import numpy as np
train = pd.read_csv("graphic/kaggle/titanik/train.csv")
test = pd.read_csv("graphic/kaggle/titanik/test.csv")
#%%
# train["Survived"].mean()
# %%
all_df = pd.concat([train.drop(columns=["Survived"]), test])
all_df
# %%
all_df["Ticket"].value_counts().head(20)
# %%
all_df["FamilySize"]=all_df["SibSp"]+all_df["Parch"]
all_df.drop(["SibSp", "Parch"], axis=1, inplace=True)
# %%
all_df
# %%
