# ----------------------------
# Program Options
# ----------------------------

NAME         ?= SCRNSVR
ICON         ?= icon.png
DESCRIPTION  ?= "CC26"
COMPRESSED   ?= YES
ARCHIVED     ?= NO

# ----------------------------

CFLAGS ?= -Wall -Wextra -Oz
CXXFLAGS ?= -Wall -Wextra -Oz

# ----------------------------

ifndef CEDEV
$(error CEDEV environment path variable is not set)
endif

include $(CEDEV)/meta/makefile.mk

