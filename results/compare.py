import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv("results/dijkstra.csv")
df_columns = df.keys()
df.head()

# Overview of Floyd
df.plot(x=df_columns[0], y=df_columns[1:], kind="line", marker="o")
plt.xticks(rotation=25)
plt.xlabel('Number of nodes')
plt.ylabel('Time Taken')
plt.title('Dijkstra\'s Algorithm - Time taken for different number of threads', fontsize=12)
plt.grid()
plt.legend()
plt.show()

# Serial vs Parallel Dijkstra - 2 Threads
df.plot(x=df_columns[0], y=[df_columns[1], df_columns[2]], kind="line", marker="o")
plt.xticks(rotation=25)
plt.xlabel('Number of nodes (N)')
plt.ylabel('Time Taken (us)')
plt.title('Dijkstra\'s Algorithm - Serial vs Parallel Execution on 2 Threads ', fontsize=12)
plt.grid()
plt.legend()
plt.show()

# Serial vs Parallel Dijkstra - 2 Threads
df.plot(x=df_columns[0], y=[df_columns[1], df_columns[3]], kind="line", marker="o")
plt.xticks(rotation=25)
plt.xlabel('Number of nodes (N)')
plt.ylabel('Time Taken (us)')
plt.title('Dijkstra\'s Algorithm - Serial vs Parallel Execution on 4 Threads ', fontsize=12)
plt.grid()
plt.legend()
plt.show()

# Serial vs Parallel Dijkstra - 2 Threads
df.plot(x=df_columns[0], y=[df_columns[1], df_columns[4]], kind="line", marker="o")
plt.xticks(rotation=25)
plt.xlabel('Number of nodes (N)')
plt.ylabel('Time Taken (us)')
plt.title('Dijkstra\'s Algorithm - Serial vs Parallel Execution on 6 Threads ', fontsize=12)
plt.grid()
plt.legend()
plt.show()

# Serial vs Parallel Dijkstra - 2 Threads
df.plot(x=df_columns[0], y=[df_columns[1], df_columns[5]], kind="line", marker="o")
plt.xticks(rotation=25)
plt.xlabel('Number of nodes (N)')
plt.ylabel('Time Taken (us)')
plt.title('Dijkstra\'s Algorithm - Serial vs Parallel Execution on 8 Threads ', fontsize=12)
plt.grid()
plt.legend()
plt.show()

# Serial vs Parallel Dijkstra - 2 Threads
df.plot(x=df_columns[0], y=[df_columns[1], df_columns[6]], kind="line", marker="o")
plt.xticks(rotation=25)
plt.xlabel('Number of nodes (N)')
plt.ylabel('Time Taken (us)')
plt.title('Dijkstra\'s Algorithm - Serial vs Parallel Execution on 10 Threads ', fontsize=12)
plt.grid()
plt.legend()
plt.show()

# Serial vs Parallel Dijkstra - 2 Threads
df.plot(x=df_columns[0], y=[df_columns[1], df_columns[7]], kind="line", marker="o")
plt.xticks(rotation=25)
plt.xlabel('Number of nodes (N)')
plt.ylabel('Time Taken (us)')
plt.title('Dijkstra\'s Algorithm - Serial vs Parallel Execution on 12 Threads ', fontsize=12)
plt.grid()
plt.legend()
plt.show()