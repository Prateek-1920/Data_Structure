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
            print(f"Vertex {src}:", end='')
            for dest in dest_list:
                print(f"({src}->{dest})", end='')
            print()

    def DFS(self, start, visited, stack):
        visited[start] = True
        stack[start] = True

        for neighbour in self.adj_list[start]:
            if not visited[neighbour]:
                if self.DFS(neighbour, visited, stack):
                    return True
            elif stack[neighbour]:
                return True
        stack[start] = False
        return False

    def cycle(self):
        visited = {vertex: False for vertex in self.adj_list}
        stack = {vertex: False for vertex in self.adj_list}

        for vertex in self.adj_list:
            if not visited[vertex]:
                if self.DFS(vertex, visited, stack):
                    return True
        return False


def main():
    graph = Graph()

    vertices = int(input("Vertices: "))
    edges = int(input("Egdes: "))

    for _ in range(edges):
        src, dest = map(int, input("ENter src dest: ").split())
        graph.add_edge(src, dest)

    graph.print_graph()

    if graph.cycle() == True:
        print("Cycle detetc")
    else:
        print("No cycle")


if __name__ == '__main__':
    main()
