'' Super Uwol Map Converter v0.1
'' For the NES/SMS/SG-1000 ports
'' Copyleft 2015 by The Mojon Twins

Dim Shared As uByte coins (1023)

Function readByteAndDoYourShit (fH As Integer, nPant As Integer, nTile As Integer) As uByte
	Dim As uByte d
	Dim As Integer i
	
	Get #fH, , d
	
	' Register star?
	If d = 4 Then 
		d = 0
		For i = nPant * 16 To 15 + nPant * 16
			If coins (i) = 0 Then
				coins (i) = nTile
				Exit For
			End If
		Next i
	End if
	
	readByteAndDoYourShit = d
End Function

Dim As Integer i, j, idx, x, y, fIn, fOut
Dim As uByte d, fullByte

If Command (1) <> "do" Then 
	? "This program has a fixed rason d'être so it won't take parameters."
	? "However, as a safeguard in case you don't have the stuff this program needs,"
	? "I'll be printing some instructions then exiting."
	?
	? "You need uwol.map in the same folder as this file."
	? "uwol.map needs to be a 16x660 tiles plain map, headerless."
	? "This should make for 55 full screens, arranged vertically."
	? "Each screen is 16x12. Tileset must be:"
	?
	? "0 = background"
	? "1 = peril"
	? "2 = platform"
	? "3 = obstacle"
	? "4 = coin"
	?
	? "This will output uwolmap.h with everything the game engine needs."
	? "You have to copy this file to /dev/assets or whatever."
	?
	? "Finally, run"
	?
	? "$ suwolmapcnv.exe do"
	? 
	? "To avoid this screen and let me do my job. Thanks."
	System
End If

fIn = FreeFile
Open "uwol.map" For Binary As #fIn

fOut = FreeFile
Open "uwolmap.h" For Output As #fOut

Print #fOut, "// uwolmap.h"
Print #fOut, "// Super Uwol screen data & coins data"
Print #fOut, "// Copyleft 2015 by The Mojon Twins"
Print #fOut, " "
Print #fOut, "const unsigned char map [] = {"

For i = 0 To 54
	If Eof (fIn) Then Print "ERROR! Not enough screens in uwol.map? "
	Print #fOut, "	";
	For j = 0 To 191 Step 4
		fullByte = readByteAndDoYourShit (fIn, i, j)
		fullByte = fullByte Or (readByteAndDoYourShit (fIn, i, j + 1) Shl 2)
		fullByte = fullByte Or (readByteAndDoYourShit (fIn, i, j + 2) Shl 4)
		fullByte = fullByte Or (readByteAndDoYourShit (fIn, i, j + 3) Shl 6)
		Print #fOut, "0x" & Lcase (Hex (fullByte, 2));
		If j < 188 Or i < 55 Then Print #fOut, ", ";
	Next j
	Print #fOut, ""
Next i

Print #fOut, "};"
Print #fOut, ""
Print #fOut, "const unsigned char coins [] = {"
idx = 0
For i = 0 To 54
	Print #fOut, "	";
	For j = 1 To 16
		Print #fOut, "0x" & Lcase (Hex (coins (idx), 2));
		If j < 16 Or i < 55 Then Print #fOut, ", ";
		idx = idx + 1
	Next j
	Print #fOut, ""
Next i
Print #fOut, "};"
Print #fOut, ""

Print "uwol.map read. uwolmap.h written. Podewwwr!"
