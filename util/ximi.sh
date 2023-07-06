#!/usr/bin/bash

# Utility script to compile both halves at once
SPLIT_UF=false

KB=fingerpunch/ximi
KM=apedley
BIN="${KB//\//_}_${KM}.uf2"

cd $(qmk env QMK_HOME)
QMK=$(pwd)
KEYMAP_DIR=$QMK/keyboards/$KB/keymaps/$KM
LOG=$KEYMAP_DIR/compile.log

echo -n "" >$LOG

if [ -z $SPLIT_UF ]; then
  for SIDE in LEFT RIGHT; do
    # cat << EOF
    SIDE_BIN="${KB//\//_}_${KM}_${SIDE}.uf2"
    echo Compiling $SIDE ...
    qmk compile -kb $KB -km $KM -c -e FP_SPLIT_$SIDE=yes 2>>$LOG || exit
    cp $BIN $SIDE_BIN
    rm $BIN
    qmk flash $SIDE_BIN

    if [ $SIDE = LEFT ]; then
      printf "\n-----------------------\n\n" >>$LOG
      read -p "Press enter to continue"
    fi
  done
# EOF
else
  echo Compiling ....
  qmk compile -kb $KB -km $KM -j 8 -e FP_CIRQUE_BOTH=yes -c 2>>$LOG || exit
  qmk flash $BIN
  read -p "Press enter to continue"
  qmk flash $BIN
fi


# clear


# make fingerpunch/ximi:apedley FP_CIRQUE_LEFT_ONLY=yes RGB_MATRIX_ENABLE=yes ENCODER_ENABLE=yes AUDIO_ENABLE=yes HAPTIC_ENABLE=yes FP_SPLIT_LEFT=yes
# mv fingerpunch_ximi_apedley.uf2 fingerpunch_ximi_apedley_left.uf2

# make fingerpunch/ximi:apedley FP_CIRQUE_LEFT_ONLY=yes RGB_MATRIX_ENABLE=yes ENCODER_ENABLE=yes AUDIO_ENABLE=yes HAPTIC_ENABLE=yes FP_SPLIT_RIGHT=yes
# mv fingerpunch_ximi_apedley.uf2 fingerpunch_ximi_apedley_right.uf2

# qmk flash fingerpunch_ximi_apedley_left.uf2

# qmk flash fingerpunch_ximi_apedley_right.uf2



