

choose_activity(A) {
	i = 0

	for i=1 to n-1 {						// Sorting Runtimes Desc.
		for j=0 to n-2 {
			if(A[j].start < A[j+1].start) {
				swap(A[j], A[j+1])
			}
		}
	}

	A[0] 									// Select 1st Activity

	i = 0

	// Select Next Activity

	for j=1 to n-1 {
		if(A[j].finish <= A[i].start) {
			A[j]
		}
		i = j
	}

}