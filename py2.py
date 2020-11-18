# %%
T = 414

def func(t, x, f):
    F = (f*x)/t + f
    return F

array = []
listx = [25, 30, 35, 40, 45, 50]
listy = [80, 82, 83.5, 84, 84.5, 85]
for i in range(len(listx)):
    array.append(func(T, listx[i], listy[i]))

print(array)
# %%
def func1(t, x, f):
    F = (f*x)/t + f
    return F
T = 420

array = []
listx = [30, 35, 40, 45, 50, 55, 60, 65]
listy = [72, 73, 74, 75, 76, 76.5, 77.5, 78]
for i in range(len(listx)):
    array.append(func1(T, listx[i], listy[i]))

print(array)
# %%
def func2(t, x, f):
    F = (f*x)/t + f
    return F
T = 454 

array = []
listx = [15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 70, 75]
listy = [63, 64, 65, 66, 67, 68, 69, 69, 69, 70, 71, 71]
for i in range(len(listx)):
    listx[i]+=7
print(listx)

for i in range(len(listx)):
    array.append(func1(T, listx[i], listy[i]))

print(array)

# %%
#加工硬化指数を求める,600
print("----------600-------------")
import matplotlib.pyplot as plt
from math import log10, log
import numpy as np
#########設定事項#########

a0 = 49.2
L0 = 64.45 #(mm)
L = 74.40 #(mm)
las_hiz = 0.17601246105918997 #最終地点のひずみ
mas_last = 64 #最終地点のマスの数

array_y = [82, 83.5, 84, 85]
array_x = [30, 35, 40, 45]

##############################
hiz = (L-L0)/L0
hip =(29690/a0)/65  #ひとます当たりの応力(MPa/mas)
hihi = las_hiz/mas_last #ひとますのひずみ

for i in range(4):
    array_y[i]*=hip
    array_y[i]*=(1+hiz)
    array_y[i]*=1e6
    array_x[i]*=hihi
    array_x[i] = log(array_x[i]+1)
    array_y[i] = log10(array_y[i])
    array_x[i] = log10(array_x[i])

print(array_x)
print(array_y)

senkei = np.polyfit(array_x, array_y, 1)
Func = np.poly1d(senkei)
a, b = np.polyfit(array_x, array_y, 1)
y2 = Func(array_x)
print("a=", a, "b=", b)
plt.plot(array_x, y2)
plt.plot(array_x, array_y, '.')

# %%
#加工硬化指数を求める,650
import matplotlib.pyplot as plt
from math import log10, log
import numpy as np
#########設定事項#########

a0 = 49.12
L0 = 64.20 #(mm)
L = 75.5 #(mm)
las_hiz =0.17601246105918997  #最終地点のひずみ
mas_last = 74 #最終地点のマスの数

array_y = [72, 74, 76, 77]
array_x = [30, 40, 50, 60]

##############################
print("-----------650----------------")
hiz = (L-L0)/L0
hip =(29690/a0)/65  #ひとます当たりの応力(MPa/mas)
hihi = las_hiz/mas_last #ひとますのひずみ

for i in range(4):
    array_y[i]*=hip
    array_y[i]*=(1+hiz)
    array_y[i]*=1e6
    array_x[i]*=hihi
    array_x[i] = log(array_x[i]+1)
    array_y[i] = log10(array_y[i])
    array_x[i] = log10(array_x[i])

print(array_x)
print(array_y)

senkei = np.polyfit(array_x, array_y, 1)
Func = np.poly1d(senkei)
a, b = np.polyfit(array_x, array_y, 1)
y2 = Func(array_x)
print("a=", a, "b=", b)
plt.plot(array_x, y2)
plt.plot(array_x, array_y, '.')
# %%
#加工硬化指数を求める,700
import matplotlib.pyplot as plt
from math import log10, log
import numpy as np
#########設定事項#########

a0 = 48.95 
L0 = 64.25 #(mm)
L = 77.4 #(mm)
las_hiz = 0.20466926070038918 #最終地点のひずみ
mas_last = 93 #最終地点のマスの数

array_y = [65, 67, 69, 71]
array_x = [27, 42, 57, 72]

##############################
print("-----------700----------------")
hiz = (L-L0)/L0
hip =(29690/a0)/65  #ひとます当たりの応力(MPa/mas)
hihi = las_hiz/mas_last #ひとますのひずみ

