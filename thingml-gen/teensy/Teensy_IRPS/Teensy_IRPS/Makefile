# The teensy version to use, 30, 31, 35, 36, or LC
TEENSY = 32

# Set to default/overclock to set CPU core speed
TEENSY_CORE_SPEED = default

# path location for core
COREPATH =  ../../../../c/lib/core/teensy3
TMPCOREFOLDER := $(subst /, ,$(COREPATH))
COREFOLDER := $(word $(shell echo $(words $(TMPCOREFOLDER))),$(TMPCOREFOLDER))

# path location for your code
EXTERNPATH = ../../../../c/utils
TMPEXTERNFOLDER := $(subst /, ,$(EXTERNPATH))
EXTERNFOLDER := $(word $(shell echo $(words $(TMPEXTERNFOLDER))),$(TMPEXTERNFOLDER))

# path location for your LIB0
LIB0PATH = ../../../../c/lib/Adafruit_NeoPixel
TMPLIB0FOLDER := $(subst /, ,$(LIB0PATH))
LIB0FOLDER := $(word $(shell echo $(words $(TMPLIB0FOLDER))),$(TMPLIB0FOLDER))



# The name of your project (used to name the compiled .hex file)
TARGET = $(notdir $(CURDIR))

# configurable options
OPTIONS = -DUSB_SERIAL -DLAYOUT_US_ENGLISH -DUSING_MAKEFILE

# directory to build in
BUILDDIR = $(abspath $(CURDIR)/build)


#************************************************************************
# Settings below this point usually do not need to be edited
#************************************************************************

# CPPFLAGS = compiler options for C and C++
INCLUDES = -Isrc -I$(COREPATH) -I$(EXTERNPATH)  -I$(LIB0PATH)
CPPFLAGS = -Wall -g -Os -mthumb -ffunction-sections -fdata-sections -nostdlib -MMD $(OPTIONS) -DTEENSYDUINO=124 $(INCLUDES)

# compiler options for C++ only
CXXFLAGS = -std=gnu++0x -felide-constructors -fno-exceptions -fno-rtti

# compiler options for C only
CFLAGS =

# linker options
LDFLAGS = -Os -Wl,--gc-sections,--defsym=__rtc_localtime=0 -mthumb --specs=nano.specs

# additional libraries to link
LIBS = -lm 

# compiler options specific to teensy version
ifeq ($(TEENSY), 30)
    CPPFLAGS += -D__MK20DX128__ -mcpu=cortex-m4 -DF_CPU=48000000
    PROCESSOR = mk20dx128
    LDSCRIPT = $(COREPATH)/$(PROCESSOR).ld
    LDFLAGS += -mcpu=cortex-m4 -T$(LDSCRIPT)
else ifeq ($(TEENSY),$(filter $(TEENSY), 31 32))
    CPPFLAGS += -D__MK20DX256__ -mcpu=cortex-m4
    ifeq ($(TEENSY_CORE_SPEED), default)
        CPPFLAGS += -DF_CPU=72000000
    else ifeq ($(TEENSY_CORE_SPEED), overclock)
        CPPFLAGS += -DF_CPU=96000000
    endif
    PROCESSOR = mk20dx256
    LDSCRIPT = $(COREPATH)/$(PROCESSOR).ld
    LDFLAGS += -mcpu=cortex-m4 -T$(LDSCRIPT)
else ifeq ($(TEENSY), LC)
    CPPFLAGS += -D__MKL26Z64__ -mcpu=cortex-m0plus -DF_CPU=48000000
    PROCESSOR = mkl26z64
    LDSCRIPT = $(COREPATH)/$(PROCESSOR).ld
    LDFLAGS += -mcpu=cortex-m0plus -T$(LDSCRIPT)
    LIBS += -larm_cortexM0l_math
else ifeq ($(TEENSY), 35)
    CPPFLAGS += -D__MK64FX512__ -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DF_CPU=120000000
    PROCESSOR = mk64fx512
		LDSCRIPT = $(COREPATH)/$(PROCESSOR).ld
    LDFLAGS += -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -T$(LDSCRIPT)
    LIBS += -larm_cortexM4lf_math
else ifeq ($(TEENSY), 36)
    CPPFLAGS += -D__MK66FX1M0__ -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16
    ifeq ($(TEENSY_CORE_SPEED), default)
        CPPFLAGS += -DF_CPU=180000000
    else ifeq ($(TEENSY_CORE_SPEED), overclock)
        CPPFLAGS += -DF_CPU=240000000
    endif
    PROCESSOR = mk66fx1m0
    LDSCRIPT = $(COREPATH)/$(PROCESSOR).ld
    LDFLAGS += -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -T$(LDSCRIPT)
    LIBS += -larm_cortexM4lf_math
else
    $(error Invalid setting for TEENSY)
endif

# names for the compiler programs
CC = arm-none-eabi-gcc
CXX = arm-none-eabi-g++
OBJCOPY = arm-none-eabi-objcopy
SIZE = arm-none-eabi-size

