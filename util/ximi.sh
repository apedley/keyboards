#!/usr/bin/env bash


make fingerpunch/ximi:apedley FP_CIRQUE_LEFT_ONLY=yes RGB_MATRIX_ENABLE=yes ENCODER_ENABLE=yes AUDIO_ENABLE=yes HAPTIC_ENABLE=yes FP_SPLIT_LEFT=yes 
mv fingerpunch_ximi_apedley.uf2 fingerpunch_ximi_apedley_left.uf2

make fingerpunch/ximi:apedley FP_CIRQUE_LEFT_ONLY=yes RGB_MATRIX_ENABLE=yes ENCODER_ENABLE=yes AUDIO_ENABLE=yes HAPTIC_ENABLE=yes FP_SPLIT_RIGHT=yes 
mv fingerpunch_ximi_apedley.uf2 fingerpunch_ximi_apedley_right.uf2

qmk flash fingerpunch_ximi_apedley_left.uf2

qmk flash fingerpunch_ximi_apedley_right.uf2



