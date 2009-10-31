use sdl
import sdl/Sdl

Motion: cover from SDL_MouseMotionEvent {
	x,y: extern Int
	xrel, yrel: extern Int
}

Keysym: cover from SDL_keysym {
	sym: extern Int
}

Key: cover from SDL_KeyboardEvent {
	keysym: extern Keysym
}

Event: cover from SDL_Event {
	type: extern Int
	key: extern Key
	motion: extern Motion
}


SDLEvent: cover {
	wait: extern(SDL_WaitEvent) static func(Event*) -> Int
	poll: extern(SDL_PollEvent) static func(Event*) -> Int
}




	SDLK_UNKNOWN		= 0 : extern const Int
	SDLK_FIRST		= 0 : extern const Int
	SDLK_BACKSPACE		= 8 : extern const Int
	SDLK_TAB		= 9 : extern const Int
	SDLK_CLEAR		= 12 : extern const Int
	SDLK_RETURN		= 13 : extern const Int
	SDLK_PAUSE		= 19 : extern const Int
	SDLK_ESCAPE		= 27 : extern const Int
	SDLK_SPACE		= 32 : extern const Int
	SDLK_EXCLAIM		= 33 : extern const Int
	SDLK_QUOTEDBL		= 34 : extern const Int
	SDLK_HASH		= 35 : extern const Int
	SDLK_DOLLAR		= 36 : extern const Int
	SDLK_AMPERSAND		= 38 : extern const Int
	SDLK_QUOTE		= 39 : extern const Int
	SDLK_LEFTPAREN		= 40 : extern const Int
	SDLK_RIGHTPAREN		= 41 : extern const Int
	SDLK_ASTERISK		= 42 : extern const Int
	SDLK_PLUS		= 43 : extern const Int
	SDLK_COMMA		= 44 : extern const Int
	SDLK_MINUS		= 45 : extern const Int
	SDLK_PERIOD		= 46 : extern const Int
	SDLK_SLASH		= 47 : extern const Int
	SDLK_0			= 48 : extern const Int
	SDLK_1			= 49 : extern const Int
	SDLK_2			= 50 : extern const Int
	SDLK_3			= 51 : extern const Int
	SDLK_4			= 52 : extern const Int
	SDLK_5			= 53 : extern const Int
	SDLK_6			= 54 : extern const Int
	SDLK_7			= 55 : extern const Int
	SDLK_8			= 56 : extern const Int
	SDLK_9			= 57 : extern const Int
	SDLK_COLON		= 58 : extern const Int
	SDLK_SEMICOLON		= 59 : extern const Int
	SDLK_LESS		= 60 : extern const Int
	SDLK_EQUALS		= 61 : extern const Int
	SDLK_GREATER		= 62 : extern const Int
	SDLK_QUESTION		= 63 : extern const Int
	SDLK_AT			= 64 : extern const Int
	/* 
	   Skip uppercase letters
	 */
	SDLK_LEFTBRACKET	= 91 : extern const Int
	SDLK_BACKSLASH		= 92 : extern const Int
	SDLK_RIGHTBRACKET	= 93 : extern const Int
	SDLK_CARET		= 94 : extern const Int
	SDLK_UNDERSCORE		= 95 : extern const Int
	SDLK_BACKQUOTE		= 96 : extern const Int
	SDLK_a			= 97 : extern const Int
	SDLK_b			= 98 : extern const Int
	SDLK_c			= 99 : extern const Int
	SDLK_d			= 100 : extern const Int
	SDLK_e			= 101 : extern const Int
	SDLK_f			= 102 : extern const Int
	SDLK_g			= 103 : extern const Int
	SDLK_h			= 104 : extern const Int
	SDLK_i			= 105 : extern const Int
	SDLK_j			= 106 : extern const Int
	SDLK_k			= 107 : extern const Int
	SDLK_l			= 108 : extern const Int
	SDLK_m			= 109 : extern const Int
	SDLK_n			= 110 : extern const Int
	SDLK_o			= 111 : extern const Int
	SDLK_p			= 112 : extern const Int
	SDLK_q			= 113 : extern const Int
	SDLK_r			= 114 : extern const Int
	SDLK_s			= 115 : extern const Int
	SDLK_t			= 116 : extern const Int
	SDLK_u			= 117 : extern const Int
	SDLK_v			= 118 : extern const Int
	SDLK_w			= 119 : extern const Int
	SDLK_x			= 120 : extern const Int
	SDLK_y			= 121 : extern const Int
	SDLK_z			= 122 : extern const Int
	SDLK_DELETE		= 127 : extern const Int
	/* End of ASCII mapped keysyms */

	/* International keyboard syms */
	SDLK_WORLD_0		= 160 : extern const Int		/* 0xA0 */
	SDLK_WORLD_1		= 161 : extern const Int
	SDLK_WORLD_2		= 162 : extern const Int
	SDLK_WORLD_3		= 163 : extern const Int
	SDLK_WORLD_4		= 164 : extern const Int
	SDLK_WORLD_5		= 165 : extern const Int
	SDLK_WORLD_6		= 166 : extern const Int
	SDLK_WORLD_7		= 167 : extern const Int
	SDLK_WORLD_8		= 168 : extern const Int
	SDLK_WORLD_9		= 169 : extern const Int
	SDLK_WORLD_10		= 170 : extern const Int
	SDLK_WORLD_11		= 171 : extern const Int
	SDLK_WORLD_12		= 172 : extern const Int
	SDLK_WORLD_13		= 173 : extern const Int
	SDLK_WORLD_14		= 174 : extern const Int
	SDLK_WORLD_15		= 175 : extern const Int
	SDLK_WORLD_16		= 176 : extern const Int
	SDLK_WORLD_17		= 177 : extern const Int
	SDLK_WORLD_18		= 178 : extern const Int
	SDLK_WORLD_19		= 179 : extern const Int
	SDLK_WORLD_20		= 180 : extern const Int
	SDLK_WORLD_21		= 181 : extern const Int
	SDLK_WORLD_22		= 182 : extern const Int
	SDLK_WORLD_23		= 183 : extern const Int
	SDLK_WORLD_24		= 184 : extern const Int
	SDLK_WORLD_25		= 185 : extern const Int
	SDLK_WORLD_26		= 186 : extern const Int
	SDLK_WORLD_27		= 187 : extern const Int
	SDLK_WORLD_28		= 188 : extern const Int
	SDLK_WORLD_29		= 189 : extern const Int
	SDLK_WORLD_30		= 190 : extern const Int
	SDLK_WORLD_31		= 191 : extern const Int
	SDLK_WORLD_32		= 192 : extern const Int
	SDLK_WORLD_33		= 193 : extern const Int
	SDLK_WORLD_34		= 194 : extern const Int
	SDLK_WORLD_35		= 195 : extern const Int
	SDLK_WORLD_36		= 196 : extern const Int
	SDLK_WORLD_37		= 197 : extern const Int
	SDLK_WORLD_38		= 198 : extern const Int
	SDLK_WORLD_39		= 199 : extern const Int
	SDLK_WORLD_40		= 200 : extern const Int
	SDLK_WORLD_41		= 201 : extern const Int
	SDLK_WORLD_42		= 202 : extern const Int
	SDLK_WORLD_43		= 203 : extern const Int
	SDLK_WORLD_44		= 204 : extern const Int
	SDLK_WORLD_45		= 205 : extern const Int
	SDLK_WORLD_46		= 206 : extern const Int
	SDLK_WORLD_47		= 207 : extern const Int
	SDLK_WORLD_48		= 208 : extern const Int
	SDLK_WORLD_49		= 209 : extern const Int
	SDLK_WORLD_50		= 210 : extern const Int
	SDLK_WORLD_51		= 211 : extern const Int
	SDLK_WORLD_52		= 212 : extern const Int
	SDLK_WORLD_53		= 213 : extern const Int
	SDLK_WORLD_54		= 214 : extern const Int
	SDLK_WORLD_55		= 215 : extern const Int
	SDLK_WORLD_56		= 216 : extern const Int
	SDLK_WORLD_57		= 217 : extern const Int
	SDLK_WORLD_58		= 218 : extern const Int
	SDLK_WORLD_59		= 219 : extern const Int
	SDLK_WORLD_60		= 220 : extern const Int
	SDLK_WORLD_61		= 221 : extern const Int
	SDLK_WORLD_62		= 222 : extern const Int
	SDLK_WORLD_63		= 223 : extern const Int
	SDLK_WORLD_64		= 224 : extern const Int
	SDLK_WORLD_65		= 225 : extern const Int
	SDLK_WORLD_66		= 226 : extern const Int
	SDLK_WORLD_67		= 227 : extern const Int
	SDLK_WORLD_68		= 228 : extern const Int
	SDLK_WORLD_69		= 229 : extern const Int
	SDLK_WORLD_70		= 230 : extern const Int
	SDLK_WORLD_71		= 231 : extern const Int
	SDLK_WORLD_72		= 232 : extern const Int
	SDLK_WORLD_73		= 233 : extern const Int
	SDLK_WORLD_74		= 234 : extern const Int
	SDLK_WORLD_75		= 235 : extern const Int
	SDLK_WORLD_76		= 236 : extern const Int
	SDLK_WORLD_77		= 237 : extern const Int
	SDLK_WORLD_78		= 238 : extern const Int
	SDLK_WORLD_79		= 239 : extern const Int
	SDLK_WORLD_80		= 240 : extern const Int
	SDLK_WORLD_81		= 241 : extern const Int
	SDLK_WORLD_82		= 242 : extern const Int
	SDLK_WORLD_83		= 243 : extern const Int
	SDLK_WORLD_84		= 244 : extern const Int
	SDLK_WORLD_85		= 245 : extern const Int
	SDLK_WORLD_86		= 246 : extern const Int
	SDLK_WORLD_87		= 247 : extern const Int
	SDLK_WORLD_88		= 248 : extern const Int
	SDLK_WORLD_89		= 249 : extern const Int
	SDLK_WORLD_90		= 250 : extern const Int
	SDLK_WORLD_91		= 251 : extern const Int
	SDLK_WORLD_92		= 252 : extern const Int
	SDLK_WORLD_93		= 253 : extern const Int
	SDLK_WORLD_94		= 254 : extern const Int
	SDLK_WORLD_95		= 255 : extern const Int		/* 0xFF */

	/* Numeric keypad */
	SDLK_KP0		= 256 : extern const Int
	SDLK_KP1		= 257 : extern const Int
	SDLK_KP2		= 258 : extern const Int
	SDLK_KP3		= 259 : extern const Int
	SDLK_KP4		= 260 : extern const Int
	SDLK_KP5		= 261 : extern const Int
	SDLK_KP6		= 262 : extern const Int
	SDLK_KP7		= 263 : extern const Int
	SDLK_KP8		= 264 : extern const Int
	SDLK_KP9		= 265 : extern const Int
	SDLK_KP_PERIOD		= 266 : extern const Int
	SDLK_KP_DIVIDE		= 267 : extern const Int
	SDLK_KP_MULTIPLY	= 268 : extern const Int
	SDLK_KP_MINUS		= 269 : extern const Int
	SDLK_KP_PLUS		= 270 : extern const Int
	SDLK_KP_ENTER		= 271 : extern const Int
	SDLK_KP_EQUALS		= 272 : extern const Int

	/* Arrows + Home/End pad */
	SDLK_UP			= 273 : extern const Int
	SDLK_DOWN		= 274 : extern const Int
	SDLK_RIGHT		= 275 : extern const Int
	SDLK_LEFT		= 276 : extern const Int
	SDLK_INSERT		= 277 : extern const Int
	SDLK_HOME		= 278 : extern const Int
	SDLK_END		= 279 : extern const Int
	SDLK_PAGEUP		= 280 : extern const Int
	SDLK_PAGEDOWN		= 281 : extern const Int

	/* Function keys */
	SDLK_F1			= 282 : extern const Int
	SDLK_F2			= 283 : extern const Int
	SDLK_F3			= 284 : extern const Int
	SDLK_F4			= 285 : extern const Int
	SDLK_F5			= 286 : extern const Int
	SDLK_F6			= 287 : extern const Int
	SDLK_F7			= 288 : extern const Int
	SDLK_F8			= 289 : extern const Int
	SDLK_F9			= 290 : extern const Int
	SDLK_F10		= 291 : extern const Int
	SDLK_F11		= 292 : extern const Int
	SDLK_F12		= 293 : extern const Int
	SDLK_F13		= 294 : extern const Int
	SDLK_F14		= 295 : extern const Int
	SDLK_F15		= 296 : extern const Int

	/* Key state modifier keys */
	SDLK_NUMLOCK		= 300 : extern const Int
	SDLK_CAPSLOCK		= 301 : extern const Int
	SDLK_SCROLLOCK		= 302 : extern const Int
	SDLK_RSHIFT		= 303 : extern const Int
	SDLK_LSHIFT		= 304 : extern const Int
	SDLK_RCTRL		= 305 : extern const Int
	SDLK_LCTRL		= 306 : extern const Int
	SDLK_RALT		= 307 : extern const Int
	SDLK_LALT		= 308 : extern const Int
	SDLK_RMETA		= 309 : extern const Int
	SDLK_LMETA		= 310 : extern const Int
	SDLK_LSUPER		= 311 : extern const Int		/* Left "Windows" key */
	SDLK_RSUPER		= 312 : extern const Int		/* Right "Windows" key */
	SDLK_MODE		= 313 : extern const Int		/* "Alt Gr" key */
	SDLK_COMPOSE		= 314 : extern const Int		/* Multi-key compose key */

	/* Miscellaneous function keys */
	SDLK_HELP		= 315 : extern const Int
	SDLK_PRINT		= 316 : extern const Int
	SDLK_SYSREQ		= 317 : extern const Int
	SDLK_BREAK		= 318 : extern const Int
	SDLK_MENU		= 319 : extern const Int
	SDLK_POWER		= 320 : extern const Int		/* Power Macintosh power key */
	SDLK_EURO		= 321 : extern const Int		/* Some european keyboards */
	SDLK_UNDO		= 322 : extern const Int		/* Atari keyboard has Undo */

	/* Add any other keys here */


	SDL_MOUSEMOTION : extern const Int
