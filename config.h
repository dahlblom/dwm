/*static const char font[]            = "-*-terminus-medium-r-*-*-16-*-*-*-*-*-iso10646-*";*/
static const char font[]            = "-*-tamsynmod-medium-r-*-*-14-*-*-*-*-*-*-*"; //-*-terminus-medium-r-*-*-20-*-*-*-*-*-*-*";
static const char font2[]           = "-*-terminus-medium-r-*-*-16-*-*-*-*-*-*-*"; /* This is Dmenu's font */
//static const char normbordercolor[] = "#444444";
//static const char normbgcolor[]     = "#222222";
//static const char normfgcolor[]     = "#bbbbbb";
//static const char selbordercolor[]  = "#F0F037";
//static const char selbgcolor[]      = "#F0F037";
//static const char selfgcolor[]      = "#05A308";
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 8;       /* snap pixel */
static const Bool showbar           = True;     /* False means no bar */
static const Bool topbar            = True;     /* False means bottom bar */

/* tagging */
static const char *tags[] = { "@", "AWS", "G", "build", "test", "prod", "Music", "IM", "WWW"  };

static const Rule rules[] = {
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Firefox",  NULL,       NULL,       1 << 8,       False,       -1 },
	{ "Thunderbird",  NULL,       NULL,       0 << 1,       False,       -1 },
};

/* layout(s) */
static const float mfact      = 0.52; /* factor of master area size [0.05..0.95] */
static const int nmaster      = 1;    /* number of clients in master area */
static const Bool resizehints = True; /* True means respect size hints in tiled resizals */
#include "bstack.c"
#include "bstackhoriz.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "þ",      tile },    /* first entry is default */
	{ "ý",      NULL },    /* no layout function means floating behavior */
	{ "ÿ",      monocle },
	{ "ü",      bstack },
	{ "û",      bstackhoriz },
};
/* appearance */
#define NUMCOLORS 12
static const char colors[NUMCOLORS][ColLast][13] = {
  // border foreground background
//	{ "#073642", "#657b83", "#002b36" }, // 1 = normal (grey on black)
//	{ "#b58900", "#eee8d5", "#002b36" }, // 2 = selected (white on black)
//	{ "#dc322f", "#002b36", "#b58900" }, // 3 = urgent (black on yellow)
//	{ "#073642", "#839496", "#073642" }, // 4 = lightgrey on brightblack
//	{ "#073642", "#073642", "#002b36" }, // 5 = brightblack on black
//	{ "#073642", "#002b36", "#073642" }, // 6 = black on brightblack
{ "#919191", "#919191", "#0c0c0c" },  // 0 = normal
{ "#e0f04e", "#e0f04e", "#0c0c0c" },  // 1 = selected
{ "#ff0000", "#ff0000", "#0c0c0c" },  // 2 = alert red
{ "#e0f04e", "#e0f04e", "#262626" },  // 3 = bright green on dark
{ "#f7f7f7", "#f46c50", "#262626" },  // 4 = red
{ "#f7f7f7", "#f4a550", "#262626" },  // 5 = orange
{ "#f7f7f7", "#f5df50", "#262626" },  // 6 = yellow
{ "#f7f7f7", "#9ddf49", "#262626" },  // 7 = green
{ "#f7f7f7", "#3ab166", "#262626" },  // 8 = oceangreen
{ "#f7f7f7", "#367e99", "#262626" },  // 9 = blue 
{ "#f7f7f7", "#8c38a1", "#262626" },  // 10 = indigo
{ "#f7f7f7", "#d0447f", "#262626" },  // 11 = violet
{ "#c3c3c3", "#c3c3c3", "#262626" },  // 12 = gray on gray
};
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
//static const char *dmenucmd[] = { "dmenu_run", "-fn", font, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *dmenucmd[] = { "dmenu_run", "-fn", font2, "-nb", colors[0][ColBG], "-nf", colors[0][ColFG],"-sb", colors[1][ColBG], "-sf", colors[1][ColFG], NULL };
static const char *termcmd[]  = { "urxvt", NULL };
static const char *slock[]  = { "slock", NULL };
static const char *chrome[]  = { "google-chrome", NULL };


static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
 	{ MODKEY,                       XK_s,      spawn,          {.v = slock } },
 	{ MODKEY,                       XK_g,      spawn,          {.v = chrome } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_e,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                       XK_r,      setlayout,      {.v = &layouts[4]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

