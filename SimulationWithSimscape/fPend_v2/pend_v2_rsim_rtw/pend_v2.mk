# Copyright 1994-2010 The MathWorks, Inc.
#
# File    : rsim_vcx64.tmf   $Revision: 1.1.6.24 $
#
# Abstract:
#       Template makefile for building a PC-based "rapid simulation" executable 
#       from the generated C code for a Simulink model using generated C code 
#       and the
#               Microsoft Visual C/C++ compiler version 8.0 for x64
#
#       Note that this template is automatically customized by the build 
#       procedure to create "<model>.mk"
#
#       The following defines can be used to modify the behavior of the
#       build:
#
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
#       file that contains 'rtwgensettings.BuildDirSuffix' see rsim.tlc

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
SYS_TARGET_FILE = rsim.tlc
BUILD_SUCCESS	= ^#^#^# Created
COMPILER_TOOL_CHAIN = vcx64

#---------------------- Tokens expanded by make_rtw ---------------------------
#
# The following tokens, when wrapped with "|>" and "<|" are expanded by the
# build procedure.
#
#  MODEL_NAME          - Name of the Simulink block diagram
#  MODEL_MODULES       - Any additional generated source modules
#  MAKEFILE_NAME       - Name of makefile created from template makefile <model>.mk
#  MATLAB_ROOT         - Path to where MATLAB is installed.
#  MATLAB_BIN          - Path to MATLAB executable.
#  S_FUNCTIONS         - List of S-functions.
#  S_FUNCTIONS_LIB     - List of S-functions libraries to link.
#  BUILDARGS           - Options passed in at the command line.
#  EXT_MODE            - yes (1) or no (0): Build for external mode
#  TMW_EXTMODE_TESTING - yes (1) or no (0): Build ext_test.c for external mode
#                        testing.
#  EXTMODE_TRANSPORT   - Name of transport mechanism (e.g. tcpip, serial) for extmode
#  EXTMODE_STATIC      - yes (1) or no (0): Use static instead of dynamic mem alloc.
#  EXTMODE_STATIC_SIZE - Size of static memory allocation buffer.

MODEL                  = pend_v2
MODULES                = pend_v2_9701bd64_1.c pend_v2_9701bd64_1_create.c pend_v2_9701bd64_1_deriv.c pend_v2_9701bd64_1_output.c pend_v2_9701bd64_1_project.c pend_v2_data.c rtGetInf.c rtGetNaN.c rt_backsubrr_dbl.c rt_forwardsubrr_dbl.c rt_logging.c rt_lu_real.c rt_matrixlib_dbl.c rt_nonfinite.c 
MAKEFILE               = pend_v2.mk
MATLAB_ROOT            = C:\Program Files\MATLAB\R2013a
ALT_MATLAB_ROOT        = C:\PROGRA~1\MATLAB\R2013a
MATLAB_BIN             = C:\Program Files\MATLAB\R2013a\bin
ALT_MATLAB_BIN         = C:\PROGRA~1\MATLAB\R2013a\bin
MASTER_ANCHOR_DIR      = 
START_DIR              = C:\Users\Connie\Desktop\3dAnimation\fPend_v2
S_FUNCTIONS            = 
S_FUNCTIONS_LIB        = 
BUILDARGS              = 
RSIM_PARAMETER_LOADING = 1
VISUAL_VER             = 11.0

EXT_MODE            = 0
TMW_EXTMODE_TESTING = 0
EXTMODE_TRANSPORT   = 0
EXTMODE_STATIC      = 0
EXTMODE_STATIC_SIZE = 1000000

SOLVER              = ode45.c
SOLVER_TYPE         = VariableStep
NUMST               = 2
TID01EQ             = 0
NCSTATES            = 4
MULTITASKING        = 0
PCMATLABROOT        = C:\\Program Files\\MATLAB\\R2013a

RSIM_SOLVER_SELECTION = 1


MODELREFS            = 
SHARED_SRC           = 
SHARED_SRC_DIR       = 
SHARED_BIN_DIR       = 
SHARED_LIB           = 
GEN_SAMPLE_MAIN      = 0
OPTIMIZATION_FLAGS   = /Od /Oy-
ADDITIONAL_LDFLAGS   = 
TARGET_LANG_EXT      = c

