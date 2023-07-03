#!/usr/bin/env bash
source ximi.sh
KEYBOARD=ximi
KEYMAP_DIR=$QMK_HOME/keyboards/fingerpunch/ximi/keymaps/apedley
KEYMAP_FILE=keymap.c
KEYMAP_TXT=km.txt
KEYMAP_PDF=km.pdf

VIZ_CONFIG=$XDG_CONFIG_HOME/keymapviz.conf


keymapviz -k $KEYBOARD $KEYMAP_DIR/$KEYMAP_FILE -c $VIZ_CONFIG -t fancy -o $KEYMAP_DIR/km.txt
paps -o $KEYMAP_DIR/km.pdf --landscape $KEYMAP_DIR/km.txt
# keymapviz -k ximi keyboards/fingerpunch/ximi/keymaps/apedley/keymap.c -c ~/.config/keymapviz.conf -t fancy | paps -o km.pdf --landscape

