#%%
import numpy as np
x1=[3, 2, 3, 3, 2, 2, 2, 2, 3, 2, 1, 2, 1, 3, 1]
x2=[3, 2, 2, 1, 2, 1, 2, 3, 2, 1, 1, 2, 1, 3, 1]
x3=[1, 3, 3, 1, 1, 2, 1, 2, 1, 2, 1, 1, 1, 3, 1]
x4=[2, 1, 2, 2, 3, 2, 3, 1, 2, 2, 2, 2, 1, 3, 1]
x5=[2, 3, 1, 3, 1, 1, 2, 2, 1, 1, 1, 1, 1, 2, 1]


x1_h = (x1-np.mean(x1)/ np.std(x1, ddof=1))
x2_h = (x2-np.mean(x2)/ np.std(x2, ddof=1))
x3_h = (x3-np.mean(x3)/ np.std(x3, ddof=1))
x4_h = (x4-np.mean(x4)/ np.std(x4, ddof=1))
x5_h = (x5-np.mean(x5)/ np.std(x5, ddof=1))

data = np.array([x1_h, x2_h, x3_h, x4_h, x5_h]).T
data

# %%
from sklearn.decomposition import PCA
import matplotlib.pyplot as plt
model = PCA()
model.fit(data)
z = model.transform(data)
print(z)

fig = plt.figure(figsize=(5, 5))
plt.plot(-z[:,0], z[:, 1], 'r*')


# %%
from sklearn.cluster import KMeans
model = KMeans(n_clusters=4)
Data = (z[:,[0,1]])
model.fit(Data)

label = model.labels_
label



# %%

c1 = Data[np.where(label == 0)[0], :]
c2 = Data[np.where(label == 1)[0], :]
c3 = Data[np.where(label == 2)[0], :]
c4 = Data[np.where(label == 3)[0], :]

fig = plt.figure(figsize=(5, 5))
plt.plot(c1[:,0], c1[:,1], '.')
plt.plot(c2[:,0], c2[:,1], 'r*')
plt.plot(c3[:,0], c3[:,1], 'g+')
plt.plot(c4[:,0], c4[:,1], 'mx')
# %%
from sklearn.discriminant_analysis import LinearDiscriminantAnalysis
model = LinearDiscriminantAnalysis()
data_set = np.array([x1, x2, x3, x4, x5, label]).T
model.fit(data_set[:,[0,1,2,3,4]], data_set[:,5])
model.predict([[3, 3, 1, 3, 3],])

# %%
