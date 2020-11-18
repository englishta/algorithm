#Begin Header {{{
from math import gcd, pi, cos, sin, e
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations, combinations_with_replacement
# }}} End Heade
# _________コーディングはここから！！___________
#設定項目
d0 = 7.921 #(mm)
df = 5.32 #(mm)
pf = 26.07  #破断荷重(KN)

a0 = (pi*d0*d0)/4 
af = (pi*df*df)/4

hip =(29690/a0)/65  #ひとます当たりの応力(MPa/mas)
hio = (29690/65)    #ひとます当たりの荷重(N/mas)

def mas_to_MPa(mas1):
    print(mas1*hip, "Mpa")
def mas_to_N(mas2):
    print(mas2*hio, "N")

def MPa_to_mas(m):
    print(m/hip, "mas")
def n_to_mas(m1):
    print(m1/hip, "mas")

    
#処理
pf*=1e3#破断荷重(NからKN)


print("A0=", a0, "(mm^2)")
print("Af=", af, "(mm^2)")


sig_f = pf/af
print("破断応力=", sig_f, "MPa")

print("破断応力のマス目は=", sig_f/hip, "マスです")

mas_to_MPa(65)
print(19)


#設定項目
print("-------600度-----------")
Pmax = 39.59#(KN)最大荷重
L0 = 64.45 #(mm)
L = 74.40 #(mm)
d0 = 7.916  #(mm)
df = 4.67 #(mm)
pf = 25.67  #破断荷重(KN)
mas_saidai = 12 #最大降伏点のマス数
mas_last = 64 #最終地点のマスの数
Puek = 36.85 #(KN)上降伏点の荷重


a0 = (pi*d0*d0)/4 
af = (pi*df*df)/4
hid = Pmax*1000/a0

hip =(29690/a0)/65  #ひとます当たりの応力(MPa/mas)
hio = (29690/65)    #ひとます当たりの荷重(N/mas)

    
#処理
Puek*=1e3
pf*=1e3#破断荷重(NからKN)
hizumi_last = (L-L0)/L0
t = mas_last/hizumi_last
hiz = hizumi_last*mas_saidai/mas_last
E = (Puek/a0)/hiz #ヤング率

print("A0=", a0, "(mm^2)")
print("Af=", af, "(mm^2)")


sig_f = pf/af
print("破断応力=", sig_f, "MPa")

print("破断応力のマス目は=", sig_f/hip, "マスです")
print("最終時点のひずみは", hizumi_last, "です")
print("(-1, 0)までのマスの数は", t, "です")
print("ヤング率は", E, "MPaです")
print("引張強さは", hid, "MPaです")
print("絞り", abs(a0-af)/a0)
#設定項目
print("-------650度-----------")
Pmax = 35.67#(KN)最大荷重
L0 = 64.2 #(mm)
L = 75.5 #(mm)
d0 = 7.909 #(mm)
df = 4.7 #(mm)
pf = 23.52  #破断荷重(KN)
mas_saidai = 21 #最大降伏点のマス数x軸
mas_last = 74 #最終地点のマスの数
Puek = 32.73 #(KN)上降伏点の荷重


a0 = (pi*d0*d0)/4 
af = (pi*df*df)/4

hip =(29690/a0)/65  #ひとます当たりの応力(MPa/mas)
hio = (29690/65)    #ひとます当たりの荷重(N/mas)
hid = Pmax*1000/a0
    
#処理
Puek*=1e3
pf*=1e3#破断荷重(NからKN)
hizumi_last = (L-L0)/L0
t = mas_last/hizumi_last
hiz = hizumi_last*mas_saidai/mas_last
E = (Puek/a0)/hiz #ヤング率

print("A0=", a0, "(mm^2)")
print("Af=", af, "(mm^2)")


sig_f = pf/af
print("破断応力=", sig_f, "MPa")

print("破断応力のマス目は=", sig_f/hip, "マスです")
print("最終時点のひずみは", hizumi_last, "です")
print("(-1, 0)までのマスの数は", t, "です")
print("ヤング率は", E, "MPaです")
print("引張強さは", hid, "MPaです")
print("絞り", abs(a0-af)/a0)


#設定項目
print("-------700度-----------")
Pmax = 32.05#(KN)最大荷重
L0 = 64.25 #(mm)
L = 77.40 #(mm)
d0 = 7.895 #(mm)
df = 4.43 #(mm)
pf = 19.99  #破断荷重(KN)
mas_saidai = 17 #最大降伏点のマス数x軸
mas_last = 93 #最終地点のマスの数
Puek = 28.42#(KN)上降伏点の荷重


a0 = (pi*d0*d0)/4 
af = (pi*df*df)/4

hip =(29690/a0)/65  #ひとます当たりの応力(MPa/mas)
hio = (29690/65)    #ひとます当たりの荷重(N/mas)
hid = Pmax*1000/a0

    
#処理
Puek*=1e3
pf*=1e3#破断荷重(NからKN)
hizumi_last = (L-L0)/L0
t = mas_last/hizumi_last
hiz = hizumi_last*mas_saidai/mas_last
E = (Puek/a0)/hiz #ヤング率

print("A0=", a0, "(mm^2)")
print("Af=", af, "(mm^2)")


sig_f = pf/af
print("破断応力=", sig_f, "MPa")

print("破断応力のマス目は=", sig_f/hip, "マスです")
print("最終時点のひずみは", hizumi_last, "です")
print("(-1, 0)までのマスの数は", t, "です")
print("ヤング率は", E, "MPaです")
print("引張強さは", hid, "MPaです")
print("絞り", abs(a0-af)/a0)