import sys
import math

def edges(graph, u, v):
    neighbors = graph[u]
    return neighbors[v]

def dijkstra(graph, source):
    q = []
    dist = {}
    prev = {}
    dist[source] = 0
    for v in graph:
        if v != source:
            dist[v] = math.inf
            prev[v] = None
        q.append((dist[v], v))
    q.sort()
    while len(q) != 0:
        u = q.pop(0)
        for v in graph[u[1]]:
            alt = dist[u[1]] + edges(graph, u[1], v)
            if alt < dist[v]:
                dist[v] = alt
                prev[v] = u
                for i in range(len(q)):
                    if q[i][1] == v:
                        q[i] = (alt, q[i][1])
                        q.sort()
                        break
    return dist, prev

num_tests = sys.stdin.readline().strip()
for _ in range(int(num_tests)):
    num_cities = sys.stdin.readline().strip()
    cities = []
    graph = {}
    for _ in range(int(num_cities)):
        city_name = sys.stdin.readline().strip()
        num_neighbors = sys.stdin.readline()
        neighbors = []
        for _ in range(int(num_neighbors)):
            neighbor = sys.stdin.readline().strip()
            neighbor = neighbor.split()
            neighbor = (int(neighbor[0]), int(neighbor[1]))
            neighbors.append(neighbor)
        cities.append((city_name, neighbors))
    for city in cities:
        graph[city[0]] = {}
        for neighbor in city[1]:
            neighbor_name = cities[neighbor[0]-1][0]
            graph[city[0]][neighbor_name] = neighbor[1] 
    num_paths = sys.stdin.readline().strip()
    for _ in range(int(num_paths)):
        path = sys.stdin.readline().strip()
        path = path.split()
        fromCity = path[0]
        toCity = path[1]
        dist, prev = dijkstra(graph, fromCity)

        print(dist[toCity], prev[toCity])
    sys.stdin.readline()
