class Graph:
    def __init__(self):
        self.adj_list = {}

    def add_edge(self, src, dest, cost):
        if src not in self.adj_list:
            self.adj_list[src] = []
        if dest not in self.adj_list:
            self.adj_list[dest] = []

        self.adj_list[src].append((dest, cost))

    def UCS(self, start, goal):
        queue = [(start, [start], 0)]  # node path cost
        while queue:
            node, path, cost = queue.pop(0)
            if node == goal:
                return path, cost

            for neighbour, edge_cost in self.adj_list[node]:
                if neighbour not in path:
                    new_path = path+[neighbour]
                    new_cost = cost+edge_cost
                    queue.append((neighbour, new_path, new_cost))
                    queue.sort()
        return None


def main():
    graph = Graph()

    num_edges = int(input("Enter the number of edges: "))

    for _ in range(num_edges):
        src, dest, cost = input(
            "Enter source, destination, and cost separated by space: ").split()
        graph.add_edge(src, dest, int(cost))

    start_node = input("Enter start node: ")
    goal_node = input("Enter goal node: ")

    path, cost = graph.UCS(start_node, goal_node)

    if path:
        print("Best path:", ' -> '.join(path))
        print("Cost:", cost)
    else:
        print("No path found")


if __name__ == "__main__":
    main()
