#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/CalculatorApp/Source/Button.o \
	${OBJECTDIR}/CalculatorApp/Source/CAMainFrame.o \
	${OBJECTDIR}/CalculatorApp/Source/CalculatorApp.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=`wx-config --cxxflags`  
CXXFLAGS=`wx-config --cxxflags`  

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/calculatorapp

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/calculatorapp: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/calculatorapp ${OBJECTFILES} ${LDLIBSOPTIONS} `wx-config --libs`

${OBJECTDIR}/CalculatorApp/Source/Button.o: CalculatorApp/Source/Button.cpp
	${MKDIR} -p ${OBJECTDIR}/CalculatorApp/Source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CalculatorApp/Source/Button.o CalculatorApp/Source/Button.cpp

${OBJECTDIR}/CalculatorApp/Source/CAMainFrame.o: CalculatorApp/Source/CAMainFrame.cpp
	${MKDIR} -p ${OBJECTDIR}/CalculatorApp/Source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CalculatorApp/Source/CAMainFrame.o CalculatorApp/Source/CAMainFrame.cpp

${OBJECTDIR}/CalculatorApp/Source/CalculatorApp.o: CalculatorApp/Source/CalculatorApp.cpp
	${MKDIR} -p ${OBJECTDIR}/CalculatorApp/Source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CalculatorApp/Source/CalculatorApp.o CalculatorApp/Source/CalculatorApp.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
