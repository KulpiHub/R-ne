import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")
    # TODO: Read database file into a variable
    databaseCSV = sys.argv[1]
    with open(databaseCSV, mode="r") as data:
        reader = csv.DictReader(data)
        dataList = list(reader)

    # TODO: Read DNA sequence file into a variable
    sequenceCSV = sys.argv[2]
    with open(sequenceCSV, mode="r") as file:
        sequence = file.read()
    # TODO: Find longest match of each STR in DNA sequence
    counts = []
    for i in range(1, len(reader.fieldnames)):
        string = reader.fieldnames[i]
        counts.append(0)

        for j in range(len(sequence)):
            stringCounter = 0

            if sequence[j:(j + len(string))] == string:
                x = 0
                while sequence[(j + x):(j + x + len(string))] == string:
                    stringCounter += 1
                    x += len(string)
                if stringCounter > counts[i - 1]:
                    counts[i - 1] = stringCounter
    # TODO: Check database for matching profiles
    for i in range(len(dataList)):
        match = 0
        for j in range(1, len(reader.fieldnames)):
            if int(counts[j - 1]) == int(dataList[i][reader.fieldnames[j]]):
                match += 1
        if match == (len(reader.fieldnames) - 1):
            print(dataList[i]['name'])
            sys.exit(0)
    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
