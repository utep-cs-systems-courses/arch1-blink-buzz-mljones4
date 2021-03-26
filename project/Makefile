# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I./h
LDFLAGS 	= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as
AR              = msp430-elf-ar

all: toy.elf

#additional rules for files
toy.elf: ${COMMON_OBJECTS} buzzer.o stateMachines.o led.o wdInterruptHandler.o p2_interrupt_handler.o switches.o main.c ./lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: toy.elf
	msp430loader.sh toy.elf $^

clean:
	rm -f *.o *.elf timerLib.a

libTimer.a: clocksTimer.o sr.o
	$(AR) crs $@ $^

install: libTimer.a
	mkdir -p ../h ../lib
	mv $^ ../lib
	cp *.h ../h

buzzer.c: buzzer.h switches.h

main.c: buzzer.h switches.h led.h

led.o: led.c led.h switches.h

wdInterruptHandler.o: stateMachines.h

stateMachines.o: led.h stateMachines.h
