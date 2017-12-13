Dim As Integer max, prime, current, i, cycle, j

Input "MAX "; max
Input "PRIME "; prime
Input "CYCLE (power of two!) "; cycle


For j = 1 To cycle
	current = j - 1
	For i = 1 To max
		Print Hex (current, 2);
		current = (current + prime): If current > max Then current = current - max
	Next i
	print
Next j
