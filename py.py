#%%
import numpy as np
def ppmi(C, verbose = False, eps = 1e-8):
    M = np.zeros_like(C, dtype = np.float32)
    N = np.sum(C)
    S = np.sum(C, axis=0)
    total = C.shape[0] * C.shape[1]
    cnt = 0

    for i in range(C.shape[0]):
        for j in range(C.shape[1]):
            pmi = np.log2(C[i, j] * N /(S[j]*S[i]+eps))
            M[i, j] = max(0, pmi)

            if verbose:
                cnt+=1
            if cnt % (total//100 + 1) == 0:
                print('%.1f%% done' % (100*cnt/total))
    return M
#%%
import numpy as np
a = np.array([[1, 2, 3], [4, 5, 6], [2, 4, 5]])
a.shape
# %%
a.shape[0]
# %%
