class Graph:
    def __init__(self):
        self.adj_list = {}

    def add_edge(self, src, dest):
        if src not in self.adj_list:
            self.adj_list[src] = []
        if dest not in self.adj_list:
            self.adj_list[dest] = []

        self.adj_list[src].append(dest)
        self.adj_list[dest].append(src)

    def print_graph(self):
        for src, dest_list in self.adj_list.items():
            print(f"Vertex {src}:", end='')
            for dest in dest_list:
                print(f"({src}->{dest})", end='')
            print()

    def BFS(self, start):
        visited = {}
        queue = [start]

        while queue:
            vertex = queue.pop(0)
            if vertex not in visited:
                print(vertex, end='')
                visited[vertex] = True
                for neighbour in self.adj_list[vertex]:
                    if neighbour not in visited:
                        queue.append(neighbour)


def main():
    graph = Graph()
    edges = (input("Edges: "))

    for _ in range(edges):
        src, dest = input("Enter src dest").split()
        graph.add_edge(src, dest)

    graph.print_graph()

    print("BFS")
    start = (input("Start vertex: "))
    graph.BFS(start)


if __name__ == '__main__':
    main()
