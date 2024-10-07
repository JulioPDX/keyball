/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default
  [0] = LAYOUT_universal(
    KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                            KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     ,
    KC_A     , KC_S     , KC_D     , LT(4, KC_F)     , KC_G     ,                            KC_H     , LT(3, KC_J)     , KC_K     , KC_L     , KC_SCLN  ,
    KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                            KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  ,
    KC_LCTL  , KC_LGUI  , KC_LALT  ,LT(3, KC_LGUI),LT(1, KC_TAB), CTL_T(KC_BSPC),SFT_T(KC_SPC),LT(2,KC_ENT),LSFT_T(KC_LNG2),KC_RALT,KC_RGUI, LT(4, KC_DEL)
  ),

  [1] = LAYOUT_universal(
    KC_ESC    , KC_HOME    , KC_UP    , KC_END    , _______  ,                            KC_LPRN    , KC_RPRN    , _______    , _______    , _______   ,
    KC_VOLU    , KC_LEFT  , KC_DOWN  ,KC_RIGHT, KC_PGUP  ,                           KC_LBRC, KC_RBRC  , _______  , _______  , _______  ,
    KC_VOLD,KC_MPRV,KC_MPLY   , KC_MNXT  ,KC_PGDN,                            KC_LCBR  , KC_RCBR   , _______  , _______  , _______   ,
    KC_INT1  , KC_EQL   , S(KC_3)  , _______  , _______  , _______  ,      _______    , MO(3)    , _______  , _______  , _______  , MO(4)
  ),

  [2] = LAYOUT_universal(
    KC_EXLM   , KC_AT     , KC_HASH     , KC_DLR     , KC_PERC  ,                            KC_PLUS  , KC_7  , KC_8  , KC_9  , KC_0  ,
   KC_CIRC, KC_AMPR     , KC_TILD     , KC_PIPE     ,KC_BSLS,                            KC_MINUS  , KC_4  , KC_5    , KC_6  , KC_EQL  ,
    KC_DQT  , KC_QUOT     , KC_UNDS     , KC_GRV     ,_______,                           KC_ASTR, KC_1  , KC_2  , KC_3  , _______  ,
    _______   , _______     , _______   , _______   , MO(3)   , _______  ,      _______  , _______  , _______  , _______  , _______  , _______
  ),

  [3] = LAYOUT_universal(
    RGB_TOG  , AML_TO   , AML_I50  , AML_D50  , _______  ,                            _______  , _______  , SSNP_HOR , SSNP_VRT , SSNP_FRE ,
    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , SCRL_DVI ,                            _______  , _______  , _______  , _______  , _______  ,
    RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , SCRL_DVD ,                            CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE ,
    QK_BOOT  , KBC_RST  , _______  , _______  , _______  , _______  ,      _______  , _______  , _______  , _______  , KBC_RST  , QK_BOOT
  ),
  [4] = LAYOUT_universal(
    KC_F1  , KC_F2   , KC_F3  , KC_F4  , KC_F5  ,                            KC_F6  , KC_F7  , KC_F8 , KC_F9 , KC_F10 ,
    _______  , _______  , _______  , _______  , _______ ,                            _______  , KC_BTN1  , KC_BTN3  , KC_BTN2  , _______  ,
    QK_BOOT , _______  , _______  , _______  , _______ ,                            _______  , _______ , _______ , _______  , _______ ,
    _______  , _______  , _______  , _______  , _______  , _______  ,      _______  , _______  , _______  , _______  , KC_F11  , KC_F12
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
