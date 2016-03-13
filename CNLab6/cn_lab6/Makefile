#
# OMNeT++/OMNEST Makefile for cn_lab6
#
# This file was generated with the command:
#  opp_makemake -f --deep -O out
#

# Name of target to be created (-o option)
TARGET = cn_lab6$(EXE_SUFFIX)

# User interface (uncomment one) (-u option)
USERIF_LIBS = $(ALL_ENV_LIBS) # that is, $(TKENV_LIBS) $(CMDENV_LIBS)
#USERIF_LIBS = $(CMDENV_LIBS)
#USERIF_LIBS = $(TKENV_LIBS)

# C++ include paths (with -I)
INCLUDE_PATH = -I. -Iresults

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS =

# Output directory
PROJECT_OUTPUT_DIR = out
PROJECTRELATIVE_PATH =
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc and .msg files
OBJS = \
    $O/nwlayerA.o \
    $O/alayer.o \
    $O/nwlayerD.o \
    $O/nwlayerB.o \
    $O/player.o \
    $O/nwlayerC.o \
    $O/dllayer.o \
    $O/nwlayerE.o \
    $O/A_PDU_m.o \
    $O/MyData_m.o \
    $O/Ack_m.o \
    $O/NW_PDU_m.o \
    $O/P_PDU_m.o \
    $O/DL_PDU_m.o

# Message files
MSGFILES = \
    A_PDU.msg \
    MyData.msg \
    Ack.msg \
    NW_PDU.msg \
    P_PDU.msg \
    DL_PDU.msg

#------------------------------------------------------------------------------

# Pull in OMNeT++ configuration (Makefile.inc or configuser.vc)

ifneq ("$(OMNETPP_CONFIGFILE)","")
CONFIGFILE = $(OMNETPP_CONFIGFILE)
else
ifneq ("$(OMNETPP_ROOT)","")
CONFIGFILE = $(OMNETPP_ROOT)/Makefile.inc
else
CONFIGFILE = $(shell opp_configfilepath)
endif
endif

ifeq ("$(wildcard $(CONFIGFILE))","")
$(error Config file '$(CONFIGFILE)' does not exist -- add the OMNeT++ bin directory to the path so that opp_configfilepath can be found, or set the OMNETPP_CONFIGFILE variable to point to Makefile.inc)
endif

include $(CONFIGFILE)

# Simulation kernel and user interface libraries
OMNETPP_LIB_SUBDIR = $(OMNETPP_LIB_DIR)/$(TOOLCHAIN_NAME)
OMNETPP_LIBS = -L"$(OMNETPP_LIB_SUBDIR)" -L"$(OMNETPP_LIB_DIR)" -loppmain$D $(USERIF_LIBS) $(KERNEL_LIBS) $(SYS_LIBS)

COPTS = $(CFLAGS)  $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
MSGCOPTS = $(INCLUDE_PATH)

# we want to recompile everything if COPTS changes,
# so we store COPTS into $COPTS_FILE and have object
# files depend on it (except when "make depend" was called)
COPTS_FILE = $O/.last-copts
ifneq ($(MAKECMDGOALS),depend)
ifneq ("$(COPTS)","$(shell cat $(COPTS_FILE) 2>/dev/null || echo '')")
$(shell $(MKPATH) "$O" && echo "$(COPTS)" >$(COPTS_FILE))
endif
endif

#------------------------------------------------------------------------------
# User-supplied makefile fragment(s)
# >>>
# <<<
#------------------------------------------------------------------------------

# Main target
all: $O/$(TARGET)
	$(Q)$(LN) $O/$(TARGET) .

$O/$(TARGET): $(OBJS)  $(wildcard $(EXTRA_OBJS)) Makefile
	@$(MKPATH) $O
	@echo Creating executable: $@
	$(Q)$(CXX) $(LDFLAGS) -o $O/$(TARGET)  $(OBJS) $(EXTRA_OBJS) $(AS_NEEDED_OFF) $(WHOLE_ARCHIVE_ON) $(LIBS) $(WHOLE_ARCHIVE_OFF) $(OMNETPP_LIBS)

.PHONY: all clean cleanall depend msgheaders

.SUFFIXES: .cc

$O/%.o: %.cc $(COPTS_FILE)
	@$(MKPATH) $(dir $@)
	$(qecho) "$<"
	$(Q)$(CXX) -c $(CXXFLAGS) $(COPTS) -o $@ $<

%_m.cc %_m.h: %.msg
	$(qecho) MSGC: $<
	$(Q)$(MSGC) -s _m.cc $(MSGCOPTS) $?

msgheaders: $(MSGFILES:.msg=_m.h)

clean:
	$(qecho) Cleaning...
	$(Q)-rm -rf $O
	$(Q)-rm -f cn_lab6 cn_lab6.exe libcn_lab6.so libcn_lab6.a libcn_lab6.dll libcn_lab6.dylib
	$(Q)-rm -f ./*_m.cc ./*_m.h
	$(Q)-rm -f results/*_m.cc results/*_m.h

cleanall: clean
	$(Q)-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(qecho) Creating dependencies...
	$(Q)$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES)  ./*.cc results/*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/A_PDU_m.o: A_PDU_m.cc \
	A_PDU_m.h
$O/Ack_m.o: Ack_m.cc \
	Ack_m.h
$O/DL_PDU_m.o: DL_PDU_m.cc \
	DL_PDU_m.h
$O/MyData_m.o: MyData_m.cc \
	MyData_m.h
$O/NW_PDU_m.o: NW_PDU_m.cc \
	NW_PDU_m.h
$O/P_PDU_m.o: P_PDU_m.cc \
	P_PDU_m.h
$O/alayer.o: alayer.cc \
	A_PDU_m.h \
	Ack_m.h \
	DL_PDU_m.h \
	MyData_m.h \
	alayer.h
$O/dllayer.o: dllayer.cc \
	Ack_m.h \
	DL_PDU_m.h \
	NW_PDU_m.h \
	P_PDU_m.h \
	dllayer.h
$O/nwlayerA.o: nwlayerA.cc \
	A_PDU_m.h \
	NW_PDU_m.h \
	nwlayerA.h
$O/nwlayerB.o: nwlayerB.cc \
	A_PDU_m.h \
	NW_PDU_m.h \
	nwlayerB.h
$O/nwlayerC.o: nwlayerC.cc \
	A_PDU_m.h \
	NW_PDU_m.h \
	nwlayerC.h
$O/nwlayerD.o: nwlayerD.cc \
	A_PDU_m.h \
	NW_PDU_m.h \
	nwlayerD.h
$O/nwlayerE.o: nwlayerE.cc \
	A_PDU_m.h \
	NW_PDU_m.h \
	nwlayerE.h
$O/player.o: player.cc \
	DL_PDU_m.h \
	P_PDU_m.h \
	player.h

