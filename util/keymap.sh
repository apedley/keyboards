#!/usr/bin/env bash
KEYBOARD=ximi
KEYBOARD_DIR=/fingerpunch
KEYMAP=apedley
KEYMAP_DIR=$QMK_HOME/keyboards$KEYBOARD_DIR/$KEYBOARD/keymaps/$KEYMAP
KEYMAP_FILE=keymap.c
KEYMAP_TXT=km.txt
KEYMAP_PDF=km.pdf

# echo $KEYMAP_DIR/$KEYMAP_FILE
VIZ_CONFIG=$XDG_CONFIG_HOME/keymapviz.conf

# keymapviz -k $KEYBOARD $KEYMAP_DIR/$KEYMAP_FILE -c $VIZ_CONFIG -r

keymapviz -k $KEYBOARD $KEYMAP_DIR/$KEYMAP_FILE -c $VIZ_CONFIG -t fancy -o $KEYMAP_DIR/$KEYMAP_TXT
# paps -o $KEYMAP_DIR/km.pdf --landscape $KEYMAP_DIR/$KEYMAP_TXT

echo To replace the keymap in the comments, run:
echo "keymapviz -k ximi $KEYMAP_DIR/$KEYMAP_FILE -c $VIZ_CONFIG -r"

# echo "keymapviz -k $KEYBOARD $KEYMAP_DIR/$KEYMAP_FILE -c $VIZ_CONFIG -t json -o $KEYMAP_DIR/km.json"
