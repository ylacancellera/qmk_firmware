/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "keymap_french.h"

enum layers {
    _AZERTY = 0,
    _LOWER,
    _RAISE,
    _ALGR,
    _ADJUST
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* 
 * Base Layer: AZERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  TAB   |   A  |   Z  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |   ^    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | Lshift |   Q  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  |   M  |   ù    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LCtrl  |   W  |   X  |   C  |   V  |   B  | esc  |ADJUST|  | TAB  |LShift|   N  |   ,  |   ;  |   :  |   !  |   *    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | GUI  | ALT  |Lower | Space| Raise|  | bkspc|enter | altgr|   <  |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_AZERTY] = LAYOUT(
      KC_TAB,	FR_A,   FR_Z, KC_E,   KC_R,   KC_T,                                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, FR_CIRC,
      KC_LSFT, 	FR_Q,   KC_S, KC_D,   KC_F,   KC_G,                                       KC_H,    KC_J,    KC_K,    KC_L,    FR_M, FR_UGRV,
      KC_LCTL,  KC_Z,   KC_X, KC_C,   KC_V,   KC_B, KC_ESC,MO(_ADJUST),KC_TAB, KC_LSFT, KC_N,    FR_COMM, FR_SCLN, FR_COLN, FR_EXLM, FR_ASTR,
          KC_LGUI, KC_LALT, MO(_LOWER), KC_SPC, MO(_RAISE),              KC_BSPC,  KC_ENT, MO(_ALGR), FR_LESS,  KC_RALT
    ),
/*
 * Lower Layer: Symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |   esc  |  &   |  é   |   "  |  '   |  (   |                              |   -  |   è  |  _   |  ç   |  à   |    )   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  ^   |  $   |  (   |  [   |  {   |                              |      | pgdn |  up  | pgup |  %   |    =   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  caps  |  %   |  #   |  )   |  ]   |  }   |      |      |  | pgup |  up  | pgdn | left | down | right|  / ? |    <   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |  ;   |  =   |  | left | down |right |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */

    [_LOWER] = LAYOUT(
      KC_ESC,  FR_AMP,  FR_EACU, FR_QUOT, FR_APOS, FR_LPRN,                                         			FR_MINS, FR_EGRV, FR_UNDS, FR_CCED,  FR_AGRV, FR_RPRN,
      KC_CAPS, ALGR(FR_CCED), FR_DLR,  FR_LPRN, ALGR(FR_LPRN), ALGR(FR_APOS),                                   	_______, KC_PGUP, KC_UP,   KC_PGDN,  KC_PERC, FR_EQL,
      _______, LSFT(FR_UGRV), ALGR(FR_QUOT), FR_RPRN, ALGR(FR_RPRN), ALGR(FR_EQL), _______, _______,  KC_PGUP, KC_UP,   KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, FR_LESS, FR_LESS,
                                             _______, _______,       _______,      KC_SCLN, KC_EQL,   KC_LEFT, KC_DOWN, KC_RIGHT,_______, _______
    ),