# To enable debugging:
# set DEBUG_BUILD = 1
DEBUG_BUILD             = 0

#--------------------------- Model and reference models -----------------------
MODELLIB                  = pend_v2lib.lib
MODELREF_LINK_LIBS        = 
MODELREF_LINK_RSPFILE     = pend_v2_ref.rsp
MODELREF_INC_PATH         = 
RELATIVE_PATH_TO_ANCHOR   = ..
MODELREF_TARGET_TYPE      = NONE

GLOBAL_TIMING_ENGINE       = 0

!if "$(MATLAB_ROOT)" != "$(ALT_MATLAB_ROOT)"
MATLAB_ROOT = $(ALT_MATLAB_ROOT)
!endif
!if "$(MATLAB_BIN)" != "$(ALT_MATLAB_BIN)"
MATLAB_BIN = $(ALT_MATLAB_BIN)
!endif

#---------------------------Solver---------------------------------------------

RSIM_WITH_SL_SOLVER = 0

!if $(RSIM_SOLVER_SELECTION) == 1
!if "$(SOLVER_TYPE)" == "VariableStep"
RSIM_WITH_SL_SOLVER = 1
!endif
!if $(GLOBAL_TIMING_ENGINE) == 1
RSIM_WITH_SL_SOLVER = 1
!endif
!endif

!if $(RSIM_SOLVER_SELECTION) == 2
RSIM_WITH_SL_SOLVER = 1
!endif

#--------------------------- Tool Specifications ------------------------------

CPU = AMD64
!include $(MATLAB_ROOT)\rtw\c\tools\vctools.mak
APPVER = 5.02

PERL = $(MATLAB_ROOT)\sys\perl\win32\bin\perl

#------------------------------ Include Path ----------------------------------

MATLAB_INCLUDES =                    $(MATLAB_ROOT)\simulink\include
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\extern\include
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\rtw\c\src
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\rtw\c\src\rapid
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\rtw\c\rsim
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\rtw\c\src\ext_mode\common

# Additional includes

MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(START_DIR)\pend_v2_rsim_rtw

MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(START_DIR)

MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\toolbox\physmod\sm\ssci\c

MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\toolbox\physmod\sm\core\c

MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\toolbox\physmod\pm_math\c

MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\toolbox\physmod\simscape\engine\sli\c

MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\toolbox\physmod\simscape\engine\core\c

MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\toolbox\physmod\simscape\compiler\core\c

MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\toolbox\physmod\network_engine\c

MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\toolbox\physmod\common\foundation\core\c


INCLUDE = .;$(RELATIVE_PATH_TO_ANCHOR);$(MATLAB_INCLUDES);$(INCLUDE)

!if "$(SHARED_SRC_DIR)" != ""
INCLUDE = $(INCLUDE);$(SHARED_SRC_DIR)
!endif

#------------------------ External mode ---------------------------------------
# Uncomment -DVERBOSE to have information printed to stdout
# To add a new transport layer, see the comments in
#   <matlabroot>/toolbox/simulink/simulink/extmode_transports.m
!if $(EXT_MODE) == 1
EXT_CC_OPTS = -DEXT_MODE # -DVERBOSE
!if $(EXTMODE_TRANSPORT) == 0 #tcpip
EXT_SRC = ext_svr.c updown.c ext_work.c rtiostream_interface.c rtiostream_tcpip.c
EXT_LIB = wsock32.lib
!endif
!if $(EXTMODE_TRANSPORT) == 1 #serial_win32
EXT_SRC = ext_svr.c updown.c ext_work.c ext_svr_serial_transport.c
EXT_SRC = $(EXT_SRC) ext_serial_pkt.c rtiostream_serial_interface.c rtiostream_serial.c
EXT_LIB =
!endif
!if $(TMW_EXTMODE_TESTING) == 1
EXT_SRC     = $(EXT_SRC) ext_test.c
EXT_CC_OPTS = $(EXT_CC_OPTS) -DTMW_EXTMODE_TESTING
!endif
!if $(EXTMODE_STATIC) == 1
EXT_SRC     = $(EXT_SRC) mem_mgr.c
EXT_CC_OPTS = $(EXT_CC_OPTS) -DEXTMODE_STATIC -DEXTMODE_STATIC_SIZE=$(EXTMODE_STATIC_SIZE)
!endif
!else
EXT_SRC     =
EXT_CC_OPTS =
EXT_LIB     =
!endif

