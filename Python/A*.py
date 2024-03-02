class Graph:

    def __init__(self):
        self.adj_list = {}

    def add_edge(self, src, dest, cost):
        if src not in self.adj_list:
            self.adj_list[src] = []
        if dest not in self.adj_list:
            self.adj_list[dest] = []

        self.adj_list[src].append((dest, cost))

    def a_star(self, start, goal, heuristic):
        queue = [(0, start, [start], 0)]  # priority, node, visited,cost
        while queue:
            priority, node, path, cost = queue.pop(0)

            if node == goal:
                return path, cost

            for neighbour, edge_cost in self.adj_list[node]:
                if neighbour not in path:
                    new_path = path+[neighbour]
                    new_cost = cost+edge_cost
                    priority = new_cost+heuristic(neighbour, goal)
                    queue.append((priority, neighbour, new_path, new_cost))
                    queue.sort()


def get_node_heuristics(node, goal):
    heuristic_value = int(input(f"Enter h value for {node} to {goal}:"))
    return heuristic_value


def main():
    graph = Graph()
    edges = int(input("Edges: "))

    for _ in range(edges):
        src, dest, cost = input("Enter src dest cost").split()
        graph.add_edge(src, dest, int(cost))

    start_node = input("Enter start node: ")
    goal_node = input("Enter goal node: ")

    path, cost = graph.a_star(start_node, goal_node, get_node_heuristics)

    if path:
        print("Best path:", ' -> '.join(path))
        print("Cost:", cost)
    else:
        print("No path found")


if __name__ == "__main__":
    main()
