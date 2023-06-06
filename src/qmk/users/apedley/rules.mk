SRC += apedley.c
SRC += qmk_rc.c

ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
	SRC += rgb_matrix_user.c
endif

SRC += features/select_word.c

COMBO_ENABLE = yes
ifeq ($(strip $(COMBO_ENABLE)), yes)
		INTROSPECTION_KEYMAP_C = combos.c
endif

LEADER_ENABLE = yes
SRC += features/leader.c

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
