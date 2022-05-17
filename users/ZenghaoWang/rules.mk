# Automatically generate combos.c when compiling:
.PHONY: %
%:
	python3 users/ZenghaoWang/ComboGen.py -i users/ZenghaoWang/combos.def -o users/ZenghaoWang/combos.c

# debugging
CONSOLE_ENABLE = no
COMMAND_ENABLE = no

TAP_DANCE_ENABLE = yes
AUTO_SHIFT_ENABLE = yes
NKRO_ENABLE = yes
COMBO_ENABLE = yes
AUDIO_ENABLE = yes
AUTO_SHIFT_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes

NO_SECRETS = no

# space saving
RGBLIGHT_ENABLE = no
AUDIO_ENABLE = no

SRC += keycodes.c
SRC += tap_hold.c
SRC += layers.c
SRC += caps_word.c


ifeq ($(strip $(AUDIO_ENABLE)), yes)
  SRC += muse.c
endif

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
  SRC += tap_dance.c
endif

ifeq ($(strip $(COMBO_ENABLE)), yes)
  SRC += combos.c
endif

ifneq ($(strip $(NO_SECRETS)), yes)
    ifneq ("$(wildcard $(USER_PATH)/secrets.c)","")
        SRC += secrets.c
    endif
endif
EXTRAFLAGS        += -flto
