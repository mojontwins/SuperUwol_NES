// SuperUwol Engine 
// Copyleft 2015 by The Mojon Twins

//#define ATTR(x,y)		((y)>11?0:scr_buff[((y)<<4)+((x)&15)])
#define ATTR(x,y)		(scr_buff[((y)<<4)+((x)&15)])
#define TILEAT(x,y)		scr_buff[((y) << 4)+(x)]
#define SGNI(n)			((n)<0?-1:1)
#define SGNC(a,b,c)		((a)<(b)?-(c):(c))
#define SATURATE_Z(n)	((n)<0?0:(n))
#define SATURATE(v,max) ((v)>=0?((v)>(max)?(max):(v)):((v)<-(max)?-(max):(v)))
#define ABS(n)			((n)<0?-(n):(n))
#define DELTA(a,b)		((a)<(b)?(b)-(a):(a)-(b))
#define CL(x1,y1,x2,y2)	((x1)+4>=(x2)&&(x1)<=(x2)+12&&(y1)+12>=(y2)&&(y1)<=(y2)+12)
#define UPDATE			update_list [update_list_index ++]

// Game modes

#define GM_1P			1
#define GM_2P_COOP		2
#define GM_2P_VS		3

// Player status / cell calculation

#define PFACING_RIGHT	0
#define PFACING_LEFT	8
#define PSTATE_NORMAL	0
#define PSTATE_NAKED	16
#define PCELL_STANDING	0
#define PCELL_RUNNING0	0
#define PCELL_ASCEND	4
#define PCELL_DESCEND	5
#define PCELL_HIT		6
#define PCELL_DEAD		7
#define PCELL_UWOL		0
#define PCELL_MEEMAID	32

#define PLAYER_UWOL		0
#define PLAYER_MEEMAID	1

// Players are in a fixed location
// at the beginning of the OAM

#define OAM_UWOL		0
#define OAM_MEEMAID		16

// Game state.
// 'Game Over' also means 'both players dead' in VS. mode
// GS_WIN_* is when screen is cleared in 1P / 2P_COOP modes.

#define GS_GAME_OVER	1
#define GS_WIN			2
#define GS_WIN_LEFT		3
#define GS_WIN_RIGHT	4

// Music

#define MUSIC_TITLE		0
#define MUSIC_PYRAMID	1
#define MUSIC_INGAME_A	2
#define MUSIC_INGAME_B	3
#define MUSIC_INGAME_C	4
#define MUSIC_INGAME_D	5
#define MUSIC_INGAME_E 	6
#define MUSIC_FANTY		7
#define MUSIC_DALE_FRAN	8
#define MUSIC_VS		9
#define MUSIC_GAME_OVER	10
#define MUSIC_ENDING_KO	11
#define MUSIC_ENDING_OK	12

// Sound channels

#define SC_UWOL			0
#define SC_MEEMAID		1
#define SC_ENEMS		2
#define SC_LEVEL		3

// Sound effects

#define SFX_SELECT		0
#define SFX_START		1
#define SFX_JUMP		2
#define SFX_CLOTHES		3
#define SFX_PLAYER_HIT	4
#define SFX_COIN		5
#define SFX_TIC_TOC		6
#define SFX_LAST_COIN	7
#define SFX_SPIKE		8
#define SFX_FANTY		9
#define SFX_NINTENDONT	10
