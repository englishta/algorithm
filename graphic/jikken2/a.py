import matplotlib.pyplot as plt
import japanize_matplotlib
import numpy as np
from mpl_toolkits.mplot3d import Axes3D


def main():
    # 乱数を50個生成して x とする。y, z も同様
    x = np.random.randn(50)
    y = np.random.randn(50)
    z = np.random.randn(50)
    # 3Dでプロット
    fig = plt.figure()
    ax = Axes3D(fig)
    for x1,y1,z1 in zip(x,y,z):
        if x1 < 0:
            ax.plot([x1], [y1], [z1], "o", color="#0000aa")
        else:
            ax.plot([x1], [y1], [z1], "o", color="#aa0000")

    # 軸のラベルを設定 
    ax.set_xlabel('x軸')
    ax.set_ylabel('y軸')
    ax.set_zlabel('z軸')
    # 表示
    plt.show() # Colaboratory では不要
    
main()