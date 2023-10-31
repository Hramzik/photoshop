

cc = gcc

MAIN_FOLDER = src
LIB_FOLDER  = src/lib

APP_FOLDER = src/app/cpp
GRAPHICS_FOLDER = src/graphics/cpp
MY_RGB_FOLDER = src/my_rgb/cpp
VECTOR_FOLDER = src/vector/cpp
TRANSFORM_FOLDER = src/transform/cpp
WIDGETS_FOLDER = src/widgets/cpp
TOOLS_FOLDER = src/tools/cpp
CLOCK_FOLDER = src/clock/cpp

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
	$(MAIN_FOLDER)/main.cpp \
	$(LIB_FOLDER)/logs.cpp \
	$(GRAPHICS_FOLDER)/graphics.cpp \
	$(GRAPHICS_FOLDER)/texture.cpp \
	$(GRAPHICS_FOLDER)/sdl.cpp \
	$(MY_RGB_FOLDER)/my_rgb.cpp \
	$(VECTOR_FOLDER)/vector.cpp \
	$(VECTOR_FOLDER)/point.cpp \
	$(VECTOR_FOLDER)/pair.cpp \
	$(WIDGETS_FOLDER)/widget.cpp \
	$(WIDGETS_FOLDER)/container.cpp \
	$(WIDGETS_FOLDER)/container_iterator.cpp \
	$(WIDGETS_FOLDER)/button.cpp \
	$(WIDGETS_FOLDER)/close_button.cpp \
	$(WIDGETS_FOLDER)/window.cpp \
	$(WIDGETS_FOLDER)/colored.cpp \
	$(WIDGETS_FOLDER)/textured.cpp \
	$(WIDGETS_FOLDER)/framed.cpp \
	$(WIDGETS_FOLDER)/canvas.cpp \
	$(WIDGETS_FOLDER)/photoshop.cpp \
	$(TOOLS_FOLDER)/palette.cpp \
	$(TOOLS_FOLDER)/tool.cpp \
	$(TOOLS_FOLDER)/brush.cpp \
	$(TRANSFORM_FOLDER)/stack.cpp \
	$(TRANSFORM_FOLDER)/transform.cpp \
	$(APP_FOLDER)/app.cpp \
	-o $(default_path) $(sdl_flags) $(flags_sdl_version) \
	-lstdc++ -O0 \
	-fmessage-length=60

