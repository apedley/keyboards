# My Keymap

## Macros

| Binding | Keycode | Output | Description
| :--- | :--- | :--- | :--- |
| Fn1+Q | `UPDIR` | `../` | n/a |
| Fn1+E | `SELWORD` | Selects word under cursor | Keep tapping to select more |
| Fn1+R | `SELLINE` | Selects the line under cursor | n/a |
| Fn1+F | `BRACES` | Normal/Shift/Ctrl: `[] {} ()` | n/a |

## Leader

The leader key is set to the upper right button.

### Delete Text

| Sequence | Output | Notes
| :--- | :--- | :--- |
| `LDR BKSP` | Backwards delete rest of characters in word on cursor | n/a |
| `LDR \` | Forward delete rest of characters in word on cursor | n/a |
| `LDR BKSP BKSP` | Backward Delete whole word on cursor | n/a |
| `LDR \ \` | Forward Delete whole word on cursor | n/a |

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