# automatically create lists of the sources and objects
CPP_FILES := src/Teensy_IRPS.cpp src/runtime.cpp src/AngleReader.cpp src/Button.cpp src/SerialOut.cpp src/PackageReader.cpp src/CalibrationStorer.cpp src/Storer.cpp src/Runner.cpp src/SoftButton.cpp src/Calibrator.cpp src/CalibrationValidator.cpp src/PulseReader.cpp src/SerialIn.cpp src/Backbone.cpp src/Blinker.cpp
SOURCES_FILES := $(CPP_FILES:.cpp=.o)


C_CORE  := $(wildcard $(COREPATH)/*.c)
CPP_CORE_TMP  := $(wildcard $(COREPATH)/*.cpp)
CPP_CORE := $(filter-out $(COREPATH)/main.cpp,$(CPP_CORE_TMP))
SOURCES_CORE  := $(C_CORE:.c=.o) $(CPP_CORE:.cpp=.o)

C_EXTERN := $(wildcard $(EXTERNPATH)/*.c)
CPP_EXTERN := $(wildcard $(EXTERNPATH)/*.cpp)
SOURCES_EXTERN := $(C_EXTERN:.c=.o) $(CPP_EXTERN:.cpp=.o)

C_LIB0 := $(wildcard $(LIB0PATH)/*.c)
CPP_LIB0 := $(wildcard $(LIB0PATH)/*.cpp)
SOURCES_LIB0 := $(C_LIB0:.c=.o) $(CPP_LIB0:.cpp=.o)



SOURCES := $(SOURCES_FILES) $(SOURCES_CORE) $(SOURCES_EXTERN) $(SOURCES_LIB0)
OBJS := $(foreach src,$(SOURCES_FILES), $(BUILDDIR)/$(src)) $(foreach core,$(SOURCES_CORE),$(subst $(COREPATH),$(BUILDDIR)/$(COREFOLDER),$(core))) $(subst $(EXTERNPATH),$(BUILDDIR)/$(EXTERNFOLDER),$(SOURCES_EXTERN))  $(subst $(LIB0PATH),$(BUILDDIR)/$(LIB0FOLDER),$(SOURCES_LIB0))

all: hex

build: $(BUILDDIR)/$(TARGET).elf

hex: $(BUILDDIR)/$(TARGET).hex

flash:
	@teensy_loader_cli -mmcu=$(PROCESSOR) -w $(BUILDDIR)/$(TARGET).hex


$(BUILDDIR)/$(COREFOLDER)/%.o: $(COREPATH)/%.c
	@echo -e "[CC]\t$<"
	@mkdir -p "$(dir $@)"
	@$(CC) $(CPPFLAGS) $(CFLAGS) -o "$@" -c "$<"

$(BUILDDIR)/$(COREFOLDER)/%.o: $(COREPATH)/%.cpp
	@echo -e "[CXX]\t$<"
	@mkdir -p "$(dir $@)"
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o "$@" -c "$<"

$(BUILDDIR)/$(EXTERNFOLDER)/%.o: $(EXTERNPATH)/%.c
	@echo -e "[CC]	$<"
	@mkdir -p "$(dir $@)"
	@$(CC) $(CPPFLAGS) $(CFLAGS) -o "$@" -c "$<"

$(BUILDDIR)/$(EXTERNFOLDER)/%.o: $(EXTERNPATH)/%.cpp
	@echo -e "[CXX]	$<"
	@mkdir -p "$(dir $@)"
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o "$@" -c "$<"

$(BUILDDIR)/$(LIB0FOLDER)/%.o: $(LIB0PATH)/%.c
	@echo -e "[CC]	$<"
	@mkdir -p "$(dir $@)"
	@$(CC) $(CPPFLAGS) $(CFLAGS) -o "$@" -c "$<"

$(BUILDDIR)/$(LIB0FOLDER)/%.o: $(LIB0PATH)/%.cpp
	@echo -e "[CXX]	$<"
	@mkdir -p "$(dir $@)"
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o "$@" -c "$<"



$(BUILDDIR)/src/%.o: src/%.cpp
	@echo -e "[CXX]\t$<"
	@mkdir -p "$(dir $@)"
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o "$@" -c "$<"

$(BUILDDIR)/$(TARGET).elf: $(OBJS) $(LDSCRIPT)
	@echo -e "[LD]\t$@"
	@$(CC) $(LDFLAGS) -o "$@" $(OBJS) $(LIBS)

$(BUILDDIR)/%.hex: $(BUILDDIR)/%.elf
	@echo -e "[HEX]\t$@"
	@$(SIZE) "$<"
	@$(OBJCOPY) -O ihex -R .eeprom "$<" "$@"

# compiler generated dependency info
-include $(OBJS:.o=.d)

print-%  : ; @echo $* = $($*)

clean:
	@echo Cleaning...
	@rm -rf "$(BUILDDIR)"
