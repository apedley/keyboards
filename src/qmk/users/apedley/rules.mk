SRC += apedley.c
SRC += qmk_rc.c
SRC += rgb.c
SRC += features/select_word.c
SRC += features/leader.c
# SRC += features/tapdance.c
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
LEADER_ENABLE = yes
CAPS_WORD_ENABLE = yes

COMBO_ENABLE = yes

TAP_DANCE_ENABLE = no