/*
 * Raise Layer: Number keys, media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |brgtUp|  €   |VolUp |      |                              |  7   |  8   |  9   |numlk |      |impr sys|
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |brgtDn|      |VolDn |      |                              |  4   |  5   |  6   |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      | Mute |      |      |      |  |      |      |  1   |  2   |  3   |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |  0   |  .   |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */

    [_RAISE] = LAYOUT(
      _______, _______, KC_BRIU, ALGR(KC_E),  KC_VOLU, _______,                                 KC_P7,   KC_P8,   KC_P9,  KC_NLCK, _______, _______,
      _______, _______, KC_BRID, _______, KC_VOLD, _______,                                     KC_P4,   KC_P5,   KC_P6,  _______, _______, _______,
      _______, _______, _______, _______, KC_MUTE, _______, _______, _______, _______, _______, KC_P1,	 KC_P2,   KC_P3,  _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, KC_P0,   KC_PDOT, _______
    ),

 /*
  * Algr layer: lower, but algred version
  *
  * ,-------------------------------------------.                              ,-------------------------------------------.
  * |    ¬   |  ¹   |   ~  |  #   |  {   |  [   |                              |  |   |  `   |  \   |  ^   |  @   |   ]    |
  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
  * |        |      |      |      |      |      |                              |      |      |      |      |      |   }    |
  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
  *                        |      |      |      |      |      |  |      |      |      |      |      |
  *                        |      |      |      |      |      |  |      |      |      |      |      |
  *                        `----------------------------------'  `----------------------------------'
  */
     [_ALGR] = LAYOUT(
       _______, ALGR(FR_AMP),  ALGR(FR_EACU), ALGR(FR_QUOT), ALGR(FR_APOS), ALGR(FR_LPRN), ALGR(FR_MINS), ALGR(FR_EGRV), ALGR(FR_UNDS), ALGR(FR_CCED),  ALGR(FR_AGRV), ALGR(FR_RPRN),
       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, ALGR(KC_EQL),
       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
     ),
