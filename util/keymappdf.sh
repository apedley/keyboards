#!/usr/bin/env bash

keymapviz -k ximi keyboards/fingerpunch/ximi/keymaps/apedley/keymap.c -c ~/.config/keymapviz.conf -t fancy | paps -o km.pdf --landscape

