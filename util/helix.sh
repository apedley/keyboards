#!/usr/bin/bash

# Utility script to compile both halves at once
SPLIT_UF=true

KB=helixrp2040
KM=pointing
BIN="${KB//\//_}_${KM}.uf2"

cd $(qmk env QMK_HOME)
QMK=$(pwd)
KEYMAP_DIR=$QMK/keyboards/$KB/keymaps/$KM
KEYMAP_FILE=keymap.c

LOG=$KEYMAP_DIR/compile.log

# echo $KEYMAP_DIR/$KEYMAP_FILE
VIZ_CONFIG=$XDG_CONFIG_HOME/keymapviz.conf

echo -n "" >$LOG

keymapviz -k helix $KEYMAP_DIR/$KEYMAP_FILE -c $VIZ_CONFIG -t fancy -o $KEYMAP_DIR/km.txt
paps -o $KEYMAP_DIR/km.pdf --landscape $KEYMAP_DIR/km.txt

# if [ -z $SPLIT_UF ]; then
  for SIDE in LEFT RIGHT; do
    # cat << EOF
    SIDE_BIN="${KB//\//_}_${KM}_${SIDE}.uf2"
    echo Compiling $SIDE ...
    qmk compile -kb $KB -km $KM -c 2>>$LOG || exit
    cp $BIN $SIDE_BIN
    rm $BIN
    qmk flash $SIDE_BIN

    if [ $SIDE = LEFT ]; then
      printf "\n-----------------------\n\n" >>$LOG
      read -p "Press enter to continue"
    fi
  done
# # EOF
# else
#   echo Compiling ....
#   qmk compile -kb $KB -km $KM -j 8 -c 2>>$LOG || exit
#   qmk flash $BIN
#   read -p "Press enter to continue"
#   qmk flash $BIN
# fi


# KB=helixrp2040
# KM=pointing
# BIN="${KB//\//_}_${KM}.uf2"

# cd $(qmk env QMK_HOME)
# QMK=$(pwd)
# LOG=$QMK/keyboards/$KB/keymaps/$KM/compile.log
# KEYMAP_DIR=$QMK/keyboards/$KB/keymaps/$KM

# echo -n "" >$LOG

# keymapviz -k helix $KEYMAP_DIR/keymap.c -o $QMK_HOME/$KB-$KM.txt -c $XDG_CONFIG_HOME/keymapviz.conf

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
