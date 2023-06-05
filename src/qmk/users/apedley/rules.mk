SRC += apedley.c
SRC += qmk_rc.c

ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
	SRC += rgb_matrix_user.c
endif

SRC += features/select_word.c

LEADER_ENABLE = yes
SRC += features/leader.c

COMBO_ENABLE = yes
SRC += features/combo.c

ifneq ("$(wildcard $(USER_PATH)/secrets.c)","")
	SRC += secrets.c
endif

ifeq ($(strip $(FLASH_BOOTLOADER)), yes)
    OPT_DEFS += -DFLASH_BOOTLOADER
endif

ifeq ($(strip $(OLED_ENABLE)), yes)
	SRC += oled.c
endif

EXTRAKEY_ENABLE = yes
DEFERRED_EXEC_ENABLE = yes
CAPS_WORD_ENABLE = yes
