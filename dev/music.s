;this file for FamiTone2 library generated by text2data tool

music_music_data:
	.byte 13
	.word @instruments
	.word @samples-3
	.word @song0ch0,@song0ch1,@song0ch2,@song0ch3,@song0ch4,307,256
	.word @song1ch0,@song1ch1,@song1ch2,@song1ch3,@song1ch4,307,256
	.word @song2ch0,@song2ch1,@song2ch2,@song2ch3,@song2ch4,307,256
	.word @song3ch0,@song3ch1,@song3ch2,@song3ch3,@song3ch4,307,256
	.word @song4ch0,@song4ch1,@song4ch2,@song4ch3,@song4ch4,307,256
	.word @song5ch0,@song5ch1,@song5ch2,@song5ch3,@song5ch4,307,256
	.word @song6ch0,@song6ch1,@song6ch2,@song6ch3,@song6ch4,307,256
	.word @song7ch0,@song7ch1,@song7ch2,@song7ch3,@song7ch4,307,256
	.word @song8ch0,@song8ch1,@song8ch2,@song8ch3,@song8ch4,307,256
	.word @song9ch0,@song9ch1,@song9ch2,@song9ch3,@song9ch4,307,256
	.word @song10ch0,@song10ch1,@song10ch2,@song10ch3,@song10ch4,307,256
	.word @song11ch0,@song11ch1,@song11ch2,@song11ch3,@song11ch4,307,256
	.word @song12ch0,@song12ch1,@song12ch2,@song12ch3,@song12ch4,307,256

@instruments:
	.byte $30 ;instrument $00
	.word @env2,@env0,@env0
	.byte $00
	.byte $30 ;instrument $01
	.word @env1,@env0,@env16
	.byte $00
	.byte $70 ;instrument $02
	.word @env5,@env0,@env0
	.byte $00
	.byte $30 ;instrument $03
	.word @env6,@env12,@env0
	.byte $00
	.byte $30 ;instrument $04
	.word @env7,@env14,@env0
	.byte $00
	.byte $30 ;instrument $05
	.word @env11,@env0,@env0
	.byte $00
	.byte $30 ;instrument $06
	.word @env8,@env0,@env0
	.byte $00
	.byte $30 ;instrument $07
	.word @env1,@env13,@env0
	.byte $00
	.byte $70 ;instrument $08
	.word @env3,@env0,@env17
	.byte $00
	.byte $70 ;instrument $09
	.word @env4,@env0,@env17
	.byte $00
	.byte $30 ;instrument $0a
	.word @env3,@env0,@env17
	.byte $00
	.byte $30 ;instrument $0b
	.word @env4,@env0,@env17
	.byte $00
	.byte $70 ;instrument $0c
	.word @env9,@env15,@env0
	.byte $00
	.byte $70 ;instrument $0d
	.word @env10,@env15,@env0
	.byte $00

@samples:
@env0:
	.byte $c0,$00,$00
@env1:
	.byte $ca,$00,$00
@env2:
	.byte $ce,$00,$00
@env3:
	.byte $cc,$cb,$ca,$ca,$c9,$03,$c8,$03,$c7,$07,$c6,$08,$c5,$0a,$c4,$0c
	.byte $c3,$0c,$c2,$12,$c1,$19,$c0,$00,$16
@env4:
	.byte $c4,$02,$c3,$0c,$c2,$0b,$c1,$12,$c0,$00,$08
@env5:
	.byte $c9,$07,$c6,$05,$c9,$07,$c9,$00,$06
@env6:
	.byte $c7,$00,$00
@env7:
	.byte $cd,$cb,$c9,$c8,$c5,$c3,$c1,$c0,$00,$07
@env8:
	.byte $c7,$c2,$c0,$00,$02
@env9:
	.byte $c8,$c8,$c7,$c7,$c6,$c6,$c5,$c5,$c4,$c4,$c3,$c2,$c1,$00,$0c
@env10:
	.byte $c6,$02,$c5,$02,$c4,$02,$c3,$c3,$c1,$00,$08
@env11:
	.byte $cc,$ca,$c8,$c6,$c4,$c3,$c2,$c1,$c0,$00,$08
@env12:
	.byte $cc,$c0,$00,$01
@env13:
	.byte $c0,$05,$bf,$be,$bd,$bc,$bb,$ba,$b9,$b8,$b7,$b6,$b5,$b4,$b3,$b2
	.byte $b1,$b0,$af,$ae,$ad,$ac,$ab,$aa,$a9,$a8,$a8,$a7,$a7,$a6,$a6,$a5
	.byte $a5,$a4,$a4,$a3,$a3,$a2,$a2,$a1,$a1,$00,$28
@env14:
	.byte $c7,$c3,$c0,$bd,$00,$02
@env15:
	.byte $c0,$c0,$c4,$c4,$c7,$c7,$00,$00
@env16:
	.byte $c0,$0e,$bf,$be,$bd,$bc,$bd,$be,$bf,$c0,$00,$02
@env17:
	.byte $c0,$0f,$c1,$02,$c2,$02,$c1,$02,$c0,$c0,$c0,$00,$02


@song0ch0:
	.byte $fb,$05
@ref0:
	.byte $98,$45,$9a,$45,$98,$45,$9a,$45,$92,$44,$83,$45,$49,$4e,$98,$45
	.byte $9a,$45,$98,$45,$92,$4c,$85,$45,$48,$85,$98,$41,$9a,$41,$98,$41
	.byte $9a,$41,$92,$40,$87,$3b,$40,$98,$41,$9a,$41,$98,$41,$92,$3a,$85
	.byte $40,$85,$44,$81
@ref1:
	.byte $98,$3d,$9a,$3d,$98,$3d,$9a,$3d,$92,$3c,$85,$37,$3d,$98,$3d,$9a
	.byte $3d,$98,$3c,$85,$92,$37,$3d,$36,$83,$36,$98,$41,$9a,$41,$98,$41
	.byte $9a,$40,$85,$92,$3e,$85,$41,$98,$41,$9a,$41,$98,$41,$92,$45,$98
	.byte $45,$9a,$45,$98,$45,$9a,$44,$81
	.byte $ff,$22
	.word @ref0
	.byte $ff,$22
	.word @ref1
@ref4:
	.byte $98,$45,$9a,$45,$98,$44,$85,$92,$44,$85,$fb,$09,$87
@song0ch0loop:
@ref5:
	.byte $00
	.byte $fd
	.word @song0ch0loop

@song0ch1:
@ref6:
	.byte $90,$45,$01,$44,$85,$01,$45,$49,$4e,$89,$4c,$85,$45,$48,$89,$41
	.byte $41,$40,$8d,$3b,$40,$89,$3a,$85,$40,$85,$44,$85
