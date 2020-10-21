import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
from math import pi, cos, sin
from statistics import mean, median,variance,stdev
d = 92e-3#シリンダ内径
r = 0.04085#クランク半径
#体積を計算する関数
def solve_v(deg):
    rad = pi*deg/180
    v1 = (pi*d*d/4)*r
    v2 = (1-cos(rad) + (r/(4*0.148))*(1-cos(2*rad)))
    v3 = (638*1e-6)/16.7
    return v1*v2+v3

#dv/d0を求める関数
def dev(deg):
    rad = pi*deg/180
    ans1 = (pi*d*d/4)*r
    ans2 = (sin(rad) + (r/2*0.148)*sin(2*rad))
    return ans1*ans2*(pi/180)

#csvファイルの読み込み
df = pd.read_csv('jikken1.csv', encoding = "SHIFT_JIS", header = 3)
x = list(df['0.6'])
x1 = list(df['0.6(1)'])
p = x+x1

y = []#dv/d0のリスト
z = []#dp/d0のリスト
vm3 = []#Vのリスト
ans = []#dq/d0のリスト熱発生率

x = list(range(-40, 60))#角度°0[-40, 71)

for i in range(-40, 71):
    vm3.append(solve_v(i))
    y.append(dev(i))


for i in range(len(p)-1):
    z.append(p[i+1]-p[i])

for i in range(100):
    ans.append((vm3[i]*z[i]+1.3*p[i]*y[i])/0.3)

plt.plot(x, ans, '.-', color = 'g', label='Heat-generated rate')
plt.ylabel( 'dQ/dθ (kg/h)' )
plt.xlabel( 'Degree' )
plt.legend()
plt.show()