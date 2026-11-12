import socket

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server.bind(("127.0.0.1", 5000))
server.listen(1)

print("Waiting for client...")

conn, addr = server.accept()
print("Connected with:", addr)

while True:
    message = conn.recv(1024).decode()

    if message == "exit":
        break

    print("Client:", message)

    message = input("Server: ")
    conn.send(message.encode())

    if message == "exit":
        break

conn.close()
server.close()