### Names & Paths ###
LIBFT		= libft.a
LIBFT_PATH	= ../libft
EXEC		= a.out

### Commands & Flags ###
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
INCS	= -I .


##@ General

.PHONY: help
help: 			## Show help
	@awk 'BEGIN {FS = ":.*##"; printf "\nUsage:\n  make $(GRN)<target>$(NC)\n"} /^[a-zA-Z_0-9-]+:.*?##/ { printf "  $(GRN)%-15s$(NC) %s\n", $$1, $$2 } /^##@/ { printf "\n$(NC)%s$(GRN)\n", substr($$0, 5) } ' Makefile

##@ Compilation Rules 🏗

.PHONY: all
all: $(LIBFT)	## Compile executable with libft

$(LIBFT):
	@echo "\t$(YEL)Compiling libft$(NC)"
	make -C $(LIBFT_PATH) extra
	cp $(LIBFT_PATH)/libft.a $(LIBFT)
	@echo "\t$(YEL)Compiling executable$(NC)"
	$(CC) $(CFLAGS) $(INCS) main.c $(LIBFT) -o $(EXEC)
	@echo "\t$(GRN)Done!$(NC)"

##@ Clean-up Rules 󰃢

.PHONY: clean
clean:			## Remove object files
	$(RM)
	make -C $(LIBFT_PATH) clean

.PHONY: fclean
fclean: clean	## Remove executable and object files
	@echo "\t$(RED)Removing executable and libft 󰃢$(NC)"
	make -C $(LIBFT_PATH) fclean
	$(RM) $(LIBFT)
	@echo "\t$(GRN)Done! 🖔$(NC)"

.PHONY: re
re: fclean all


### ANSI Color Codes ###

# Regular text
BLK = \033[0;30m
RED = \033[0;31m
GRN = \033[0;32m
YEL = \033[0;33m
BLU = \033[0;34m
MAG = \033[0;35m
CYN = \033[0;36m
WHT = \033[0;37m

# Regular bold text
BBLK = \033[1;30m
BRED = \033[1;31m
BGRN = \033[1;32m
BYEL = \033[1;33m
BBLU = \033[1;34m
BMAG = \033[1;35m
BCYN = \033[1;36m
BWHT = \033[1;37m

# Regular underline text
UBLK = \033[4;30m
URED = \033[4;31m
UGRN = \033[4;32m
UYEL = \033[4;33m
UBLU = \033[4;34m
UMAG = \033[4;35m
UCYN = \033[4;36m
UWHT = \033[4;37m

# Regular background
BLKB = \033[40m
REDB = \033[41m
GRNB = \033[42m
YELB = \033[43m
BLUB = \033[44m
MAGB = \033[45m
CYNB = \033[46m
WHTB = \033[47m

# High intensity background 
BLKHB = \033[0;100m
REDHB = \033[0;101m
GRNHB = \033[0;102m
YELHB = \033[0;103m
BLUHB = \033[0;104m
MAGHB = \033[0;105m
CYNHB = \033[0;106m
WHTHB = \033[0;107m

# High intensity text
HBLK = \033[0;90m
HRED = \033[0;91m
HGRN = \033[0;92m
HYEL = \033[0;93m
HBLU = \033[0;94m
HMAG = \033[0;95m
HCYN = \033[0;96m
HWHT = \033[0;97m

# Bold high intensity text
BHBLK = \033[1;90m
BHRED = \033[1;91m
BHGRN = \033[1;92m
BHYEL = \033[1;93m
BHBLU = \033[1;94m
BHMAG = \033[1;95m
BHCYN = \033[1;96m
BHWHT = \033[1;97m

# Reset
NC=\033[0m

