import socket

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

client.connect(("127.0.0.1", 5000))

while True:
    message = input("Client: ")
    client.send(message.encode())

    if message == "exit":
        break

    message = client.recv(1024).decode()
    print("Server:", message)

    if message == "exit":
        break

client.close()