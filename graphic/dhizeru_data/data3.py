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
x2 = list(df['0.3'])
x3 = list(df['0.3(1)'])
x4 = list(df['0.4'])
x5 = list(df['0.4(1)'])
p = x+x1
p1 = x2+x3
p2 = x4+x5

y = []#dv/d0のリスト
z = []#dp/d0のリスト
z1 = []#0.3Mpa
z2 = []#0.4Mpa
vm3 = []#Vのリスト
ans = []#dq/d0のリスト熱発生率
ans_tree = []#0.3Mpa
ans_for = []

x = list(range(-40, 60))#角度°0[-40, 71)

for i in range(-40, 71):
    vm3.append(solve_v(i))
    y.append(dev(i))


for i in range(len(p)-1):
    z.append(p[i+1]-p[i])
    z1.append(p1[i+1]-p1[i])
    z2.append(p2[i+1]-p2[i])


for i in range(100):
    ans.append((vm3[i]*z[i]+1.3*p[i]*y[i])/0.3)
    ans_tree.append((vm3[i]*z1[i]+1.3*p[i]*y[i])/0.3)
    ans_for.append((vm3[i]*z2[i]+1.3*p[i]*y[i])/0.3)

#plt.plot(x, ans, '.-', color = 'g', label='Pme = 0.6Mpa')
#plt.plot(x, ans_for, '.-', color = 'b', label='Pme = 0.4Mpa')
#plt.plot(x, ans_tree, '.-', color = 'deeppink', label='Pme = 0.3Mpa')
#plt.hist(ans, color = 'g', bins = 30, label='Pme=0.6MPa')
#plt.hist(ans_tree, color='b', bins=30, label = 'Pme = 0.4MPa')
plt.hist(ans_for, color='deeppink', bins=30, label = 'Pme = 0.3MPa')
plt.ylabel( 'number' )
plt.xlabel( 'dQ/dθ (kg/h)' )
plt.legend()
plt.show()