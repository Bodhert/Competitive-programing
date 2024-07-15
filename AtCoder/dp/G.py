import sys
sys.setrecursionlimit(10**9)

max_know_distances = []


def dfs(graph, node):
    global max_know_distances

    if max_know_distances[node] != -1:
        return max_know_distances[node]

    longest_path = 0
    for neir in graph[node]:
        longest_path = max(longest_path, dfs(graph, neir))

    max_know_distances[node] = 1 + longest_path

    return max_know_distances


def solve(graph):
    for current_node in range(len(graph)):
        dfs(graph, current_node)


def main():
    nodes, edges = map(int, input().split())
    graph = [[] for i in range(nodes)]
    global max_know_distances
    max_know_distances = [-1] * (nodes)
    for i in range(edges):
        from_, to = map(int, input().split())
        from_ -= 1
        to -= 1
        graph[from_].append(to)

    solve(graph)
    print(max(max_know_distances))


main()
