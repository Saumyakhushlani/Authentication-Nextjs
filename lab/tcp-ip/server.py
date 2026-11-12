# Scholar No : 24112011148
import socket
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(("127.0.0.1", 5000))
server.listen(1)

print("Server waiting for connection...")
conn, addr = server.accept()
print("Connected:", addr)

while True:
    data = conn.recv(1024)
    if not data:
        break
    print("Client:", data.decode())
    conn.sendall(data)

conn.close()
server.close()