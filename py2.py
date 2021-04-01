import pandas as pd
url = "https://info.finance.yahoo.co.jp/ranking/?kd=1&tm=d&mk=1"

dfs = pd.read_html(url)
df = dfs[0]
print(df.head)