#------------------------------ Parameter Tuning ------------------------------
!if $(RSIM_PARAMETER_LOADING) == 1
PARAM_CC_OPTS = -DRSIM_PARAMETER_LOADING
!endif
!if $(EXT_MODE) == 1
PARAM_CC_OPTS = -DRSIM_PARAMETER_LOADING
!endif

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
CC_OPTS = $(OPTS) $(EXT_CC_OPTS) $(OPTIMIZATION_FLAGS)
!else
CC_OPTS = $(OPT_OPTS) $(OPTS) $(EXT_CC_OPTS)
!endif


CPP_REQ_DEFINES = -DMODEL=$(MODEL) -DHAVESTDIO
!if "$(RSIM_WITH_SL_SOLVER)" == "1"
CPP_REQ_DEFINES = $(CPP_REQ_DEFINES) \
                  -DNRT -DRSIM_WITH_SL_SOLVER
!if "$(MULTITASKING)" == "1"
CPP_REQ_DEFINES = $(CPP_REQ_DEFINES) -DRSIM_WITH_SOLVER_MULTITASKING -DNUMST=$(NUMST)\
	           -DTID01EQ=$(TID01EQ)	
!endif

!else
CPP_REQ_DEFINES = $(CPP_REQ_DEFINES) -DRT -DNUMST=$(NUMST) \
                  -DTID01EQ=$(TID01EQ) -DNCSTATES=$(NCSTATES)\
                  -DMT=$(MULTITASKING)
!endif

# Uncomment this line to move warning level to W4
# cflags = $(cflags:W3=W4)
CFLAGS   = $(MODELREF_INC_PATH) $(cflags) $(cvarsmt) $(PARAM_CC_OPTS) /wd4996 \
	   $(DBG_FLAG) $(CC_OPTS) $(CPP_REQ_DEFINES) $(USER_INCLUDES)
CPPFLAGS = $(MODELREF_INC_PATH) $(cflags) $(cvarsmt) $(PARAM_CC_OPTS) \
	   /wd4996 /EHsc- $(DBG_FLAG) $(CPP_OPTS) $(CC_OPTS) $(CPP_REQ_DEFINES) \
	   $(USER_INCLUDES)
LDFLAGS  = $(ldebug) $(conflags) $(EXT_LIB) $(conlibs) $(ADDITIONAL_LDFLAGS)

#----------------------------- Source Files -----------------------------------

#Standalone executable
!if "$(MODELREF_TARGET_TYPE)" == "NONE"
PRODUCT   = $(RELATIVE_PATH_TO_ANCHOR)\$(MODEL).exe	

REQ_SRCS  = $(MODEL).c $(MODULES) \
            rsim_main.c rsim_sup.c rsim_mat.c simulink_solver_api.c rapid_utils.c \
            $(EXT_SRC)

!if "$(RSIM_WITH_SL_SOLVER)" == "0"
REQ_SRCS = $(REQ_SRCS) rt_sim.c $(SOLVER)
!endif
#Model Reference Target
!else
PRODUCT   = $(MODELLIB)
REQ_SRCS  = $(MODULES)
!endif

USER_SRCS =

SRCS = $(REQ_SRCS) $(USER_SRCS) $(S_FUNCTIONS)
OBJS_CPP_UPPER = $(SRCS:.CPP=.obj)
OBJS_CPP_LOWER = $(OBJS_CPP_UPPER:.cpp=.obj)
OBJS_C_UPPER = $(OBJS_CPP_LOWER:.C=.obj)
OBJS = $(OBJS_C_UPPER:.c=.obj)
SHARED_OBJS = $(SHARED_SRC:.c=.obj)

#--------------------------- Required Libraries -------------------------------

