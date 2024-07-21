from cs50 import get_int

height = get_int("Pyramid height: ")
if height < 1 or height > 8:
    height = get_int("Pyramid Height: ")

for i in range(height):
    print((height - 1 - i) * " ", end="")
    print((i + 1) * "#")