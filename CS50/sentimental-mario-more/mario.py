from cs50 import get_int


def hash(ctype, times):
    print(ctype * times, end="")


def main():
    while True:
        input = get_int("Height: ")

        if (input >= 1 and input <= 8):
            break

    hash_index = 1
    for i in range(input):
        hash(" ", input - 1 - i)
        hash("#", hash_index + i)
        hash(" ", 2)
        hash("#", hash_index + i)
        print()

if __name__ == "__main__":
    main()
    