CC = arm-none-eabi-gcc
AS = arm-none-eabi-as 
LD = arm-none-eabi-ld 
BIN = arm-none-eabi-objcopy
CFLAGS = -mthumb -mcpu=cortex-m3 -std=c99

main.bin: main.elf 
	$(BIN) -O binary main.elf main.bin
main.elf: linker.ld crt.o main.o 
	$(LD) -T linker.ld -o main.elf crt.o main.o  
crt.o: crt.s
	$(AS) -o crt.o crt.s 
main.o: main.c 
	$(CC) $(CFLAGS) -c -o main.o main.c 
clear:
	rm -f *.o *.elf *.bin 
