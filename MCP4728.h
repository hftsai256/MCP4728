/*
   Marko Pinteric 2020
   GPIO communication based on Tiny GPIO Access on http://abyz.me.uk/rpi/pigpio/examples.html

   Header for MCP4728.c
*/

/* gpio modes (Tiny GPIO) */

#define PI_INPUT  0
#define PI_OUTPUT 1
#define PI_ALT0   4
#define PI_ALT1   5
#define PI_ALT2   6
#define PI_ALT3   7
#define PI_ALT4   3
#define PI_ALT5   2

/* values for pull-ups/downs off, pull-down && pull-up (Tiny GPIO) */

#define PI_PUD_OFF  0
#define PI_PUD_DOWN 1
#define PI_PUD_UP   2

/* chip data */

struct chip
{
   unsigned sda;
   unsigned scl;
   unsigned ldac;
   unsigned address;
   unsigned bus;
};


/* ---------------- public functions ----------------------- */

/* initialises communications */
struct chip *initialise(int sda, int scl, int ldac, int address);

/* deinitialise communications */
int deinitialise(struct chip *tempchip);

/* gets the DAC address */
int getaddress(struct chip *tempchip);

/* sets the DAC address */
int setaddress(struct chip *tempchip, unsigned addr);

/* writes single value to the selected DAC channel using internal reference - channels 1 to 4 */
int singleinternal(struct chip *tempchip, int channel, float volt, bool eeprom);

/* writes single value to the selected DAC channel using external reference - channels 1 to 4 */
int singleexternal(struct chip *tempchip, int channel, float rel, bool eeprom);

/* writes four values to the DAC channels using internal reference */
int multipleinternal(struct chip *tempchip, float volts[], bool eeprom);

/* writes four values to DAC channels using external reference */
int multipleexternal(struct chip *tempchip, float rels[], bool eeprom);

/* ---------------- Tiny GPIO functions ----------------------- */

void gpioSetMode(unsigned gpio, unsigned mode);

int gpioGetMode(unsigned gpio);

void gpioSetPullUpDown(unsigned gpio, unsigned pud);

int gpioRead(unsigned gpio);

void gpioWrite(unsigned gpio, unsigned level);

int gpioInitialise(void);