MAT_LIBS = $(MATLAB_ROOT)\extern\lib\win64\microsoft\libut.lib \
           $(MATLAB_ROOT)\extern\lib\win64\microsoft\libmx.lib \
           $(MATLAB_ROOT)\extern\lib\win64\microsoft\libmat.lib \
           $(MATLAB_ROOT)\extern\lib\win64\microsoft\libmwsl_fileio.lib

!if "$(RSIM_WITH_SL_SOLVER)" == "1"
MAT_LIBS = $(MAT_LIBS) $(MATLAB_ROOT)\extern\lib\win64\microsoft\libmwsl_solver_rtw.lib
!endif

# ------------------------- Additional Libraries ------------------------------

LIBS =

!if "$(OPT_OPTS)" == "$(DEFAULT_OPT_OPTS)"
LIBS = $(LIBS) $(MATLAB_ROOT)\toolbox\physmod\sm\ssci\lib\win64\sm_ssci_vcx64.lib
!else
LIBS = $(LIBS) sm_ssci.lib
!endif

!if "$(OPT_OPTS)" == "$(DEFAULT_OPT_OPTS)"
LIBS = $(LIBS) $(MATLAB_ROOT)\toolbox\physmod\sm\core\lib\win64\sm_vcx64.lib
!else
LIBS = $(LIBS) sm.lib
!endif

!if "$(OPT_OPTS)" == "$(DEFAULT_OPT_OPTS)"
LIBS = $(LIBS) $(MATLAB_ROOT)\toolbox\physmod\pm_math\lib\win64\pm_math_vcx64.lib
!else
LIBS = $(LIBS) pm_math.lib
!endif

!if "$(OPT_OPTS)" == "$(DEFAULT_OPT_OPTS)"
LIBS = $(LIBS) $(MATLAB_ROOT)\toolbox\physmod\simscape\engine\sli\lib\win64\ssc_sli_vcx64.lib
!else
LIBS = $(LIBS) ssc_sli.lib
!endif

!if "$(OPT_OPTS)" == "$(DEFAULT_OPT_OPTS)"
LIBS = $(LIBS) $(MATLAB_ROOT)\toolbox\physmod\simscape\engine\core\lib\win64\ssc_core_vcx64.lib
!else
LIBS = $(LIBS) ssc_core.lib
!endif

!if "$(OPT_OPTS)" == "$(DEFAULT_OPT_OPTS)"
LIBS = $(LIBS) $(MATLAB_ROOT)\toolbox\physmod\network_engine\lib\win64\ne_vcx64.lib
!else
LIBS = $(LIBS) ne.lib
!endif

!if "$(OPT_OPTS)" == "$(DEFAULT_OPT_OPTS)"
LIBS = $(LIBS) $(MATLAB_ROOT)\toolbox\physmod\common\foundation\core\lib\win64\pm_vcx64.lib
!else
LIBS = $(LIBS) pm.lib
!endif


LIBS = $(LIBS)

# ---------------------------- Linker Script ----------------------------------

CMD_FILE = $(MODEL).lnk
GEN_LNK_SCRIPT = $(MATLAB_ROOT)\rtw\c\tools\mkvc_lnk.pl

#--------------------------------- Rules --------------------------------------
all: set_environment_variables $(PRODUCT)

!if "$(MODELREF_TARGET_TYPE)" == "NONE"
#--- Stand-alone model ---
$(PRODUCT) : $(OBJS) $(SHARED_LIB) $(LIBS) $(MODELREF_LINK_LIBS)
	@cmd /C "echo ### Linking ..."
	$(PERL) $(GEN_LNK_SCRIPT) $(CMD_FILE) $(OBJS)
	$(LD) $(LDFLAGS) $(S_FUNCTIONS_LIB) $(SHARED_LIB) $(LIBS) $(MAT_LIBS) @$(CMD_FILE) @$(MODELREF_LINK_RSPFILE) -out:$@
	@del $(CMD_FILE)
	@cmd /C "echo $(BUILD_SUCCESS) executable $(MODEL).exe"
!else
#--- Model reference Coder Target ---
$(PRODUCT) : $(OBJS) $(SHARED_LIB)
	@cmd /C "echo ### Linking ..."
	$(PERL) $(GEN_LNK_SCRIPT) $(CMD_FILE) $(OBJS)
	$(LD) -lib /OUT:$(MODELLIB) @$(CMD_FILE) $(S_FUNCTIONS_LIB)
	@cmd /C "echo $(BUILD_SUCCESS) static library $(MODELLIB)"
