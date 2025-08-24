include config.mk 

svet2_O_SET := app_svet2 src_button src_timer src_svetofor# список зависимостей для r
BUILD_DIR := build/
SRC_DIR := src/
APP_DIR := app/

TARGET := svet2

# правило для компиляции

define elf_tmpl
$(1).elf: $(addsuffix .o,$($(1)_O_SET))
	$$(eval OBJS := $$(addprefix $(BUILD_DIR),$$^))
	# создание .elf
	$(CC) $(CFLAGS) $$(OBJS) -o $(BUILD_DIR)$$@
endef

all: $(TARGET).hex

$(eval $(call elf_tmpl,$(TARGET))) # для всех элементов в ALL_RUNS сделать run_tmpl


%.o: 
	# Создание .o
	$(CC) $(CFLAGS) -c $(subst _,/,$(basename $@)).c -o $(BUILD_DIR)$@

%.hex: %.elf
	# Создание .hex
	$(OBJCOPY) -O ihex -R .eeprom $(BUILD_DIR)$< $(APP_DIR)$@

flash:
	stty -F /dev/ttyACM0 1200
	sleep 2 
	avrdude -v -p $(AVRDUDE_MCU) -c wiring -P /dev/ttyACM0 -b 115200 -D -U flash:w:$(APP_DIR)$(TARGET).hex 

clean:
	rm -f $(BUILD_DIR)*.elf $(BUILD_DIR)*.hex $(BUILD_DIR)*.o $(APP_DIR)$(TARGET).hex
# `%.hex: $(BUILD_DIR)%.elf
# `	# Создание .hex
# `	$(OBJCOPY) -O ihex -R .eeprom $< $(BUILD_DIR)$@

# $^ -- все зависимости
# $@ -- цель 
# $* -- шаблонная часть
# $< -- первый элемент в списке зависимостей
.PHONY: all flash clean
