#include QMK_KEYBOARD_H

#include "leader.h"
#include "apedley.h"
leader_t leader = {.isLeading = false, .timedOut = false};

void leader_start_user() {
    leader.isLeading = true;
}

void leader_end_user() {
    leader.isLeading = false;
    process_leader_dictionary();
}

void process_leader_dictionary(void) {
    if (leader_sequence_two_keys(KC_BSPC, KC_BSPC)) {
        /*  Backward delete current word (on cursor) */
        SEND_STRING(SS_LCTL(SS_TAP(X_RGHT)) SS_LCTL(SS_LSFT(SS_TAP(X_LEFT))) SS_TAP(X_BSPC));
    } else if (leader_sequence_one_key(KC_BSPC)) {
        /*  Previous word delete */
        SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_LEFT))) SS_TAP(X_BSPC));
    } else if (leader_sequence_two_keys(KC_DEL, KC_DEL)) {
        /*  Forward delete current word (on cursor) */
        SEND_STRING(SS_LCTL(SS_TAP(X_LEFT)) SS_LCTL(SS_LSFT(SS_TAP(X_RGHT))) SS_TAP(X_DEL));
    } else if (leader_sequence_one_key(KC_DEL)) {
        /*  Next word delete */
        SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_RGHT))) SS_TAP(X_DEL));
    } else if (leader_sequence_one_key(KC_LSFT)) {
        // Leader, shift =>  caps word on
        caps_word_on();
    } else if (leader_sequence_three_keys(QK_GESC, QK_GESC, QK_GESC)) {
        // Leader, esc esc esc => code block
        // SEND_STRING("```" SS_TAP(X_ENT) "```" SS_TAP(X_UP) SS_TAP(X_ENT));
        SEND_STRING("```" SS_TAP(X_ENT) "```" SS_TAP(X_UP));
    } else if (leader_sequence_one_key(QK_GESC)) {
        // Leader, esc =>  `
        SEND_STRING(SS_TAP(X_GRV));
    } else if (leader_sequence_two_keys(KC_G, KC_A)) {
        // Leader, g, a => git add and commit
        SEND_STRING("git add . && git commit -m \"\"" SS_TAP(X_LEFT));
    } else if (leader_sequence_two_keys(KC_G, KC_C)) {
        // Leader, g, c => git commit
        SEND_STRING("git commit -m \"\"" SS_TAP(X_LEFT));
    // } else if (leader_sequence_one_key(KC_PGUP)) {
    //     // Leader, pgup => home
    //     // SEND_STRING(SS_TAP(X_HOME));     MAC
    //     SEND_STRING(SS_LCTL(SS_TAP(X_HOME)));
    // } else if (leader_sequence_one_key(KC_PGDN)) {
    //     // Leader, pgdn => end
    //     SEND_STRING(SS_LCTL(SS_TAP(X_END))); // SEND_STRING(SS_TAP(X_END));   MAC
    } else if(leader_sequence_timed_out()) {
        leader.timedOut = true;
        leader.timedOutTimer = timer_read();
    }

    process_leader_dictionary_secret();
}
