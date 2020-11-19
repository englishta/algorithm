# %%
import pandas as pd

obj = pd.Series([4, 7, -5, 3])
obj.values
obj.index


# %%
obj2 = pd.Series([4, 7, -5, 3], index=['a', 'b', 'c', 'd'])
obj2


# %%

obj2['a']
obj2['c']
# %%

obj2*2
# %%
print(obj)#objの値は変更されない
# %%
obj22 = obj2*2
print(obj22)

# %%
