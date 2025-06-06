﻿# Copyright 1994-2022 The MathWorks, Inc.
#
#
# Abstract:
#       Template makefile for building a Windows-based stand-alone embedded
#       real-time version of Simulink model using generated C code and the
#          Microsoft Visual C/C++ compiler for x64.
#
#       Note that this template is automatically customized by the build 
#       procedure to create "<model>.mk"
#
#       The following defines can be used to modify the behavior of the
#       build:
#         OPT_OPTS       - Optimization option. See DEFAULT_OPT_OPTS in
#                          vctools.mak for default.
#         OPTS           - User specific options.
#         CPP_OPTS       - C++ compiler options.
#         USER_SRCS      - Additional user sources, such as files needed by
#                          S-functions.
#         USER_INCLUDES  - Additional include paths
#                          (i.e. USER_INCLUDES="-Iwhere-ever -Iwhere-ever2")
#
#       To enable debugging:
#         set DEBUG_BUILD = 1, which will trigger OPTS=-Zi (may vary with
#                               compiler version, see compiler doc) 
#
#       This template makefile is designed to be used with a system target
#       file that contains 'rtwgensettings.BuildDirSuffix' see ert.tlc


#------------------------ Macros read by make_rtw -----------------------------
#
# The following macros are read by the build procedure:
#
#  MAKECMD         - This is the command used to invoke the make utility
#  HOST            - What platform this template makefile is targeted for
#                    (i.e. PC or UNIX)
#  BUILD           - Invoke make from the build procedure (yes/no)?
#  SYS_TARGET_FILE - Name of system target file.

MAKECMD         = nmake
HOST            = PC
BUILD           = yes
SYS_TARGET_FILE = any
BUILD_SUCCESS	= ^#^#^# Created

# Opt in to simplified format by specifying compatible Toolchain
TOOLCHAIN_NAME = [\
    "Microsoft Visual C++ 2022 v17.0 | nmake (64-bit Windows)", \
    "Microsoft Visual C++ 2019 v16.0 | nmake (64-bit Windows)", \
    "Microsoft Visual C++ 2017 v15.0 | nmake (64-bit Windows)"]

#---------------------- Tokens expanded by make_rtw ---------------------------
#
# The following tokens, when wrapped with "|>" and "<|" are expanded by the
# build procedure.
#
#  MODEL_NAME          - Name of the Simulink block diagram
#  MODEL_MODULES       - Any additional generated source modules
#  MAKEFILE_NAME       - Name of makefile created from template makefile <model>.mk
#  MATLAB_ROOT         - Path to where MATLAB is installed.
#  S_FUNCTIONS_LIB     - List of S-functions libraries to link.
#  NUMST               - Number of sample times
#  NCSTATES            - Number of continuous states
#  BUILDARGS           - Options passed in at the command line.
#  MULTITASKING        - yes (1) or no (0): Is solver mode multitasking
#  INTEGER_CODE        - yes (1) or no (0): Is generated code purely integer
#  MAT_FILE            - yes (1) or no (0): Should mat file logging be done,
#                        if 0, the generated code runs indefinitely
#  MULTI_INSTANCE_CODE - Is the generated code multi instantiable (1/0)?
#  MODELREFS           - List of referenced models
#  SHRLIBTARGET        - Is this build intended for generation of a shared library instead 
#                        of executable (1/0)?
#  MAKEFILEBUILDER_TGT - Is this build performed by the MakefileBuilder class
#                        e.g. to create a PIL executable?
#  STANDALONE_SUPPRESS_EXE - Build the standalone target but only create object code modules 
#                            and do not build an executable

