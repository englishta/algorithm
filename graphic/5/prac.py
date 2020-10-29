import numpy as np
from matplotlib import pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
 
# データを用意する
w0 = 1.0                             # 定数
w1 = 1.0                             # 係数1
w2 = 2.0                             # 係数2
x = np.random.uniform(0, 10, 300)    # ノイズを含んだx軸を作成
y = np.random.uniform(0, 10, 300)    # ノイズを含んだy軸を作成
# ノイズを含んだ平面点列データを作成
z = w0 + (w1 * x) + (w2 * y) + np.random.uniform(0, 5, 300)
 
# ここからグラフ描画
# フォントの種類とサイズを設定する。
plt.rcParams['font.size'] = 14
plt.rcParams['font.family'] = 'Times New Roman'
 
# グラフの入れ物を用意する。
fig = plt.figure()
ax1 = Axes3D(fig)
 
# 軸のラベルを設定する。
ax1.set_xlabel('x')
ax1.set_ylabel('y')
ax1.set_zlabel('z')
 
# データプロットする。
ax1.scatter3D(x, y, z, label='Dataset')
plt.legend()
 
# グラフを表示する。
plt.show()