!endif

!if $(GEN_SAMPLE_MAIN) == 0
!if "$(TARGET_LANG_EXT)" ==  "cpp"
rsim_main.obj : $(MATLAB_ROOT)\rtw\c\rsim\rsim_main.c
	@cmd /C "echo ### Compiling $(MATLAB_ROOT)\rtw\c\rsim\rsim_main.c"
	$(CC) /TP $(CPPFLAGS) $(MATLAB_ROOT)\rtw\c\rsim\rsim_main.c
!else
rsim_main.obj : $(MATLAB_ROOT)\rtw\c\rsim\rsim_main.c
	@cmd /C "echo ### Compiling $(MATLAB_ROOT)\rtw\c\rsim\rsim_main.c"
	$(CC) $(CFLAGS) $(MATLAB_ROOT)\rtw\c\rsim\rsim_main.c
!endif

{$(MATLAB_ROOT)\rtw\c\rsim}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<
!endif

{$(MATLAB_ROOT)\rtw\c\src}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\rtw\c\src\rapid}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\rtw\c\src\ext_mode\common}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\rtw\c\src\rtiostream\rtiostreamtcpip}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\rtw\c\src\ext_mode\serial}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\rtw\c\src\ext_mode\custom}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

simulink_solver_api.obj  : $(MATLAB_ROOT)\simulink\include\simulink_solver_api.c
	@cmd /C "echo ### Compiling $(MATLAB_ROOT)\rtw\c\rsim\simulink_solver_api.c"
	$(CC) $(CFLAGS) $(MATLAB_ROOT)\simulink\include\simulink_solver_api.c

# Additional sources

{$(MATLAB_ROOT)\rtw\c\src}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\simulink\src}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\toolbox\physmod\sm\ssci\c}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\toolbox\physmod\sm\core\c}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\toolbox\physmod\pm_math\c}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\toolbox\physmod\simscape\engine\sli\c}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\toolbox\physmod\simscape\engine\core\c}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\toolbox\physmod\simscape\compiler\core\c}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\toolbox\physmod\network_engine\c}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\toolbox\physmod\common\foundation\core\c}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<



{$(MATLAB_ROOT)\rtw\c\src}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\simulink\src}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\physmod\sm\ssci\c}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\physmod\sm\core\c}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\physmod\pm_math\c}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\physmod\simscape\engine\sli\c}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\physmod\simscape\engine\core\c}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\physmod\simscape\compiler\core\c}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\physmod\network_engine\c}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\physmod\common\foundation\core\c}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<



# Look in simulink/src helper files

{$(MATLAB_ROOT)\simulink\src}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

# Put these rule last, otherwise nmake will check toolboxes first

{$(RELATIVE_PATH_TO_ANCHOR)}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

{$(RELATIVE_PATH_TO_ANCHOR)}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

!if "$(SHARED_LIB)" != ""
$(SHARED_LIB) : $(SHARED_SRC)
	@cmd /C "echo ### Creating $@"
	@$(CC) $(CFLAGS) -Fo$(SHARED_BIN_DIR)\ @<<
$?
<<
	@$(LIBCMD) /nologo /out:$@ $(SHARED_OBJS)
	@cmd /C "echo ### $@ Created"
!endif

set_environment_variables:
	@set INCLUDE=$(INCLUDE)
	@set LIB=$(LIB)


# Libraries:



MODULES_sm_ssci = \
    sm_ssci_3dd14f0a.obj \
    sm_ssci_646478c5.obj \
    sm_ssci_916e6db1.obj \
    sm_ssci_b2b6b422.obj \
    sm_ssci_c16a187b.obj \


sm_ssci.lib : rtw_proj.tmw $(MAKEFILE) $(MODULES_sm_ssci)
	@cmd /C "echo ### Creating $@"
	$(LIBCMD) /nologo /out:$@ $(MODULES_sm_ssci)
	@cmd /C "echo ### $@ Created"

MODULES_sm = \
    sm_b402b573.obj \
    sm_bc63e36c.obj \


