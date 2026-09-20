// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include <stdio.h>

//SINGLE KEY FUNCTIONS
enum custom_keycodes {
    KC_CLAUDE = SAFE_RANGE /*Claude Shortcut, needs to be set in apple shortcuts*/,
    KC_FOCUS /*Focus Shortcut, ´´ */,
    KC_LIGHT /* Switch on/off smart lights ´´*/,
    KC_AMUTE /* Mute Audio */,
    KC_CLOCKMODE
};

// Brining the one rotary without the b pin connected in
#define ENCODER2_PIN GP3

static bool encoder2_last = true;
static uint16_t encoder2_last_fire = 0;
static bool clocksetting_mode = false;
static uint16_t clockminutes = 0;
static uint32_t clock_last_tick = 0;


void keyboard_post_init_user(void) {
    gpio_set_pin_input_high(ENCODER2_PIN);
    encoder2_last = gpio_read_pin(ENCODER2_PIN);
}

enum {
    TD_LOCK, // Display Lock/ Shutdown Menu
    TD_AUDIO, // Audio Control
    TD_CAMERA // Screenshots/ Screen Recording
};

void audio_finished(tap_dance_state_t *state, void *user_data);
void audio_reset(tap_dance_state_t *state, void *user_data);
void camera_finished(tap_dance_state_t *state, void *user_data);
void camera_reset(tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
    KC_AMUTE,  KC_FOCUS,  TD(TD_AUDIO),  KC_LIGHT, // row 0: col 0, 1, 2, 3
    KC_CLOCKMODE,  TD(TD_LOCK),  KC_CLAUDE, TD(TD_CAMERA) // row 1: col 0, 1, 2, 3
)
};

//TAP_DANCE
tap_dance_action_t tap_dance_actions[] = {
    [TD_LOCK]  = ACTION_TAP_DANCE_DOUBLE(LCTL(LGUI(KC_Q)), LCTL(KC_PWR)),
    [TD_AUDIO] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, audio_finished, audio_reset),
    [TD_CAMERA] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, camera_finished, camera_reset)
};

void audio_finished(tap_dance_state_t *state, void *user_data) { //Tought it was nicer to have a keep pressed function so one would not have to triple press a key. 
    if (state->pressed == true) {
        tap_code(KC_MNXT);
    } else if (state->count == 1) {
        tap_code(KC_MPLY);
    } else if (state->count == 2) {
        tap_code(KC_MPRV);
    }
}

void audio_reset(tap_dance_state_t *state, void *user_data) {
}

void camera_finished(tap_dance_state_t *state, void *user_data) {
    if (state->pressed == true) {
        tap_code16(LSFT(LGUI(KC_5)));
    }
    else if (state->count == 1) {
        tap_code16(LSFT(LGUI(KC_4)));
    }
}

void camera_reset(tap_dance_state_t *state, void *user_data) {
}

//ROTARY ENCODER
bool encoder_update_user(uint8_t index, bool clockwise){
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return false;
}



bool process_record_user(uint16_t keycode, keyrecord_t *record){
    if (record->event.pressed) {
        switch (keycode) {
            case KC_CLAUDE:
                tap_code16(LGUI(LSFT(KC_C)));
                return false;
            case KC_FOCUS:
                tap_code16(LGUI(LSFT(KC_F)));
                return false;
            case KC_LIGHT:
                tap_code16(LGUI(LSFT(KC_L)));
                return false;
            case KC_AMUTE:
                tap_code16(KC_MUTE);
                return false;
            case KC_CLOCKMODE:
                clocksetting_mode = !clocksetting_mode;
                return false;
        }
    }
    return true;
}

// Rotary without b pin function
void matrix_scan_user(void) {
    bool current = gpio_read_pin(ENCODER2_PIN);
    if (encoder2_last && !current && timer_elapsed(encoder2_last_fire) > 50) {
        if (clocksetting_mode == true) {
            clockminutes++;
            if (clockminutes >= 1440) {
                clockminutes = 0;
            }
        } else {
            tap_code16(LCTL(LGUI(KC_F)));
        }
        encoder2_last_fire = timer_read();
    }
    if (timer_elapsed32(clock_last_tick) >= 60000) {
        clockminutes++;
        if (clockminutes >= 1440) {
            clockminutes = 0;
        }
        clock_last_tick = timer_read32();
    }
    encoder2_last = current;
}

//DISPLAY

bool oled_task_user(void) {
    char clock_buf[6];
    snprintf(clock_buf, sizeof(clock_buf), "%02d:%02d", (clockminutes / 60) % 24, clockminutes % 60);
    oled_write_ln(clock_buf, false);
    return false;
}