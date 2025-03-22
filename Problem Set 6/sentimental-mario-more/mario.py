from cs50 import get_int

while True:
    height = get_int("Height: ")
    if 0 < height < 9:
        break

for i in range(height):
    spaces = height - 1
    while spaces > i:
        print(" ", end="")
        spaces -= 1
    for j in range(i + 1):
        print("#", end="")
    print("  ", end="")

    for k in range(i + 1):
        print("#", end="")
    print()
