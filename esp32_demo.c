/*
 * esp32_demo.c
 *
 * Minimal ESP32 toolchain/workflow test.
 *
 * This deliberately does not use ESP-IDF, FreeRTOS, Arduino,
 * or any ESP32 SDK. The purpose is simply to verify that:
 *
 *     C source
 *        -> Xtensa GCC
 *        -> ELF
 *        -> binary
 *
 * works with the project Makefile.
 */

#include <stdint.h>

/*
 * Volatile global gives us something visible in the generated
 * object code and prevents the compiler from removing the loop.
 */
volatile uint32_t esp32_test_counter = 0;

static uint32_t fibonacci(uint32_t n)
{
    uint32_t a = 0;
    uint32_t b = 1;

    for (uint32_t i = 0; i < n; ++i) {
        uint32_t next = a + b;
        a = b;
        b = next;
    }

    return a;
}

/*
 * This is intentionally just a normal C entry point for now.
 *
 * Once the ESP32 startup/linker layer is added, this can become
 * the actual firmware entry point.
 */
int main(void)
{
    uint32_t result = fibonacci(10);

    esp32_test_counter = result;

    /*
     * Keep the firmware alive.
     *
     * The volatile counter also gives us a simple value to inspect
     * in a debugger/emulator later.
     */
    for (;;) {
        ++esp32_test_counter;

        /*
         * Deliberately simple delay loop.
         * No SDK dependency.
         */
        for (volatile uint32_t i = 0; i < 100000; ++i) {
        }
    }

    return 0;
}
