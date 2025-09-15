# This program cleans the word list to remove
# all lines that contain symbols other than a-z A-Z
# original word list
# https://raw.githubusercontent.com/kkrypt0nn/wordlists/refs/heads/main/wordlists/languages/english.txt
import fileinput

with fileinput.input(files=('english.txt'), encoding="utf-8", inplace=True) as f:
    for line in f:
        line = line.strip()
        if not line.isalpha() or len(line) < 4:
           print("", end="")
        else:
            print(line)


