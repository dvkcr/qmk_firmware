#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    _COLEMAK_L,
    _COLEMAK_M,
    _NAV,
    _LOWER,
    _RAISE
};

enum custom_keycodes {
    COLEMAK_L = SAFE_RANGE,
    COLEMAK_M
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
/*  COLEMAK_L (GACS)
 *                ,------.                                                  ,------.
 *         ,------|   F  |------.                                    ,------|   U  |------.
 *         |   W  |------|   P  |------.                      ,------|   L  |------|   Y  |
 *  ,------+------| C_S  |------|   G  |                      |   J  |------| C_E  |------+------.
 *  |   Q  | A_R  |------| S_T  |------|                      |------| S_N  |------| A_I  |   ;  |
 *  |------+------|   C  |------|   D  |                      |   H  |------|   ,  |------+------|
 *  | G_A  |   X  |------| N_V  |------|                      |------|   M  |------|   .  | G_O  |
 *  |------+------'      `------|   B  | ,------.    ,------. |   K  |------'      `------+------|
 *  |   Z  |                    `------' | C-B  |    | C-B  | `------'                    |   /  |
 *  `------'           ,------------------------.    ,------------------------.           `------'
 *                     |  Meh | L_Tb |Enter |            | Space| R_Bs | Hyper|
 *                     `--------------------'            `--------------------'
 */
    [_COLEMAK_L] = LAYOUT_split_3x5_4
    (
    /* left hand */
        KC_Q,           KC_W,           KC_F,                   KC_P,           KC_G,
        LGUI_T(KC_A),   LALT_T(KC_R),   LCTL_T(KC_S),           LSFT_T(KC_T),   KC_D,
        KC_Z,           KC_X,           KC_C,                   LT(_NAV, KC_V), KC_B,
                        KC_MEH,         LT(_LOWER, KC_TAB),     KC_ENT,         LCTL(KC_B),
    /* right hand */
         KC_J,          KC_L,           KC_U,                   KC_Y,           KC_SCLN,
         KC_H,          RSFT_T(KC_N),   RCTL_T(KC_E),           RALT_T(KC_I),   RGUI_T(KC_O),
         KC_K,          KC_M,           KC_COMM,                KC_DOT,         KC_SLSH,
         RCTL(KC_B),    KC_SPC,         LT(_RAISE, KC_BSPC),    KC_HYPR
     ),

/*  COLEMAK_R (CAGS)
 *                ,------.                                                  ,------.
 *         ,------|   F  |------.                                    ,------|   U  |------.
 *         |   W  |------|   P  |------.                      ,------|   L  |------|   Y  |
 *  ,------+------| G_S  |------|   G  |                      |   J  |------| G_E  |------+------.
 *  |   Q  | A_R  |------| S_T  |------|                      |------| S_N  |------| A_I  |   ;  |
 *  |------+------|   C  |------|   D  |                      |   H  |------|   ,  |------+------|
 *  | C_A  |   X  |------| N_V  |------|                      |------|   M  |------|   .  | C_O  |
 *  |------+------'      `------|   B  | ,------.    ,------. |   K  |------'      `------+------|
 *  |   Z  |                    `------' | C-B  |    | C-B  | `------'                    |   /  |
 *  `------'           ,------------------------.    ,------------------------.           `------'
 *                     |  Meh | L_Tb |Enter |            | Space| R_Bs | Hyper|
 *                     `--------------------'            `--------------------'
 */
    [_COLEMAK_M] = LAYOUT_split_3x5_4
    (
    /* left hand */
        KC_Q,           KC_W,           KC_F,                   KC_P,           KC_G,
        LCTL_T(KC_A),   LALT_T(KC_R),   LGUI_T(KC_S),           LSFT_T(KC_T),   KC_D,
        KC_Z,           KC_X,           KC_C,                   LT(_NAV, KC_V), KC_B,
                        KC_MEH,         LT(_LOWER, KC_TAB),     KC_ENT,         LCTL(KC_B),
    /* right hand */
        KC_J,           KC_L,           KC_U,                   KC_Y,           KC_SCLN,
        KC_H,           RSFT_T(KC_N),   RGUI_T(KC_E),           RALT_T(KC_I),   RCTL_T(KC_O),
        KC_K,           KC_M,           KC_COMM,                KC_DOT,         KC_SLSH,
        RCTL(KC_B),     KC_SPC,         LT(_RAISE, KC_BSPC),    KC_HYPR
     ),

/*  _NAV
 *                ,------.                                                  ,------.
 *         ,------|      |------.                                    ,------|  Up  |------.
 *         |      |------|      |------.                      ,------|      |------|  Del |
 *  ,------+------|      |------|      |                      |      |------| Down |------+------.
 *  | Boot |      |------|      |------|                      |------| Left |------|Right | Bksp |
 *  |------+------|      |------|      |                      |      |------| PGDN |------+------|
 *  |      |      |------|      |------|                      |------| PGUP |------| Home |Enter |
 *  |------+------'      `------|      | ,------.    ,------. |      |------'      `------+------|
 *  |      |                    `------' | CMKL |    | CMKM | `------'                    |  End |
 *  `------'           ,------------------------.    ,------------------------.           `------'
 *                     |      |      | Esc  |            | Esc  |      |      |
 *                     `--------------------'            `--------------------'
 */
    [_NAV] = LAYOUT_split_3x5_4
    (
    /* left hand */
        QK_BOOT,        _______,        _______,            _______,        _______,
        _______,        _______,        _______,            _______,        _______,
        _______,        _______,        _______,            _______,        _______,
                        _______,        _______,            KC_ESC,         COLEMAK_L,
    /* right hand */
        _______,        _______,        KC_UP,              KC_DEL,         KC_BSPC,
        _______,        KC_LEFT,        KC_DOWN,            KC_RGHT,        KC_ENT,
        _______,        KC_PGUP,        KC_PGDN,            KC_HOME,        KC_END,
        COLEMAK_M,      KC_ESC,         _______,            _______
     ),

/*  _LOWER
 *                ,------.                                                  ,------.
 *         ,------|   3  |------.                                    ,------|   8  |------.
 *         |   2  |------|   4  |------.                      ,------|   7  |------|   9  |
 *  ,------+------|  F3  |------|   5  |                      |   6  |------|   =  |------+------.
 *  |   1  |  F2  |------|  F4  |------|                      |------|   -  |------|   [  |   0  |
 *  |------+------|  F9  |------|  F5  |                      |  F6  |------|   \  |------+------|
 *  |  F1  |  F8  |------|  F10 |------|                      |------|   '  |------|   `  |   ]  |
 *  |------+------'      `------|  F11 | ,------.    ,------. |  F12 |------'      `------+------|
 *  |  F7  |                    `------' |      |    |      | `------'                    |      |
 *  `------'           ,------------------------.    ,------------------------.           `------'
 *                     |      |      |      |            |      |      |      |
 *                     `--------------------'            `--------------------'
 */
    [_LOWER] = LAYOUT_split_3x5_4
    (
    /* left hand */
        KC_1,           KC_2,           KC_3,               KC_4,           KC_5,
        KC_F1,          KC_F2,          KC_F3,              KC_F4,          KC_F5,
        KC_F7,          KC_F8,          KC_F9,              KC_F10,         KC_F11,
                        _______,        _______,            _______,        _______,
    /* right hand */
        KC_6,           KC_7,           KC_8,               KC_9,           KC_0,
        KC_F6,          KC_MINS,        KC_EQL,             KC_LBRC,        KC_RBRC,
        KC_F12,         KC_QUOT,        KC_BSLS,            KC_GRV,         _______,
        _______,        _______,        _______,            _______
     ),

/*  _RAISE
 *                ,------.                                                  ,------.
 *         ,------|   #  |------.                                    ,------|   *  |------.
 *         |   @  |------|   $  |------.                      ,------|   &  |------|   (  |
 *  ,------+------|  F3  |------|   %  |                      |   ^  |------|   +  |------+------.
 *  |   !  |  F2  |------|  F4  |------|                      |------|   _  |------|   {  |   )  |
 *  |------+------|  F9  |------|  F5  |                      |  F6  |------|   |  |------+------|
 *  |  F1  |  F8  |------|  F10 |------|                      |------|   "  |------|   ~  |   }  |
 *  |------+------'      `------|  F11 | ,------.    ,------. |  F12 |------'      `------+------|
 *  |  F7  |                    `------' |      |    |      | `------'                    |      |
 *  `------'           ,------------------------.    ,------------------------.           `------'
 *                     |      |      |      |            |      |      |      |
 *                     `--------------------'            `--------------------'
 */
    [_RAISE] = LAYOUT_split_3x5_4
    (
    /* left hand */
        KC_EXLM,        KC_AT,          KC_HASH,            KC_DLR,         KC_PERC,
        KC_F1,          KC_F2,          KC_F3,              KC_F4,          KC_F5,
        KC_F7,          KC_F8,          KC_F9,              KC_F10,         KC_F11,
                        _______,        _______,            _______,        _______,
    /* right hand */
        KC_CIRC,        KC_AMPR,        KC_ASTR,            KC_LPRN,        KC_RPRN,
        KC_F6,          KC_UNDS,        KC_PLUS,            KC_LCBR,        KC_RCBR,
        KC_F12,         KC_DQUO,        KC_PIPE,            KC_TILD,        _______,
        _______,        _______,        _______,            _______
     ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode)
    {
    case COLEMAK_L:
        if (record->event.pressed)
        {
            set_single_persistent_default_layer(_COLEMAK_L);
        }
        return false;
    case COLEMAK_M:
        if (record->event.pressed)
        {
            set_single_persistent_default_layer(_COLEMAK_M);
        }
        return false;
    }
    return true;
}
