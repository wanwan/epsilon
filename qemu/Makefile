QEMU=qemu-system-x86_64
UEFI_CODE=-bios uefi_bios.x64/OVMF_CODE.fd
UEFI_FLASH=
UEFI_IMAGE=
DD=dd
IMAGE=image.img
IMAGE_SIZE=10240

.PHONY: run image

default: run

run: image
	$(QEMU) $(UEFI_CODE) $(UEFI_FLASH)

image:
	$(DD) if=/dev/zero of=$(IMAGE) bs=1024 count=$(IMAGE_SIZE)
	make makepartition


.ONESHELL:
makepartition:

clean:
	rm $(IMAGE)