@ref7:
	.byte $3c,$89,$36,$89,$3c,$89,$36,$85,$37,$3d,$36,$85,$37,$40,$89,$3e
	.byte $89,$40,$89,$44,$85,$86,$41,$45,$49,$4f,$4c,$81
	.byte $ff,$1b
	.word @ref6
	.byte $ff,$1b
	.word @ref7
@ref10:
	.byte $90,$45,$01,$44,$95
@song0ch1loop:
@ref11:
	.byte $00
	.byte $fd
	.word @song0ch1loop

@song0ch2:
@ref12:
	.byte $80,$45,$45,$49,$5d,$45,$45,$4d,$5d,$45,$45,$49,$5d,$45,$45,$4f
	.byte $4d,$41,$41,$45,$59,$41,$41,$45,$59,$41,$41,$45,$59,$41,$41,$4d
	.byte $48,$81
@ref13:
	.byte $3d,$3d,$55,$3d,$3d,$55,$3d,$55,$3d,$3d,$55,$3d,$3d,$55,$3d,$55
	.byte $41,$41,$59,$41,$41,$59,$41,$59,$41,$41,$59,$41,$41,$59,$41,$58
	.byte $81
@ref14:
	.byte $45,$45,$49,$5d,$45,$45,$4d,$5d,$45,$45,$49,$5d,$45,$45,$4f,$4d
	.byte $41,$41,$45,$59,$41,$41,$45,$59,$41,$41,$45,$59,$41,$41,$4d,$48
	.byte $81
@ref15:
	.byte $3d,$3d,$55,$3d,$3d,$55,$3d,$55,$3d,$3d,$55,$3d,$3d,$55,$3d,$55
	.byte $41,$41,$59,$41,$41,$59,$41,$59,$41,$41,$59,$8e,$58,$5c,$60,$66
	.byte $64,$58,$5c,$60,$66,$64
@ref16:
	.byte $80,$45,$01,$44,$95
@song0ch2loop:
@ref17:
	.byte $00
	.byte $fd
	.word @song0ch2loop

@song0ch3:
@ref18:
	.byte $8a,$21,$8c,$1b,$88,$21,$8c,$1b,$8a,$21,$21,$88,$21,$8c,$1f,$8a
	.byte $21,$21,$88,$21,$8a,$21,$8c,$1b,$8a,$21,$88,$21,$21,$8a,$21,$8c
	.byte $1b,$88,$21,$8c,$1b,$8a,$21,$21,$88,$21,$8a,$21,$21,$88,$21,$21
	.byte $8a,$21,$88,$21,$21,$21,$20,$81
	.byte $ff,$21
	.word @ref18
	.byte $ff,$21
	.word @ref18
	.byte $ff,$21
	.word @ref18
@ref22:
	.byte $20,$85,$20,$95
@song0ch3loop:
@ref23:
	.byte $81
	.byte $fd
	.word @song0ch3loop

@song0ch4:
@ref24:
	.byte $f9,$85
@ref25:
	.byte $f9,$85
@ref26:
	.byte $f9,$85
@ref27:
	.byte $f9,$85
@ref28:
	.byte $9f
@song0ch4loop:
@ref29:
	.byte $81
	.byte $fd
	.word @song0ch4loop


@song1ch0:
	.byte $fb,$05
@song1ch0loop:
@ref30:
	.byte $98,$45,$45,$45,$9a,$45,$98,$45,$96,$3f,$44,$85,$98,$45,$45,$45
	.byte $9a,$45,$98,$45,$96,$3e,$85,$45,$98,$3f,$3f,$3f,$9a,$3f,$98,$3f
	.byte $96,$3f,$44,$85,$98,$3f,$3f,$3f,$9a,$3f,$98,$3f,$96,$3e,$85,$44
	.byte $81
@ref31:
	.byte $98,$37,$37,$37,$9a,$37,$98,$37,$96,$3f,$44,$85,$98,$37,$37,$37
	.byte $9a,$37,$98,$37,$96,$3e,$85,$45,$98,$3b,$3b,$3b,$9a,$3b,$98,$3b
	.byte $96,$3f,$44,$85,$98,$3b,$3b,$3b,$9a,$3b,$98,$3b,$96,$48,$85,$4c
	.byte $81
	.byte $fd
	.word @song1ch0loop

@song1ch1:
@song1ch1loop:
@ref32:
	.byte $94,$44,$89,$96,$45,$94,$3f,$45,$01,$45,$01,$45,$01,$45,$3e,$85
	.byte $45,$45,$44,$89,$96,$45,$94,$3f,$45,$01,$45,$01,$45,$01,$45,$3e
	.byte $85,$45,$44,$81
@ref33:
	.byte $44,$89,$96,$45,$94,$3f,$45,$01,$45,$01,$45,$01,$45,$3e,$85,$45
	.byte $45,$44,$89,$96,$45,$94,$3f,$45,$01,$45,$01,$45,$45,$45,$48,$85
	.byte $4c,$85
	.byte $fd
	.word @song1ch1loop

@song1ch2:
@song1ch2loop:
@ref34:
	.byte $80,$45,$01,$5d,$45,$45,$5d,$01,$45,$01,$45,$5d,$45,$45,$5d,$45
	.byte $5d,$3f,$01,$57,$3f,$3f,$57,$01,$3f,$01,$3f,$57,$3f,$3f,$57,$3f
	.byte $56,$81
@ref35:
	.byte $37,$01,$4f,$37,$37,$4f,$01,$37,$01,$37,$4f,$37,$37,$4f,$37,$4f
	.byte $3b,$01,$53,$3b,$3b,$53,$01,$3b,$01,$3b,$53,$3b,$3b,$53,$3b,$52
	.byte $81
	.byte $fd
	.word @song1ch2loop

@song1ch3:
@song1ch3loop:
	.byte $ff,$21
	.word @ref18
	.byte $ff,$21
	.word @ref18
	.byte $fd
	.word @song1ch3loop

@song1ch4:
@song1ch4loop:
@ref38:
	.byte $f9,$85
@ref39:
	.byte $f9,$85
	.byte $fd
	.word @song1ch4loop


@song2ch0:
	.byte $fb,$04
@song2ch0loop:
@ref40:
	.byte $98,$2f,$2f,$9a,$2e,$85,$92,$36,$85,$98,$2f,$9a,$2f,$92,$2e,$85
	.byte $98,$2e,$85,$2f,$2f,$92,$32,$85
@ref41:
	.byte $98,$29,$29,$28,$85,$92,$36,$85,$98,$29,$9a,$29,$92,$2e,$85,$98
	.byte $28,$85,$29,$28,$89
@ref42:
	.byte $2f,$2f,$9a,$2e,$85,$92,$36,$85,$98,$2f,$9a,$2f,$92,$2e,$85,$98
	.byte $2e,$85,$2f,$2f,$92,$32,$85
	.byte $ff,$0f
	.word @ref41
@ref44:
	.byte $90,$32,$8d,$32,$85,$32,$89,$92,$33,$90,$36,$8d,$36,$85
