import socket

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

ip = input("Enter server IP: ")
client.connect((ip, 5000))

filename = input("Enter file name: ")

client.send(filename.encode())

file = open(filename, "rb")

while True:
    data = file.read(1024)

    if not data:
        break

    client.send(data)

file.close()
client.close()

print("File sent successfully")