MODEL                   = mcb_host_model_f28069m
MODULES                 = coder_posix_time.c mcb_host_model_f28069m.c mcb_host_model_f28069m_capi.c mcb_host_model_f28069m_data.c mcb_host_model_f28069m_tgtconn.c rtGetInf.c rtGetNaN.c rt_nonfinite.c raccel_main.c raccel_sup.c raccel_mat.c simulink_solver_api.c raccel_utils.c slsa_sim_common_utils.c ext_svr.c updown.c ext_work.c rtiostream_interface.c rtiostream_tcpip.c rtiostream_utils.c
PRODUCT                 = mcb_host_model_f28069m.exe
MAKEFILE                = mcb_host_model_f28069m.mk
MATLAB_ROOT             = C:\Program Files\MATLAB\R2023b
ALT_MATLAB_ROOT         = C:\PROGRA~1\MATLAB\R2023b
START_DIR               = E:\GiaotrinhDH\DATN\exampleSixStep
S_FUNCTIONS_LIB         = $(MATLAB_ROOT)\extern\lib\win64\microsoft\asynciocoder.lib
NUMST                   = 1
NCSTATES                = 0
BUILDARGS               =  RSIM_SOLVER_SELECTION=1 PCMATLABROOT="C:\\Program Files\\MATLAB\\R2023b" EXTMODE_STATIC_ALLOC=0 EXTMODE_STATIC_ALLOC_SIZE=1000000 EXTMODE_TRANSPORT=0 TMW_EXTMODE_TESTING=0 RSIM_PARAMETER_LOADING=1 OPTS="-DTGTCONN -DIS_SIM_TARGET -DNRT -DRSIM_PARAMETER_LOADING -DRSIM_WITH_SL_SOLVER -DENABLE_SLEXEC_SSBRIDGE=1 -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DON_TARGET_WAIT_FOR_START=0 -DTID01EQ=0"
MULTITASKING            = 0
INTEGER_CODE            = 0
MAT_FILE                = 1
ALLOCATIONFCN           = 0
ONESTEPFCN              = 0
TERMFCN                 = 1
ENABLE_SLEXEC_SSBRIDGE  = 1
MULTI_INSTANCE_CODE     = 0
CLASSIC_INTERFACE       = 1
MODELREFS               = 
TARGET_LANG_EXT         = c
SHRLIBTARGET            = 0
MAKEFILEBUILDER_TGT     = 0
STANDALONE_SUPPRESS_EXE = 0
OPTIMIZATION_FLAGS      = /DNDEBUG /Od /Oy-
ADDITIONAL_LDFLAGS      =  -LARGEADDRESSAWARE
INTERLEAVED_COMPLEX_FLAGS = -R2018a
DEFINES_CUSTOM          = -DEXT_MODE -DIS_RAPID_ACCEL 
DEFINES_OTHER           = -DHAVESTDIO
COMPILE_FLAGS_OTHER     = 
SYSTEM_LIBS             = /LIBPATH:"C:\Program Files\MATLAB\R2023b\extern\lib\win64\microsoft" libmwipp.lib libut.lib libmx.lib libmex.lib libmat.lib libmwmathutil.lib libmwslsa_sim.lib libmwslexec_simbridge.lib libmwsl_fileio.lib libmwsigstream.lib libmwsl_AsyncioQueue.lib libmwsl_services.lib libmwsdi_raccel.lib libmwi18n.lib libmwcoder_target_services.lib libmwcoder_ParamTuningTgtAppSvc.lib libmwslpointerutil.lib libmwsl_simtarget_instrumentation.lib libfixedpoint.lib libmwslexec_simlog.lib libmwstringutil.lib
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0

# To enable debugging:
# set DEBUG_BUILD = 1
DEBUG_BUILD             = 0

#--------------------------- Model and reference models -----------------------
MODELLIB                  = 
MODELREF_LINK_LIBS        = 
MODELREF_LINK_RSPFILE     = mcb_host_model_f28069m_ref.rsp
COMPILER_COMMAND_FILE     = mcb_host_model_f28069m_comp.rsp
RELATIVE_PATH_TO_ANCHOR   = ..\..\..
MODELREF_TARGET_TYPE      = NONE

!if "$(MATLAB_ROOT)" != "$(ALT_MATLAB_ROOT)"
MATLAB_ROOT = $(ALT_MATLAB_ROOT)
!endif

#--------------------------- Tool Specifications ------------------------------
!include $(MATLAB_ROOT)\rtw\c\tools\vctools.mak

CMD_FILE             = $(MODEL).rsp

#------------------------------ Include/Lib Path ------------------------------

INCLUDE = .;$(RELATIVE_PATH_TO_ANCHOR);$(INCLUDE)

#----------------- Compiler and Linker Options --------------------------------

# Optimization Options
OPT_OPTS = $(DEFAULT_OPT_OPTS)

