#include QMK_KEYBOARD_H

#include "leader.h"
#include "apedley.h"
#include "print.h"
leader_t leader = {.isLeading = false, .timedOut = false};

__attribute__((weak)) bool process_leader_dictionary_secret() { return true; }

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

/* (|) */
void ldrkey_send_paranthesis_wrap_ini(void) {
  SEND_STRING("()" SS_TAP(X_LEFT));
}

/* (X) */
void ldrkey_send_paranthesis_wrap_word(void) {
  SEND_STRING(SS_LCTL(SS_TAP(X_LEFT)) "(" SS_LCTL(SS_TAP(X_RIGHT)) ")");
}

/* (selection) */
void ldrkey_send_paranthesis_wrap_selection(void) {
  SEND_STRING(SS_LCTL(SS_TAP(X_X)) "()" SS_TAP(X_LEFT) SS_LCTL(SS_TAP(X_V))
                  SS_TAP(X_RIGHT));
}

/* [|] */
void ldrkey_send_bracket_wrap_ini(void) { SEND_STRING("[]" SS_TAP(X_LEFT)); }

/* [X] */
void ldrkey_send_bracket_wrap_word(void) {
  SEND_STRING(SS_LCTL(SS_TAP(X_LEFT)) "[" SS_LCTL(SS_TAP(X_RIGHT)) "]");
}

/* [selection] */
void ldrkey_send_bracket_wrap_selection(void) {
  SEND_STRING(SS_LCTL(SS_TAP(X_X)) "[]" SS_TAP(X_LEFT) SS_LCTL(SS_TAP(X_V))
                  SS_TAP(X_RIGHT));
}

/* {|} */
void ldrkey_send_curlybrace_wrap_ini(void) { SEND_STRING("{}" SS_TAP(X_LEFT)); }

/* {X} */
void ldrkey_send_curlybrace_wrap_word(void) {
  SEND_STRING(SS_LCTL(SS_TAP(X_LEFT)) "{" SS_LCTL(SS_TAP(X_RIGHT)) "}");
}

/* {selection} */
void ldrkey_send_curlybrace_wrap_selection(void) {
  SEND_STRING(SS_LCTL(SS_TAP(X_X)) "{}" SS_TAP(X_LEFT) SS_LCTL(SS_TAP(X_V))
                  SS_TAP(X_RIGHT));
}

