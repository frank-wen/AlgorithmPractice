fin = open('SCC.txt')
numbers = list()
for line in fin:
    string = line.split()
    a = int(string[0])
    b = int(string[1])
    if a not in numbers:
        numbers.append(a)
    if b not in numbers:
        numbers.append(b)

print(len(numbers))
