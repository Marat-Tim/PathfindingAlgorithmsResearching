import pandas as pd
from matplotlib import pyplot as plt

df = pd.read_csv("./vertices.csv", sep=";", index_col="index")

graph_types = ["полный граф", "дерево", "средне-связный граф"]
finders = ["Флойд-Уоршелл", "Дейкстра", "Беллман-Форд"]

max_time = df.max().max()
fig, axs = plt.subplots(figsize=(20, 20), nrows=len(finders), ncols=len(graph_types))
for i in range(len(finders)):
    for j in range(len(graph_types)):
        axs[i][j].plot(df[f"{finders[i]} + {graph_types[j]}"])
        axs[i][j].set_title(f"{finders[i]} + {graph_types[j]}")
        axs[i][j].set_xlabel("Количество вершин в графе")
        axs[i][j].set_ylabel("Время работы в наносекундах")
        axs[i][j].grid()
fig.savefig("image/separately.png")

fig, axs = plt.subplots(figsize=(7, 21), nrows=len(graph_types))
for i in range(len(graph_types)):
    for finder in finders:
        axs[i].plot(df[f"{finder} + {graph_types[i]}"], label=finder)
        axs[i].legend()
        axs[i].set_title(graph_types[i])
        axs[i].set_xlabel("Количество вершин в графе")
        axs[i].set_ylabel("Время работы в наносекундах")
        axs[i].grid()
fig.savefig("image/aggregated.png")