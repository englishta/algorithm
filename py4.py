#%%
import numpy as np
from sklearn import datasets

iris = datasets.load_iris()
X = iris.data
Y = iris.target

X_train = X[ np.arange(0, len(X), 2) ]
Y_train = Y[ np.arange(0, len(Y), 2) ]

X_test = X[ np.arange(1, len(X), 2) ]
Y_test = Y[ np.arange(1, len(Y), 2) ]

#%%
from sklearn.neighbors import KNeighborsClassifier
from sklearn import metrics
ef = []
k_value = []
for k in range(1, 60):
    model = KNeighborsClassifier(n_neighbors=k)
    model.fit(X_train, Y_train)
    Y_predicted = model.predict(X_test)
    metrics.confusion_matrix(Y_test, Y_predicted)
    ef.append(metrics.accuracy_score(Y_test, Y_predicted))
    k_value.append(k)
# %%
import matplotlib.pyplot as plt
plt.plot(k_value, ef, 'r.-')
# %%
