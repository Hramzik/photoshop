

cc = gcc

SRC_FOLDER = src
LIB_FOLDER  = src/lib

APP_FOLDER       = src/app/cpp
GRAPHICS_FOLDER  = src/graphics/cpp
MY_RGB_FOLDER    = src/my_rgb/cpp
VECTOR_FOLDER    = src/vector/cpp
TRANSFORM_FOLDER = src/transform/cpp
EVENTS_FOLDER    = src/events/cpp
WIDGETS_FOLDER   = src/widgets/cpp
TOOLS_FOLDER     = src/tools/cpp
FILTERS_FOLDER   = src/filters/cpp
CLOCK_FOLDER     = src/clock/cpp

PLUGIN_STANDART_FOLDER = src/plug-standart
RENDER_TARGET_FOLDER   = src/plug-standart/Impl/RenderTarget/SdlRenderTarget
SDL_ADAPTERS_FOLDER    = src/plug-standart/Impl/RenderTarget/SdlRenderTarget/SdlAdapters

exefolder = exe

define flags
	-Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wmissing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -D_DEBUG -D_EJUDGE_CLIENT_SIDE
endef

define sdl_flags
	-LC:\Users\hramz_3vliuy6\Desktop\lib\SDL2\lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
endef

define flags_sdl_version
	-Wshadow -Winit-self -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wmissing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -D_DEBUG -D_EJUDGE_CLIENT_SIDE
endef


sc = @ #showcommands
default_name = prog
default_path = $(exefolder)/$(default_name)


all: program


program:
	$(sc) $(cc) \
	$(SRC_FOLDER)/main.cpp \
	$(WIDGETS_FOLDER)/my_widget.cpp \
	\
	$(SDL_ADAPTERS_FOLDER)/MyVertexArray.cpp \
	$(SDL_ADAPTERS_FOLDER)/MyRenderTarget.cpp \
	$(SDL_ADAPTERS_FOLDER)/MyRenderTexture.cpp \
	$(SDL_ADAPTERS_FOLDER)/MyRenderWindow.cpp \
	$(SDL_ADAPTERS_FOLDER)/Converters.cpp \
	$(RENDER_TARGET_FOLDER)/RenderTarget.cpp \
	\
	-o $(default_path) $(sdl_flags) $(flags_sdl_version) \
	-lstdc++ -O0 \
	-fmessage-length=60 \
	-fcompare-debug-second \
	-I $(SRC_FOLDER) \
	-I $(PLUGIN_STANDART_FOLDER) \
	-I C:/Users/hramz_3vliuy6/Desktop/lib/SDL2/include/SDL2