for i in range(4):
    array_y[i]*=hip
    array_y[i]*=(1+hiz)
    array_y[i]*=1e6
    array_x[i]*=hihi
    array_x[i] = log(array_x[i]+1)
    array_y[i] = log10(array_y[i])
    array_x[i] = log10(array_x[i])

print(array_x)
print(array_y)

senkei = np.polyfit(array_x, array_y, 1)
Func = np.poly1d(senkei)
a, b = np.polyfit(array_x, array_y, 1)
y2 = Func(array_x)
print("a=", a, "b=", b)
plt.plot(array_x, y2)
plt.plot(array_x, array_y, '.')
# %%
#加工硬化指数を求める,焼きならし
import matplotlib.pyplot as plt
from math import log10, log, pi
import numpy as np

#########設定事項#########
d = 7.921 #(mm)
L0 = 64.00 #(mm)
L = 80.5 #(mm)
mas_last = 116 #最終地点のマスの数

array_y = [54, 62, 64, 65]
array_x = [33, 53, 73, 93]

##############################
print("-----------yakinarasi----------------")
a0 = (pi*d**2)/4 
hip =(29690/a0)/65  #ひとます当たりの応力(MPa/mas)
las_hiz = (L-L0)/L0 #最終地点のひずみ
hihi = las_hiz/mas_last #ひとますのひずみ

x = []#kousyou_hizumi
y = []#kousyou_ouryoku(MPa)
x1 = []#sin_hizumi
y1 = []#sin_ouryoku(MPa)

for i in range(4):
    array_y[i]*=hip#公称応力MPa
    y.append(array_y[i])#y.append()
    array_y[i]*=(1+hiz)
    array_y[i]*=1e6
    array_x[i]*=hihi#公称ひずみ
    x.append(array_x[i])#x.append()
    array_x[i] = log(array_x[i]+1)#真ひずみ
    #x1.append()y1.append()
    x1.append(array_x[i])
    y1.append(array_y[i]*1e-6)
    array_y[i] = log10(array_y[i])#log10toru
    array_x[i] = log10(array_x[i])

print("x", x)
print("y", y)
print("x1", x1)
print("y1", y1)

senkei = np.polyfit(array_x, array_y, 1)
Func = np.poly1d(senkei)
a, b = np.polyfit(array_x, array_y, 1)
y2 = Func(array_x)
print("a=", a, "b=", b)
plt.plot(array_x, y2)
plt.plot(array_x, array_y, '.')
# %%

#加工硬化指数を求める,焼きならし
import matplotlib.pyplot as plt
from math import log10, log, pi
import numpy as np

#########設定事項#########
d = 7.981 #(mm)
L0 = 64.65 #(mm)
L = 72.95 #(mm)
mas_last = 36 #最終地点のマスの数

array_y = [68, 76, 79, 82]
array_x = [15, 20, 25, 30]

##############################
print("-----------misyori----------------")
hiz = (L-L0)/L0
a0 = (pi*d**2)/4 
hip =(29690/a0)/65  #ひとます当たりの応力(MPa/mas)
hihi = hiz/mas_last #ひとますのひずみ

x = []#kousyou_hizumi
y = []#kousyou_ouryoku(MPa)
x1 = []#sin_hizumi
y1 = []#sin_ouryoku(MPa)

for i in range(4):
    array_y[i]*=hip#公称応力MPa
    y.append(array_y[i])#y.append()
    array_y[i]*=(1+hiz)
    array_y[i]*=1e6
    array_x[i]*=hihi#公称ひずみ
    x.append(array_x[i])#x.append()
    array_x[i] = log(array_x[i]+1)#真ひずみ
    #x1.append()y1.append()
    x1.append(array_x[i])
    y1.append(array_y[i]*1e-6)
    array_y[i] = log10(array_y[i])#log10toru
    array_x[i] = log10(array_x[i])

print("x", x)
print("y", y)
print("x1", x1)
print("y1", y1)

senkei = np.polyfit(array_x, array_y, 1)
Func = np.poly1d(senkei)
a, b = np.polyfit(array_x, array_y, 1)
y2 = Func(array_x)
print("a=", a, "b=", b)
plt.plot(array_x, y2)
plt.plot(array_x, array_y, '.')
# %%
