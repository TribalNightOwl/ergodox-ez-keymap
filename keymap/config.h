//define modifiers
#define MODS_SHIFT_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))
#define MODS_CTRL_MASK  (MOD_BIT(KC_LCTL)|MOD_BIT(KC_RCTRL))
#define MODS_ALT_MASK  (MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT))
#define MODS_GUI_MASK  (MOD_BIT(KC_LGUI)|MOD_BIT(KC_RGUI))

#define RGBLIGHT_SLEEP
#undef RGBLIGHT_ANIMATIONS
#define RGBLIGHT_EFFECT_KNIGHT

#ifdef RGBLIGHT_ENABLE
#define rgblight_set_blue        rgblight_sethsv (0xFF,  0xFF, 0xFF);
#define rgblight_set_red         rgblight_sethsv (0x00,  0xFF, 0xFF);
#define rgblight_set_green       rgblight_sethsv (0x78,  0xFF, 0xFF);
#define rgblight_set_orange      rgblight_sethsv (0x1E,  0xFF, 0xFF);
#define rgblight_set_teal        rgblight_sethsv (0xC3,  0xFF, 0xFF);
#define rgblight_set_magenta     rgblight_sethsv (0x12C, 0xFF, 0xFF);
#define rgblight_set_yellow      rgblight_sethsv (0x3C,  0xFF, 0xFF);
#define rgblight_set_purple      rgblight_sethsv (0x10E, 0xFF, 0xFF);
#define rgblight_set_white       rgblight_sethsv (0x00,  0x00, 0xFF);

#define RGBLIGHT_COLOR_LAYER_0 0x00, 0x00, 0x00  // OFF
#define RGBLIGHT_COLOR_LAYER_1 0x00, 0x00, 0xFF  // BLUE
#define RGBLIGHT_COLOR_LAYER_2 0xFF, 0x00, 0x00  // RED
#define RGBLIGHT_COLOR_LAYER_3 0x00, 0xFF, 0x00
#define RGBLIGHT_COLOR_LAYER_4 0xFF, 0xFF, 0x00
#define RGBLIGHT_COLOR_LAYER_5 0x00, 0xFF, 0xFF
#define RGBLIGHT_COLOR_LAYER_6 0xFF, 0x00, 0xFF
#define RGBLIGHT_COLOR_LAYER_7 0xFF, 0xFF, 0xFF
#endif

#undef  TAPPING_TERM
#define TAPPING_TERM 200

#undef  ONESHOT_TAP_TOGGLE
#define ONESHOT_TAP_TOGGLE 2  /* Tapping this number of times holds the key until tapped this number of times again. */

#undef  ONESHOT_TIMEOUT
#define ONESHOT_TIMEOUT 5000  /* Time (in ms) before the one shot key is released */

#undef  DEBOUNCE
#define DEBOUNCE 2

#undef DEBOUNCE_DELAY
#define DEBOUNCE_DELAY 9

/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT
