# Name : Saumya Khushlani
# Scholar : 24112011148
import random

def stop_and_wait(n):
    seq = 0
    frame = 1

    while frame <= n:
        print("\n[Sender] Sending Frame", frame, "(Seq:", seq, ")")

        if random.random() < 0.2:
            print("[Network] Frame", frame, "lost! Timeout occurred.")
            print("[Sender] Resending Frame", frame)
            continue

        print("[Receiver] Received Frame", frame, "(Seq:", seq, "). Sending ACK...")

        if random.random() < 0.2:
            print("[Network] ACK lost! Timeout occurred.")
            print("[Sender] Resending Frame", frame)
            continue

        print("[Sender] ACK", seq, "received.")
        seq = 1 - seq
        frame += 1

stop_and_wait(4)
