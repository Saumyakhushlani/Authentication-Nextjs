# Name : Saumya Khushlani
# Scholar : 24112011148


def parity_bits(m):
    r = 0
    while 2 ** r < m + r + 1:
        r += 1
    return r


def generate_code(data):
    m = len(data)
    r = parity_bits(m)
    n = m + r
    code = [0] * n
    j = 0
    for i in range(1, n + 1):
        if i & (i - 1):
            code[i - 1] = int(data[j])
            j += 1

    for i in range(r):
        pos = 2 ** i
        parity = 0

        for j in range(1, n + 1):
            if j & pos:
                parity ^= code[j - 1]

        code[pos - 1] = parity

    return "".join(map(str, code)), r


def check_code(code, r):
    n = len(code)
    error = 0

    for i in range(r):
        pos = 2 ** i
        parity = 0

        for j in range(1, n + 1):
            if j & pos:
                parity ^= int(code[j - 1])

        if parity:
            error += pos

    if error == 0:
        return "Valid Data Received", code

    if error <= n:
        code = list(code)
        code[error - 1] = "0" if code[error - 1] == "1" else "1"
        return "Error detected at bit position " + str(error) + " -> Corrected", "".join(code)

    return "Multi-bit Error Detected", code


data = "1011"

code, r = generate_code(data)

print("Original Data Bits:", data)
print("Generated Hamming Code (7,4):", code)

status, _ = check_code(code, r)
print("Receiver Check (No Error):", status)

corrupted = code[:2] + ("1" if code[2] == "0" else "0") + code[3:]
status, _ = check_code(corrupted, r)
print("Receiver Check (Single Bit Error at Pos 3):", status)

corrupted = list(code)
for pos in (3, 5):
    corrupted[pos - 1] = "1" if corrupted[pos - 1] == "0" else "0"
status, _ = check_code("".join(corrupted), r)
print("Receiver Check (Two Bit Error at Pos 3 & 5):", status)
