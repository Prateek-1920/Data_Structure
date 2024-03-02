class Graph:
    def __init__(self, num_vertices):
        self.num_vertices = num_vertices
        self.adj_matrix = [[0] * num_vertices for _ in range(num_vertices)]

    def add_edge(self, src, dest, weight):
        self.adj_matrix[src][dest] = weight

    def tsp_bfs(self, start):
        visited = [False] * self.num_vertices
        # Queue stores (current city, visited cities, total distance)
        queue = [(start, [start], 0)]
        min_distance = float('inf')
        min_path = []

        while queue:
            current_city, visited_cities, distance = queue.pop(0)

            if len(visited_cities) == self.num_vertices:  # All cities visited
                # Add distance back to start city
                distance += self.adj_matrix[current_city][start]
                if distance < min_distance:
                    min_distance = distance
                    min_path = visited_cities + [start]
                continue

            for next_city in range(self.num_vertices):
                if not visited[next_city] and self.adj_matrix[current_city][next_city] != 0:
                    new_distance = distance + \
                        self.adj_matrix[current_city][next_city]
                    if new_distance < min_distance:  # Pruning: Only explore if potentially shorter path
                        new_visited = visited_cities + [next_city]
                        queue.append((next_city, new_visited, new_distance))
                        visited[next_city] = True  # Mark city as visited

        return min_path, min_distance


def main():
    num_vertices = int(input("Enter the number of cities: "))
    graph = Graph(num_vertices)

    print("Enter the adjacency matrix (row by row):")
    for i in range(num_vertices):
        row = list(map(int, input().split()))
        for j, weight in enumerate(row):
            graph.add_edge(i, j, weight)

    start_city = int(input("Enter the starting city index: "))
    min_path, min_distance = graph.tsp_bfs(start_city)

    print("Shortest path:", min_path)
    print("Shortest distance:", min_distance)


if __name__ == "__main__":
    main()
