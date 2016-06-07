
/*
 * Modified for the Maxim 31855 SPI Sensor
 * Copyright (c) 2016 Avnet, Inc.  All rights reserved.
 *
 * Avnet, Inc.
 * Avnet IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS" AS A
 * COURTESY TO YOU.  BY PROVIDING THIS DESIGN, CODE, OR INFORMATION AS
 * ONE POSSIBLE   IMPLEMENTATION OF THIS FEATURE, APPLICATION OR
 * STANDARD, Avnet IS MAKING NO REPRESENTATION THAT THIS IMPLEMENTATION
 * IS FREE FROM ANY CLAIMS OF INFRINGEMENT, AND YOU ARE RESPONSIBLE
 * FOR OBTAINING ANY RIGHTS YOU MAY REQUIRE FOR YOUR IMPLEMENTATION.
 * Avnet EXPRESSLY DISCLAIMS ANY WARRANTY WHATSOEVER WITH RESPECT TO
 * THE ADEQUACY OF THE IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO
 * ANY WARRANTIES OR REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE
 * FROM CLAIMS OF INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License.
 *
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>

#include <linux/input.h>

#define EVENT_FILE "/dev/input/event0"
#define OUT_OF_RANGE -500.0

volatile int interrupt = 0;

// Handle signal interrupt
void sigHandler(int signo) {
	printf("SigINT received.\n");
	interrupt = 1;
}

int main()
{
        int fd;
        struct input_event ie;
        float humidity = OUT_OF_RANGE;
        float temperature = OUT_OF_RANGE;

	//catch interrupt signal
	signal(SIGINT, sigHandler);
	signal(SIGTERM, sigHandler);

        if((fd = open(EVENT_FILE, O_RDONLY)) == -1) {
                perror("opening HTS221 device");
                exit(EXIT_FAILURE);
        }

	while(!interrupt) {

 	  if (read(fd, &ie, sizeof(struct input_event)) != 0) {
	    //               printf("time %ld.%06ld\ttype %d\tcode %d\tvalue %d\n",
	    //                      ie.time.tv_sec, ie.time.tv_usec, ie.type, ie.code, ie.value);
	    switch (ie.code){
	    case 40:  //Relative Humidity
	      humidity = (float)ie.value/1000.0;
	      break;
	    case 9:   //Temperature
	      temperature = (float)ie.value/1000.0;
	      break;
	    default:
	      break;
	    }
	    
	    if (humidity != OUT_OF_RANGE && temperature != OUT_OF_RANGE) {
	    	printf("Humidity = %7.3f%%  Temperature = %7.3f C or %7.3f F\n", humidity, temperature, temperature * 1.8 + 32);
	    	humidity = temperature = OUT_OF_RANGE;
	    }
	  }
	  
	  else {
	    printf("Sensor read failed...aborting\n");
	    break;
	  }
	  sleep(1);
	}

	(void) close(fd);
        return 0;
}
