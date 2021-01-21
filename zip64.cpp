#include "MicroBit.h"
#include "pxt.h"
using namespace pxt;

/**
 * This is the :GAME ZIP64 Package
 */
//% color=#00A654 weight=100
namespace GAME_ZIP64 {

    MicroBit uBit;
    bool initialized = false;
    bool pinDriveSet = false;

    //%
    void pinDriveInit() {
        if (pinDriveSet) return;

        #if MICROBIT_CODAL
            uBit.io.P0.setHighDrive(true);
        #endif

        pinDriveSet = true;
    }

    //%
    void init() {
        if (initialized) return;
        //This function sets all the buttons on the :GAME ZIP64 to actually appear as buttons on the micro:bit
        #define ALLOC_PIN_BUTTON(id) new MicroBitButton(getPin(id)->name, id, MICROBIT_BUTTON_ALL_EVENTS, PullUp);
            ALLOC_PIN_BUTTON(MICROBIT_ID_IO_P8)
            ALLOC_PIN_BUTTON(MICROBIT_ID_IO_P12)
            ALLOC_PIN_BUTTON(MICROBIT_ID_IO_P13)
            ALLOC_PIN_BUTTON(MICROBIT_ID_IO_P14)
            ALLOC_PIN_BUTTON(MICROBIT_ID_IO_P15)
            ALLOC_PIN_BUTTON(MICROBIT_ID_IO_P16)
        #undef ALLOC_PIN_BUTTON

        initialized = true;
    }
}