# %%
# ライブラリインポート
import graphviz
from sklearn.datasets import load_iris
from sklearn.tree import DecisionTreeClassifier
from sklearn.tree import export_graphviz
# データの読み込みとモデルの学習


iris = load_iris()
X, y = load_iris(return_X_y=True)
clf = DecisionTreeClassifier(min_samples_split=5)
clf.fit(X, y)

dot_data = export_graphviz(
                        clf,
                        filled=True,
                        rounded=True,
                        out_file=None
                    )
graph = graphviz.Source(dot_data)
graph.render("iris-tree", format="png")

graph
# %%