@ref45:
	.byte $2e,$85,$2e,$8d,$36,$8d,$32,$85,$2e,$85,$32,$85
@ref46:
	.byte $32,$8d,$32,$85,$32,$89,$92,$33,$90,$36,$8d,$36,$85
	.byte $ff,$0c
	.word @ref45
	.byte $fd
	.word @song2ch0loop

@song2ch1:
@song2ch1loop:
@ref48:
	.byte $90,$36,$8d,$2f,$01,$2e,$85,$00,$85,$2e,$85,$32,$85,$2e,$85
@ref49:
	.byte $36,$8d,$38,$85,$36,$85,$00,$85,$2e,$85,$32,$85,$2e,$85
@ref50:
	.byte $36,$8d,$2f,$01,$2e,$85,$00,$85,$2e,$85,$32,$85,$2e,$85
@ref51:
	.byte $36,$85,$38,$85,$38,$85,$36,$85,$00,$85,$2e,$85,$32,$85,$2e,$85
@ref52:
	.byte $94,$32,$85,$32,$85,$32,$85,$32,$85,$36,$85,$36,$85,$36,$85,$36
	.byte $85
@ref53:
	.byte $2e,$85,$2e,$85,$2e,$85,$36,$85,$36,$85,$32,$85,$2e,$85,$32,$85
@ref54:
	.byte $32,$85,$32,$85,$32,$85,$32,$85,$36,$85,$36,$85,$36,$85,$36,$85
	.byte $ff,$10
	.word @ref53
	.byte $fd
	.word @song2ch1loop

@song2ch2:
@song2ch2loop:
@ref56:
	.byte $80,$2f,$01,$2f,$2f,$01,$47,$00,$85,$2f,$47,$2f,$47,$00,$85,$2f
	.byte $46,$81
@ref57:
	.byte $29,$01,$29,$29,$01,$41,$00,$85,$29,$41,$29,$41,$00,$85,$29,$40
	.byte $81
@ref58:
	.byte $2f,$01,$2f,$2f,$01,$47,$00,$85,$2f,$47,$2f,$47,$00,$85,$2f,$46
	.byte $81
	.byte $ff,$11
	.word @ref57
@ref60:
	.byte $25,$25,$3d,$25,$25,$3d,$25,$3d,$29,$29,$41,$29,$29,$41,$29,$40
	.byte $81
@ref61:
	.byte $21,$21,$39,$21,$21,$39,$21,$39,$25,$25,$3d,$25,$25,$3d,$25,$3c
	.byte $81
	.byte $ff,$11
	.word @ref60
@ref63:
	.byte $21,$21,$39,$21,$21,$39,$21,$39,$8e,$55,$55,$6c,$85,$59,$59,$70
	.byte $85
	.byte $fd
	.word @song2ch2loop

@song2ch3:
@song2ch3loop:
@ref64:
	.byte $8a,$21,$8c,$1b,$8a,$21,$21,$88,$21,$8c,$1b,$88,$21,$8c,$1b,$8a
	.byte $21,$88,$21,$8a,$21,$21,$88,$21,$8c,$1b,$88,$21,$20,$81
@ref65:
	.byte $8a,$21,$8c,$1b,$8a,$21,$21,$88,$21,$8c,$1b,$88,$21,$8c,$1b,$8a
	.byte $21,$88,$21,$8a,$21,$21,$88,$21,$21,$21,$20,$81
	.byte $ff,$11
	.word @ref64
	.byte $ff,$11
	.word @ref65
	.byte $ff,$11
	.word @ref64
	.byte $ff,$11
	.word @ref65
	.byte $ff,$11
	.word @ref64
	.byte $ff,$11
	.word @ref65
	.byte $fd
	.word @song2ch3loop

@song2ch4:
@song2ch4loop:
@ref72:
	.byte $bf
@ref73:
	.byte $bf
@ref74:
	.byte $bf
@ref75:
	.byte $bf
@ref76:
	.byte $bf
@ref77:
	.byte $bf
@ref78:
	.byte $bf
@ref79:
	.byte $bf
	.byte $fd
	.word @song2ch4loop


@song3ch0:
	.byte $fb,$04
@song3ch0loop:
@ref80:
	.byte $98,$4b,$9a,$4b,$98,$4b,$92,$33,$98,$41,$9a,$41,$98,$4b,$92,$36
	.byte $89,$98,$4a,$89,$92,$3a,$89
@ref81:
	.byte $98,$47,$9a,$47,$98,$47,$92,$3d,$98,$3d,$9a,$3d,$98,$47,$92,$36
	.byte $89,$98,$46,$85,$92,$3a,$87,$33,$36
@ref82:
	.byte $98,$43,$9a,$43,$98,$43,$92,$33,$98,$39,$9a,$39,$98,$43,$92,$2e
	.byte $89,$98,$42,$91,$92,$2e,$81
@ref83:
	.byte $98,$47,$9a,$47,$98,$47,$92,$39,$98,$3d,$9a,$3d,$98,$47,$92,$36
	.byte $85,$39,$98,$47,$92,$38,$85,$3c,$85,$3c,$81
	.byte $fd
	.word @song3ch0loop

@song3ch1:
@song3ch1loop:
@ref84:
	.byte $90,$32,$95,$36,$95,$3a,$8d
@ref85:
	.byte $3c,$85,$3a,$85,$32,$85,$36,$8d,$3a,$8d,$33,$36,$81
@ref86:
	.byte $32,$95,$2e,$9d,$2e,$85
@ref87:
	.byte $38,$85,$38,$85,$36,$85,$36,$85,$38,$85,$38,$85,$3c,$85,$3c,$85
	.byte $fd
	.word @song3ch1loop

@song3ch2:
@song3ch2loop:
@ref88:
	.byte $80,$1b,$01,$33,$1b,$1b,$33,$01,$1b,$01,$1b,$33,$1b,$1b,$33,$1b
	.byte $32,$81
@ref89:
	.byte $17,$01,$2f,$17,$17,$2f,$01,$17,$01,$17,$2f,$17,$17,$2f,$17,$2e
	.byte $81
@ref90:
	.byte $13,$01,$2b,$13,$13,$2b,$01,$13,$01,$13,$2b,$13,$13,$2b,$13,$2a
	.byte $81
	.byte $ff,$11
	.word @ref89
	.byte $fd
	.word @song3ch2loop

@song3ch3:
@song3ch3loop:
@ref92:
	.byte $8a,$21,$8c,$1b,$88,$21,$8c,$1b,$8a,$21,$21,$88,$21,$8c,$1f,$8a
	.byte $21,$21,$88,$21,$8a,$21,$8c,$1b,$8a,$21,$88,$21,$8c,$1a,$81
