
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

    def BFS(self, start):
        visited = {vertex: False for vertex in self.adj_list}
        queue = [start]
        visited[start] = True
        bfs_order = []

        while queue:
            vertex = queue.pop(0)
            bfs_order.append(vertex)
            for neighbour in self.adj_list[vertex]:
                if not visited[neighbour]:
                    queue.append(neighbour)
                    visited[neighbour] = True
        return bfs_order
