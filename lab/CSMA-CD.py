import random

def csma_cd():
    for i in range(5):
        print("Station", i + 1, end=": ")
        if random.random() < 0.7:
            print("Data transmitted successfully")
        else:
            print("Collision detected, retransmitting")

def non_persistent():
    for i in range(5):
        print("Station", i + 1, end=": ")
        if random.random() < 0.6:
            print("Channel available, transmitting")
        else:
            print("Channel busy, waiting")

def one_persistent():
    for i in range(5):
        print("Station", i + 1, end=": ")
        print("Transmitting when channel becomes idle")

def p_persistent():
    p = 0.5
    for i in range(5):
        print("Station", i + 1, end=": ")
        if random.random() < p:
            print("Transmitting")
        else:
            print("Waiting for next slot")

print("1. CSMA/CD")
print("2. Non-persistent CSMA")
print("3. 1-persistent CSMA")
print("4. P-persistent CSMA")

choice = int(input("Enter choice: "))

if choice == 1:
    csma_cd()
elif choice == 2:
    non_persistent()
elif choice == 3:
    one_persistent()
elif choice == 4:
    p_persistent()
else:
    print("Invalid choice")