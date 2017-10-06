/*
 *  Copyright 2002 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *  
 */
/* "@(#) DSP/BIOS 4.80.208 12-06-02 (barracuda-l19)" */
/*
 *  ======== volume.h ========
 *
 */

#ifndef __VOLUME_H
#define __VOLUME_H

#ifndef TRUE
#define TRUE 1
#endif

#define BUFSIZE 0x64

#define FRAMESPERBUFFER 10

#define MINGAIN 5
#define MAXGAIN 10

#define MINCONTROL 0
#define MAXCONTROL 19

#define BASELOAD 1

struct PARMS {
	int Beta;
	int EchoPower;
	int ErrorPower;
	int Ratio;
	struct PARMS *Link;
};

#endif /* __VOLUME_H */
