# Name : Saumya Khushlani
# Scholar : 24112011148

import random

def go_back_n(n, window):
    base = 0
    next_frame = 0

    while base < n:

        while next_frame < base + window and next_frame < n:
            print("[Sender] Sending Frame", next_frame)
            next_frame += 1

        print("\nChecking status of Frame", base)

        if random.random() < 0.25:
            print("[Error] Frame", base, "or its ACK was lost/corrupted")
            print("[Sender] Go-Back-N: Resetting window back to Frame", base)
            next_frame = base
        else:
            print("[Receiver] ACK received for Frame", base)
            base += 1


go_back_n(7, 3)
