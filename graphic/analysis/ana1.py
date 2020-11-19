# %%
seq1 = ['foo', 'bar', 'baz']
seq2 = ['one', 'two', 'three']
#for x, y in zip(seq1, seq2):
#    print(x, y)

for i, (a, b) in enumerate(zip(seq1, seq2)):
    print(i, a, b)
# %%
