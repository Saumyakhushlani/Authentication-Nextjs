#Scholar No : 24112011148

n = int(input("Enter number of routers: "))
print("Enter cost matrix (999 for infinity):")
dist = [list(map(int, input().split())) for _ in range(n)]

for k in range(n):
    for i in range(n):
        for j in range(n):
            if dist[i][j] > dist[i][k] + dist[k][j]:
                dist[i][j] = dist[i][k] + dist[k][j]

for i in range(n):
    print("Router", i + 1)
    for j in range(n):
        print("To router", j + 1, "cost =", dist[i][j])