@ref93:
	.byte $8a,$21,$8c,$1b,$88,$21,$8c,$1b,$8a,$21,$21,$88,$21,$8a,$21,$21
	.byte $88,$21,$21,$8a,$21,$88,$21,$21,$21,$20,$81
	.byte $ff,$11
	.word @ref92
	.byte $ff,$11
	.word @ref93
	.byte $fd
	.word @song3ch3loop

@song3ch4:
@song3ch4loop:
@ref96:
	.byte $bf
@ref97:
	.byte $bf
@ref98:
	.byte $bf
@ref99:
	.byte $bf
	.byte $fd
	.word @song3ch4loop


@song4ch0:
	.byte $fb,$04
@song4ch0loop:
@ref100:
	.byte $94,$2c,$85,$92,$2c,$85,$98,$45,$45,$9a,$45,$98,$45,$94,$26,$85
	.byte $92,$26,$85,$98,$3f,$3f,$9a,$3f,$98,$3e,$81
@ref101:
	.byte $94,$1e,$85,$92,$2c,$85,$98,$45,$45,$9a,$45,$98,$45,$94,$22,$85
	.byte $92,$26,$85,$98,$3b,$3b,$9a,$3b,$98,$3a,$81
	.byte $ff,$11
	.word @ref100
	.byte $ff,$11
	.word @ref101
@ref104:
	.byte $92,$44,$85,$3e,$85,$3a,$85,$3e,$85,$44,$85,$3e,$85,$3a,$85,$3e
	.byte $85
@ref105:
	.byte $44,$85,$3e,$85,$3a,$85,$3e,$85,$44,$85,$3e,$85,$3a,$85,$3e,$85
@ref106:
	.byte $44,$85,$3e,$85,$3a,$85,$3e,$85,$44,$85,$3e,$85,$3a,$85,$4c,$85
@ref107:
	.byte $4c,$8d,$48,$8d,$44,$87,$45,$49,$44,$8b
	.byte $fd
	.word @song4ch0loop

@song4ch1:
@song4ch1loop:
@ref108:
	.byte $90,$2c,$8d,$35,$30,$85,$2c,$89,$26,$85,$2c,$85,$26,$85
@ref109:
	.byte $2c,$8d,$35,$30,$85,$2c,$89,$26,$85,$30,$85,$34,$85
@ref110:
	.byte $2c,$8d,$35,$30,$85,$2c,$89,$26,$85,$2c,$85,$26,$85
	.byte $ff,$0d
	.word @ref109
@ref112:
	.byte $44,$85,$3e,$85,$3e,$85,$3a,$85,$3e,$85,$3a,$85,$3e,$85,$44,$85
@ref113:
	.byte $87,$3e,$85,$3e,$85,$3a,$85,$3e,$85,$3a,$85,$3e,$85,$44,$85
@ref114:
	.byte $87,$3e,$85,$3e,$85,$3a,$85,$3e,$85,$3a,$85,$3e,$85,$4c,$85
@ref115:
	.byte $87,$48,$8d,$44,$8d,$45,$49,$44,$8d
	.byte $fd
	.word @song4ch1loop

@song4ch2:
@song4ch2loop:
@ref116:
	.byte $80,$2c,$00,$44,$00,$2d,$2d,$44,$00,$44,$00,$45,$2d,$26,$00,$3e
	.byte $00,$27,$27,$3e,$00,$3e,$00,$3f,$26,$81
@ref117:
	.byte $1e,$00,$36,$00,$1f,$1f,$36,$00,$36,$00,$37,$1f,$22,$00,$3a,$00
	.byte $23,$23,$3a,$00,$3a,$00,$3b,$22,$81
@ref118:
	.byte $2c,$00,$44,$00,$2d,$2d,$44,$00,$44,$00,$45,$2d,$26,$00,$3e,$00
	.byte $27,$27,$3e,$00,$3e,$00,$3f,$26,$81
	.byte $ff,$19
	.word @ref117
@ref120:
	.byte $37,$37,$4f,$37,$37,$4f,$37,$4f,$37,$37,$4f,$37,$37,$4f,$37,$4e
	.byte $81
@ref121:
	.byte $3b,$3b,$53,$3b,$3b,$53,$3b,$53,$45,$45,$5d,$45,$45,$5d,$45,$5c
	.byte $81
	.byte $ff,$11
	.word @ref120
@ref123:
	.byte $3b,$3b,$53,$3b,$3b,$53,$3b,$53,$8e,$4e,$4e,$52,$52,$5c,$5c,$60
	.byte $60,$64,$64,$60,$60,$5c,$5c,$52,$52
	.byte $fd
	.word @song4ch2loop

@song4ch3:
@song4ch3loop:
@ref124:
	.byte $8a,$21,$8c,$1b,$8a,$21,$8c,$1b,$88,$21,$8c,$1b,$1b,$8a,$21,$21
	.byte $88,$21,$8a,$21,$8c,$1b,$8a,$21,$88,$21,$8c,$1b,$88,$20,$81
@ref125:
	.byte $8a,$21,$8c,$1b,$8a,$21,$8c,$1b,$88,$21,$8c,$1b,$1b,$8a,$21,$21
	.byte $88,$21,$8a,$21,$8c,$1b,$88,$21,$21,$21,$20,$81
	.byte $ff,$11
	.word @ref124
	.byte $ff,$11
	.word @ref125
	.byte $ff,$11
	.word @ref124
	.byte $ff,$11
	.word @ref125
	.byte $ff,$11
	.word @ref124
	.byte $ff,$11
	.word @ref125
	.byte $fd
	.word @song4ch3loop

@song4ch4:
@song4ch4loop:
@ref132:
	.byte $bf
@ref133:
	.byte $bf
@ref134:
	.byte $bf
@ref135:
	.byte $bf
@ref136:
	.byte $bf
@ref137:
	.byte $bf
@ref138:
	.byte $bf
@ref139:
	.byte $bf
	.byte $fd
	.word @song4ch4loop


@song5ch0:
	.byte $fb,$04
@song5ch0loop:
@ref140:
	.byte $98,$45,$9a,$45,$98,$44,$85,$92,$44,$85,$3e,$8d,$98,$44,$85,$45
	.byte $45,$92,$3e,$85
@ref141:
	.byte $98,$3f,$9a,$3f,$98,$3e,$85,$92,$3e,$85,$3e,$85,$3a,$85,$98,$3e
	.byte $85,$3f,$3f,$92,$3e,$85
	.byte $ff,$0e
	.word @ref140
	.byte $ff,$10
	.word @ref141
@ref144:
	.byte $01,$36,$85,$36,$85,$3a,$85,$3e,$8d,$3e,$85,$3a,$85,$36,$81
@ref145:
	.byte $83,$3a,$85,$3a,$85,$3e,$85,$42,$8d,$48,$85,$44,$85,$3e,$81
	.byte $fd
	.word @song5ch0loop

