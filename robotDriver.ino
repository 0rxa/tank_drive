#include <XBOXRECV.h>

#define lm1 2
#define lm2 3
#define rm1 4
#define rm2 5
#define speed HIGH

USB Usb;
XBOXRECV Xbox(&Usb);

void setup()
{
	while(Usb.Init() == -1); // Wait for USB Shield ///////////////

	// Declare pins ///////////////////////////////////////////////
	for(int c = 2; c < 8; c++)
	{
		pinMode(c, OUTPUT);
	}
	///////////////////////////////////////////////////////////////
}

void loop()
{
	STARTLOOP:
	// Ensure everything is healthy ///////////////////////
	Usb.Task();
	if(!Xbox.XboxReceiverConnected)
	{
		digitalWrite( lm2, 0 );
		digitalWrite( rm2, 0 );
		digitalWrite( lm1, 0 );
		digitalWrite( rm1, 0 );
		goto STARTLOOP;
	}
	if(!Xbox.Xbox360Connected[0])
	{
		digitalWrite( lm2, 0 );
		digitalWrite( rm2, 0 );
		digitalWrite( lm1, 0 );
		digitalWrite( rm1, 0 );
		goto STARTLOOP;
	}
	///////////////////////////////////////////////////////
	
	// Movement //////////////////////////////////////////////
	if( Xbox.getButtonPress(R2, 0) )
	{
		digitalWrite( lm1, speed );
		digitalWrite( rm1, speed );
		digitalWrite( lm2,     0 );
		digitalWrite( rm2,     0 );
	}
	else if( Xbox.getButtonPress(L2, 0) )
	{
		digitalWrite( lm1,     0 );
		digitalWrite( rm1,     0 );
		digitalWrite( lm2, speed );
		digitalWrite( rm2, speed );
	}
	else if( Xbox.getButtonPress(L1, 0) )
	{
		digitalWrite( lm1,     0 );
		digitalWrite( lm2, speed );
		digitalWrite( rm1, speed );
		digitalWrite( rm2,     0 );
	}
	else if( Xbox.getButtonPress(R1, 0) )
	{
		digitalWrite( lm1, speed );
		digitalWrite( lm2,     0 );
		digitalWrite( rm1,     0 );
		digitalWrite( rm2, speed );
	}
	else
	{
		digitalWrite( lm2, 0 );
		digitalWrite( rm2, 0 );
		digitalWrite( lm1, 0 );
		digitalWrite( rm1, 0 );
	}
	///////////////////////////////////////////////////////
}
