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

    def print_list(self):
        for src, dest_list in self.adj_list.items():
            print(f"Vertex {src}: ", end=" ")
            for dest in dest_list:
                print(f"({src}->{dest})", end=" ")
            print()


def main():
    graph = Graph()
    vertices = int(input("Number of vertices: "))
    edges = int(input("Number of edges: "))

    for _ in range(edges):
        src, dest = map(int, input("Enter src and dest: ").split())
        graph.add_edge(src, dest)

    graph.print_list()


if __name__ == "__main__":
    main()