@song5ch1:
@song5ch1loop:
@ref146:
	.byte $90,$44,$8d,$3e,$8d,$3a,$85,$3e,$85,$3e,$85,$3a,$85
@ref147:
	.byte $87,$3e,$85,$3e,$85,$3a,$85,$44,$85,$44,$85,$3e,$85,$44,$85
@ref148:
	.byte $44,$8d,$3e,$8d,$3a,$85,$3e,$85,$3e,$85,$3a,$85
	.byte $ff,$0f
	.word @ref147
@ref150:
	.byte $36,$85,$36,$85,$3a,$85,$3e,$8d,$3e,$85,$3a,$85,$36,$85
@ref151:
	.byte $3a,$85,$3a,$85,$3e,$85,$42,$8d,$48,$85,$44,$85,$3e,$85
	.byte $fd
	.word @song5ch1loop

@song5ch2:
@song5ch2loop:
@ref152:
	.byte $80,$2d,$01,$45,$2d,$2d,$45,$01,$2d,$01,$2d,$45,$2d,$2d,$45,$2d
	.byte $44,$81
@ref153:
	.byte $27,$01,$3f,$27,$27,$3f,$01,$27,$01,$27,$3f,$27,$27,$3f,$27,$3e
	.byte $81
@ref154:
	.byte $2d,$01,$45,$2d,$2d,$45,$01,$2d,$01,$2d,$45,$2d,$2d,$45,$2d,$44
	.byte $81
	.byte $ff,$11
	.word @ref153
@ref156:
	.byte $1f,$01,$37,$1f,$1f,$37,$01,$1f,$01,$1f,$37,$1f,$1f,$37,$1f,$36
	.byte $81
@ref157:
	.byte $23,$01,$3b,$23,$23,$3b,$01,$23,$01,$23,$3b,$23,$23,$3b,$23,$3a
	.byte $81
	.byte $fd
	.word @song5ch2loop

@song5ch3:
@song5ch3loop:
	.byte $ff,$11
	.word @ref92
	.byte $ff,$11
	.word @ref93
	.byte $ff,$11
	.word @ref92
	.byte $ff,$11
	.word @ref93
	.byte $ff,$11
	.word @ref92
	.byte $ff,$11
	.word @ref93
	.byte $fd
	.word @song5ch3loop

@song5ch4:
@song5ch4loop:
@ref164:
	.byte $bf
@ref165:
	.byte $bf
@ref166:
	.byte $bf
@ref167:
	.byte $bf
@ref168:
	.byte $bf
@ref169:
	.byte $bf
	.byte $fd
	.word @song5ch4loop


@song6ch0:
	.byte $fb,$04
@song6ch0loop:
@ref170:
	.byte $98,$3d,$9a,$3d,$98,$3d,$9a,$3d,$92,$3c,$8d,$98,$39,$9a,$39,$98
	.byte $39,$9a,$39,$92,$38,$8d
@ref171:
	.byte $98,$35,$9a,$35,$98,$35,$9a,$35,$92,$34,$8d,$98,$39,$9a,$39,$98
	.byte $39,$9a,$39,$92,$38,$89,$3c,$81
@ref172:
	.byte $98,$39,$9a,$39,$98,$39,$9a,$39,$92,$38,$8d,$98,$35,$9a,$35,$98
	.byte $35,$9a,$35,$92,$34,$89,$34,$81
@ref173:
	.byte $98,$33,$9a,$33,$98,$33,$9a,$33,$92,$32,$89,$33,$98,$35,$9a,$35
	.byte $98,$35,$9a,$34,$89,$92,$38,$85
@ref174:
	.byte $82,$3c,$8d,$38,$8d,$3d,$42,$85,$46,$89,$42,$85
@ref175:
	.byte $3c,$8d,$38,$8d,$3d,$42,$85,$46,$89,$4a,$85
@ref176:
	.byte $4a,$9d,$40,$89,$42,$89,$40,$85
	.byte $ff,$08
	.word @ref176
@ref178:
	.byte $86,$55,$4b,$55,$4b,$55,$4b,$55,$4b,$5b,$51,$5b,$51,$5b,$51,$5b
	.byte $50,$81
@ref179:
	.byte $5f,$55,$5f,$55,$5f,$55,$5f,$55,$63,$59,$63,$59,$63,$59,$69,$6c
	.byte $81
	.byte $fd
	.word @song6ch0loop

@song6ch1:
@song6ch1loop:
@ref180:
	.byte $90,$3c,$9d,$38,$9d
@ref181:
	.byte $34,$9d,$38,$95,$3c,$85
@ref182:
	.byte $38,$9d,$34,$95,$34,$85
@ref183:
	.byte $32,$95,$32,$85,$34,$8d,$38,$8d
@ref184:
	.byte $84,$3c,$8d,$38,$8d,$3d,$42,$85,$46,$89,$42,$85
	.byte $ff,$0b
	.word @ref175
	.byte $ff,$08
	.word @ref176
	.byte $ff,$08
	.word @ref176
@ref188:
	.byte $4a,$85,$4c,$85,$4a,$46,$4a,$89,$46,$8d,$42,$8d
@ref189:
	.byte $4a,$85,$4c,$85,$4a,$46,$4c,$89,$4a,$8d,$50,$85,$54,$85
	.byte $fd
	.word @song6ch1loop

@song6ch2:
@song6ch2loop:
@ref190:
	.byte $80,$3d,$01,$39,$3d,$01,$3d,$01,$3d,$01,$39,$01,$3d,$4b,$39,$47
	.byte $3c,$81
@ref191:
	.byte $3d,$01,$39,$3d,$01,$3d,$01,$3d,$01,$39,$01,$3d,$4b,$39,$47,$3c
	.byte $81
@ref192:
	.byte $39,$01,$35,$39,$01,$39,$01,$39,$01,$35,$01,$39,$47,$35,$43,$38
	.byte $81
	.byte $ff,$11
	.word @ref192
@ref194:
	.byte $3d,$3d,$55,$3d,$3d,$55,$3d,$55,$39,$39,$51,$39,$39,$51,$39,$50
	.byte $81
@ref195:
	.byte $35,$35,$4d,$35,$35,$4d,$35,$4d,$33,$33,$4b,$33,$33,$4b,$33,$4a
	.byte $81
	.byte $ff,$11
	.word @ref194
	.byte $ff,$11
	.word @ref195
@ref198:
	.byte $3d,$3d,$55,$3d,$3d,$55,$3d,$55,$43,$43,$5b,$43,$43,$5b,$43,$5a
	.byte $81
@ref199:
	.byte $47,$47,$5f,$47,$47,$5f,$47,$5f,$4b,$4b,$63,$4b,$4b,$63,$4b,$62
	.byte $81
	.byte $fd
	.word @song6ch2loop