sm.lib : rtw_proj.tmw $(MAKEFILE) $(MODULES_sm)
	@cmd /C "echo ### Creating $@"
	$(LIBCMD) /nologo /out:$@ $(MODULES_sm)
	@cmd /C "echo ### $@ Created"

MODULES_pm_math = \
    pm_math_1966ea7d.obj \
    pm_math_1ad202b7.obj \
    pm_math_1c69d5b2.obj \
    pm_math_2cdd2951.obj \
    pm_math_3463da5d.obj \
    pm_math_360e4b46.obj \
    pm_math_48bd51fb.obj \
    pm_math_6309b74b.obj \
    pm_math_646fa971.obj \
    pm_math_65b2d2c7.obj \
    pm_math_706b4d88.obj \
    pm_math_7d094dcf.obj \
    pm_math_9e672043.obj \
    pm_math_b7b980b1.obj \
    pm_math_d1be0f30.obj \
    pm_math_da630bd2.obj \
    pm_math_f760e8f6.obj \


pm_math.lib : rtw_proj.tmw $(MAKEFILE) $(MODULES_pm_math)
	@cmd /C "echo ### Creating $@"
	$(LIBCMD) /nologo /out:$@ $(MODULES_pm_math)
	@cmd /C "echo ### $@ Created"

MODULES_ssc_sli = \
    ssc_sli_0763c151.obj \
    ssc_sli_0bd269e6.obj \
    ssc_sli_1ada6a7f.obj \
    ssc_sli_1e092b23.obj \
    ssc_sli_360cfd63.obj \
    ssc_sli_43618287.obj \
    ssc_sli_466b08dd.obj \
    ssc_sli_4e028390.obj \
    ssc_sli_500cc49a.obj \
    ssc_sli_51dbd3b5.obj \
    ssc_sli_550a4805.obj \
    ssc_sli_5a0cb974.obj \
    ssc_sli_62d81790.obj \
    ssc_sli_77063d8b.obj \
    ssc_sli_7a618260.obj \
    ssc_sli_7f630b0f.obj \
    ssc_sli_89d0f30a.obj \
    ssc_sli_8a621c2a.obj \
    ssc_sli_8a64c4e2.obj \
    ssc_sli_9c030181.obj \
    ssc_sli_b2b70359.obj \
    ssc_sli_c5b48e5b.obj \
    ssc_sli_c7dda239.obj \
    ssc_sli_ce623f02.obj \
    ssc_sli_dcd66f69.obj \
    ssc_sli_fa0ce53e.obj \
    ssc_sli_fbdf29da.obj \


ssc_sli.lib : rtw_proj.tmw $(MAKEFILE) $(MODULES_ssc_sli)
	@cmd /C "echo ### Creating $@"
	$(LIBCMD) /nologo /out:$@ $(MODULES_ssc_sli)
	@cmd /C "echo ### $@ Created"

