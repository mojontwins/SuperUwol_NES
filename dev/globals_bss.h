// SuperUwol Engine 
// Copyleft 2015 by The Mojon Twins

static unsigned char update_list [UPDATE_LIST_SIZE * 3 + 1];
static unsigned char update_list_index;
signed char fader;

unsigned char scr_buff [192 + 16];
unsigned char attr_table [64];
unsigned char game_mode;
unsigned char dead_counter;
unsigned char paused;
unsigned char debounce_pause;
unsigned char gen_result;
unsigned char which_ending;
unsigned char seq_level;

// Level control
unsigned char n_pant, n_floor, n_column;
unsigned char exits_on;
unsigned char exit_left, exit_right;
unsigned char fanty_on;
unsigned char d1, d2;
unsigned char visited [55];

// Map rendering
unsigned char *gp_map;
unsigned char *gp_tsmap, *gp_tsmsh, *gp_tsmbk;
unsigned char rdit, rdt, rdxt, rdx, rdy, rdbyte, rdct;
unsigned char rdbg, rdfg;

// Players
unsigned char plife_uwol, plife_meemaid;
unsigned char pwins_uwol, pwins_meemaid;

// Current BG palette
unsigned char *c_pal_bg;
