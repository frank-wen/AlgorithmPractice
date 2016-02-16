
int * merge(int * head, int * tail, int length) {
     int * merged = malloc(length * sizeof(int));
     int headIndex, tailIndex;
     headIndex = tailIndex = 0;
     while (headIndex < length/2 && tailIndex < length - length/2 ) {
		 if (head[headIndex] < tail[tailIndex]) 
             *merged++ = head[headIndex++];
         else
            *merged++ = tail[tailIndex++];
    }
   while(headIndex < length/2) {
        *merged++ = head[headIndex++];
   }
    while(tailIndex < length - length/2) {
		*merged++ = tail[tailIndex++];
	}
    return  merged - length;
}


int * mergeSort(int * array, int length) {
    if (length > 1) {
        int * head, * tail;
        head = array;
        tail = array + length/2;
        head =  mergeSort(head, length/2);
        tail = mergeSort(tail, length - length/2);
        array =  merge(head, tail,length);

    }
    return array;
}


