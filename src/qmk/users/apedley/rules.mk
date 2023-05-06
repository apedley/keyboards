SRC += apedley.c
SRC += qmk_rc.c
SRC += rgb.c
SRC += features/select_word.c
SRC += features/leader.c

ifneq ("$(wildcard $(USER_PATH)/secrets.c)","")
    SRC += secrets.c
endif

ifeq ($(strip $(FLASH_BOOTLOADER)), yes)
    OPT_DEFS += -DFLASH_BOOTLOADER
endif


DEFERRED_EXEC_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes
LEADER_ENABLE = yes
COMBO_ENABLE = no
CAPS_WORD_ENABLE = yes
RAW_ENABLE = yes
CONSOLE_ENABLE = yes
