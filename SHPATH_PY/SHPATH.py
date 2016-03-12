#Modified from: https://gist.github.com/mdsrosa/c71339cb23bc51e711d8

from collections import defaultdict, deque
import sys


class Graph(object):
    def __init__(self):
        self.nodes = set()
        self.edges = defaultdict(list)
        self.distances = {}

    def add_node(self, value):
        self.nodes.add(value)

    def add_edge(self, from_node, to_node, distance):
        self.edges[from_node].append(to_node)
        self.edges[to_node].append(from_node)
        self.distances[(from_node, to_node)] = distance


def dijkstra(graph, initial):
    visited = {initial: 0}
    path = {}

    nodes = set(graph.nodes)

    while nodes:
        min_node = None
        for node in nodes:
            if node in visited:
                if min_node is None:
                    min_node = node
                elif visited[node] < visited[min_node]:
                    min_node = node
        if min_node is None:
            break

        nodes.remove(min_node)
        current_weight = visited[min_node]

        for edge in graph.edges[min_node]:
            try:
                weight = current_weight + graph.distances[(min_node, edge)]
            except:
                continue
            if edge not in visited or weight < visited[edge]:
                visited[edge] = weight
                path[edge] = min_node

    return visited, path


def shortest_path(graph, origin, destination):
    visited, paths = dijkstra(graph, origin)
    full_path = deque()
    _destination = paths[destination]

    while _destination != origin:
        full_path.appendleft(_destination)
        _destination = paths[_destination]

    full_path.appendleft(origin)
    full_path.append(destination)

    #return visited[destination], list(full_path)
    return visited[destination]

if __name__ == '__main__':

    num_tests = sys.stdin.readline()
    num_tests = int(num_tests.strip())
    #print "Number of tests: %d" % num_tests 

    for test in range(num_tests):
        graph = Graph()
        cities = ['']
        edges = []
        paths = []
        num_cities = sys.stdin.readline()
        num_cities = int(num_cities.strip())
        #print "Number of cities: %d" % num_cities
        for city_id in range(1, num_cities+1):
	    city_name = sys.stdin.readline()
            city_name = city_name.strip()
            cities.append(city_name)
            #print cities[city_id]
            num_neighbors = sys.stdin.readline()
            num_neighbors = int(num_neighbors.strip())
            #print "Number of neighbors: %d" % num_neighbors
            for neighbor in range(num_neighbors):
                edge = sys.stdin.readline()
                edge = edge.strip()
                edge = edge.split()
                nr = int(edge[0])
                cost = int(edge[1])
                #print edge
                edges.append([city_id, nr, cost])
        num_paths = sys.stdin.readline()
        num_paths = int(num_paths.strip())
        #print "Number of paths to find: %d" % num_paths
        for line in range(num_paths):
            line = sys.stdin.readline()
            line = line.strip()
            endpoints = line.split()
            #print endpoints
            paths.append([endpoints[0], endpoints[1]])
        for city_id in range(1, num_cities+1):
            #print cities[city_id]
            graph.add_node(cities[city_id])
        for edge in range(len(edges)):
            edges[edge][0] = cities[edges[edge][0]]
            edges[edge][1] = cities[edges[edge][1]]
            #print edges[edge]
            graph.add_edge(edges[edge][0], edges[edge][1], edges[edge][2])
        for path in range(len(paths)):
            #print paths[path]
            print(shortest_path(graph, paths[path][0], paths[path][1]))
        print
                  

#    for node in ['A', 'B', 'C', 'D', 'E', 'F', 'G']:
#        graph.add_node(node)

#    graph.add_edge('A', 'B', 10)
#    graph.add_edge('A', 'C', 20)
#    graph.add_edge('B', 'D', 15)
#    graph.add_edge('C', 'D', 30)
#    graph.add_edge('B', 'E', 50)
#    graph.add_edge('D', 'E', 30)
#    graph.add_edge('E', 'F', 5)
#    graph.add_edge('F', 'G', 2)

#    print(shortest_path(graph, 'A', 'D')) # output: (25, ['A', 'B', 'D'])