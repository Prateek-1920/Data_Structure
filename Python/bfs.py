class Graph:
    def __init__(self):
        self.adj_list = {}

    def add_edge(self, src, dest, weight):
        if src not in self.adj_list:
            self.adj_list[src] = []
        if dest not in self.adj_list:
            self.adj_list[dest] = []

        self.adj_list[src].append((dest, weight))
        # self.adj_list[dest].append(src)  #for undirected

    def print_graph(self):
        for src, dest_list in self.adj_list.items():
            print(f"Vertex {src}:", end='')
            for dest, weight in dest_list:
                print(f"({src}->({dest},{weight})", end='')
            print()

    def BFS(self, start):
        visited = {}
        queue = [start]

        while queue:
            vertex = queue.pop(0)
            if vertex not in visited:
                print(vertex, end=' ')
                visited[vertex] = True
                for neighbour,weight in self.adj_list[vertex]:
                    if neighbour not in visited:
                        queue.append(neighbour)


def main():
    graph = Graph()
    edges = int(input("Edges: "))

    for _ in range(edges):
        src, dest, weight = input("Enter src dest and weight").split()
        graph.add_edge(src, dest, int(weight))

    graph.print_graph()

    print("BFS")
    start = (input("Start vertex: "))
    graph.BFS(start)


if __name__ == '__main__':
    main()
