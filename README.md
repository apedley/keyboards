# Keyboards


## Compile and Flash

***TODO: Add scripts for this***

### Keychron K6 Pro
```sh
cd keychron-qmk
qmk compile -kb keychron/k6_pro/ansi/rgb -km apedley
qmk flash keychron_k6_pro_ansi_rgb_apedley.bin
```

All at once:

```bash
cd keychron-qmk
qmk flash -kb keychron/k6_pro/ansi/rgb -km apedley
```

### Inland MK47

```sh
cd qmk_mk47
qmk compile -kb inland/mk47 -km apedley
qmk flash qmk_mk47/inland_mk47_apedley.bin
```
All at once:

```bash
cd qmk_mk47
qmk flash -kb qmk_mk47/mk47 -km apedley
```

## Structure

This repository links together my keyboard layouts with their appropriate firmware. The user files and keymaps are both symlinked into the qmk folder where they would normally be. For example:

```bash
ln -s ../../../../../../../src/qmk/keyboards/keychron/k6_pro/ansi/rgb/keymaps/apedley ./keychron-qmk/keyboards/keychron/k6_pro/ansi/rgb/keymaps/apedley
ln -s ../../src/qmk/users/apedley ./keychron-qmk/users/apedley
```

