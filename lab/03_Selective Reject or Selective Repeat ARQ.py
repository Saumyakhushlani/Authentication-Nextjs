# Name : Saumya Khushlani
# Scholar : 24112011148
import random

def selective_repeat(n, window):
    ack = [False] * n
    base = 0

    while base < n:

        end = min(base + window, n)

        print("\nCurrent Window:", base, "to", end - 1)

        for i in range(base, end):

            if not ack[i]:
                print("[Sender] Transmitting Frame", i)

                if random.random() < 0.3:
                    print("[Network] Frame", i, "suffered an error")
                else:
                    print("[Receiver] Frame", i, "received correctly")
                    ack[i] = True

        while base < n and ack[base]:
            base += 1

    print("\nAll frames transmitted successfully!")

selective_repeat(6, 3)
