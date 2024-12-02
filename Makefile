# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmertane <jmertane@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/28 10:37:44 by jmertane          #+#    #+#              #
#    Updated: 2024/02/06 17:49:09 by jmertane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#    VARIABLES
# **************************************************************************** #

NAME := libft.a

SOURCEDIR := sources
HEADERDIR := include
BUILDDIR  := build
BUILDLOG  := build.log

# **************************************************************************** #
#    COMMANDS
# **************************************************************************** #

RM := rm -rf
AR := ar -rcs

# **************************************************************************** #
#    COMPILATION
# **************************************************************************** #

CC        := cc
CFLAGS    := -Wall -Werror -Wextra
CPPFLAGS  := -c -MMD -MP
MAKEFLAGS += --no-print-directory -j4

# **************************************************************************** #
#    SOURCES
# **************************************************************************** #

SOURCES := ft_isalpha.c \
           ft_isdigit.c \
           ft_isalnum.c \
           ft_isascii.c \
           ft_isprint.c \
           ft_strlen.c \
           ft_memset.c \
           ft_bzero.c \
           ft_memcpy.c \
           ft_memmove.c \
           ft_strlcpy.c \
           ft_strlcat.c \
           ft_toupper.c \
           ft_tolower.c \
           ft_strchr.c \
           ft_strrchr.c \
           ft_strncmp.c \
           ft_memchr.c \
           ft_memcmp.c \
           ft_strnstr.c \
           ft_atoi.c \
           ft_calloc.c \
           ft_strdup.c \
           ft_substr.c \
           ft_strjoin.c \
           ft_strtrim.c \
           ft_split.c \
           ft_itoa.c \
           ft_strmapi.c \
           ft_striteri.c \
           ft_putchar_fd.c \
           ft_putstr_fd.c \
           ft_putendl_fd.c \
           ft_putnbr_fd.c \
           ft_lstnew.c \
           ft_lstadd_front.c \
           ft_lstsize.c \
           ft_lstlast.c \
           ft_lstadd_back.c \
           ft_lstdelone.c \
           ft_lstclear.c \
           ft_lstiter.c \
           ft_lstmap.c \
           ft_printf.c \
           ft_printf_fmt.c \
           ft_gnl.c \
           ft_gnl_utils.c \
           ft_free_single.c \
           ft_free_double.c \
           ft_strcmp.c \
           ft_isspace.c \
           ft_issign.c

OBJECTS := $(addprefix $(BUILDDIR)/, $(SOURCES:.c=.o))

INCS := $(addprefix -I, $(HEADERDIR))

DEPS := $(OBJECTS:.o=.d)

vpath %.c $(SOURCEDIR)

# **************************************************************************** #
#    RULES
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(AR) $(NAME) $^
	printf "$(V)$(B)Binary:$(T)$(Y) $(NAME) $(T)\n"

re: fclean
	make all

# **************************************************************************** #
#    BUILD
# **************************************************************************** #

define build_cmd
$1/%.o: %.c | $(BUILDDIR)
	if ! $(CC) $(CFLAGS) $(CPPFLAGS) $(INCS) $$< -o $$@ 2> $(BUILDLOG); then \
		printf "$(R)$(B)\nError: \
		$(V)Unable to create object file: \
		$(R)$(B)$$@$(Y)\n\n"; \
		sed '$$d' $(BUILDLOG); exit 1 ; \
	else \
		printf "$(C)$(B)Object: $(G)$$@ $(T)\n"; \
	fi
endef

# **************************************************************************** #
#    CLEAN
# **************************************************************************** #

clean:
	$(call delete_cmd, $(BUILDDIR), $(BUILDLOG))

fclean: clean
	$(call delete_cmd, $(NAME))

define delete_cmd
	printf "$(R)$(B)Delete:$(T)$(Y)$1$2$3$4$5$(T)\n"
	$(RM) $1 $2 $3 $4 $5
endef

# **************************************************************************** #
#    COLORS
# **************************************************************************** #

T = \033[0m
B = \033[1m
G = \033[32m
V = \033[35m
C = \033[36m
Y = \033[33m
R = \033[31m

# **************************************************************************** #
#    UTILS
# **************************************************************************** #

-include $(DEPS)

$(BUILDDIR):
	mkdir -p $@

$(foreach build, $(BUILDDIR), $(eval $(call build_cmd, $(build))))

# **************************************************************************** #
#    PHONY
# **************************************************************************** #

.PHONY: all bonus re
.PHONY: clean fclean

.SILENT:
