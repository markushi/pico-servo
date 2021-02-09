#include "pico/stdlib.h"
#include "src/pico_servo.h"

const uint SERVO_PIN = 15;

int
main()
{
    const uint min = 30;
    const uint max = 150;

    servo_enable(SERVO_PIN);

    bool clockwise = true;
    uint angle = 0;

    while (1) {
        servo_set_position(SERVO_PIN, angle);

        sleep_ms(20);

        if (clockwise) {
            angle++;
        } else {
            angle--;
        }
        if (angle == 0 || angle == 180) {
            clockwise = !clockwise;
        }
    }
    return 0;
}