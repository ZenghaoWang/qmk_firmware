# ComboGen

A simple python script for generation combo definitions with significantly less boilerplate.

## Background

This was inspired by the enhanced combos from Gboard, seen [here](http://combos.gboards.ca/).

I tried using it after merging [#8751](https://github.com/qmk/qmk_firmware/pull/8591) into my repository, but I couldn't get it to compile, and it hasn't been updated in a year anyways.

Anyways, the reason this script exists is because defining combos in QMK is a pain in the ass. First you have to add members to an enum, then you have to declare the uint16_t variables, then you have to use the index to enum into the key_combos array, and call the COMB macro. 
In short, you need to maintain a combo in 3 different places, 4 if you use ``process_combo_event()`` for more complex combos.

With this script, you will only need to define and modify your combos in one location, saving you a ton of time and boilerplate writing.
For example, this single line defines a combo which activates capslock when A and O are pressed at the same time:
```c
AO_CAPSLOCK, A_O_COMBO, true, KC_CAPS, NULL, NULL, HOME_A, HOME_O;
```

By comparison, here is what you would need to write in vanilla qmk:
```c
enum combo_events {
	AO_CAPSLOCK,
	COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM A_O_COMBO[] = {HOME_A, HOME_O, COMBO_END};

combo_t key_combos[] = {
	[AO_CAPSLOCK] = COMBO(A_O_COMBO, KC_CAPS),
};
```

## Get Started

1. Merge [#8751](https://github.com/qmk/qmk_firmware/pull/8591) into your repo.
2. Add ``COMBO_ENABLE = yes`` into your ``rules.mk``.
3. Add ``SRC += combos.c``
4. Create a file to put your combo definitions into. You can call it whatever you want, I called mine ``combos.def``, stolen from gboards.
5. Define combos like this:
```c
// name, trigger name, simple? res, shift res, ctrl res, trigger keys...
WF_Q, W_F_COMBO, false, "q", "Q", SS_LCTL("q"), KC_W, LT_F_WINDOW;
CK_Z, C_K_COMBO, false, "z", "Z", SS_LCTL("z"), KC_X, KC_C;
AO_CAPSLOCK, A_O_COMBO, true, KC_CAPS, NULL, NULL, HOME_A, HOME_O;
```
Each line is a combo definition. If simple = true, then shift res and ctrl res must be NULL and result must be a basic keycode.

If simple = false, then res can be any string that can be fed into SEND_STRING, and the shift and ctrl variants can be filled in to determine what happens when the combo is activated in conjunction with those mod keys.
6. Run the script:
```bash
python3 ComboGen.py -o path/to/definitions -i path/to/combos.c
```
You can then check ``combos.c`` to see the generated boilerplate.

7. Optionally, if you want this script to run every time you compile your keymap, add the following to your ``rules.mk``:
```makefile
.PHONY: %
%:
    python3 ComboGen.py -o path/to/definitions -i path/to/combos.c
```

A working example can be found on my qmk fork [here](https://github.com/ZenghaoWang/qmk_firmware/tree/dev_zenghao/users/ZenghaoWang).

