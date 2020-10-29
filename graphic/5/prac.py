import numpy as np
from matplotlib import pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
 
def jukaiki_bunseki(x1, x2, y):

    N = np.size(x1) # 標本数
    Y = np.c_[y]
    X = np.c_[x1, x2, np.ones(N)]

    tmp = np.dot(X.T, X) # XTX
    r1 = np.linalg.inv(tmp) # (XTX)^-1 逆行列
    r2 = np.dot(X.T, Y) # XTY
    A = np.dot(r1, r2) # 係数ベクトル

    a1 = A[0] # 傾き
    a2 = A[1] # 傾き
    b = A[2] # 切片b


    # [追加機能]回帰直線の妥当性を評価する
    Y_hat = a1*x1 + a2*x2 + b # 予測値
    C = np.corrcoef(Y_hat, y)[0,1] # 相関係数
    # 決定係数
    R2 = np.sum( (Y_hat-np.mean(y))**2 ) / np.sum( (y-np.mean(y))**2 )
    print('a1=', a1)
    print('a2=', a2)
    print('b=', b)
    print('C=', C)
    print('R2=', R2)
    return


x1 = [8, 7, 5, 4, 6, 2, 3, 9]
x2 = [8, 7, 9, 3, 8, 3, 6, 7]
#x3 = [4, 7, 8, 3, 8, 5, 6, 9]
y = [18, 12, 14, 6, 12, 8, 10, 16]

jukaiki_bunseki(x1, x2, y)
# フォントの種類とサイズを設定する。
plt.rcParams['font.size'] = 14
plt.rcParams['font.family'] = 'Times New Roman'
 
# グラフの入れ物を用意する。
fig = plt.figure()
ax1 = Axes3D(fig)
 
# 軸のラベルを設定する。
ax1.set_xlabel('x1')
ax1.set_ylabel('x2')
ax1.set_zlabel('y')
 
# データプロットする。
ax1.scatter3D(x1, x2, y, label='Dataset', color = 'deeppink')
plt.legend()
 
# グラフを表示する。
plt.show()