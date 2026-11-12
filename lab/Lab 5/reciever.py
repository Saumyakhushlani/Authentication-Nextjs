# Scholar No - 24112011148

import socket

server = socket.socket()
server.bind(("localhost", 5000))
server.listen(1)

connection, address = server.accept()

while True:
    data = connection.recv(1024)

    if not data:
        break

    frame = data.decode()
    print("Received:", frame)

    connection.send(("ACK " + frame).encode())

connection.close()
server.close()