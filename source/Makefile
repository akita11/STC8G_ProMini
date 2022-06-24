CC := sdcc

bin_name := blink
BUILD_DIR := ./build/

C_FLAGS := -V -mmcs51 --model-small --xram-size 0x800 --xram-loc 0x0000 --code-size 0x8000 -o $(BUILD_DIR)

all: main
	$(CC) ./build/main.rel -o ./build/$(bin_name).ihx
	sdobjcopy -I ihex -O binary $(join $(BUILD_DIR),$(bin_name).ihx) $(join $(BUILD_DIR),$(bin_name).bin)

main: ./src/main.c 
	$(CC) -c $(C_FLAGS) $^ -I./inc -o $(BUILD_DIR)

clean:
	rm ./build/*

