#!/usr/bin/env bash

BRANCH=$(git rev-parse --abbrev-ref HEAD)
BASE_DIR="${HOME}/git"
QMK_BRANCH="TribalNightOwl-ergodox-ez"
QMK_SRC_DIR="${BASE_DIR}/qmk_firmware"
QMK_REPO="git@github.com:TribalNightOwl/qmk_firmware.git"
MYKEYMAP_NAME="TribalNightOwl"
MYKEYMAP_DIR="${BASE_DIR}/ergodox-ez-keymap/${BRANCH}/keymap/${MYKEYMAP_NAME}"

clone(){
    cd "${BASE_DIR}" || exit
    rm -rf "${QMK_SRC_DIR}"
    git clone --recurse-submodules "${QMK_REPO}"
    cd "${QMK_SRC_DIR}" || exit
    git checkout "${QMK_BRANCH}"
}

clean(){
    cd "${QMK_SRC_DIR}" || exit
    git clean -fd
    git checkout "${QMK_BRANCH}"
}

update(){
    cd "${QMK_SRC_DIR}" || exit
    rsync -av --delete "${MYKEYMAP_DIR}" "${QMK_SRC_DIR}"/keyboards/ergodox_ez/keymaps
}

build(){
    update
    util/docker_build.sh ergodox_ez:"${MYKEYMAP_NAME}"
    cp "${QMK_SRC_DIR}/.build/ergodox_ez_${MYKEYMAP_NAME}.hex" "${MYKEYMAP_DIR}"
}

flash(){
    update
    util/docker_build.sh ergodox_ez:"${MYKEYMAP_NAME}":flash
}

"$@"
