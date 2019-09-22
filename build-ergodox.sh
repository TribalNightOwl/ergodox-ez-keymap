QMK_SRC_DIR=~/git/qmk_firmware
QMK_KEYMAPS_DIR=${QMK_SRC_DIR}/keyboards/ergodox_ez/keymaps
MYKEYMAP_DIR=~/git/ergodox-ez-keymap
MYKEYMAP_NAME=TribalNightOwl

rm -rf ${QMK_KEYMAPS_DIR}/${MYKEYMAP_NAME}
cp -r  ${MYKEYMAP_DIR} ${QMK_KEYMAPS_DIR}/${MYKEYMAP_NAME}

cd ${QMK_SRC_DIR}
docker run -e keymap=${MYKEYMAP_NAME} -e keyboard=ergodox_ez --rm -v $('pwd'):/qmk:rw -u $(id -u):$(id -g) edasque/qmk_firmware