MODULES_ssc_core = \
    ssc_core_01d712d7.obj \
    ssc_core_01db7fea.obj \
    ssc_core_01dcc633.obj \
    ssc_core_026ff268.obj \
    ssc_core_04da2c69.obj \
    ssc_core_05058dd9.obj \
    ssc_core_06ba677c.obj \
    ssc_core_06ba68a6.obj \
    ssc_core_0764a3ad.obj \
    ssc_core_0768a42c.obj \
    ssc_core_076b7741.obj \
    ssc_core_0864e4ae.obj \
    ssc_core_0bd666aa.obj \
    ssc_core_0f019bd9.obj \
    ssc_core_0f0420a6.obj \
    ssc_core_1108d1b5.obj \
    ssc_core_166caddf.obj \
    ssc_core_1b0315f1.obj \
    ssc_core_1b0cafd5.obj \
    ssc_core_1c64d74c.obj \
    ssc_core_1c656373.obj \
    ssc_core_1c6b0332.obj \
    ssc_core_1c6b0f35.obj \
    ssc_core_23d5dc0e.obj \
    ssc_core_24b4cdee.obj \
    ssc_core_2568b075.obj \
    ssc_core_256dd47a.obj \
    ssc_core_26d2e48c.obj \
    ssc_core_280c0222.obj \
    ssc_core_29d2a20c.obj \
    ssc_core_2a669a14.obj \
    ssc_core_2bbc5160.obj \
    ssc_core_2cd54448.obj \
    ssc_core_2d095f25.obj \
    ssc_core_30bd2090.obj \
    ssc_core_30bf43ef.obj \
    ssc_core_3169e4b7.obj \
    ssc_core_330dceec.obj \
    ssc_core_37d4ea84.obj \
    ssc_core_38d9af99.obj \
    ssc_core_38df7cb7.obj \
    ssc_core_390bbe0e.obj \
    ssc_core_3c06e0d0.obj \
    ssc_core_3dd7f5fc.obj \
    ssc_core_40d704a7.obj \
    ssc_core_40db6c85.obj \
    ssc_core_41017299.obj \
    ssc_core_440f9cd3.obj \
    ssc_core_4666b45b.obj \
    ssc_core_466b06df.obj \
    ssc_core_48b08af1.obj \
    ssc_core_48b1386a.obj \
    ssc_core_4965213d.obj \
    ssc_core_4ad7a19e.obj \
    ssc_core_4ad9135b.obj \
    ssc_core_4db6bd68.obj \
    ssc_core_4db86fcc.obj \
    ssc_core_4e04eecd.obj \
    ssc_core_500718de.obj \
    ssc_core_51d5b9a3.obj \
    ssc_core_53b3fda6.obj \
    ssc_core_54d55ae9.obj \
    ssc_core_54d63c45.obj \
    ssc_core_550a9a70.obj \
    ssc_core_56b1a2bf.obj \
    ssc_core_56b4a298.obj \
    ssc_core_59b034b8.obj \
    ssc_core_5a07074f.obj \
    ssc_core_5a0fdaac.obj \
    ssc_core_5d6ba758.obj \
    ssc_core_616494c7.obj \
    ssc_core_6167281d.obj \
    ssc_core_63030358.obj \
    ssc_core_67d1f118.obj \
    ssc_core_68da074b.obj \
    ssc_core_6b6b89d2.obj \
    ssc_core_6c0642ff.obj \
    ssc_core_6dd23923.obj \
    ssc_core_6dd833f3.obj \
    ssc_core_6e6bba26.obj \
    ssc_core_706e4ae5.obj \
    ssc_core_71b6e960.obj \
    ssc_core_76d825be.obj \
    ssc_core_780fa54b.obj \
    ssc_core_79dd08ab.obj \
    ssc_core_7a613edb.obj \
    ssc_core_7bb79f23.obj \
    ssc_core_7d0b92a7.obj \
    ssc_core_7ebac74c.obj \
    ssc_core_820e26d8.obj \
    ssc_core_820f4eaa.obj \
    ssc_core_8569edc5.obj \
    ssc_core_870cc9ba.obj \
    ssc_core_880d3897.obj \
    ssc_core_8a6471dc.obj \
    ssc_core_8bb063d9.obj \
    ssc_core_8d0c049c.obj \
    ssc_core_8f61989f.obj \
    ssc_core_96061071.obj \
    ssc_core_97d767fe.obj \
    ssc_core_97dcde38.obj \
    ssc_core_9c01d168.obj \
    ssc_core_9dd110ad.obj \
    ssc_core_9ddb783e.obj \
    ssc_core_9fb0e229.obj \
    ssc_core_9fb0e6d6.obj \
    ssc_core_9fb25b4f.obj \
    ssc_core_9fb2efdc.obj \
    ssc_core_a00457ac.obj \
    ssc_core_a1d393be.obj \
    ssc_core_a1d6f570.obj \
    ssc_core_a4d3adaf.obj \
    ssc_core_a4d4c45e.obj \
    ssc_core_a6b78ccc.obj \
    ssc_core_a6bce7bb.obj \
    ssc_core_a7672daf.obj \
    ssc_core_a867d880.obj \
    ssc_core_a9bb7f35.obj \
    ssc_core_a9bf1ff2.obj \
    ssc_core_aa0efe9f.obj \
    ssc_core_abd5e7b4.obj \
    ssc_core_acb64294.obj \
    ssc_core_acb6462e.obj \
    ssc_core_b1038cbb.obj \
    ssc_core_b10e34f4.obj \
    ssc_core_b2b3b239.obj \
    ssc_core_b366cffb.obj \
    ssc_core_b402b40d.obj \
    ssc_core_b407dc7e.obj \
    ssc_core_b40edf20.obj \
    ssc_core_b8b01afe.obj \
    ssc_core_b96ebc21.obj \
    ssc_core_bb0b2992.obj \
    ssc_core_be01a0db.obj \
    ssc_core_c168ace6.obj \
    ssc_core_c3003040.obj \
    ssc_core_c5b63cb2.obj \
    ssc_core_c8d83e88.obj \
    ssc_core_c8df395b.obj \
    ssc_core_c90f4384.obj \
    ssc_core_cab615c8.obj \
    ssc_core_cab87eff.obj \
    ssc_core_cabdc251.obj \
    ssc_core_cb616a40.obj \
    ssc_core_cb63b745.obj \
    ssc_core_cc067f58.obj \
    ssc_core_ce6a84bb.obj \
    ssc_core_d1beb31a.obj \
    ssc_core_d3d34d7c.obj \
    ssc_core_d3df2fff.obj \
    ssc_core_d4ba8ed2.obj \
    ssc_core_d708bbfb.obj \
    ssc_core_d9d13dac.obj \
    ssc_core_dbbdc82b.obj \
    ssc_core_deb7fd8d.obj \
    ssc_core_e2b61d72.obj \
    ssc_core_e400c1c2.obj \
    ssc_core_e4061965.obj \
    ssc_core_e407adf8.obj \
    ssc_core_eb093eda.obj \
    ssc_core_ee000fbe.obj \
    ssc_core_ee01086d.obj \
    ssc_core_ee0f0141.obj \
    ssc_core_f2610835.obj \
    ssc_core_f3b47568.obj \
    ssc_core_f867a7f6.obj \
    ssc_core_f9b6dbed.obj \
    ssc_core_fa09e9e6.obj \
    ssc_core_fbd34e62.obj \
    ssc_core_fd6bfe36.obj \
    ssc_core_fede7425.obj \
    ssc_core_ff06d9a4.obj \


