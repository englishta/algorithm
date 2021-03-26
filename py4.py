from math import gcd, pi, cos, sin, tan, e
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations, combinations_with_replacement


import Crypto.PublicKey.RSA as RSA


# 与えられたもの
N =1615765684321463054078226051959887884233678317734892901740763321135213636796075462401950274602405095138589898087428337758445013281488966866073355710771864671726991918706558071231266976427184673800225254531695928541272546385146495736420261815693810544589811104967829354461491178200126099661909654163542661541699404839644035177445092988952614918424317082380174383819025585076206641993479326576180793544321194357018916215113009742654408597083724508169216182008449693917227497813165444372201517541788989925461711067825681947947471001390843774746442699739386923285801022685451221261010798837646928092277556198145662924691803032880040492762442561497760689933601781401617086600593482127465655390841361154025890679757514060456103104199255917164678161972735858939464790960448345988941481499050248673128656508055285037090026439683847266536283160142071643015434813473463469733112182328678706702116054036618277506997666534567846763938692335069955755244438415377933440029498378955355877502743215305768814857864433151287
E = 3
C = 1220012318588871886132524757898884422174534558055593713309088304910273991073554732659977133980685370899257850121970812405700793710546674062154237544840177616746805668666317481140872605653768484867292138139949076102907399831998827567645230986345455915692863094364797526497302082734955903755050638155202890599808154558034707767377524500302754459807923331810585173010977657982069888996945830789092526932364658459034145456505057469113036134559745659079236466119515004648189278227777550415021840140147319061470183840214034417917161940379351273394212022847037696265532968684592354941479799473941357715953204487236888712642494877545201005807776354854390358015733495331101077851132489983665939643188064986446883595239842621440918456201787168234988410659153219277329426230136499096098072681939491840913961290536851217677043565743644469862992310241563891464225935615676242084658617931225618537173689559419607688905143683603007487996422560430269750305079282818976557285786253025774883158125978164878245223052992502106

# ./mesieve を使ってN=p*qのp,qを求める

# p = 299681192390656691733849646142066664329
# q = 324144336644773773047359441106332937713
# l = (p-1)*(q-1)

# d = RSA.inverse(E, (p-1)*(q-1))
# d = pow(E, -1, l)
# m = pow(C, d, N)
m = C**(1/3)

print(RSA.long_to_bytes(m))