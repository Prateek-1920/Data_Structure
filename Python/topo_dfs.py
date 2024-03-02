class Graph:
    def __init__(self):
        self.adj_list = {}

    def add_edge(self, src, dest):
        if src not in self.adj_list:
            self.adj_list[src] = []
        if dest not in self.adj_list:
            self.adj_list[dest] = []

        self.adj_list[src].append(dest)

    def print_graph(self):
        for src, dest_list in self.adj_list.items():
            print(f"Vertex {src}: ", end="")
            for dest in dest_list:
                print(f"({src}->{dest})", end=" ")
            print()

    def DFS(self, start, visited, stack):
        visited[start] = True
        for neighbour in self.adj_list[start]:
            if not visited[neighbour]:
                self.DFS(neighbour, visited, stack)
        stack.append(start)

    def toposort(self):
        visited = {vertex: False for vertex in self.adj_list}
        stack = []

        for vertex in self.adj_list:
            if not visited[vertex]:
                self.DFS(vertex, visited, stack)

        return stack[::-1]


def main():
    graph = Graph()
    vertices = int(input("Verti: "))
    edges = int(input("edg: "))

    for _ in range(edges):
        src, dest = map(int, input("Src dest :").split())
        graph.add_edge(src, dest)

    graph.print_graph()

    print("TOP SORT")
    top = graph.toposort()
    print(top)


if __name__ == '__main__':
    main()
