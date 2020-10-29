import numpy as np
xs = np.linspace(0, 10, 100)
sins = np.sin(xs)
randoms = np.random.rand(100)

import plotly.graph_objects as go
fig = go.Figure(data=[
    go.Scatter(x=xs, y=sins, name="sin"),
    go.Scatter(x=xs, y=randoms, name="random"),
])
fig.show()
