#!/usr/bin/env bash

BRANCH=$(git rev-parse --abbrev-ref HEAD)
BASE_DIR="${HOME}/git"
QMK_SRC_DIR="${BASE_DIR}/qmk_firmware"
QMK_REPO="git@github.com:TribalNightOwl/qmk_firmware.git"
MYKEYMAP_NAME="TribalNightOwl"
MYKEYMAP_DIR="${BASE_DIR}/ergodox-ez-keymap/${BRANCH}/keymap/${MYKEYMAP_NAME}"

clone(){
    cd "${BASE_DIR}" || exit
    rm -rf "${QMK_SRC_DIR}"
    git clone --recurse-submodules "${QMK_REPO}"
}

update(){
    cd "${QMK_SRC_DIR}" || exit
    rsync -av --delete "${MYKEYMAP_DIR}" "${QMK_SRC_DIR}"/keyboards/ergodox_ez/keymaps
}

build(){
    update
    util/docker_build.sh ergodox_ez:"${MYKEYMAP_NAME}"
}

flash(){
    update
    util/docker_build.sh ergodox_ez:"${MYKEYMAP_NAME}":flash
}


"$@"
