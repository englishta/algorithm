# %%
import pandas as pd

obj = pd.Series([4, 7, -5, 3])
obj.values
obj.index


# %%
obj2 = pd.Series([4, 7, -5, 3], index=['a', 'b', 'c', 'd'])
obj2


# %%
