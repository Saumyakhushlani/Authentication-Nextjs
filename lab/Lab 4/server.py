import socket

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(("0.0.0.0", 5000))
server.listen(1)

print("Waiting for connection...")

conn, addr = server.accept()
print("Connected with:", addr)

filename = conn.recv(1024).decode()

file = open("received_" + filename, "wb")

while True:
    data = conn.recv(1024)

    if not data:
        break

    file.write(data)

file.close()
conn.close()
server.close()

print("File received successfully")