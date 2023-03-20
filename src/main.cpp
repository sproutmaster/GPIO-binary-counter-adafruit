#include <Arduino.h>
void setup ()
{
    // set DDRD to write mode
    unsigned char *DDRD_;
    DDRD_ = (unsigned char *) 0x2A;
    *DDRD_ |= 0b10001100;
}

unsigned char number = 0;

void loop()
{
    // Led 1 : bit 7, Led 2: bit 3, Led 3: bit 2
    unsigned char *portD;
    portD = (unsigned char *) 0x2B;

    if (number < 7)
        number+=1;
    else
        number = 0;

    *portD = (((number) & 3) << 2) | (((number) & 4) << 5);
    delay(1000);

}
