#include "mbed.h"
#include "i2c-lcd.h"
#include <string>
using namespace std;

int row=0;
int col=0;

string teststring;

char *test = NULL;

// Für LCD auf Basis-Board:
// Brücke von D15(SCL) -> PA_11
// Brücke von D14 (SDA) -> PA_12

 
int main() {
    lcd_init ();
    lcd_clear ();

    lcd_put_cur(0, 0);

    teststring = "Ein Teststring 9";
    test = (char *) teststring.c_str();
    lcd_send_string (test);

    ThisThread::sleep_for(2000ms);

    lcd_put_cur(1, 0);

    lcd_send_string("Welt");

    ThisThread::sleep_for(2000ms);

    lcd_clear();

    while (1)
    {

	    for (int i=0;i<128;i++)
	    {
		    lcd_put_cur(row, col);

            lcd_send_data(i+48);

            col++;

            if (col > 15) {row++; col = 0;}
            if (row > 1) row=0;

            ThisThread::sleep_for(250ms);
	  }
  }
}