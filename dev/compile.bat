@echo off

if [%1]==[justcompile] goto :compile
if [%1]==[mapenems] goto :mapenems

echo Palettes
echo ========
cd ..\gfx
..\utils\mkts.exe mode=pals pals=palts0.png out=..\dev\work\palts0.h label=pal_bg_0 silent
..\utils\mkts.exe mode=pals pals=palts1.png out=..\dev\work\palts1.h label=pal_bg_1 silent
..\utils\mkts.exe mode=pals pals=palts2.png out=..\dev\work\palts2.h label=pal_bg_2 silent
..\utils\mkts.exe mode=pals pals=palts3.png out=..\dev\work\palts3.h label=pal_bg_3 silent
..\utils\mkts.exe mode=pals pals=palss.png out=..\dev\work\palss0.h label=pal_ss_0 silent
..\utils\mkts.exe mode=pals pals=paltsl.png out=..\dev\work\paltsl.h label=pal_light_bg silent
..\utils\mkts.exe mode=pals pals=palssl.png out=..\dev\work\palssl.h label=pal_light_fg silent
..\utils\mkts.exe mode=pals pals=paltsp.png out=..\dev\work\paltsp.h label=pal_bg_p silent
..\utils\mkts.exe mode=pals pals=paltst.png out=..\dev\work\paltst.h label=pal_bg_t silent
..\utils\mkts.exe mode=pals pals=paltscuts.png out=..\dev\work\paltscuts.h label=pal_bg_cuts silent
..\utils\mkts.exe mode=pals pals=palmt.png out=..\dev\work\palmt.h label=pal_mt silent
cd ..\dev
copy /b work\palts0.h + work\palts1.h + work\palts2.h + work\palts3.h + work\palss0.h + work\paltsl.h + work\palssl.h + work\paltsp.h + work\paltst.h + work\paltscuts.h + work\palmt.h assets\palettes.h > nul

echo Graphics
echo ========
cd ..\gfx
..\utils\mkts.exe mode=chars in=font.png out=chrts1.bin pals=palts0.png offset=0,0 size=32,2 silent
..\utils\mkts.exe mode=chars in=pyramid.png out=chrts2.bin pals=palts0.png offset=0,0 size=4,1 silent
..\utils\mkts.exe mode=mapped in=ts.png out=chrts3.bin pals=palts0.png tsmap=..\dev\assets\metatileset.h offset=0,0 size=8,8 metasize=2,2 label=tsmap tmapoffset=68 max=43 silent
..\utils\mkts.exe mode=mapped in=logo.png out=chrts4.bin pals=paltst.png tsmap=..\dev\assets\titleset.h offset=0,0 size=6,7 metasize=2,2 label=title tmapoffset=171 max=39 silent
..\utils\mkts.exe mode=mapped in=endings.png out=chrts5.bin pals=paltscuts.png tsmap=..\dev\assets\endingset.h offset=0,0 size=4,8 metasize=2,2 label=ending tmapoffset=213 silent

..\utils\mkts.exe mode=sprites16 in=sspl.png out=chrss1.bin pals=palss.png tsmap=..\dev\assets\metasprites_pl.h offset=0,0 size=10,3 max=22 metasize=2,2 sprorg=-4,-16 label=spr_pl genflipped silent
..\utils\mkts.exe mode=sprites16 in=sspl.png out=chrss1B.bin pals=palss.png tsmap=..\dev\assets\metasprites_ex.h offset=0,12 size=2,1 metasize=4,1 sprorg=-8,-0 label=spr_ex tmapoffset=150 genflipped silent
..\utils\mkts.exe mode=sprites16 in=ssenit.png out=chrss2.bin pals=palss.png tsmap=..\dev\assets\metasprites_en.h offset=0,0 size=8,1 metasize=2,1 sprorg=0,0 label=spr_en tmapoffset=164 silent
..\utils\mkts.exe mode=sprites16 in=ssenit.png out=chrss3.bin pals=palss.png tsmap=..\dev\assets\metasprites_fa.h offset=0,2 size=8,1 metasize=2,1 sprorg=0,0 label=spr_fa tmapoffset=196 genflipped silent
..\utils\mkts.exe mode=sprites16 in=ssenit.png out=chrss4.bin pals=palss.png tsmap=..\dev\assets\metasprites_it.h offset=0,4 size=4,1 metasize=2,1 sprorg=0,0 label=spr_it tmapoffset=222 silent
..\utils\mkts.exe mode=sprites16 in=ssenit.png out=chrss5.bin pals=palmt.png tsmap=..\dev\assets\metasprite_logo.h offset=10,4 size=1,1 metasize=6,1 sprorg=0,0 label=spr_logo tmapoffset=238 silent

copy /b chrts1.bin + chrts2.bin + chrts3.bin + chrts4.bin + chrts5.bin chrts.bin > nul
..\utils\fillto.exe chrts.bin 4096
del chrts1.bin > nul
del chrts2.bin > nul
del chrts3.bin > nul
del chrts4.bin > nul
del chrts5.bin > nul

copy /b chrss1.bin + chrss1B.bin + chrss2.bin + chrss3.bin + chrss4.bin + chrss5.bin chrss.bin > nul
..\utils\fillto.exe chrss.bin 4096
del chrss1.bin > nul
del chrss1B.bin > nul
del chrss2.bin > nul
del chrss3.bin > nul
del chrss4.bin > nul
del chrss5.bin > nul

copy /b chrts.bin + chrss.bin ..\dev\tileset.chr
del chrts.bin > nul
del chrss.bin > nul
cd ..\dev

:mapenems

echo Map
echo ===
cd ..\map
suwolmapcnv.exe do
copy uwolmap.h ..\dev\assets\ > nul
cd ..\dev

echo Enems
echo =====
..\utils\eneexp2.exe ..\enems\uwol.ene assets\uwolenems.h _ nohotspots

:compile

echo Compiling...
echo ============
cc65 -Oi uwol.c --add-source
ca65 crt0.s
ca65 uwol.s

ld65 -C nes.cfg -o suwol.nes crt0.o uwol.o runtime.lib

del uwol.s > nul
del uwol.o > nul
del crt0.o > nul
