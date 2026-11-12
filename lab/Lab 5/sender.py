# Scholar No - 24112011148

import socket
import time

client = socket.socket()
client.connect(("localhost", 5000))

frames = ["Frame1", "Frame2", "Frame3", "Frame4"]

for frame in frames:
    print("Sending:", frame)
    client.send(frame.encode())

    ack = client.recv(1024).decode()
    print("Received:", ack)

    time.sleep(1)

client.close()