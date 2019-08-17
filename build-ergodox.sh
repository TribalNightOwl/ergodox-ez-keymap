cd ~/git/qmk_firmware
docker run -e keymap=TribalNightOwl -e keyboard=ergodox_ez --rm -v $('pwd'):/qmk:rw -u $(id -u):$(id -g) edasque/qmk_firmware
