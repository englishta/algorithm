# #%%
# import numpy as np
# from sklearn import datasets
# iris = datasets.load_iris()
# X = iris.data
# Y = iris.target
# X_train = X[ np.arange(0, len(X), 2) ] # 偶数行: 学習データ(説明変数)
# Y_train = Y[ np.arange(0, len(Y), 2) ] # 偶数行: 学習データ(目的変数: 教師ラベル)
# X_test = X[ np.arange(1, len(X), 2) ] # 奇数行: テストデータ(説明変数)
# Y_test = Y[ np.arange(1, len(Y), 2) ] 

# from sklearn.neural_network import MLPClassifier
# import warnings
# warnings.filterwarnings( 'ignore' )

# # %%
# model = MLPClassifier( hidden_layer_sizes = 10, max_iter = 100000 ) 
# model.fit( X_train, Y_train )
# Y_predicted = model.predict( X_test ) 
# Y_predicted

# # %%
# from sklearn import metrics
# metrics.confusion_matrix( Y_test, Y_predicted )

# # %%

# metrics.accuracy_score( Y_test, Y_predicted ) 

# # %%
# Y_predicted_train = model.predict( X_train )
# metrics.confusion_matrix( Y_train, Y_predicted_train ) 

# # %%
# metrics.accuracy_score( Y_train, Y_predicted_train ) 

# %%
##################report
# %%
import numpy as np
from sklearn import datasets
from sklearn import metrics
from sklearn.neural_network import MLPClassifier
import warnings
import matplotlib.pyplot as plt
warnings.filterwarnings( 'ignore' )

iris = datasets.load_iris()
X = iris.data
Y = iris.target
X_train = X[ np.arange(0, len(X), 2) ] # 偶数行: 学習データ(説明変数)
Y_train = Y[ np.arange(0, len(Y), 2) ] # 偶数行: 学習データ(目的変数: 教師ラベル)
X_test = X[ np.arange(1, len(X), 2) ] # 奇数行: テストデータ(説明変数)
Y_test = Y[ np.arange(1, len(Y), 2) ] 

publi = []
learn = []
k_value = []

for k in range(1, 31):
    model = MLPClassifier( hidden_layer_sizes = k, max_iter = 100000 ) 
    model.fit( X_train, Y_train )
    Y_predicted = model.predict( X_test ) 
    Y_predicted

    k_value.append(k)
    publi.append(metrics.accuracy_score( Y_test, Y_predicted )) 

    Y_predicted_train = model.predict( X_train )
    learn.append(metrics.accuracy_score( Y_train, Y_predicted_train ))



#%%
plt.plot(k_value, publi, 'r.-')
plt.plot(k_value, learn, 'b.-')
print(k_value)
print(publi)
# %%
