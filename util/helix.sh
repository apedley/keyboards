#!/usr/bin/bash

KB=helixrp2040
KM=pointing
BIN="${KB//\//_}_${KM}.uf2"

cd $(qmk env QMK_HOME)
QMK=$(pwd)
LOG=$QMK/keyboards/$KB/keymaps/$KM/compile.log
KEYMAP_DIR=$QMK/keyboards/$KB/keymaps/$KM

echo -n "" >$LOG

keymapviz -k helix $KEYMAP_DIR/keymap.c -o $QMK_HOME/$KB-$KM.txt -c $XDG_CONFIG_HOME/keymapviz.conf

# qmk compile -kb $KB -km $KM || exit

# echo Flashing first half ...
# qmk flash $BIN

# read -p "Press enter to continue"

# printf "\n \n" >>$LOG

# echo Flashing second half ...
# qmk flash $BIN

# for SIDE in LEFT RIGHT; do
#   cat << EOF
#   echo Compiling $SIDE ...

#   qmk compile -kb $KB -km $KM -c -e FP_SPLIT_$SIDE=yes 2>>$LOG || exit

#   cp $BIN /mnt/c/Users/apedl/Desktop/$SIDE-$BIN
#   rm $BIN

#   if [ $SIDE = LEFT ]; then
#     printf "\n-----------------------\n\n" >>$LOG
#   fi

# EOF
# done
