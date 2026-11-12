# Scholar No : 24112011148

import heapq

n = int(input("Enter number of routers: "))
graph = [[] for _ in range(n)]

m = int(input("Enter number of links: "))

for _ in range(m):
    u, v, w = map(int, input("Enter router1 router2 cost: ").split())
    graph[u - 1].append((v - 1, w))
    graph[v - 1].append((u - 1, w))

src = int(input("Enter source router: ")) - 1
dist = [float('inf')] * n
dist[src] = 0
pq = [(0, src)]

while pq:
    d, u = heapq.heappop(pq)
    if d != dist[u]:
        continue
    for v, w in graph[u]:
        if dist[v] > d + w:
            dist[v] = d + w
            heapq.heappush(pq, (dist[v], v))

for i in range(n):
    print("Router", i + 1, "cost =", dist[i])