# General User Options
!if "$(DEBUG_BUILD)" == "0"
DBG_FLAG =
!else
#   Set OPT_OPTS=-Zi and any additional flags for debugging
DBG_FLAG = -Zi
!endif

!if "$(OPTIMIZATION_FLAGS)" != ""
CC_OPTS = $(OPTS) $(COMPILE_FLAGS_OTHER) $(OPTIMIZATION_FLAGS)
!else
CC_OPTS = $(OPTS) $(COMPILE_FLAGS_OTHER) $(OPT_OPTS) 
!endif

# Defines
CPP_REQ_DEFINES = -DMODEL=$(MODEL) -DNUMST=$(NUMST) -DNCSTATES=$(NCSTATES) \
		  -DMAT_FILE=$(MAT_FILE) -DINTEGER_CODE=$(INTEGER_CODE) \
		  -DONESTEPFCN=$(ONESTEPFCN) -DTERMFCN=$(TERMFCN) \
		  -DHAVESTDIO -DMULTI_INSTANCE_CODE=$(MULTI_INSTANCE_CODE) \
		  -DCLASSIC_INTERFACE=$(CLASSIC_INTERFACE) \
		  -DALLOCATIONFCN=$(ALLOCATIONFCN) \
		  $(DEFINES_CUSTOM) $(DEFINES_OTHER)

!if "$(MODELREF_TARGET_TYPE)" == "SIM"
!if "$(ENABLE_SLEXEC_SSBRIDGE)" != "0"
CPP_REQ_DEFINES = $(CPP_REQ_DEFINES) -DENABLE_SLEXEC_SSBRIDGE=$(ENABLE_SLEXEC_SSBRIDGE)
!endif
!else
CPP_REQ_DEFINES = $(CPP_REQ_DEFINES) -DMT=$(MULTITASKING)
!endif

CPP_REQ_DEFINES = $(CPP_REQ_DEFINES) -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=$(MODEL_HAS_DYNAMICALLY_LOADED_SFCNS)

CVARSFLAG = $(cvarsdll)

CFLAGS = $(cflags) @$(COMPILER_COMMAND_FILE) $(CVARSFLAG) \
	 -D_CRT_SECURE_NO_WARNINGS $(DBG_FLAG) $(CC_OPTS) $(CPP_REQ_DEFINES) \
	 $(USER_INCLUDES)

CPPFLAGS = $(cflags) @$(COMPILER_COMMAND_FILE) $(CVARSFLAG) \
	   -EHs -D_CRT_SECURE_NO_WARNINGS $(DBG_FLAG) $(CPP_OPTS) $(CC_OPTS) \
	   $(CPP_REQ_DEFINES) $(USER_INCLUDES)

LDFLAGS = $(ldebug) $(conflags) $(conlibs) $(ADDITIONAL_LDFLAGS)

#----------------------------- Source Files -----------------------------------

ADD_SRCS =

SRCS = $(ADD_SRCS) $(MODULES) $(USER_SRCS)

USER_SRCS =


OBJS_CPP_UPPER = $(SRCS:.CPP=.obj)
OBJS_CPP_LOWER = $(OBJS_CPP_UPPER:.cpp=.obj)
OBJS_C_UPPER = $(OBJS_CPP_LOWER:.C=.obj)
OBJS = $(OBJS_C_UPPER:.c=.obj)

#-------------------------- Additional Libraries -------------------------------

LIBS = 


LIBS = $(LIBS) $(S_FUNCTIONS_LIB)

#--------------------------------- Rules --------------------------------------
all: set_environment_variables $(PRODUCT)

!if "$(MODELREF_TARGET_TYPE)" == "NONE"
#--- Shared library target (.dll) ---
!if $(SHRLIBTARGET)==1
$(PRODUCT) : $(OBJS) $(LIBS) $(MODELREF_LINK_LIBS)
	@cmd /C "echo ### Linking ..."
	$(LD) $(LDFLAGS) $(LIBS) $(SYSTEM_LIBS) \
    @$(CMD_FILE) @$(MODELREF_LINK_RSPFILE) -dll -def:$(MODEL).def -out:$@
	@cmd /C "echo $(BUILD_SUCCESS) dynamically linked library  $(PRODUCT)"
