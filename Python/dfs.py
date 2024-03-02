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
            print(f"Vertex {src}: ", end="")
            for dest in dest_list:
                print(f"({src}->{dest})", end=" ")
            print()

    def DFS(self, start):
        stack = [start]
        visited = {}

        while stack:
            vertex = stack.pop()
            if vertex not in visited:
                print(vertex, end=' ')
                visited[vertex] = True
                for neighbour in (self.adj_list[vertex]):
                    if neighbour not in visited:
                        stack.append(neighbour)


def main():
    graph = Graph()
    edges = int(input("Edges: "))

    for _ in range(edges):
        src, dest = input("Enter src dest: ").split()
        graph.add_edge(src, dest)

    graph.print_graph()

    start = (input("Enter start: "))
    print("DFS: ")
    graph.DFS(start)


if __name__ == '__main__':
    main()
