/*
 * TEST.C
 *
 * Stupid test-bed for the time-slicing functions in SLICE.ASM;
 * simply detects a multi-tasker and then waits for a keystroke
 * twice, once with time-slicing and once without.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


#include "slice.h"

static char *tasker_names[] =
{
    "None",
    "DesqView",
    "Windows 3.x (enhanced)",
    "OS/2 2.0",
    "OS/2 2.1"
};

void main(void)
{
    int tasker = detect_multitasker();

    printf("Multitasker found: %s\r\n", tasker_names[tasker]);

	if (!tasker)
		exit(1);

    puts("Waiting for keystroke (no slicing...)");
    while (!kbhit())
        ;

    getch();

    puts("Waiting for keystroke (slicing...)");
    while (!kbhit())
        timeslice();

    getch();

    exit(0);
}