!else
!if $(MAKEFILEBUILDER_TGT)==1
PREBUILT_SRCS  = $(MODULES)
PREBUILT_OBJS_CPP_UPPER = $(PREBUILT_SRCS:.CPP=.obj)
PREBUILT_OBJS_CPP_LOWER = $(PREBUILT_OBJS_CPP_UPPER:.cpp=.obj)
PREBUILT_OBJS_C_UPPER = $(PREBUILT_OBJS_CPP_LOWER:.C=.obj)
PREBUILT_OBJS = $(PREBUILT_OBJS_C_UPPER:.c=.obj)
$(PRODUCT) : $(PREBUILT_OBJS) $(OBJS) $(MODELLIB) $(LIBS) $(MODELREF_LINK_LIBS)
	@cmd /C "echo ### Linking ..."
	$(LD) $(LDFLAGS) $(MODELLIB) $(LIBS) $(PREBUILT_OBJS) @$(CMD_FILE) @$(MODELREF_LINK_RSPFILE) -out:$@
	@cmd /C "echo $(BUILD_SUCCESS) executable $(PRODUCT)"
!else
!if $(STANDALONE_SUPPRESS_EXE)==1
#  Build object code only for top level model
.PHONY: $(PRODUCT)
$(PRODUCT) : $(OBJS) $(LIBS)
	@cmd /C "echo $(BUILD_SUCCESS) object modules $(PRODUCT)"
!else
#--- Stand-alone model (.exe) ---
$(PRODUCT) : $(OBJS) $(LIBS) $(MODELREF_LINK_LIBS)
	@cmd /C "echo ### Linking ..."
	$(LD) $(LDFLAGS) $(LIBS) @$(CMD_FILE) @$(MODELREF_LINK_RSPFILE) $(SYSTEM_LIBS) -out:$@
	@cmd /C "echo $(BUILD_SUCCESS) executable $(PRODUCT)"
!endif
!endif
!endif
!else
#--- Library target ---
$(PRODUCT) : $(OBJS) 
	@cmd /C "echo ### Linking ..."
	$(LD) -lib /OUT:$(MODELLIB) @$(CMD_FILE)
	@cmd /C "echo  $(BUILD_SUCCESS) static library $(MODELLIB)"
!endif	


#-------------------------- Support for building modules ----------------------
{$(MATLAB_ROOT)\rtw\c\src}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\simulink\src}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\toolbox\simulink\blocks\src}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\rtw\c\src\ext_mode\common}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\toolbox\coder\rtiostream\src\rtiostreamtcpip}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\toolbox\coder\rtiostream\src\utils}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

coder_posix_time.obj : $(MATLAB_ROOT)\toolbox\eml\externalDependency\timefun\coder_posix_time.c
	@cmd /C "echo ### Compiling $(MATLAB_ROOT)\toolbox\eml\externalDependency\timefun\coder_posix_time.c
	$(CC) $(CFLAGS) $(MATLAB_ROOT)\toolbox\eml\externalDependency\timefun\coder_posix_time.c

raccel_main.obj : $(MATLAB_ROOT)\rtw\c\raccel\raccel_main.c
	@cmd /C "echo ### Compiling $(MATLAB_ROOT)\rtw\c\raccel\raccel_main.c
	$(CC) $(CFLAGS) $(MATLAB_ROOT)\rtw\c\raccel\raccel_main.c

raccel_sup.obj : $(MATLAB_ROOT)\rtw\c\raccel\raccel_sup.c
	@cmd /C "echo ### Compiling $(MATLAB_ROOT)\rtw\c\raccel\raccel_sup.c
	$(CC) $(CFLAGS) $(MATLAB_ROOT)\rtw\c\raccel\raccel_sup.c

raccel_mat.obj : $(MATLAB_ROOT)\rtw\c\raccel\raccel_mat.c
	@cmd /C "echo ### Compiling $(MATLAB_ROOT)\rtw\c\raccel\raccel_mat.c
	$(CC) $(CFLAGS) $(MATLAB_ROOT)\rtw\c\raccel\raccel_mat.c

