#include <hidapi/hidapi.h>
#include "hp-tracerled.h"

/* const unsigned char RED = 0xFD; */
/* const unsigned char GREEN = 0x40; */
/* const unsigned char BLUE = 0x01; */
const unsigned char RED = 0x00;
const unsigned char GREEN = 0x00;
const unsigned char BLUE = 0x00;

void set_solid_color(hid_device *handle, color color) {

}

int main(int argc, char *argv[]) {
    hid_device *handle;
    unsigned char usb_buf[] =
    {
        0x00, 0x00, 0x12,
        LED_ROTATION_STATIC,
        0x01, 0x01, // [Custom color count, number]
        0x00, 0x00,
        RED, GREEN, BLUE, // [0x08 - 0x2C]  R, G, B
        RED, GREEN, BLUE, // 12 x 3 = 36
        RED, GREEN, BLUE,
        RED, GREEN, BLUE,
        RED, GREEN, BLUE,
        RED, GREEN, BLUE,
        RED, GREEN, BLUE,
        RED, GREEN, BLUE,
        RED, GREEN, BLUE,
        RED, GREEN, BLUE,
        RED, GREEN, BLUE,
        RED, GREEN, BLUE, 
        0x00, 0x00, 0x00, 0x00,
        0x64, // Brightness
        0x00,
        0x00, 0x00, 0x00, 0x00,
        0x01, 0x01, 0x00, 0x01  // [0x36-0x39] zone / 0x01 / theme / speed
    };

    hid_init();
    handle = hid_open(HP_TRACERLED_VID, HP_TRACERLED_PID, NULL);

    for (int i = 0x01; i <= LED_ZONE_FRONT_FAN_TOP; i++) {
        color color = { RED, GREEN, BLUE };

        usb_buf[USB_BUF_ZONE_INDEX] = i;
        hid_write(handle, usb_buf, 58);

        set_solid_color(handle, color);
    }

    hid_close(handle);
    hid_exit();

    return 0;
}

