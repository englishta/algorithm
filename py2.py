#%%
even_numbers = [x for x in range(11) if x%2 == 0]
squares = [x*x for x in range(5)]
even_squares = [x*x for x in even_numbers]

print(even_numbers)
print(squares)
print(even_squares)

# %%
if not 0: print("Yes1")
if not 0.0: print("Yes2")
if not []: print("Yes3")
if not {}: print("Yes4")
if not "": print("Yes5")
if not None: print("Yes6")
if not False: print("Yes7")
if not set(): print("Yes8")
# %%