@song6ch3:
@song6ch3loop:
	.byte $ff,$11
	.word @ref92
	.byte $ff,$11
	.word @ref93
	.byte $ff,$11
	.word @ref92
	.byte $ff,$11
	.word @ref93
	.byte $ff,$11
	.word @ref92
	.byte $ff,$11
	.word @ref93
	.byte $ff,$11
	.word @ref92
	.byte $ff,$11
	.word @ref93
	.byte $ff,$11
	.word @ref92
	.byte $ff,$11
	.word @ref93
	.byte $fd
	.word @song6ch3loop

@song6ch4:
@song6ch4loop:
@ref210:
	.byte $bf
@ref211:
	.byte $bf
@ref212:
	.byte $bf
@ref213:
	.byte $bf
@ref214:
	.byte $bf
@ref215:
	.byte $bf
@ref216:
	.byte $bf
@ref217:
	.byte $bf
@ref218:
	.byte $bf
@ref219:
	.byte $bf
	.byte $fd
	.word @song6ch4loop


@song7ch0:
	.byte $fb,$03
@song7ch0loop:
@ref220:
	.byte $94,$32,$85,$34,$85,$38,$85,$3a,$85,$3e,$85,$3a,$85,$38,$85,$3a
	.byte $85
@ref221:
	.byte $32,$85,$34,$85,$38,$85,$3a,$85,$3e,$85,$3a,$85,$38,$85,$3a,$85
	.byte $ff,$10
	.word @ref221
@ref223:
	.byte $32,$85,$34,$85,$38,$85,$3a,$85,$3e,$85,$3a,$85,$3e,$85,$40,$85
	.byte $ff,$10
	.word @ref221
	.byte $ff,$10
	.word @ref221
	.byte $ff,$10
	.word @ref221
@ref227:
	.byte $32,$85,$34,$85,$38,$85,$3a,$85,$47,$49,$4d,$4f,$47,$49,$4d,$50
	.byte $81
	.byte $fd
	.word @song7ch0loop

@song7ch1:
@song7ch1loop:
@ref228:
	.byte $90,$4a,$8d,$4c,$8d,$50,$8d,$52,$85,$52,$85
@ref229:
	.byte $56,$8d,$52,$85,$52,$85,$50,$8d,$4a,$85,$4b,$4a,$81
@ref230:
	.byte $4a,$8d,$4c,$8d,$50,$8d,$52,$85,$52,$85
	.byte $ff,$0d
	.word @ref229
@ref232:
	.byte $4a,$85,$4c,$85,$50,$85,$52,$85,$4a,$85,$4c,$85,$50,$85,$52,$85
@ref233:
	.byte $50,$85,$52,$85,$56,$85,$58,$85,$50,$85,$52,$85,$56,$85,$58,$85
	.byte $ff,$10
	.word @ref232
@ref235:
	.byte $50,$85,$52,$85,$56,$85,$58,$85,$51,$53,$57,$59,$51,$53,$57,$5a
	.byte $81
	.byte $fd
	.word @song7ch1loop

@song7ch2:
@song7ch2loop:
@ref236:
	.byte $80,$33,$4b,$33,$33,$4b,$4b,$33,$4b,$35,$4d,$35,$35,$4d,$4d,$35
	.byte $4c,$81
@ref237:
	.byte $3b,$53,$3b,$3b,$53,$53,$3b,$53,$39,$51,$39,$39,$4d,$4d,$35,$4c
	.byte $81
@ref238:
	.byte $33,$4b,$33,$33,$4b,$4b,$33,$4b,$35,$4d,$35,$35,$4d,$4d,$35,$4c
	.byte $81
	.byte $ff,$11
	.word @ref237
@ref240:
	.byte $33,$33,$4b,$33,$33,$4b,$33,$4b,$35,$35,$4d,$35,$35,$4d,$35,$4c
	.byte $81
@ref241:
	.byte $39,$39,$51,$39,$39,$51,$39,$51,$3b,$3b,$53,$3b,$3b,$53,$3f,$40
	.byte $81
	.byte $ff,$11
	.word @ref240
	.byte $ff,$11
	.word @ref241
	.byte $fd
	.word @song7ch2loop

@song7ch3:
@song7ch3loop:
@ref244:
	.byte $8a,$21,$8c,$1b,$8a,$21,$21,$88,$21,$8c,$1b,$8a,$21,$8c,$1b,$8a
	.byte $21,$88,$21,$8a,$21,$21,$88,$21,$8c,$1b,$88,$21,$20,$81
@ref245:
	.byte $8a,$21,$8c,$1b,$8a,$21,$21,$88,$21,$8c,$1b,$88,$21,$8c,$1b,$8a
	.byte $21,$21,$88,$21,$21,$8a,$21,$21,$88,$21,$20,$81
	.byte $ff,$11
	.word @ref244
	.byte $ff,$11
	.word @ref245
	.byte $ff,$11
	.word @ref244
	.byte $ff,$11
	.word @ref245
	.byte $ff,$11
	.word @ref244
	.byte $ff,$11
	.word @ref245
	.byte $fd
	.word @song7ch3loop

@song7ch4:
@song7ch4loop:
@ref252:
	.byte $bf
@ref253:
	.byte $bf
@ref254:
	.byte $bf
@ref255:
	.byte $bf
@ref256:
	.byte $bf
@ref257:
	.byte $bf
@ref258:
	.byte $bf
@ref259:
	.byte $bf
	.byte $fd
	.word @song7ch4loop


@song8ch0:
	.byte $fb,$05
@ref260:
	.byte $94,$3d,$40,$85,$3c,$40,$3c,$85,$3d,$41,$47,$40,$85,$3c,$85,$47
	.byte $41,$3c,$81
@ref261:
	.byte $41,$01,$40,$95
@song8ch0loop:
@ref262:
	.byte $00
	.byte $fd
	.word @song8ch0loop

@song8ch1:
@ref263:
	.byte $90,$47,$4a,$85,$46,$4a,$46,$85,$47,$4b,$51,$4a,$85,$46,$85,$51
	.byte $4b,$46,$81
@ref264:
	.byte $4b,$01,$4a,$95
@song8ch1loop:
@ref265:
	.byte $00
	.byte $fd
	.word @song8ch1loop

@song8ch2:
@ref266:
	.byte $80,$33,$33,$4b,$33,$33,$4b,$33,$4b,$2f,$2f,$47,$2f,$2f,$47,$2f
	.byte $46,$81
@ref267:
	.byte $33,$01,$32,$95
@song8ch2loop:
@ref268:
	.byte $00
	.byte $fd
	.word @song8ch2loop

@song8ch3:
@ref269:
	.byte $bf
@ref270:
	.byte $9f
@song8ch3loop:
@ref271:
	.byte $81
	.byte $fd
	.word @song8ch3loop

@song8ch4:
@ref272:
	.byte $bf
@ref273:
	.byte $9f
@song8ch4loop:
@ref274:
	.byte $81
	.byte $fd
	.word @song8ch4loop


