#%%
import pandas as pd
url = "https://info.finance.yahoo.co.jp/ranking/?kd=1&tm=d&mk=1"

dfs = pd.read_html(url)
df = dfs[0]
df
#%%

df.columns = ['順位', 'コード', '市場', '名称', '日付', '取引値', '前日比', '増加値', '出来高', '掲示板']
df = df.drop('掲示板', axis=1)
#%%
df = df.drop(df.index[-1])
df = df.astype({'順位' : int})
#%%
df['増加値']=[e.replace('+', '') for e in df['増加値'].tolist()]
#%%
df
#%%
# df = df.astype({'順位' : int, 'コード': int, '取引値' : int, '増加値' : int, '出来高' : int})
#%%
df['前日比'] = [e.replace('+', '').replace('%', '') for e in df['前日比'].tolist()]
#%%
df = df.astype({'前日比' : float})
df.to_csv('./stock_up.csv', encoding = 'utf_8_sig')

# %%
