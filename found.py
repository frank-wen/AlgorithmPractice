fin = open('kargerMinCut.txt')
short = 100
word = list()
line = 1
n = 0
for line in fin:
    n = n+1
    words = line.split()
    if len(words) < short:
        short = len(words)
        word = words
        line = n

print(word,line)
