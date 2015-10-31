def swap(arr, i, j):
	temp = arr[i]
	arr[i] = arr[j]
	arr[j] = temp

def quick_sort(arr, l, r):
	if r-l <= 1:
		return
	else:
		i = l+1
		j = l+1
		pivot = arr[l]
		while j < r:
			if arr[j] < pivot:
				swap(arr, i, j)
				i = i+1
			j = j+1
		swap(arr,l,i-1)
	quick_sort(arr, l, i-1)
	quick_sort(arr, i, r)
	
fin = open('IntegerArray.txt')
arr = []
for line in fin:
	number = int(line.strip())
	arr.append(number)

quick_sort(arr,0,len(arr))

index = 0
while index < 30:
	print(arr[index])
	index += 1
