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
frame

# %%
#列の順を指定する
frame = pd.DataFrame(data, columns=['year', 'state', 'pop'])
frame

# %%
#存在しない列を指定するとNaNが代入される
frame2 = pd.DataFrame(data, columns=['year', 'state', 'pop', 'NAN'])
frame2

# %%
#データフレームからシリーズを取り出す
#列を取り出す
#sannsyou
frame2['year']

# %%
#zokusei
frame2.year
# %%
#行をSeriesで取り出す
#indexで指定する
print(frame2)
frame2.loc[0]

# %%
#NAN列の値をスカラー値で書き変える
print(frame2)
frame2['NAN'] = 16.5
print(frame2)


# %%
#NAN列の値を配列で書き換え
print(frame2)
seq1 = [1.2, 2.4, 5.2, 3.2]
frame2['NAN'] = seq1

print()
print(frame2)

# %%
#NAN列の値をSeriesで書き換え
print(frame2)
print()

val = pd.Series([0.0, 2.22, 5.2, 3.2])
frame2['NAN'] = val
print(frame2)

# %%
#列の削除
del frame2['NAN']
print(frame2)


# %%
#state列が'Nevada'であるかどうかを示す真偽値をもった列を追加

frame2['eastern'] = frame2.state == 'Nevada'
print(frame2)

# %%
seq2 = frame2['eastern']
print(seq2)
frame2['eastern'][2] = True
print(seq2)


# %%

print(frame2)
frame2['eastern'] = frame2['state'] == 'Nevada'
print(frame2)



# %%
#列と行を入れ替えたものを表示
frame2.T
# %%
frame2
# %%

obj = pd.Series([4.5, 7.2, -5.3, 3.6], index=['d', 'b', 'a', 'c'])
print(obj)

obj2 = obj.reindex(['a', 'b', 'c', 'd', 'e'])
print(obj2)

# %%
obj3 = pd.Series(['blue', 'purple', 'yellow'], index=[0, 2, 4])
obj3

# %%
obj3.reindex(range(6), method='ffill')

# %%
data = {'state' : ['Ohio', 'OHIO', 'Nevada', 'Nevada'], 
'year' : [2000, 2001, 2001, 2003], 'pop' : [1.5, 1.7, 3.6, 2.4]}

frame = pd.DataFrame(data)
print(frame)
# %%
#データフレームのreindex,
#データ抽出
frame2 = frame.reindex([0, 2, 3])
print(frame2)

frame2 = frame.reindex(columns=['year', 'pop'])
print(frame2)

frame2 = frame.loc[[0, 1, 2], ['year', 'pop']]
print(frame2)
# %%
frame = pd.read_table('sample.csv')
print(frame)

# %%