@song9ch0:
	.byte $fb,$04
@song9ch0loop:
@ref275:
	.byte $86,$3d,$40,$85,$3c,$85,$40,$85,$41,$47,$40,$85,$3c,$85,$40,$85
	.byte $3c,$81
@ref276:
	.byte $3d,$40,$85,$3c,$85,$40,$85,$41,$47,$40,$85,$46,$85,$4a,$89
@ref277:
	.byte $3d,$40,$85,$3c,$85,$40,$85,$41,$47,$40,$85,$3c,$85,$40,$85,$3c
	.byte $81
	.byte $ff,$0f
	.word @ref276
@ref279:
	.byte $82,$32,$8d,$2e,$8d,$33,$01,$32,$85,$2e,$85,$32,$85
@ref280:
	.byte $8f,$2e,$8d,$33,$01,$32,$85,$2e,$85,$38,$85
@ref281:
	.byte $8f,$3c,$8d,$40,$95,$32,$85
@ref282:
	.byte $87,$38,$8d,$3c,$85,$86,$4a,$48,$46,$44,$42,$40,$3e,$3c,$3a,$38
	.byte $36,$34,$32,$30,$2e,$2c
	.byte $fd
	.word @song9ch0loop

@song9ch1:
@song9ch1loop:
@ref283:
	.byte $84,$47,$4a,$85,$46,$85,$4a,$85,$4b,$51,$4a,$85,$46,$85,$4a,$85
	.byte $46,$81
@ref284:
	.byte $47,$4a,$85,$46,$85,$4a,$85,$4b,$51,$4a,$85,$50,$85,$54,$89
@ref285:
	.byte $47,$4a,$85,$46,$85,$4a,$85,$4b,$51,$4a,$85,$46,$85,$4a,$85,$46
	.byte $81
	.byte $ff,$0f
	.word @ref284
@ref287:
	.byte $4a,$8d,$46,$8d,$50,$85,$4a,$85,$46,$85,$4a,$85
@ref288:
	.byte $8f,$46,$8d,$50,$85,$4a,$85,$46,$85,$4a,$85
	.byte $ff,$0c
	.word @ref287
@ref290:
	.byte $87,$50,$8d,$54,$85,$54,$52,$50,$4e,$4c,$4a,$48,$46,$44,$42,$40
	.byte $3e,$3c,$3a,$38,$36
	.byte $fd
	.word @song9ch1loop

@song9ch2:
@song9ch2loop:
@ref291:
	.byte $80,$1b,$1b,$33,$1b,$1b,$33,$1b,$33,$17,$17,$2f,$17,$17,$2f,$17
	.byte $2e,$81
@ref292:
	.byte $21,$21,$39,$21,$21,$39,$21,$21,$25,$25,$3d,$25,$25,$3d,$25,$3c
	.byte $81
@ref293:
	.byte $1b,$1b,$33,$1b,$1b,$33,$1b,$33,$17,$17,$2f,$17,$17,$2f,$17,$2e
	.byte $81
	.byte $ff,$11
	.word @ref292
@ref295:
	.byte $33,$33,$4b,$33,$33,$4b,$33,$4b,$2f,$2f,$47,$2f,$2f,$47,$2f,$46
	.byte $81
@ref296:
	.byte $39,$39,$51,$39,$39,$51,$39,$39,$3d,$3d,$55,$3d,$3d,$55,$3d,$54
	.byte $81
	.byte $ff,$11
	.word @ref295
@ref298:
	.byte $39,$39,$51,$39,$39,$51,$39,$39,$8e,$54,$8d,$58,$8d
	.byte $fd
	.word @song9ch2loop

@song9ch3:
@song9ch3loop:
@ref299:
	.byte $8a,$21,$21,$88,$21,$8a,$21,$21,$21,$88,$21,$8c,$1f,$8a,$21,$21
	.byte $88,$21,$8a,$21,$8c,$1b,$8a,$21,$88,$21,$8c,$1a,$81
@ref300:
	.byte $8a,$21,$21,$88,$21,$8a,$21,$21,$21,$88,$21,$8a,$21,$88,$21,$21
	.byte $21,$21,$8a,$21,$21,$88,$21,$20,$81
	.byte $ff,$11
	.word @ref299
	.byte $ff,$11
	.word @ref300
	.byte $ff,$11
	.word @ref299
	.byte $ff,$11
	.word @ref300
	.byte $ff,$11
	.word @ref299
	.byte $ff,$11
	.word @ref300
	.byte $fd
	.word @song9ch3loop

@song9ch4:
@song9ch4loop:
@ref307:
	.byte $bf
@ref308:
	.byte $bf
@ref309:
	.byte $bf
@ref310:
	.byte $bf
@ref311:
	.byte $bf
@ref312:
	.byte $bf
@ref313:
	.byte $bf
@ref314:
	.byte $bf
	.byte $fd
	.word @song9ch4loop


@song10ch0:
	.byte $fb,$06
@ref315:
	.byte $98,$45,$9a,$45,$98,$45,$92,$44,$87,$45,$40,$83,$98,$45,$9a,$45
	.byte $98,$45,$92,$41,$44,$8d
@song10ch0loop:
@ref316:
	.byte $00
	.byte $fd
	.word @song10ch0loop

@song10ch1:
@ref317:
	.byte $90,$45,$01,$44,$85,$01,$45,$40,$85,$45,$45,$41,$44,$91
@song10ch1loop:
@ref318:
	.byte $00
	.byte $fd
	.word @song10ch1loop

@song10ch2:
@ref319:
	.byte $80,$2d,$2d,$45,$41,$2d,$2d,$45,$4d,$45,$45,$41,$44,$91
@song10ch2loop:
@ref320:
	.byte $00
	.byte $fd
	.word @song10ch2loop

@song10ch3:
@ref321:
	.byte $8a,$21,$21,$88,$21,$8c,$1b,$1f,$8a,$21,$88,$21,$8a,$21,$88,$21
	.byte $21,$8a,$21,$88,$20,$91
@song10ch3loop:
@ref322:
	.byte $81
	.byte $fd
	.word @song10ch3loop

@song10ch4:
@ref323:
	.byte $bf
@song10ch4loop:
@ref324:
	.byte $81
	.byte $fd
	.word @song10ch4loop


@song11ch0:
	.byte $fb,$07
@song11ch0loop:
@ref325:
	.byte $98,$4b,$4b,$9a,$4b,$96,$3c,$89,$94,$40,$85,$43,$40,$85,$38,$89
	.byte $3c,$85,$38,$85,$39,$32,$89,$90,$42,$85,$41,$38,$85,$3c,$85,$40
	.byte $89
@ref326:
	.byte $98,$4b,$4b,$9a,$4b,$96,$3c,$89,$94,$40,$85,$43,$40,$85,$38,$89
	.byte $3c,$85,$38,$85,$39,$32,$89,$90,$42,$85,$41,$38,$85,$3c,$85,$41
	.byte $38,$85
	.byte $fd
	.word @song11ch0loop

