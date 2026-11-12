# Name : Saumya Khushlani
# Scholar : 24112011148

def add_parity(data, mode):
    ones = data.count("1")

    if mode == "even":
        bit = "0" if ones % 2 == 0 else "1"
    else:
        bit = "1" if ones % 2 == 0 else "0"

    return data + bit


def check_parity(data, mode):
    ones = data.count("1")

    if mode == "even":
        return ones % 2 == 0
    else:
        return ones % 2 != 0


data = "1011001"

even_data = add_parity(data, "even")
odd_data = add_parity(data, "odd")

print("Original Data:", data)
print("Even Parity Encoded:", even_data)
print("Valid?", check_parity(even_data, "even"))
print("Odd Parity Encoded:", odd_data)
print("Valid?", check_parity(odd_data, "odd"))
