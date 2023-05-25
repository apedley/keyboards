# Userspace Configuration

## Macros

| Binding | Keycode | Output | Description
| :--- | :--- | :--- | :--- |
| Fn1+Q | `UPDIR` | `../` | n/a |
| Fn1+E | `SELWORD` | Selects word under cursor | Keep tapping to select more |
| Fn1+R | `SELLINE` | Selects the line under cursor | n/a |
| Fn1+F | `BRACES` | Normal/Shift/Ctrl: `[] {} ()` | n/a |

## Leader

The leader key is set to the upper right button and also as a combo on `,` and `.`.

### Select Text

| Sequence | Output | Alternate Sequence
| :--- | :--- | :--- |
| `LDR LEFT-ARROW` | Select everything on this line before cursor | `LDR A` |
| `LDR LEFT-ARROW LEFT-ARROW` | Select everything on this line before cursor up to end of previous line | `LDR A A` |
| `LDR RIGHT-ARROW` | Select everything on this line after cursor | `LDR D` |
| `LDR RIGHT-ARROW LEFT-ARROW` | Select everything on this line | `LDR D A` |
| `LDR UP-ARROW  UP-ARROW` | Select everything on the page before the cursor | `LDR W W` |
| `LDR DOWN-ARROW  DOWN-ARROW` | Select everything on the page after the cursor | `LDR S S` |

### Delete Text

| Sequence | Output | Notes
| :--- | :--- | :--- |
| `LDR BKSP` | Backwards delete rest of characters in word on cursor | n/a |
| `LDR \` | Forward delete rest of characters in word on cursor | n/a |
| `LDR BKSP BKSP` | Backward Delete whole word on cursor | n/a |
| `LDR \ \` | Forward Delete whole word on cursor | n/a |

### Space Cadet Like Macros

| Sequence | Output | Notes
| :--- | :--- | :--- |
| `LDR '` | `'WORD'`¶ | Will wrap word on cursor 'between two single quotes |
| `LDR '  '` | `"WORD"`¶ | Will wrap word on cursor between two double quotes |
| `LDR GUI` | `(WORD)`¶ | Will wrap word on cursor between two parenthesis  |
| `LDR GUI GUI` | `(SELECTION)`¶ | Will wrap selection between two parenthesis  |
| `LDR CTRL` | `{WORD}`¶ | Will wrap word on cursor between two curly braces  |
| `LDR CTRL CTRL` | `{SELECTION}`¶ | Will wrap selection between two curly braces  |
| `LDR ALT` | `[WORD]`¶ | Will wrap word on cursor between two brackets  |
| `LDR ALT ALT` | `[SELECTION]`¶ | Will wrap selection between two brackets  |

### Text Expansion

| Sequence | Output | Notes
| :--- | :--- | :--- |
| `LDR ESC` | `` ` `` | n/a |
| `LDR  ESC  ESC  ESC` | ```` ``` ¶ \n ``` ```` | n/a |
| `LDR G A` | `git add . && git commit -m "¶"` | n/a |
| `LDR G C` | `git commit -m "¶"` | n/a |
| `LDR S` | `sudo systemctl ¶` | n/a |
| `LDR D C` | `docker compose ¶` | n/a |
| `LDR D U` | `docker compose up -d` | n/a |
| `LDR Q H` | ``export QMK_HOME=`pwd` `` | n/a |
| `LDR I P` | `10.0.0.¶` | n/a |
| `LDR K /` | [QMK Keycode List](https://docs.qmk.fm/#/keycodes) URL | n/a |

### Key Access and Misc

| Sequence | Output | Notes
| :--- | :--- | :--- |
| `LDR SHIFT` | Caps Word On | n/a |
| `LDR SHIFT SHIFT` | Caps Lock On | n/a |
| `LDR T` | Ctrl+T | n/a |
| `LDR T T` | Ctrl+Shift+Space | n/a |
| `LDR LDR LDR` | Printscreen | n/a |
| `LDR SPACE` | Shift+Space | n/a |
| `LDR W` | OS: Close current file/tab | n/a |
| `LDR Q` | OS: Close current application | n/a |

## Caps Word

Activated by double tapping shift.

## License

Copyright 2023 Andrew Pedley apedley@gmail.com @apedley

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
