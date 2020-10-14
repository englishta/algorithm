import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
####################関数##################
#空気の密度を求める関数(kg/m^3)
def low_air(Ta):
    ans = 273*1.293*756/((273+Ta)*763)
    return ans
#粘性補正係数を求める関数
def nyu(Ta):
    ans = ((380+25.5)/400)*((293/(243+Ta))**1.5)
    return ans
###############変数宣言と初期化#####################
Hu = 28430 #低発熱量(kj/kg)
PI = 3.14159265359 #円周率
pmf =0.00228641642172201
Gth = 9.0
K20 = 0.01572
T0 = 25.5 #気温
####################################
x = [0.3, 0.4, 0.5, 0.6]
Gf=[0.591, 0.768, 0.972, 1.167]#燃料流量(kg/h)
W=[35.672, 48.02, 61.25, 73.794]#荷重N
N=[950.2, 956.8, 960.4, 961.6]#回転数rpm
Qc=[0.00135, 0.00255, 0.00305, 0.00455]#流量m^3/min
dT=[9.4, 10, 8.8, 8.2]
dp=[0.3118515, 0.312636, 0.312832135, 0.3118515]
Ta=[28, 30, 31, 32.6] #吸気温度(℃)
##########リスト初期化#################
T=[0]*4 #軸トルクのリスト(Nm)
L=[0]*4 #軸出力のリスト(kw)
Be=[0]*4 #燃費消費率のリスト(g/kwh)
qe=[0]*4 #正味熱効率
qm=[0]*4 #機械熱効率
qc=[0]*4 #冷却損失
qex=[0]*4 #排気損失
Ga=[0]*4 #吸入空気量
Ram=[0]*4 #平均空気過剰率
###############計算########################
for i in range(4):
    T[i]+=W[i]*0.4085
    L[i]+=(PI*T[i]*N[i])/30000
    Be[i]+=Gf[i]/L[i]
    qe[i]+=100*3600*L[i]/(Hu*Gf[i])
    qm[i]+=100*(x[i]/(x[i]+pmf))
    qc[i]+=100*(4186*60*Qc[i]*dT[i])/(Hu*Gf[i])
    Ga[i]+=3.6*low_air(Ta[i])*K20*nyu(Ta[i])*dp[i]
    Ram[i]+=Ga[i]/(Gf[i]*9.0)
    #qex[i]+=4.186*
#########################################
plt.plot(x, Gf, '.-' )
plt.plot(x, L, '.-' )
plt.plot(x, Be, '.-' )
plt.show()