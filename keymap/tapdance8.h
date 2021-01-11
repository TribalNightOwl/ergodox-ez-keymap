/*
 * SINGLE_TAP  = tmux prefix
 * SINGLE_HOLD = tmux copy mode
 * DOUBLE_TAP  = tmux copy
 * DOUBLE_HOLD = tmux paste
 *
 */

//instance of 'tap' for this tap dance.
static tap dance8_state = {
  .is_press_action = true,
  .state = 0
};

void dance8_finished (qk_tap_dance_state_t *state, void *user_data) {
  dance8_state.state = cur_dance(state);
  switch (dance8_state.state) {
    case SINGLE_TAP:  register_code(KC_LCTL); register_code(KC_B); break;
    case SINGLE_HOLD: register_code(KC_LCTL); register_code(KC_B); unregister_code(KC_LCTL); unregister_code(KC_B); register_code(KC_LBRACKET); break;
    case DOUBLE_TAP:  register_code(KC_LCTL); register_code(KC_W); break;
    case DOUBLE_HOLD: register_code(KC_LCTL); register_code(KC_B); unregister_code(KC_LCTL); unregister_code(KC_B); register_code(KC_RBRACKET); break;
    case DOUBLE_SINGLE_TAP: register_code(KC_NO);
    //Last case is for fast typing. Assuming your key is `f`:
    //For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
    //In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
  }
}

void dance8_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (dance8_state.state) {
    case SINGLE_TAP:  unregister_code(KC_LCTL); unregister_code(KC_B); break;
    case SINGLE_HOLD: unregister_code(KC_LBRACKET); break;
    case DOUBLE_TAP:  unregister_code(KC_LCTL); unregister_code(KC_W); break;
    case DOUBLE_HOLD: unregister_code(KC_RBRACKET); break;
    case DOUBLE_SINGLE_TAP: unregister_code(KC_NO);
  }
  dance8_state.state = 0;
}

#define TAPDANCE8(x) [x] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance8_finished, dance8_reset)
