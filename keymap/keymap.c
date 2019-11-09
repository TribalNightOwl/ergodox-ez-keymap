#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "tapdances.h"


#define BASE 0 // default layer
#define NUMB 1 // numbers to home row
#define MOVE 2 // move keys

#define _______ KC_TRNS

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Insert |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Del    |   A  |S/Ctrl|   D  |   F  |   G  |------|           |------|   H  |   J  |K/Ctrl|   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv   |  '"  |      |  ~L1 | ~L2  |                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 |Backsp|	Tab  |------|       |------|  Enter |Space |
 *                                 |ace   |	     | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
    // left hand
    KC_ESC,        KC_1,    KC_2,        KC_3,        KC_4,         KC_5,                       _______,
		KC_INS,        KC_Q,    KC_W,        KC_E,        KC_R,         KC_T,   TD(CT_SQTE_DQTE_BQTE_CARET),
    KC_DELT,       KC_A,    ALT_T(KC_S), CTL_T(KC_D), LSFT_T(KC_F), KC_G,
		TD(CT_COPY_PASTE_CUT_EMACS), KC_Z,    KC_X,        KC_C, KC_V,  KC_B,   TD(CT_LPRN_LBRC_LCBR_LTHAN),
		_______,    _______,  KC_ESC,    TT(MOVE),    TT(NUMB),
	                                                                                                KC_ESC,   KC_LGUI,
                                                                                                            _______,
                                                                                             KC_BSPC,KC_TAB,_______,

        // right hand
    AG_SWAP,                      KC_6,           KC_7,              KC_8,            KC_9,                       KC_0,           KC_PSCR,
		_______,                      KC_Y,           KC_U,              KC_I,            KC_O,                       KC_P,           _______,
                                  KC_H,   RSFT_T(KC_J),      RCTL_T(KC_K),    LALT_T(KC_L),  TD(CT_MINUS_UNDSCR_EQUAL),    GUI_T(KC_QUOT),
    TD(CT_RPRN_RBRC_RCBR_GTHAN),  KC_N,           KC_M,  TD(CT_COMM_SCLN),  TD(CT_DOT_CLN),     TD(CT_SLSH_PIPE_BSLSH),           _______,
                                         OSM(MOD_RSFT),     OSM(MOD_RCTL),   OSM(MOD_LALT),                    _______,           _______,
		_______,KC_ESC,
    _______,
		_______,KC_ENT, KC_SPC
    ),