@song11ch1:
@song11ch1loop:
@ref327:
	.byte $94,$33,$39,$3c,$85,$98,$51,$9a,$50,$85,$98,$51,$94,$2f,$33,$38
	.byte $85,$98,$47,$9a,$46,$85,$94,$33,$42,$85,$41,$38,$85,$98,$43,$43
	.byte $9a,$43,$98,$43,$43,$9a,$43,$98,$47,$47,$9a,$47,$98,$47,$9a,$46
	.byte $81
	.byte $ff,$21
	.word @ref327
	.byte $fd
	.word @song11ch1loop

@song11ch2:
@song11ch2loop:
@ref329:
	.byte $80,$33,$33,$4b,$33,$33,$4b,$33,$4b,$2f,$2f,$47,$33,$39,$2f,$33
	.byte $39,$39,$39,$51,$39,$39,$51,$39,$51,$3d,$3d,$55,$39,$3d,$33,$39
	.byte $3c,$81
@ref330:
	.byte $33,$33,$4b,$33,$33,$4b,$33,$4b,$2f,$2f,$47,$33,$39,$2f,$33,$39
	.byte $39,$39,$51,$39,$39,$51,$39,$51,$3d,$3d,$55,$39,$3d,$33,$39,$3c
	.byte $81
	.byte $fd
	.word @song11ch2loop

@song11ch3:
@song11ch3loop:
	.byte $ff,$21
	.word @ref18
	.byte $ff,$21
	.word @ref18
	.byte $fd
	.word @song11ch3loop

@song11ch4:
@song11ch4loop:
@ref333:
	.byte $f9,$85
@ref334:
	.byte $f9,$85
	.byte $fd
	.word @song11ch4loop


@song12ch0:
	.byte $fb,$06
@song12ch0loop:
@ref335:
	.byte $98,$45,$45,$45,$9a,$45,$92,$34,$8d,$98,$45,$45,$45,$9a,$45,$92
	.byte $2c,$8d
@ref336:
	.byte $98,$3f,$3f,$3f,$9a,$3f,$92,$36,$85,$34,$85,$98,$3f,$3f,$3f,$9a
	.byte $3f,$92,$2c,$85,$30,$85
@ref337:
	.byte $98,$37,$37,$37,$9a,$37,$98,$37,$96,$31,$34,$85,$98,$37,$37,$37
	.byte $9a,$37,$92,$2d,$26,$89
@ref338:
	.byte $98,$3b,$3b,$3b,$9a,$3b,$98,$3b,$96,$31,$34,$85,$98,$3b,$3b,$3b
	.byte $9a,$3b,$98,$3b,$92,$30,$85,$34,$81
@ref339:
	.byte $98,$45,$45,$45,$9a,$45,$98,$45,$92,$49,$4c,$85,$98,$45,$45,$45
	.byte $9a,$45,$98,$45,$96,$44,$85,$3e,$81
@ref340:
	.byte $98,$3f,$3f,$3f,$9a,$3f,$98,$3f,$96,$49,$4c,$85,$98,$3f,$3f,$3f
	.byte $9a,$3f,$98,$3f,$96,$44,$85,$4c,$81
@ref341:
	.byte $98,$37,$37,$37,$9a,$37,$98,$37,$96,$49,$4c,$85,$98,$37,$37,$37
	.byte $9a,$37,$98,$37,$96,$44,$85,$3e,$81
@ref342:
	.byte $98,$3b,$3b,$3b,$9a,$3b,$98,$3b,$96,$49,$4c,$85,$98,$3b,$3b,$3b
	.byte $9a,$3b,$98,$3b,$96,$44,$85,$4c,$81
	.byte $fd
	.word @song12ch0loop

@song12ch1:
@song12ch1loop:
@ref343:
	.byte $90,$34,$a5,$2c,$85,$31,$2d,$30,$85
@ref344:
	.byte $34,$85,$92,$35,$90,$37,$34,$9d,$2c,$89,$2c,$81
@ref345:
	.byte $94,$1e,$95,$96,$31,$34,$91,$90,$26,$89,$26,$81
@ref346:
	.byte $2c,$89,$2d,$2a,$89,$2b,$2c,$89,$2d,$30,$85,$34,$85
@ref347:
	.byte $94,$45,$01,$44,$85,$49,$4c,$85,$44,$89,$3e,$85,$44,$85,$3e,$85
@ref348:
	.byte $45,$01,$44,$85,$49,$4c,$85,$44,$89,$3e,$85,$44,$85,$4c,$85
@ref349:
	.byte $45,$01,$44,$85,$49,$4c,$85,$44,$89,$3e,$85,$44,$85,$3e,$85
	.byte $ff,$0f
	.word @ref348
	.byte $fd
	.word @song12ch1loop

@song12ch2:
@song12ch2loop:
@ref351:
	.byte $80,$2d,$2d,$45,$2d,$3f,$45,$01,$2d,$2d,$45,$01,$2d,$3f,$01,$45
	.byte $2c,$81
@ref352:
	.byte $27,$27,$3f,$27,$35,$3f,$01,$27,$27,$3f,$01,$27,$35,$01,$3f,$26
	.byte $81
@ref353:
	.byte $1f,$1f,$37,$1f,$2d,$37,$01,$1f,$1f,$37,$01,$1f,$2d,$01,$37,$1e
	.byte $81
@ref354:
	.byte $23,$23,$3b,$23,$35,$3b,$01,$23,$23,$3b,$01,$23,$35,$01,$3b,$22
	.byte $81
@ref355:
	.byte $2d,$2d,$45,$2d,$3f,$45,$01,$2d,$2d,$45,$01,$2d,$3f,$01,$45,$2c
	.byte $81
	.byte $ff,$11
	.word @ref352
	.byte $ff,$11
	.word @ref353
	.byte $ff,$11
	.word @ref354
	.byte $fd
	.word @song12ch2loop

@song12ch3:
@song12ch3loop:
	.byte $ff,$11
	.word @ref92
	.byte $ff,$11
	.word @ref93
	.byte $ff,$11
	.word @ref92
	.byte $ff,$11
	.word @ref93
	.byte $ff,$11
	.word @ref92
	.byte $ff,$11
	.word @ref93
	.byte $ff,$11
	.word @ref92
	.byte $ff,$11
	.word @ref93
	.byte $fd
	.word @song12ch3loop

@song12ch4:
@song12ch4loop:
@ref367:
	.byte $bf
@ref368:
	.byte $bf
@ref369:
	.byte $bf
@ref370:
	.byte $bf
@ref371:
	.byte $bf
@ref372:
	.byte $bf
@ref373:
	.byte $bf
@ref374:
	.byte $bf
	.byte $fd
	.word @song12ch4loop
