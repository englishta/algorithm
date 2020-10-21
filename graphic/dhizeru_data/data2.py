import pandas as pd
df = pd.read_csv('jikken1.csv', encoding = "SHIFT_JIS", header = 3)
x = list(df['0.3'])
x1 = list(df['0.3(1)'])
list1 = x+x1
print(list1)