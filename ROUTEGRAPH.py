import sys
import networkx as nx
import matplotlib.pyplot as plt
if __name__ == "__main__":
    print(sys.argv[0])
    print(sys.argv[1])
    f = open("out.txt", "r")
    path = f.read()
    cities = path.split(",")
    print(cities)
    g = nx.Graph()
    for i in range(len(cities)-2):
        print(cities[i], cities[i+1])
        g.add_edge(cities[i], cities[i+1])
    nx.draw(g, with_labels=True)
    plt.savefig("graph.png")
