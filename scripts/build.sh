QMK_SRC_DIR=/qmk
QMK_KEYMAPS_DIR=${QMK_SRC_DIR}/keyboards/ergodox_ez/keymaps
MYKEYMAP_DIR=/keymap
MYKEYMAP_NAME=TribalNightOwl
KEYBOARD=ergodox_ez

rm -rf ${QMK_KEYMAPS_DIR}/${MYKEYMAP_NAME}
cp -r  ${MYKEYMAP_DIR} ${QMK_KEYMAPS_DIR}/${MYKEYMAP_NAME}

cd ${QMK_SRC_DIR}


make git-submodule
make ${KEYBOARD}:${MYKEYMAP_NAME}
