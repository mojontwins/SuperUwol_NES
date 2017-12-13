Dim As String newOrder, m, o, header, screenEnemies (54), enemiesChunk
Dim As Integer order (54), i, oi, fi, fo, x, y, yy, np, mw, mh, nenems
Dim As uByte map (54, 191), d

''
Cls
? "WILL READ mapa.map & enems.ene!"
? "Sort this out before doing anything. Both must be in the same folder as this"
? "file."
? "Enter new order, numbers 1-55, comma separated."

Line Input newOrder: newOrder = newOrder & ","

oi = 0: o = "": For i = 1 To Len (newOrder)
	m = Mid (newOrder, i, 1): If m = "," Then
		If Len (Trim (o)) Then
			order (oi) = Val (o) - 1
			'? "Value #" & oi & " = " & order (oi)
			o = "": oi = oi + 1
		End If
	Else
		o = o & m
	End If
Next i

If oi <> 54 Then ? "Check your facts. We have 55 levels, 1-55!"

Cls
? "Reading map to memory"
fi = FreeFile
Open "mapa.map" For Binary as #fi
yy = Csrlin
For np = 0 To 54
	x = 1: y = 2
	For i = 0 To 191
		Get #fi, , d: map (np, i) = d
		Locate  y, x: ? Hex (d, 1);
		x = x + 1: If x = 17 Then x = 1: y = y + 1
	Next i
Next np
Close fi

? "Reordering map"

fo = FreeFile
Kill "uwol.map"
Open "uwol.map" For Binary As #fo
? "Writing screen... ";
For oi = 0 To 54
	? order (oi);
	For i = 0 To 191
		d = map (order (oi), i): Put #fo, , d
	Next i
Next oi
Close #fo 

? "Reading enems to memory"
fi = FreeFile
Open "enems.ene" For Binary As #fi
? "Reading header"
header = Input (261, fi)
? "Reading 55 enemy chunks"
For i = 0 To 54
	screenEnemies (i) = Input (24, fi)
Next i

? "Writing reordered enems"
fo = FreeFile
Open "uwol.ene" For Binary As #fo
Put #fo, , header
For oi = 0 To 54
	Put #fo, , screenEnemies (order (oi))
Next oi

? "Filling with all the junk at the end of the file..."
While Not Eof (fi)
	Get #fi, , d: Put #fo, , d
Wend

Close
? "DONE!"
? "uwol.map & uwol.ene written."
