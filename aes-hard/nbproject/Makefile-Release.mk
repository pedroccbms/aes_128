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
	${OBJECTDIR}/_ext/42fdcd59/aes_128_key_expansion.o \
	${OBJECTDIR}/_ext/42fdcd59/aes_128_teste.o \
	${OBJECTDIR}/_ext/42fdcd59/aes_encrypt_decrypt.o \
	${OBJECTDIR}/welcome.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/aes-hard

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/aes-hard: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/aes-hard ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/42fdcd59/aes_128_key_expansion.o: ../../../Documentos/TCC2/AES-HARD/aes_128_key_expansion.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/42fdcd59
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/42fdcd59/aes_128_key_expansion.o ../../../Documentos/TCC2/AES-HARD/aes_128_key_expansion.c

${OBJECTDIR}/_ext/42fdcd59/aes_128_teste.o: ../../../Documentos/TCC2/AES-HARD/aes_128_teste.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/42fdcd59
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/42fdcd59/aes_128_teste.o ../../../Documentos/TCC2/AES-HARD/aes_128_teste.c

${OBJECTDIR}/_ext/42fdcd59/aes_encrypt_decrypt.o: ../../../Documentos/TCC2/AES-HARD/aes_encrypt_decrypt.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/42fdcd59
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/42fdcd59/aes_encrypt_decrypt.o ../../../Documentos/TCC2/AES-HARD/aes_encrypt_decrypt.c

${OBJECTDIR}/welcome.o: welcome.cc 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/welcome.o welcome.cc

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/aes-hard

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
