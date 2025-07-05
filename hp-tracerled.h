#define HP_TRACERLED_PID 0x84FD
#define HP_TRACERLED_VID 0x103C

#define USB_BUF_ZONE_INDEX 0x36

typedef struct color {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} color;

typedef enum {
    LED_ROTATION_STATIC = 0x01,
    LED_ROTATION_BREATHING = 0x06,
    LED_ROTATION_CYCLE = 0x07,
    LED_ROTATION_BLINKING = 0x08,
} tracerled_mode;

typedef enum {
    LED_ZONE_LOGO = 0x01,
    LED_ZONE_BAR = 0x02,
    LED_ZONE_UNKNOWN_1 = 0x03, // ??
    LED_ZONE_CPU = 0x04,
    LED_ZONE_FRONT_FAN_BOTTOM = 0x05,
    LED_ZONE_FRONT_FAN_MIDDLE = 0x06,
    LED_ZONE_FRONT_FAN_TOP = 0x07,
} tracerled_zone;

typedef struct tracerled_packet {
    tracerled_zone zone;
    tracerled_mode mode;
    unsigned char brightness;
} trackerled_packet;
