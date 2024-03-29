

cc = gcc

SRC_FOLDER = src
OBJ_FOLDER = obj
LIB_FOLDER  = src/lib

APP_FOLDER       = src/app/cpp
GRAPHICS_FOLDER  = src/graphics/cpp
MY_RGB_FOLDER    = src/my_rgb/cpp
VECTOR_FOLDER    = src/vector/cpp
OBSERVER_FOLDER  = src/observer/cpp

WIDGETS_FOLDER   = src/widgets/cpp
CANVAS_FOLDER    = src/canvas/cpp
TOOLS_FOLDER     = src/tools/cpp
FILTERS_FOLDER   = src/filters/cpp
PLUGINS_FOLDER   = src/plugins/cpp
PLUGIN_DATA_FOLDER = src/plugin_data/cpp

PHOTOSHOP_FOLDER = src/photoshop/cpp

PLUGIN_STANDART_FOLDER       = src/plug-standart
PLUGIN_IMPLEMENTATION_FOLDER = src/plug-standart/Impl
RENDER_TARGET_FOLDER         = src/plug-standart/Impl/RenderTarget/SdlRenderTarget
SDL_ADAPTERS_FOLDER          = src/plug-standart/Impl/RenderTarget/SdlRenderTarget/SdlAdapters

exefolder = exe

define flags
	-Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wmissing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -D_DEBUG -D_EJUDGE_CLIENT_SIDE
endef

define sdl_flags
	-LC:\Users\hramz_3vliuy6\Desktop\lib\SDL2\lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf
endef

define windows_dialogs_flags
	-LC:\Users\hramz_3vliuy6\gcc\x86_64-w64-mingw32\lib -lcomdlg32
endef

define flags_sdl_version
	-Wshadow -Winit-self -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wmissing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -D_DEBUG -D_EJUDGE_CLIENT_SIDE
endef

define flags_standart_version
	-Wshadow -Winit-self -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wmissing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -D_DEBUG -D_EJUDGE_CLIENT_SIDE
endef

sc = @ #showcommands
default_name = prog
default_path = $(exefolder)/$(default_name)

all: program

program:

	$(sc) $(cc) \
	$(GRAPHICS_FOLDER)/sdl.cpp \
	$(MY_RGB_FOLDER)/my_rgb.cpp \
	$(VECTOR_FOLDER)/pair.cpp \
	$(VECTOR_FOLDER)/point.cpp \
	$(VECTOR_FOLDER)/vector2d.cpp \
	$(VECTOR_FOLDER)/vector3d.cpp \
	$(OBSERVER_FOLDER)/observer.cpp \
	$(OBSERVER_FOLDER)/observable.cpp \
	$(LIB_FOLDER)/logs.cpp \
\
	$(PLUGIN_IMPLEMENTATION_FOLDER)/LayoutBox/LayoutBox.cpp \
	$(PLUGIN_IMPLEMENTATION_FOLDER)/TransformStack.cpp \
	$(PLUGIN_IMPLEMENTATION_FOLDER)/Widget.cpp \
	$(PLUGIN_IMPLEMENTATION_FOLDER)/Canvas/SelectionMask.cpp \
\
	$(SDL_ADAPTERS_FOLDER)/MyVertexArray.cpp \
	$(SDL_ADAPTERS_FOLDER)/MyRenderTarget.cpp \
	$(SDL_ADAPTERS_FOLDER)/MyRenderTexture.cpp \
	$(SDL_ADAPTERS_FOLDER)/MyRenderWindow.cpp \
	$(SDL_ADAPTERS_FOLDER)/Converters.cpp \
	$(RENDER_TARGET_FOLDER)/RenderTarget.cpp \