simulink_solver_api.obj : $(MATLAB_ROOT)\simulink\include\simulink_solver_api.c
	@cmd /C "echo ### Compiling $(MATLAB_ROOT)\simulink\include\simulink_solver_api.c
	$(CC) $(CFLAGS) $(MATLAB_ROOT)\simulink\include\simulink_solver_api.c

raccel_utils.obj : $(MATLAB_ROOT)\rtw\c\src\rapid\raccel_utils.c
	@cmd /C "echo ### Compiling $(MATLAB_ROOT)\rtw\c\src\rapid\raccel_utils.c
	$(CC) $(CFLAGS) $(MATLAB_ROOT)\rtw\c\src\rapid\raccel_utils.c

slsa_sim_common_utils.obj : $(MATLAB_ROOT)\rtw\c\src\rapid\slsa_sim_common_utils.c
	@cmd /C "echo ### Compiling $(MATLAB_ROOT)\rtw\c\src\rapid\slsa_sim_common_utils.c
	$(CC) $(CFLAGS) $(MATLAB_ROOT)\rtw\c\src\rapid\slsa_sim_common_utils.c

ext_svr.obj : $(MATLAB_ROOT)\rtw\c\src\ext_mode\common\ext_svr.c
	@cmd /C "echo ### Compiling $(MATLAB_ROOT)\rtw\c\src\ext_mode\common\ext_svr.c
	$(CC) $(CFLAGS) $(MATLAB_ROOT)\rtw\c\src\ext_mode\common\ext_svr.c

updown.obj : $(MATLAB_ROOT)\rtw\c\src\ext_mode\common\updown.c
	@cmd /C "echo ### Compiling $(MATLAB_ROOT)\rtw\c\src\ext_mode\common\updown.c
	$(CC) $(CFLAGS) $(MATLAB_ROOT)\rtw\c\src\ext_mode\common\updown.c

ext_work.obj : $(MATLAB_ROOT)\rtw\c\src\ext_mode\common\ext_work.c
	@cmd /C "echo ### Compiling $(MATLAB_ROOT)\rtw\c\src\ext_mode\common\ext_work.c
	$(CC) $(CFLAGS) $(MATLAB_ROOT)\rtw\c\src\ext_mode\common\ext_work.c

rtiostream_interface.obj : $(MATLAB_ROOT)\rtw\c\src\ext_mode\common\rtiostream_interface.c
	@cmd /C "echo ### Compiling $(MATLAB_ROOT)\rtw\c\src\ext_mode\common\rtiostream_interface.c
	$(CC) $(CFLAGS) $(MATLAB_ROOT)\rtw\c\src\ext_mode\common\rtiostream_interface.c

rtiostream_tcpip.obj : $(MATLAB_ROOT)\toolbox\coder\rtiostream\src\rtiostreamtcpip\rtiostream_tcpip.c
	@cmd /C "echo ### Compiling $(MATLAB_ROOT)\toolbox\coder\rtiostream\src\rtiostreamtcpip\rtiostream_tcpip.c
	$(CC) $(CFLAGS) $(MATLAB_ROOT)\toolbox\coder\rtiostream\src\rtiostreamtcpip\rtiostream_tcpip.c

rtiostream_utils.obj : $(MATLAB_ROOT)\toolbox\coder\rtiostream\src\utils\rtiostream_utils.c
	@cmd /C "echo ### Compiling $(MATLAB_ROOT)\toolbox\coder\rtiostream\src\utils\rtiostream_utils.c
	$(CC) $(CFLAGS) $(MATLAB_ROOT)\toolbox\coder\rtiostream\src\utils\rtiostream_utils.c



{$(MATLAB_ROOT)\rtw\c\src}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\simulink\src}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\simulink\blocks\src}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\rtw\c\src\ext_mode\common}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\coder\rtiostream\src\rtiostreamtcpip}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\coder\rtiostream\src\utils}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<




# Put these rules last, otherwise nmake will check toolboxes first

{$(RELATIVE_PATH_TO_ANCHOR)}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(RELATIVE_PATH_TO_ANCHOR)}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

set_environment_variables:
	@set INCLUDE=$(INCLUDE)
	@set LIB=$(LIB)

# Libraries:






#----------------------------- Dependencies -----------------------------------

$(OBJS) : $(MAKEFILE) rtw_proj.tmw
