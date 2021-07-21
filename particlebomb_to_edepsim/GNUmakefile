#
# This is an example GNUmakefile for my packages
#
NAME = particlebomb_to_edepsim

# specific names for this package
SOURCES = $(wildcard *.cxx)
FMWK_HEADERS = LinkDef.h
HEADERS = $(filter-out $(FMWK_HEADERS), $(wildcard *.h))

G4_INCDIR=/app/geant4/include/Geant4
G4_LIBDIR=/app/geant4/lib/
EDEP_SRCDIR=~/edep-sim/src/

# include options for this package
INCFLAGS  = -I. \
			-I $(EDEP_ROOT) \
			-I $(DLPGENERATOR_INCDIR) \
			-I $(LARCV_INCDIR) \
			-I $(G4_INCDIR) \
			-I $(EDEP_SRCDIR)

LDDFLAGS = -L. \
		   -L $(EDEP_ROOT) \
		   -L $(DLPGENERATOR_LIBDIR) \
		   -L $(LARCV_LIBDIR) \
		   -L $(LD_LIBRARY_PATH) \
		   -L $(G4_LIBDIR)

# platform-specific options
OSNAME          = $(shell uname -s)
HOST            = $(shell uname -n)
OSNAMEMODE      = $(OSNAME)

# call kernel specific compiler setup
include $(MYSW_DIR)/Makefile/Makefile.${OSNAME}

# call the common GNUmakefile
include $(MYSW_DIR)/Makefile/GNUmakefile.CORE
