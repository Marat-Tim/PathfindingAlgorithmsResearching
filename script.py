import pandas as pd
from matplotlib import pyplot as plt

df = pd.read_csv("./vertices.csv", sep=";", index_col="index")

graph_types = ["полный граф", "дерево", "средне-связный граф"]
finders = ["Флойд-Уоршелл", "Дейкстра", "Беллман-Форд"]

fig, axs = plt.subplots(figsize=(7, 21), nrows=len(finders))
for i in range(len(finders)):
    for type in graph_types:
        axs[i].plot(df[f"{finders[i]} + {type}"], label=type)
        axs[i].legend()
        axs[i].set_title(finders[i])
        axs[i].set_xlabel("Количество вершин в графе")
        axs[i].set_ylabel("Время работы в наносекундах")
        axs[i].grid()
fig.tight_layout()
fig.savefig("image/aggregated_by_finders.png", bbox_inches='tight')

fig, axs = plt.subplots(figsize=(7, 21), nrows=len(graph_types))
for i in range(len(graph_types)):
    for finder in finders:
        axs[i].plot(df[f"{finder} + {graph_types[i]}"], label=finder)
        axs[i].legend()
        axs[i].set_title(graph_types[i])
        axs[i].set_xlabel("Количество вершин в графе")
        axs[i].set_ylabel("Время работы в наносекундах")
        axs[i].grid()
fig.tight_layout()
fig.savefig("image/aggregated_by_types.png", bbox_inches='tight')