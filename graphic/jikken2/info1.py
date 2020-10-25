import matplotlib.pyplot as plt
y =[40.4, 75.1, 31.4]
labels = ['before', 'A', 'B']
x = [1, 2, 3]
fig = plt.figure()
ax = fig.add_subplot(1, 1, 1)
bar_list = ax.bar(x, y, tick_label=labels)
bar_list[0].set_color("g")
bar_list[1].set_color("deeppink")
bar_list[2].set_color("blue")
plt.ylabel('average')
plt.xlabel('type')
plt.show()












