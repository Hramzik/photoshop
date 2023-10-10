

cc = gcc

MAIN_FOLDER   = src
LIB_FOLDER    = src/lib

exefolder = exe

define flags
	-Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wmissing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -D_DEBUG -D_EJUDGE_CLIENT_SIDE
endef

define sdl_flags
	-LC:\Users\hramz_3vliuy6\Desktop\lib\SDL2\lib -lmingw32 -lSDL2main -lSDL2
endef

define flags_sdl_version
	-Wshadow -Winit-self -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wmissing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -D_DEBUG -D_EJUDGE_CLIENT_SIDE
endef


sc = @ #showcommands
default_name = prog
default_path = $(exefolder)/$(default_name)


all: NAME


NAME:
	$(sc) $(cc) \
	$(MAIN_FOLDER)/main.cpp \
	$(LIB_FOLDER)/logs.cpp \
	-o $(default_path) $(sdl_flags) $(flags_sdl_version) -lstdc++ -Ofast