/* Keymap 1: Numbers Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  |  L0  |           |  L0  |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * | Version |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |PrintScr|
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |   0  |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Numbers
[NUMB] = LAYOUT_ergodox(
    // left hand
		KC_ESC ,_______,       _______,       _______,        _______,  _______,  TO(BASE),
		_______,  KC_F1,         KC_F2,         KC_F3,          KC_F4,    KC_F5,   _______,
		_______,   KC_1,  LALT_T(KC_2),  LCTL_T(KC_3),   LSFT_T(KC_4),     KC_5,
		_______,_______,       _______,       _______,        _______,  _______,   _______,
		EPRM   ,_______,       _______,       _______,        _______,

    // left thumb
                                       _______,_______,
                                               _______,
                               _______,_______,_______,

    // right hand
	  _______,_______,      _______,       _______,        _______, _______,                    KC_F12,
	  _______, KC_F6 ,        KC_F7,         KC_F8,          KC_F9,  KC_F10,                    KC_F11,
             KC_6  , RSFT_T(KC_7),  RCTL_T(KC_8),   LALT_T(KC_9),    KC_0, TD(CT_MINUS_UNDSCR_EQUAL),
    _______,_______,      _______,       _______,        _______, _______,                   _______,
                          _______,       _______,        _______, _______,                   _______,

   // right thumb
       _______, _______,
       _______,
       _______, _______, _______
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |  L0  |           |  L0  |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      | Up   |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      | Left | Down | Right|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      | Lclk | Rclk |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Mclk |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MOVE] = LAYOUT_ergodox(
       _______, _______, _______, _______, _______, _______, TO(BASE),
       _______, KC_NO  , KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U, TO(BASE),
       _______, KC_ESC , KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,
       _______, _______, _______, _______, _______, KC_NO  , KC_NO,
       _______, _______, _______, _______, _______,

   // left thumb
                                          _______,_______,
                                                  _______,
                                  _______,_______,_______,


   // right hand
       TO(BASE),  _______,     _______,      _______,      _______, _______,      _______,
	   TO(BASE), KC_PGUP,      KC_HOME,      KC_UP,        KC_END,  KC_NO  ,      _______,
                 KC_PGDN,      KC_LEFT,      KC_DOWN,      KC_RGHT, KC_NO  ,      _______,
       _______,  KC_MS_ACCEL0, KC_BTN1,      KC_BTN3,      KC_BTN2, KC_MS_ACCEL2, _______,
                               _______,      _______,      _______, _______, _______,


   // right thumb
       _______, _______,
       _______,
       _______, _______, _______

),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case KC_ENTER:
    if (record->event.pressed) {
    	ergodox_right_led_1_on();
    	ergodox_right_led_2_on();
    	ergodox_right_led_3_on();
    }
    return true; // Let QMK send the enter press/release events

    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom();
  rgblight_sethsv_noeeprom(0, 0, 0);
  rgblight_mode_noeeprom(0);
}
// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
	  uint8_t modifiers = get_mods();
	  uint8_t one_shot = get_oneshot_mods();
	  uint8_t led_usb_state = host_keyboard_leds();

	  ergodox_board_led_off();
	  ergodox_right_led_1_off();
	  ergodox_right_led_2_off();
	  ergodox_right_led_3_off();

	  // Since we're not using the LEDs here for layer indication anymore,
	  // then lets use them for modifier indicators.  Shame we don't have 4...
	  // Also, no "else", since we want to know each, independantly.
    if ((modifiers | one_shot) & MODS_SHIFT_MASK || led_usb_state & (1 << USB_LED_CAPS_LOCK)) {
		  ergodox_right_led_1_on();
    }
    if ((modifiers | one_shot) & MODS_CTRL_MASK) {
      ergodox_right_led_2_on();
    }
    if ((modifiers | one_shot) & MODS_ALT_MASK) {
      ergodox_right_led_3_on();
	  }
};

// used to remember the light color an mode
uint8_t mymode = 0;
uint8_t myhue = 0;
uint8_t mysat = 0;
uint8_t myval = 0;

void reset_light_state(uint8_t mode, uint8_t hue, uint8_t sat, uint8_t val) {
  // Update global values so we can return to them
  mymode = mode;
  myhue = hue;
  mysat = sat;
  myval = val;
  rgblight_sethsv_noeeprom(hue, sat, val);
  rgblight_mode_noeeprom(mode);
};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
  switch (layer) {
      case NUMB:
        // reset_light_state(1, 170, 255, 255);
        reset_light_state(1, HSV_BLUE);
        break;
      case MOVE:
        // reset_light_state(23, 43, 255, 255);
        reset_light_state(23, HSV_YELLOW);
        break;
      default:
        reset_light_state(0, 0, 0, 0);
        break;
    }
  return state;
};

// called whenever any one shot modifier key is toggled on or off
void oneshot_mods_changed_user(uint8_t mods) {
  if (mods & MOD_MASK_SHIFT) {
    println("Oneshot mods SHIFT");
    rgblight_sethsv_noeeprom(HSV_RED);
  }
  if (mods & MOD_MASK_CTRL) {
    println("Oneshot mods CTRL");
    rgblight_sethsv_noeeprom(HSV_GREEN);
  }
  if (mods & MOD_MASK_ALT) {
    println("Oneshot mods ALT");
    rgblight_sethsv_noeeprom(HSV_AZURE);
  }
  if (mods & MOD_MASK_GUI) {
    println("Oneshot mods GUI");
  }
  if (!mods) {
    println("Oneshot mods off");
    rgblight_sethsv_noeeprom(myhue, mysat, myval);
  }
};

// called whenever any one shot modifier key is locked and unlocked
void oneshot_locked_mods_changed_user(uint8_t mods) {
  if (mods & MOD_MASK_SHIFT) {
    println("Oneshot locked mods SHIFT");
    rgblight_sethsv_noeeprom(HSV_RED);
  }
  if (mods & MOD_MASK_CTRL) {
    println("Oneshot locked mods CTRL");
    rgblight_sethsv_noeeprom(HSV_GREEN);
  }
  if (mods & MOD_MASK_ALT) {
    println("Oneshot locked mods ALT");
    rgblight_sethsv_noeeprom(HSV_AZURE);
  }
  if (mods & MOD_MASK_GUI) {
    println("Oneshot locked mods GUI");
  }
  if (!mods) {
    println("Oneshot locked mods off");
    rgblight_sethsv_noeeprom(myhue, mysat, myval);
  }
};