void process_leader_dictionary(void) {

  /*
      Delete Text
  */
  if (leader_sequence_two_keys(KC_BSPC, KC_BSPC)) {
    /*  Backward delete current word (on cursor) */
    SEND_STRING(SS_LCTL(SS_TAP(X_RGHT)) SS_LCTL(SS_LSFT(SS_TAP(X_LEFT)))
                    SS_TAP(X_BSPC));
  } else if (leader_sequence_one_key(KC_BSPC)) {
    /*  Previous word delete */
    SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_LEFT))) SS_TAP(X_BSPC));
  } else if (leader_sequence_two_keys(KC_BSLS, KC_BSLS)) {
    /*  Forward delete current word (on cursor) */
    SEND_STRING(SS_LCTL(SS_TAP(X_LEFT)) SS_LCTL(SS_LSFT(SS_TAP(X_RGHT)))
                    SS_TAP(X_DEL));
  } else if (leader_sequence_one_key(KC_BSLS)) {
    /*  Next word delete */
    SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_RGHT))) SS_TAP(X_DEL));
    /*
        Select Text
    */
  } else if (leader_sequence_one_key(KC_LEFT) ||
             leader_sequence_one_key(KC_A)) {
    // Leader, left =>  Select everything on this line before cursor
    SEND_STRING(SS_LSFT(SS_TAP(X_HOME)));
  } else if (leader_sequence_two_keys(KC_LEFT, KC_LEFT) ||
             leader_sequence_two_keys(KC_A, KC_A)) {
    // Leader, left, left =>  Select everything on this line before cursor up to
    // end of previous line
    SEND_STRING(SS_LSFT(SS_TAP(X_UP) SS_TAP(X_END)));
  } else if (leader_sequence_one_key(KC_RIGHT) ||
             leader_sequence_one_key(KC_D)) {
    // Leader, right =>  Select everything on this line after cursor
    SEND_STRING(SS_LSFT(SS_TAP(X_END)));
  } else if (leader_sequence_two_keys(KC_RIGHT, KC_LEFT) ||
             leader_sequence_two_keys(KC_D, KC_A)) {
    // Leader, right, left => Select everything on this line
    SEND_STRING(SS_TAP(X_END) SS_LSFT(SS_TAP(X_HOME)));
  } else if (leader_sequence_two_keys(KC_UP, KC_UP) ||
             leader_sequence_two_keys(KC_W, KC_W)) {
    // Leader, up, up => Select everything on the page before the cursor
    SEND_STRING(SS_LSFT(SS_LCTL(SS_TAP(X_HOME))));
  } else if (leader_sequence_two_keys(KC_DOWN, KC_DOWN) ||
             leader_sequence_two_keys(KC_S, KC_S)) {
    // Leader, down, down => Select everything on the page after the cursor
    SEND_STRING(SS_LSFT(SS_LCTL(SS_TAP(X_END))));
    /*
        Space Cadet Like Macros
    */

  } else if (leader_sequence_one_key(KC_QUOT)) {
    // Leader, ' => Will wrap word on cursor between two single quotes
    SEND_STRING(SS_LCTL(SS_TAP(X_LEFT)) "'" SS_LCTL(SS_TAP(X_RIGHT)) "'");
  } else if (leader_sequence_two_keys(KC_QUOT, KC_QUOT)) {
    // Leader, ', ' => Will wrap word on cursor between two double quotes
    SEND_STRING(SS_LCTL(SS_TAP(X_LEFT)) "\"" SS_LCTL(SS_TAP(X_RIGHT)) "\"");
  } else if (leader_sequence_one_key(KC_LGUI)) {
    // Leader, LGUI => Will wrap word on cursor between two parenthesis
    ldrkey_send_paranthesis_wrap_word();
  } else if (leader_sequence_two_keys(KC_LGUI, KC_LGUI)) {
    // Leader, LGUI, LGUI => Will wrap selection between two parenthesis
    ldrkey_send_paranthesis_wrap_selection();
  } else if (leader_sequence_one_key(KC_LCTL)) {
    // Leader, LCTL => Will wrap word on cursor between two curly braces
    ldrkey_send_curlybrace_wrap_word();
  } else if (leader_sequence_two_keys(KC_LCTL, KC_LCTL)) {
    // Leader, LCTL, LCTL => Will wrap selection between two curly braces
    ldrkey_send_curlybrace_wrap_selection();
  } else if (leader_sequence_one_key(KC_LALT)) {
    // Leader, LALT => Will wrap word on cursor between two brackets
    ldrkey_send_bracket_wrap_word();
  } else if (leader_sequence_two_keys(KC_LALT, KC_LALT)) {
    // Leader, LALT, LALT => Will wrap selection between two brackets
    ldrkey_send_bracket_wrap_selection();

    /*
        Misc
    */
  } else if (leader_sequence_one_key(KC_LSFT)) {
    // Leader, shift =>  caps word on
    caps_word_on();
  } else if (leader_sequence_two_keys(KC_LSFT, KC_LSFT)) {
    // Leader, shift, shift =>  caps lock
    SEND_STRING(SS_TAP(X_CAPS));
  } else if (leader_sequence_one_key(KC_SPC)) {
    // Leader, space =>  shift space
    SEND_STRING(SS_LSFT(SS_TAP(X_SPC)));
  } else if (leader_sequence_one_key(KC_W)) {
    // Leader, W =>  OS: Close current file/tab
    SEND_STRING(SS_LCTL(SS_TAP(X_W)));
  } else if (leader_sequence_one_key(KC_Q)) {
    // Leader, Q =>  OS: Close current application
    SEND_STRING(SS_LALT(SS_TAP(X_F4)));
  } else if (leader_sequence_one_key(KC_T)) {
    // Leader, T =>  Ctrl T
    SEND_STRING(SS_LCTL(SS_TAP(X_T)));
  } else if (leader_sequence_two_keys(KC_T, KC_T)) {
    // Leader, T, T =>  Ctrl Shift T
    SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_T))));
  } else if (leader_sequence_two_keys(QK_LEAD, QK_LEAD)) {
    // Leader, Leader, Leader =>  Printscreen
    SEND_STRING(SS_TAP(X_PSCR));

    /*
        Text Expansion
    */
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
  } else if (leader_sequence_two_keys(KC_K, KC_SLSH)) {
    // Leader, K, / => QMK keycodes
    SEND_STRING("https://docs.qmk.fm/#/keycodes");
  } else if (process_leader_dictionary_secret() &&
             leader_sequence_timed_out()) {
    leader.timedOut = true;
    leader.timedOutTimer = timer_read();
    return;
  }

  leader.success = true;
  leader.successTimer = timer_read();
}
