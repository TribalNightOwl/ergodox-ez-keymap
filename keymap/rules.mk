TAP_DANCE_ENABLE = yes
RGBLIGHT_ENABLE = yes
DEBOUNCE_TYPE = sym_defer_g
BOOTMAGIC_ENABLE = yes

ifndef QUANTUM_DIR
    include ../../../../Makefile
endif