ssc_core.lib : rtw_proj.tmw $(MAKEFILE) $(MODULES_ssc_core)
	@cmd /C "echo ### Creating $@"
	$(LIBCMD) /nologo /out:$@ $(MODULES_ssc_core)
	@cmd /C "echo ### $@ Created"

MODULES_ne = \
    ne_03b6336b.obj \
    ne_23d90911.obj \
    ne_38dea646.obj \
    ne_390cbc71.obj \
    ne_3ab8881f.obj \
    ne_3b664010.obj \
    ne_3c033af4.obj \
    ne_3fb96ad2.obj \
    ne_42b0ffc8.obj \
    ne_45d43f88.obj \
    ne_47b9c424.obj \
    ne_48b6562f.obj \
    ne_4c607df4.obj \
    ne_57686ca9.obj \
    ne_59b4e14a.obj \
    ne_5bd7a7a4.obj \
    ne_8f6c4657.obj \
    ne_95b22d2e.obj \
    ne_9fbe8f50.obj \
    ne_a1d5f1af.obj \
    ne_af03741f.obj \
    ne_b0dd440f.obj \
    ne_b40304b0.obj \
    ne_d9dde03a.obj \
    ne_df6be635.obj \
    ne_e8bbbd86.obj \
    ne_eb048896.obj \
    ne_ee0cb880.obj \
    ne_fd61f8e5.obj \


ne.lib : rtw_proj.tmw $(MAKEFILE) $(MODULES_ne)
	@cmd /C "echo ### Creating $@"
	$(LIBCMD) /nologo /out:$@ $(MODULES_ne)
	@cmd /C "echo ### $@ Created"

MODULES_pm = \
    pm_26dc3230.obj \


pm.lib : rtw_proj.tmw $(MAKEFILE) $(MODULES_pm)
	@cmd /C "echo ### Creating $@"
	$(LIBCMD) /nologo /out:$@ $(MODULES_pm)
	@cmd /C "echo ### $@ Created"



#----------------------------- Dependencies -----------------------------------

$(OBJS) : $(MAKEFILE) rtw_proj.tmw
