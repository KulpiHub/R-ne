from cs50 import get_string


def main():

    userInput = get_string("Input: ")
    stringLength = string_length(userInput)  # function call
    wordsNumber = string_space(userInput)  # function call
    sentenceNumber = string_end(userInput)  # function call
    indexCalculation = (0.0588 * stringLength / wordsNumber * 100) - (0.296 * sentenceNumber / wordsNumber * 100) - 15.8
    index = round(indexCalculation)

    if index < 1:
        print("Before Grade 1")
    elif index > 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")


# letter counter
def string_length(str):
    letterCounter = 0
    strLen = len(str)
    for i in range(strLen):
        if(str[i].isalpha()):
            letterCounter += 1
    return letterCounter


# word counter
def string_space(str):
    wordCounter = 0
    strLen = len(str)
    for i in range(strLen):
        if(str[i].isspace()):
            wordCounter += 1
    return wordCounter + 1


# sentence counter
def string_end(str):
    sentenceCounter = 0
    strLen = len(str)
    for i in range(strLen):
        if(str[i] == '.' or str[i] == '!' or str[i] == '?'):
            sentenceCounter += 1
    return sentenceCounter


if __name__ == "__main__":
    main()