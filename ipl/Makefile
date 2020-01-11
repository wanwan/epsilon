
SRCS=main.c
OBJS=main.o

EDK2_ROOT=/home/waka/repos/edk2
EDK2_APL=$(EDK2_ROOT)/AppPkg/Applications
IPL_DIR=$(EDK2_APL)/ipl
EDK2_BUILD_DIR=$(EDK2_ROOT)/Build/AppPkg/DEBUG_GCC5/X64/

IPL_EFI=ipl.efi

.PHONY: default

default: ipl

ipl:
	mkdir -p $(IPL_DIR)
	cp $(SRCS) $(IPL_DIR)
	(cd $(EDK2_ROOT); source ./edksetup.sh; build)
	cp $(EDK2_BUILD_DIR)/$(IPL_EFI) .



