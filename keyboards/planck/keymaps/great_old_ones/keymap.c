#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#include "muse.h"
#endif
#include "eeprom.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define UC_ENT LT(_UNICODE, KC_ENT)

enum planck_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
};

enum planck_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
  _UNICODE
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

enum custom_keycodes {
  ACUTE = SAFE_RANGE,
  EGRAVE,
  ECIRC,
  AGRAVE,
  ACIRC,
  CEDILLA,
  UGRAVE,
  EMDASH
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_planck_grid(
        KC_ESCAPE,  KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPACE,
        KC_TAB,     KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCOLON,  KC_QUOTE,
        KC_LSHIFT,  KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMMA,   KC_DOT,     KC_UP,      UC_ENT,
        KC_LCTRL,   KC_LALT,    KC_LALT,    KC_LGUI,    LOWER,      KC_SPACE,   XXXXXXX,    RAISE,      KC_SLASH,   KC_LEFT,    KC_DOWN,    KC_RIGHT
    ),

    [_LOWER] = LAYOUT_planck_grid(
        KC_TILD,    KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,    KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,    _______,
        KC_DELETE,  _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_MINUS,   KC_PLUS,    _______,    KC_PIPE,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_LCBR,    KC_RCBR,    KC_VOLU,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    XXXXXXX,    _______,    KC_QUES,    KC_MUTE,    KC_VOLD,    KC_MUTE
    ),

    [_RAISE] = LAYOUT_planck_grid(
        KC_GRAVE,   KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       _______,
        KC_DELETE,  _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_MINUS,   KC_EQUAL,   _______,    KC_BSLASH,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_LBRACKET,KC_RBRACKET,_______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    XXXXXXX,    _______,    _______,    _______,    _______,    _______
    ),

    [_ADJUST] = LAYOUT_planck_grid(
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        RESET,      _______,    _______,    _______,    _______,    _______,    XXXXXXX,    _______,    _______,    _______,    _______,    _______
    ),

    [_UNICODE] = LAYOUT_planck_grid(
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    EMDASH,     AGRAVE,     ACIRC,      CEDILLA,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    ACUTE,      EGRAVE,     ECIRC,      _______,
        _______,    _______,    _______,    _______,    _______,    _______,    XXXXXXX,    _______,    UGRAVE,     _______,    _______,    _______
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ACUTE:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("e")"e");
            }
            break;
        case EGRAVE:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("`")"e");
            }
            break;
        case AGRAVE:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("`")"a");
            }
            break;
        case UGRAVE:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("`")"u");
            }
            break;
        case ECIRC:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("i")"e");
            }
            break;
        case ACIRC:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("i")"a");
            }
            break;
        case CEDILLA:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("c"));
            }
            break;
        case EMDASH:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_LSFT("-")));
            }
            break;
    }
    return true;
}

#ifdef AUDIO_ENABLE
bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo+=1;
            } else {
                muse_tempo-=1;
            }
        }
    } else {
        if (clockwise) {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_DOWN);
            unregister_code(KC_MS_WH_DOWN);
        #else
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        #endif
        } else {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_UP);
            unregister_code(KC_MS_WH_UP);
        #else
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        #endif
        }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
    case RAISE:
    case LOWER:
        return false;
    default:
        return true;
    }
}
#endif

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
