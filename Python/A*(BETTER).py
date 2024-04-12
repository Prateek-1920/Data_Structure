                    
class Graph:
    def __init__(self, adjacency_list, heuristic_values):
        self.adjacency_list = adjacency_list
        self.heuristic_values = heuristic_values

    def get_neighbours(self, vertex):
        return self.adjacency_list[vertex]

    def heuristics(self, node):
        return self.heuristic_values[node]

    def a_star(self, start, stop):
        open_list = [start]  # discovered but not explored
        closed = []  # explored

        g = {start: 0}  # cost of reaching each node
        parents = {start: start}  # stores parents of every node required to reconstruct

        while open_list:
            n = open_list.pop(0)
            for v in open_list:
                if g[v] + self.heuristics(v) < g[n] + self.heuristics(n):
                    n = v
            if n is None:
                print("No path")
                return None

            if n == stop:  # terminating condition
                final_path = []
                while parents[n] != n:
                    final_path.append(n)
                    n = parents[n]

                final_path.append(start)
                final_path.reverse()
                print("Path found: ", final_path)
                return final_path

            for (m, weight) in self.get_neighbours(n):
                if m not in open_list and m not in closed:
                    open_list.append(m)
                    parents[m] = n  # n is parent of m
                    g[m] = g[n] + weight

                else:
                    if g[m] > g[n] + weight:
                        g[m] = g[n] + weight
                        parents[m] = n
                        if m in closed:
                            closed.remove(m)
                            open_list.append(m)

            closed.append(n)
        print("Path does not exist")
        return None

# Taking user input for the graph
adjacency_list = {}
heuristic_values = {}
vertices = input("Enter vertices separated by spaces: ").split()

for vertex in vertices:
    edges_input = input(f"Enter adjacent vertices and weights for vertex {vertex} (format: destination_vertex1 weight1 destination_vertex2 weight2 ...): ").split()
    adjacency_list[vertex] = []
    for i in range(0, len(edges_input), 2):
        adjacent_vertex = edges_input[i]
        weight = int(edges_input[i+1])
        adjacency_list[vertex].append((adjacent_vertex, weight))

    heuristic_value = int(input(f"Enter heuristic value for vertex {vertex}: "))
    heuristic_values[vertex] = heuristic_value

# Creating the graph and finding the shortest path
graph = Graph(adjacency_list, heuristic_values)
start_vertex = input("Enter start vertex: ")
stop_vertex = input("Enter stop vertex: ")
graph.a_star(start_vertex, stop_vertex)
