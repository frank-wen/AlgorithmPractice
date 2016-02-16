heap_low = list()
heap_high = list()

med = 0
meds = list()
n = 0
fin = open('Median.txt')
for line in fin:
    number = int(line)
    if number > med:
        heap_high.append(number)
        heap_high.sort(reverse = True)
    else:
        heap_low.append(number)
        heap_low.sort()
    l1 = len(heap_high)
    l2 = len(heap_low)
    if l1-l2 > 1:
        heap_low.append(heap_high.pop())
        med = heap_low[l2]
    elif l2-l1 > 1:
        heap_high.append(heap_low.pop())
        med = heap_low[l2-2]
    elif l1 - l2 == 1:
        med = heap_high[l1-1]
    else:
        med = heap_low[l2-1]
    meds.append(med)
    if len(meds) < 10:
        print(med)

print(len(meds),sum(meds))

