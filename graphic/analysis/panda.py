# %%
import pandas as pd

obj = pd.Series([4, 7, -5, 3])
obj.values
obj.index
print(obj)


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
#dictonaryをSeriesに入れる,Keyがインデックス,valueがオブジェクト

sdata={'Ohio':35000, 'Texas':71000, 'Oregon':16000, 'Utah':5000} 
obj3 = pd.Series(sdata)

obj3
# %%
#keyを並べ替えて指定すると、Seriesのオブジェクトも並べ替えられる
states = ['Texas', 'Utah','Ohio','Oregon']
obj4 = pd.Series(sdata, index=states)
obj4


# %%
#Californiaインデックスのオブジェクトは存在しない
states = ['California','Utah', 'Ohio','Oregon']
obj4 = pd.Series(sdata, index=states)
obj4

# %%
pd.isnull(obj4)
# %%
pd.notnull(obj4)

# %%
obj4.isnull()
# %%
obj4.notnull()
# %%
#gattai
#両方のインデックスに存在するものだけ足し合わされる
print("----------obj3--------")
print(obj3)
print("---------obj4--------")
print(obj4)
print("--------obj3+obj4--------")
obj3+obj4


# %%
#name
obj4.name = 'population'
obj4.index.name = 'state'

obj4
# %%

obj = pd.Series([4, 7, -5, 3])
obj.values
obj.index
print(obj)

obj.index = ['a', 'b', 'c', 'd']
print(obj)


# %%
#DataFrame
#配列をvalueにもつ辞書から初期化する方法
data = {'state' : ['Ohio', 'OHIO', 'Nevada', 'Nevada'], 
'year' : [2000, 2001, 2001, 2003], 'pop' : [1.5, 1.7, 3.6, 2.4]}

frame = pd.DataFrame(data)
print(frame)

# %%



