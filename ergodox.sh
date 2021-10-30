#!/usr/bin/env bash

# Execute this script on the machine where src resides
BRANCH=update-to-qmk_cli
QMK_SRC_DIR=~/git/qmk_firmware
MYKEYMAP_DIR=~/git/ergodox-ez-keymap/${BRANCH}/keymap/
SCRIPTS_DIR=~/git/ergodox-ez-keymap/${BRANCH}/scripts
IMAGE=tribrhy/buildkeyboard
TAG="latest"

build(){
    docker run --rm \
                -v ${QMK_SRC_DIR}:/qmk:rw \
                -v ${MYKEYMAP_DIR}:/keymap:rw \
                -v ${SCRIPTS_DIR}:/scripts:rw \
                ${IMAGE}:${TAG}

    cp ${QMK_SRC_DIR}/*.hex ${MYKEYMAP_DIR}/../
}

shell(){
    docker run --rm -it \
                -v ${QMK_SRC_DIR}:/qmk:rw \
                -v ${MYKEYMAP_DIR}:/keymap:rw \
                -v ${SCRIPTS_DIR}:/scripts:rw \
                ${IMAGE}:${TAG} bash
}

build_image(){
    docker build . -t ${IMAGE}:${TAG}
}

"$@"
