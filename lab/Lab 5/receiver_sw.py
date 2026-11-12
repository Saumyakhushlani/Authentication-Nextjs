# Scholar No - 24112011148
import socket
server = socket.socket()
server.bind(("localhost", 6000))
server.listen(1)

connection, address = server.accept()

count = 0

while True:
    data = connection.recv(1024)

    if not data:
        break

    frame = data.decode()
    print("Received:", frame)

    count+=1

    if count == 3:
        connection.send("ACK Window".encode())
        count = 0

connection.close()
server.close()