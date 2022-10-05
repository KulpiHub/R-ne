from cs50 import get_int

def main():

    # CC number input
    while True:
        cc_number = get_int("Number: ")

        if (cc_number > 0):
            break

    # CC number length
    cc_number_len = len(str(cc_number))

    # CC number length check, if it's not in range it will break print that card is invalid
    if (cc_number_len != 13 and cc_number_len != 15 and cc_number_len != 16):
        print("INVALID")

    # luhn's algorithm
    def luhn_algo(cc_number):
        def all_digits(n):
            return [int(d) for d in str(n)]
        digits = all_digits(cc_number)
        odd_digits = digits[-1::-2]
        even_digits = digits[-2::-2]
        checksum = 0
        checksum += sum(odd_digits)
        for d in even_digits:
            checksum += sum(all_digits(d*2))
        return checksum % 10

    # CC number company check
    def card_check(cc_number):
        first_two_digits = int(str(cc_number)[0:2])

        if (first_two_digits == 34 or first_two_digits == 37) and cc_number_len == 15:
            print("AMEX")
        elif (first_two_digits >= 40 and first_two_digits < 50) and (cc_number_len == 13 or cc_number_len == 16):
            print("VISA")
        elif (first_two_digits > 50 and first_two_digits < 56) and cc_number_len == 16:
            print("MASTERCARD")
        else:
            print("INVALID")

    print(card_check(cc_number)) if luhn_algo(cc_number) == 0 else print("INVALID!")

if __name__ == "__main__":
    main()