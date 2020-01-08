QEMU=qemu-system-x86_64
UEFI_CODE=-drive if=pflash,format=raw,readonly,file=uefi_bios.x64/OVMF_CODE.fd
UEFI_FLASH=-drive if=pflash,format=raw,file=uefi_bios.x64/OVMF_VARS.fd
UEFI_IMAGE=
DD=dd
IMAGE_FILE=image.img
IMAGE_SIZE=10240

.PHONY: run image make_partition

default: run

run: image
	$(QEMU) $(UEFI_CODE) $(UEFI_FLASH)

image:
	$(DD) if=/dev/zero of=$(IMAGE_FILE) bs=1024 count=$(IMAGE_SIZE)
	make make_partition 

clean:
	rm $(IMAGE_FILE)

make_partition: make_partition.sh
	./make_partition.sh $(IMAGE_FILE)
