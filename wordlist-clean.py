# This program cleans the word list to remove
# all lines that contain symbols other than a-z A-Z
# original word list
# https://raw.githubusercontent.com/kkrypt0nn/wordlists/refs/heads/main/wordlists/languages/english.txt
import fileinput
import random

mvlst: list[str] = []

with fileinput.input(files=('english.txt'), encoding="utf-8", inplace=True) as f:
    for line in f:
        line = line.strip()
        if not line.isalpha() or len(line) < 4:
           print("", end="")
        else:
            if random.randint(1,5) == 2:
                mvlst.append(line)
                print("", end="")
            else:
                print(line)

with open(file="english.txt", mode="a") as f:
    for l in mvlst:
        f.write(l + "\n")
