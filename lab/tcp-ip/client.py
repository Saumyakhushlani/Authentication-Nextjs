# Scholar No : 24112011148
import socket

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(("127.0.0.1", 5000))

while True:
    message = input("Enter message (exit to quit): ")
    if message == "exit":
        break
    client.sendall(message.encode())
    data = client.recv(1024)
    print("Echo from server:", data.decode())

client.close()