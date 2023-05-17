#include QMK_KEYBOARD_H

#include "leader.h"
#include "apedley.h"
#include "print.h"
leader_t leader = {.isLeading = false, .timedOut = false};

__attribute__((weak))
bool process_leader_dictionary_secret() {
    return true;
}

void leader_start_user() {
    leader.isLeading = true;
    leader.timedOut = false;
    leader.success = false;
#ifdef COMBO_ENABLE
    combo_disable();
#endif
}

void leader_end_user() {
    leader.isLeading = false;
    process_leader_dictionary();
#ifdef COMBO_ENABLE
    combo_enable();
#endif
}

void process_leader_dictionary(void) {

    if (leader_sequence_two_keys(KC_BSPC, KC_BSPC)) {
        /*  Backward delete current word (on cursor) */
        SEND_STRING(SS_LCTL(SS_TAP(X_RGHT)) SS_LCTL(SS_LSFT(SS_TAP(X_LEFT))) SS_TAP(X_BSPC));
    } else if (leader_sequence_one_key(KC_BSPC)) {
        /*  Previous word delete */
        SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_LEFT))) SS_TAP(X_BSPC));
    } else if (leader_sequence_two_keys(KC_BSLS, KC_BSLS)) {
        /*  Forward delete current word (on cursor) */
        SEND_STRING(SS_LCTL(SS_TAP(X_LEFT)) SS_LCTL(SS_LSFT(SS_TAP(X_RGHT))) SS_TAP(X_DEL));
    } else if (leader_sequence_one_key(KC_BSLS)) {
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
    } else if (leader_sequence_one_key(KC_S)) {
        // Leader, s => sudo systemctl
        SEND_STRING("sudo systemctl ");
    } else if (leader_sequence_two_keys(KC_D, KC_C)) {
        // Leader, d, c => docker compose
        SEND_STRING("docker compose ");
    } else if (leader_sequence_two_keys(KC_D, KC_U)) {
        // Leader, d, u => docker compose up -d
        SEND_STRING("docker compose up -d");
    } else if (leader_sequence_two_keys(KC_Q, KC_H)) {
        // Leader, q, h => export QMK_HOME=`pwd`
        SEND_STRING("export QMK_HOME=`pwd`");
    } else if (leader_sequence_two_keys(KC_I, KC_P)) {
        // Leader, i, p => 10.0.0.
        SEND_STRING("10.0.0.");
    } else if (process_leader_dictionary_secret() && leader_sequence_timed_out()) {
        leader.timedOut = true;
        leader.timedOutTimer = timer_read();
        return;
    }

    leader.success = true;
    leader.successTimer = timer_read();



}
