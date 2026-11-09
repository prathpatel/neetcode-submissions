def get_longer_word(word1: str, word2: str) -> str:
    first=len(word1)
    second=len(word2)
    if first >= second:
     return word1
    else:
     return word2

    return long_word



# do not modify below this line
print(get_longer_word("yellow", "orange"))
print(get_longer_word("red", "blue"))
print(get_longer_word("green", "blue"))
