fin = open('IntegerArray.txt')
bucket = list(range(100001))

for line in fin:
    number = int(line.strip())
    bucket[number] = 1

j = 0
while j < 100001:
    if bucket[j] == 1:
        if j < 30:
            print(j)
    j = j+1