/*
 * Adjust Layer: Function keys, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        | F1   |  F2  | F3   | F4   | F5   |                              | F6   | F7   |  F8  | F9   | F10  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | TOG  | SAI  | HUI  | VAI  | MOD  |                              |      |      |      | F11  | F12  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      | SAD  | HUD  | VAD  | RMOD |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_ADJUST] = LAYOUT(
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
      _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,                                     _______, _______, _______, KC_F11,  KC_F12,  _______,
      _______, RGB_M_P, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_kyria_logo(void) {
    static const char PROGMEM kyria_logo[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x0e, 0x0c, 0xbc, 0xb8, 0xf0, 0xf0, 0xe0, 0xc0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x3e, 0x72, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfc, 0xfc, 0xf8, 0xf8, 0xf0, 0xf0, 0xf0, 0xe0, 0xe0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x80, 0x80, 0x80, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0xc0, 0xc0, 0xe0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf0, 0x70, 0xf8, 0x38, 0xbc, 0xdc, 0xce, 0xce, 0x1e, 0x07, 0x43, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x27, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0x7f, 0x7f, 0x3f, 0x3f, 0x1f, 0xff, 0xff, 0xff, 0xfb, 0xfb, 0xff, 0xff, 0xff, 0xfc, 0xfc, 0xf9, 0xf3, 0xc3, 0x02, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf3, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0x8c, 0xfc, 0xfd, 0x7d, 0x7f, 0xff, 0xff, 0xcf, 0xcf, 0x1f, 0x1f, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf8, 0xfe, 0xff, 0xff, 0xff, 0x9f, 0x1f, 0x1f, 0x1f, 0x3f, 0x3f, 0x3f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xdf, 0x1f, 0xdc, 0xfc, 0xff, 0x7f, 0x1f, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xf8, 0xf8, 0xf8, 0xf0, 0xf0, 0xf0, 0xf0, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe7, 0xc3, 0xc3, 0xc1, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf8, 0xf8, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xcf, 0x3f, 0x3f, 0x3f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0x0f, 0x1f, 0x3f, 0x3f, 0x3f, 0x1f, 0x0f, 0x0f, 0x0f, 0x1f, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

static void render_woman_numlk(void) {
	static const char PROGMEM w[] = {
		0x3f, 0xff, 0xb7, 0xff, 0xff, 0xfc, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x98, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xcc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xcc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0xff, 0xfd, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0xff, 0xfd, 0xff, 0xff, 0xff, 0xf8, 0x18, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0xff, 0xfd, 0xff, 0xff, 0xff, 0xf0, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0xff, 0xfd, 0xff, 0xff, 0xff, 0xf1, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0xff, 0xfd, 0xff, 0xf8, 0x3f, 0xf3, 0x80, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0xff, 0xfd, 0xef, 0xc0, 0x1f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0xff, 0xf9, 0xe0, 0xfc, 0x1f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0xff, 0xf9, 0xe3, 0xff, 0xdf, 0xf8, 0x80, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0xef, 0xf3, 0xe7, 0xff, 0xff, 0xf1, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x8f, 0xe3, 0xef, 0xf0, 0x67, 0xf8, 0x04, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x87, 0xe2, 0xcf, 0xc0, 0x17, 0xff, 0xf6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x83, 0xc2, 0xcf, 0x02, 0x1f, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x03, 0xc2, 0xee, 0x00, 0x3f, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x03, 0x82, 0xec, 0x01, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x03, 0x84, 0xff, 0x0f, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 
0x03, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xf0, 0x00, 0x00, 0x00, 
0x03, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x03, 0xff, 0xfe, 0x00, 0x00, 0x00, 
0x06, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xc0, 0x00, 0x00, 
0x06, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xf8, 0x00, 0x00, 
0x04, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 
0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 
0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 
0x00, 0x00, 0x7f, 0xff, 0xff, 0x1d, 0xff, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 
0x08, 0x00, 0xff, 0xff, 0xff, 0x9f, 0xff, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 
0x84, 0x08, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 
0xc4, 0x08, 0xff, 0xff, 0xff, 0xff, 0xef, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 
0xc6, 0xce, 0xff, 0xff, 0xff, 0xff, 0x86, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x40, 0x00, 
0xc6, 0xcc, 0x7f, 0xff, 0xff, 0xff, 0x86, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xf0, 0x18, 0x20, 0x00, 
0xc7, 0xc4, 0x3f, 0xff, 0xff, 0xfc, 0x02, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 
0xc7, 0xce, 0x3f, 0xff, 0xff, 0xc3, 0x06, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 
0xc3, 0xc6, 0x1f, 0xff, 0xff, 0x00, 0x06, 0x01, 0xff, 0xff, 0xff, 0xff, 0xe6, 0x00, 0x00, 0x00, 
0xc3, 0xc7, 0x1f, 0xff, 0xf8, 0x00, 0x06, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 
0xc1, 0xe3, 0x0f, 0xff, 0xf0, 0x00, 0x07, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 
0xc3, 0xe1, 0x8f, 0xff, 0xf0, 0x00, 0x07, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 
0xc1, 0xe1, 0x87, 0xff, 0xf0, 0x0c, 0x06, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 
0x81, 0xe0, 0x47, 0xff, 0xf0, 0x7e, 0x0e, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 
0x80, 0xe0, 0x27, 0xff, 0xf3, 0xff, 0x0f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 
0x00, 0xe0, 0x31, 0xff, 0xf3, 0xff, 0xcf, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 
0xc0, 0xc0, 0x18, 0xff, 0xf3, 0xff, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 
0xc0, 0xc0, 0x0c, 0xff, 0xf9, 0xff, 0xe5, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 
0xc1, 0x80, 0x04, 0x7f, 0xff, 0xff, 0xf5, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 
0x83, 0x80, 0x03, 0x0f, 0xff, 0xfe, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 
0x07, 0x80, 0x00, 0xcf, 0xff, 0xe1, 0xe7, 0xff, 0xff, 0xc3, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 
0x1f, 0x80, 0xe0, 0x00, 0xff, 0xff, 0xef, 0xff, 0xfc, 0x01, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 
0x7f, 0x8f, 0xe0, 0x02, 0x7f, 0xff, 0xdf, 0xff, 0xf8, 0x01, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 
0xff, 0xff, 0xc0, 0x00, 0x7d, 0xa3, 0xff, 0xff, 0xf8, 0x00, 0x7f, 0x80, 0x00, 0x00, 0x00, 0x00, 
0xff, 0xff, 0xe0, 0x00, 0x7c, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x7f, 0x80, 0x00, 0x00, 0x00, 0x00
	};
    oled_write_raw_P(w, sizeof(w));
}


static void render_woman_full(void) {
	static const char PROGMEM w[] = {
		0x3f, 0xff, 0xb7, 0xff, 0xff, 0xfc, 0x60, 0x00, 0x00, 0x00, 0x00, 0x03, 0xf0, 0x00, 0x00, 0x00,
0x3f, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x70, 0x00, 0x00, 0x00, 0x00, 0x07, 0xf0, 0x00, 0x00, 0x00,
0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x30, 0x00, 0x00, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x00,
0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xb8, 0x00, 0x00, 0x00, 0x0c, 0x03, 0x80, 0x30, 0x00, 0x00,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x98, 0x00, 0x00, 0x00, 0x08, 0x03, 0x82, 0x88, 0x00, 0x00,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xcc, 0x00, 0x00, 0x00, 0x00, 0x03, 0x40, 0x00, 0x00, 0x00,
0xff, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xcc, 0x00, 0x00, 0x00, 0x20, 0x03, 0x4f, 0x00, 0x00, 0x00,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe4, 0x00, 0x00, 0x01, 0xff, 0xc3, 0x66, 0x00, 0x00, 0x00,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe6, 0x00, 0x00, 0x01, 0xff, 0xe0, 0x78, 0x00, 0x00, 0x00,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0x00, 0x00, 0x01, 0xff, 0xc4, 0x7c, 0x00, 0x00, 0x00,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x01, 0xff, 0xce, 0x7f, 0x9c, 0x00, 0x00,
0xff, 0xfd, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x9e, 0x7f, 0xfc, 0x00, 0x00,
0xff, 0xfd, 0xff, 0xff, 0xff, 0xf8, 0x18, 0x80, 0x00, 0x00, 0x7f, 0x9f, 0xff, 0xfe, 0x00, 0x00,
0xff, 0xfd, 0xff, 0xff, 0xff, 0xf0, 0x78, 0x00, 0x00, 0x00, 0x7f, 0x0f, 0xff, 0xfc, 0x00, 0x00,
0xff, 0xfd, 0xff, 0xff, 0xff, 0xf1, 0xf8, 0x00, 0x00, 0x00, 0x7f, 0x07, 0x3f, 0xf8, 0x00, 0x00,
0xff, 0xfd, 0xff, 0xf8, 0x3f, 0xf3, 0x80, 0x40, 0x00, 0x00, 0x3f, 0x06, 0x3f, 0xf8, 0x00, 0x00,
0xff, 0xfd, 0xef, 0xc0, 0x1f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x00, 0xff, 0xf0, 0x00, 0x00,
0xff, 0xf9, 0xe0, 0xfc, 0x1f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x9b, 0x7f, 0xe0, 0x00, 0x00,
0xff, 0xf9, 0xe3, 0xff, 0xdf, 0xf8, 0x80, 0x20, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xe0, 0x00, 0x00,
0xef, 0xf3, 0xe7, 0xff, 0xff, 0xf1, 0x80, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xc0, 0x00, 0x00,
0x8f, 0xe3, 0xef, 0xf0, 0x67, 0xf8, 0x04, 0x10, 0x00, 0x00, 0x3f, 0xff, 0xff, 0x00, 0x00, 0x00,
0x87, 0xe2, 0xcf, 0xc0, 0x17, 0xff, 0xf6, 0x00, 0x00, 0x00, 0xb8, 0x03, 0x3f, 0x00, 0x00, 0x00,
0x83, 0xc2, 0xcf, 0x02, 0x1f, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x70, 0x00, 0x3e, 0x00, 0x00, 0x00,
0x03, 0xc2, 0xee, 0x00, 0x3f, 0xff, 0xff, 0x00, 0x00, 0x03, 0xf0, 0x00, 0x3e, 0x00, 0x00, 0x00,
0x03, 0x82, 0xec, 0x01, 0xff, 0xff, 0xff, 0x00, 0x00, 0x01, 0xf8, 0x00, 0x3e, 0x00, 0x00, 0x00,
0x03, 0x84, 0xff, 0x0f, 0xff, 0xff, 0xff, 0x00, 0x00, 0x01, 0xf9, 0xf8, 0xfe, 0x00, 0x00, 0x00,
0x03, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x01, 0xf7, 0xff, 0xfe, 0x00, 0x00, 0x00,
0x03, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x01, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00,
0x06, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x01, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00,
0x06, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00,
0x04, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00,
0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80,
0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80,
0x00, 0x00, 0x7f, 0xff, 0xff, 0x1d, 0xff, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80,
0x08, 0x00, 0xff, 0xff, 0xff, 0x9f, 0xff, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80,
0x84, 0x08, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00,
0xc4, 0x08, 0xff, 0xff, 0xff, 0xff, 0xef, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00,
0xc6, 0xce, 0xff, 0xff, 0xff, 0xff, 0x86, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x40, 0x00,
0xc6, 0xcc, 0x7f, 0xff, 0xff, 0xff, 0x86, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xf0, 0x18, 0x20, 0x00,
0xc7, 0xc4, 0x3f, 0xff, 0xff, 0xfc, 0x02, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00,
0xc7, 0xce, 0x3f, 0xff, 0xff, 0xc3, 0x06, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00,
0xc3, 0xc6, 0x1f, 0xff, 0xff, 0x00, 0x06, 0x01, 0xff, 0xff, 0xff, 0xff, 0xe6, 0x00, 0x00, 0x00,
0xc3, 0xc7, 0x1f, 0xff, 0xf8, 0x00, 0x06, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00,
0xc1, 0xe3, 0x0f, 0xff, 0xf0, 0x00, 0x07, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00,
0xc3, 0xe1, 0x8f, 0xff, 0xf0, 0x00, 0x07, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00,
0xc1, 0xe1, 0x87, 0xff, 0xf0, 0x0c, 0x06, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00,
0x81, 0xe0, 0x47, 0xff, 0xf0, 0x7e, 0x0e, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00,
0x80, 0xe0, 0x27, 0xff, 0xf3, 0xff, 0x0f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00,
0x00, 0xe0, 0x31, 0xff, 0xf3, 0xff, 0xcf, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00,
0xc0, 0xc0, 0x18, 0xff, 0xf3, 0xff, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00,
0xc0, 0xc0, 0x0c, 0xff, 0xf9, 0xff, 0xe5, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00,
0xc1, 0x80, 0x04, 0x7f, 0xff, 0xff, 0xf5, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00,
0x83, 0x80, 0x03, 0x0f, 0xff, 0xfe, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00,
0x07, 0x80, 0x00, 0xcf, 0xff, 0xe1, 0xe7, 0xff, 0xff, 0xc3, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00,
0x1f, 0x80, 0xe0, 0x00, 0xff, 0xff, 0xef, 0xff, 0xfc, 0x01, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00,
0x7f, 0x8f, 0xe0, 0x02, 0x7f, 0xff, 0xdf, 0xff, 0xf8, 0x01, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00,
0xff, 0xff, 0xc0, 0x00, 0x7d, 0xa3, 0xff, 0xff, 0xf8, 0x00, 0x7f, 0x80, 0x00, 0x00, 0x00, 0x00,
0xff, 0xff, 0xe0, 0x00, 0x7c, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x7f, 0x80, 0x00, 0x00, 0x00, 0x00,
	}
    oled_write_raw_P(w, sizeof(w));
}

static void render_status(void) {
    uint8_t led_usb_state = host_keyboard_leds();
    if (IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK)) {
        if (IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK)) {
            render_woman_full();
	} else {
            render_woman_numlk();
	}
    }
    return
    // QMK Logo and version information
    render_qmk_logo();
    oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _AZERTY:
            oled_write_P(PSTR("Stedounet\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        case _ALGR:
            oled_write_P(PSTR("Algr\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_kyria_logo();
    }
}
#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}
#endif


