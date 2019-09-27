QMK_SRC_DIR=~/git/qmk_firmware
MYKEYMAP_DIR=~/git/ergodox-ez-keymap/keymap/
SCRIPTS_DIR=~/git/ergodox-ez-keymap/scripts

docker run --rm \
-v ${QMK_SRC_DIR}:/qmk:rw \
-v ${MYKEYMAP_DIR}:/keymap:rw \
-v ${SCRIPTS_DIR}:/scripts:rw \
buildkeyboard

cp ${QMK_SRC_DIR}/*.hex ${MYKEYMAP_DIR}/../
