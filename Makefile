CROSS_COMPILER = arm-none-eabi

GCC = -gcc

MACHINE = cortex-m3

COMPILER_FLAGS_C = -c -mcpu=${MACHINE} -mthumb -std=gnu11 -Wall -o0
COMPILER_FLAGS_C_PLS_PLS = -c -mcpu=${MACHINE} -mthumb -std=gnu++11 -Wall -o0

LINKER_FLAGS = -nostdlib -T stm32_ls.ld -Wl,-Map=./build/final.map

BUILD_PATH = ./build/

MAIN_FILE = main.c

all: main.o stm32_startUp.o final.elf

main.o:${MAIN_FILE}
	${CROSS_COMPILER}${GCC} ${COMPILER_FLAGS_C} -o ${BUILD_PATH}$@ $^

stm32_startUp.o:stm32_startUp.c
	${CROSS_COMPILER}${GCC} ${COMPILER_FLAGS_C} -o ${BUILD_PATH}$@ $^

final.elf:${BUILD_PATH}main.o ${BUILD_PATH}stm32_startUp.o
	${CROSS_COMPILER}${GCC} ${LINKER_FLAGS} -o ${BUILD_PATH}$@ $^

clean:
	del ${BUILD_PATH}*.o
