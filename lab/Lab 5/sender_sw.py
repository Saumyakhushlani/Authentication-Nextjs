# Scholar No - 24112011148
import socket
import time
client = socket.socket()
client.connect(("localhost", 6000))

frames = ["F1", "F2", "F3", "F4", "F5"]
window_size = 3

start = 0

while start < len(frames):
    end = min(start + window_size, len(frames))

    for i in range(start, end):
        print("Sending:", frames[i])
        client.send(frames[i].encode())
        time.sleep(0.5)

    ack = client.recv(1024).decode()
    print("Received:", ack)

    start = end

client.close()