# Name : Saumya Khushlani
# Scholar : 24112011148
def vrc_encode(data):
    result = []

    for block in data:
        parity = "0" if block.count("1") % 2 == 0 else "1"
        result.append(block + parity)

    return result


def vrc_check(data):
    for block in data:
        if block.count("1") % 2 != 0:
            return False

    return True


data = ["1100001", "1100010", "1100011"]

encoded = vrc_encode(data)

print("VRC Encoded Blocks:", encoded)
print("VRC Check Result:", "Valid" if vrc_check(encoded) else "Corrupted")
