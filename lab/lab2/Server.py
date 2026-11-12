import socket

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server.bind(("127.0.0.1", 5000))
server.listen(1)

print("Server waiting for connection...")

conn, addr = server.accept()

print("Connected with:", addr)

data = conn.recv(1024).decode()
print("Client:", data)

conn.send("Message received".encode())

conn.close()
server.close()