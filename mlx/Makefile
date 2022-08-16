#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2
.SILENT:

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11

SAVE = "\033[s"
CUT = "\033[K"
GREEN = "\033[32m"
RESET = "\033[0m"
UP = "\033[A"

all: $(NOM)

$(NOM):	$(OBJ)
	@ar -cr $(NOM) $(OBJ)
	@ranlib $(NOM)
	@echo $(SAVE)$(CUT)$(GREEN) Compiling with $(CFLAGS)...$(RESET)
	@echo $(CUT) $(GREEN)[$^] to [$@] $(RESET)
	@printf $(UP)$(UP)

clean:
	rm -f $(NOM) $(OBJ) *~
	rm -f mlx_app

re: clean all
