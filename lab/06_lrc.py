# Name : Saumya Khushlani
# Scholar : 24112011148
def lrc_encode(data):
    length = len(data[0])
    checksum = ""

    for i in range(length):
        count = sum(int(block[i]) for block in data)

        if count % 2 == 0:
            checksum += "0"
        else:
            checksum += "1"

    return data, checksum


def lrc_check(data, checksum):
    _, result = lrc_encode(data)
    return result == checksum


data = ["11100111", "11011101", "00111001"]

blocks, checksum = lrc_encode(data)

print("Data Blocks:", blocks)
print("Computed LRC Checksum:", checksum)
print("Validation:", "Pass" if lrc_check(blocks, checksum) else "Fail")