\
	$(SRC_FOLDER)/main.cpp \
	$(APP_FOLDER)/app.cpp \
	$(APP_FOLDER)/events.cpp \
	$(WIDGETS_FOLDER)/my_widget.cpp \
	$(WIDGETS_FOLDER)/window.cpp \
	$(WIDGETS_FOLDER)/colored.cpp \
	$(WIDGETS_FOLDER)/textured.cpp \
	$(WIDGETS_FOLDER)/texted.cpp \
	$(WIDGETS_FOLDER)/actions.cpp \
	$(WIDGETS_FOLDER)/button.cpp \
	$(WIDGETS_FOLDER)/decorator.cpp \
	$(WIDGETS_FOLDER)/manager.cpp \
	$(WIDGETS_FOLDER)/container.cpp \
	$(WIDGETS_FOLDER)/container_iterator.cpp \
	$(WIDGETS_FOLDER)/container_riterator.cpp \
	$(WIDGETS_FOLDER)/framed_window.cpp \
	$(WIDGETS_FOLDER)/hider.cpp \
	$(WIDGETS_FOLDER)/aligner.cpp \
	$(WIDGETS_FOLDER)/square_aligner.cpp \
	$(WIDGETS_FOLDER)/column_aligner.cpp \
	$(WIDGETS_FOLDER)/row_aligner.cpp \
\
	$(CANVAS_FOLDER)/canvas.cpp \
	$(CANVAS_FOLDER)/clear_action.cpp \
	$(CANVAS_FOLDER)/new_action.cpp \
	$(CANVAS_FOLDER)/open_action.cpp \
	$(CANVAS_FOLDER)/save_action.cpp \
\
	$(WIDGETS_FOLDER)/canvas_viewer.cpp \
	$(WIDGETS_FOLDER)/canvas_focus_manager.cpp \
	$(WIDGETS_FOLDER)/canvas_manager.cpp \
\
	$(PLUGIN_DATA_FOLDER)/plugin_data.cpp \
\
	$(TOOLS_FOLDER)/color_palette.cpp \
	$(TOOLS_FOLDER)/tool_palette.cpp \
\
	$(FILTERS_FOLDER)/palette.cpp \
\
	$(PHOTOSHOP_FOLDER)/photoshop.cpp \
	$(PHOTOSHOP_FOLDER)/plugin_loader.cpp \
	$(PHOTOSHOP_FOLDER)/color_selection.cpp \
	$(PHOTOSHOP_FOLDER)/color_selection_action.cpp \
	$(PHOTOSHOP_FOLDER)/tool_selection.cpp \
	$(PHOTOSHOP_FOLDER)/tool_selection_action.cpp \
	$(PHOTOSHOP_FOLDER)/filter_applying.cpp \
	$(PHOTOSHOP_FOLDER)/filter_applying_action.cpp \
	$(PHOTOSHOP_FOLDER)/menu.cpp \
	$(PHOTOSHOP_FOLDER)/menu_entry.cpp \
	$(PHOTOSHOP_FOLDER)/file_menu_entry.cpp \
\
	-o $(default_path) \
	$(sdl_flags) $(flags_standart_version) \
	$(windows_dialogs_flags) \
	-lstdc++ -O0 \
	-fmessage-length=60 \
	-fcompare-debug-second \
	-I $(SRC_FOLDER) \
	-I $(PLUGIN_STANDART_FOLDER) \
	-I C:/Users/hramz_3vliuy6/Desktop/lib/SDL2/include/SDL2


pencil:

	$(sc) $(cc) \
	$(PLUGINS_FOLDER)/pencil.cpp \
\
	$(TOOLS_FOLDER)/tool.cpp \
	$(PLUGIN_DATA_FOLDER)/plugin_data.cpp \
\
	-shared \
\
	-o dll/pencil.dll \
	$(flags_standart_version) \
	-lstdc++ -O0 \
	-fmessage-length=60 \
	-fcompare-debug-second \
	-I $(SRC_FOLDER) \
	-I $(PLUGIN_STANDART_FOLDER) \

monochrome:

	$(sc) $(cc) \
	$(PLUGINS_FOLDER)/monochrome.cpp \
\
	$(FILTERS_FOLDER)/filter.cpp \
	$(PLUGIN_DATA_FOLDER)/plugin_data.cpp \
\
	-shared \
\
	-o dll/monochrome.dll \
	$(flags_standart_version) \
	-lstdc++ -O0 \
	-fmessage-length=60 \
	-fcompare-debug-second \
	-I $(SRC_FOLDER) \
	-I $(PLUGIN_STANDART_FOLDER) \