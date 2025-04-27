
include ../common/Makefile.common

EXE      = .elf
SRC      = full.c
CFLAGS  += -L../common
LDFLAGS += -T ../common/$(LINKSCR)
TARGET   = full
OUTPUT   = $(TARGET)$(EXE)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(OUTPUT) $(SRC) $(LDFLAGS)
	$(OBJDUMP) -d $(OUTPUT) > $(TARGET).dis
	$(READELF) -a $(OUTPUT) > $(TARGET).symbol

clean:
	$(RM) *.o $(OUTPUT) $(TARGET).dis $(TARGET).symbol
