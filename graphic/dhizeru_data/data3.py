import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
from math import pi, cos, sin
from statistics import mean, median,variance,stdev

#体積を計算する関数
def solve_v(deg):
    rad = pi*deg/180
    v1 = pi*((0.148)**2)*0.066
    v2 = (1-cos(rad) + (0.066/(4*0.148))*(1-cos(2*rad)))
    v3 = (638*1e-6)/16.7
    return v1*v2+v3

#dv/d0を求める関数
def dev(deg):
    rad = pi*deg/180
    ans = pi*(0.184**2)*(0.066/4)* ( (sin(rad)+(0.066/(2*0.148) )*sin(2*rad) ) )*(pi/180)
    return ans

#csvファイルの読み込み
df = pd.read_csv('jikken1.csv', encoding = "SHIFT_JIS", header = 3)
x = list(df['0.3'])
x1 = list(df['0.3(1)'])
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

plt.plot(x, ans, '-', color = 'g', label = 'dq/d0')
plt.ylabel( 'dQ/dθ (kg/h)' )
plt.xlabel( 'Degree' )
plt.legend()
plt.show()