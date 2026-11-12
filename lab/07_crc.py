# Name : Saumya Khushlani
# Scholar : 24112011148
def xor_operation(a, b):
    result = ""

    for i in range(1, len(b)):
        if a[i] == b[i]:
            result += "0"
        else:
            result += "1"

    return result


def modulo2_div(dividend, divisor):
    pick = len(divisor)
    temp = dividend[:pick]

    while pick < len(dividend):
        if temp[0] == "1":
            temp = xor_operation(divisor, temp) + dividend[pick]
        else:
            temp = xor_operation("0" * pick, temp) + dividend[pick]

        pick += 1

    if temp[0] == "1":
        temp = xor_operation(divisor, temp)
    else:
        temp = xor_operation("0" * pick, temp)

    return temp


def crc_encode(data, key):
    data = data + "0" * (len(key) - 1)
    remainder = modulo2_div(data, key)

    return data[:-(len(key) - 1)] + remainder


def crc_check(data, key):
    remainder = modulo2_div(data, key)
    return int(remainder) == 0


data = "100100"
key = "1101"

codeword = crc_encode(data, key)

print("Original Data:", data)
print("CRC Key:", key)
print("Encoded Data:", codeword)

print("Receiver Check (Uncorrupted):",
      "Valid" if crc_check(codeword, key) else "Error")

corrupted = codeword[:-1] + ("1" if codeword[-1] == "0" else "0")

print("Receiver Check (Corrupted):",
      "Valid" if crc_check(corrupted, key) else "Error")
