QEMU=qemu-system-x86_64
UEFI_CODE=-drive if=pflash,format=raw,readonly,file=uefi_bios.x64/OVMF_CODE.fd
UEFI_FLASH=-drive if=pflash,format=raw,file=uefi_bios.x64/OVMF_VARS.fd
UEFI_IMAGE=
DD=dd
IMAGE_FILE=image.img
IMAGE_SIZE=10240

.PHONY: run image install uefi kernel clean make_partition

default: run

run: image
#	$(QEMU) $(UEFI_CODE) $(UEFI_FLASH) -hda $(IMAGE_FILE) -net none
	$(QEMU) $(UEFI_CODE) $(UEFI_FLASH) -hda fat:rw:efi.image/HelloWorld -net none

image:
	$(DD) if=/dev/zero of=$(IMAGE_FILE) bs=1024 count=$(IMAGE_SIZE)
	make make_partition
	sudo losetup -Pf $(IMAGE_FILE)
	sudo mkfs.fat -F 32 /dev/loop0p1
	sudo mkfs.ext2 /dev/loop0p2
	sudo losetup -d /dev/loop0

install:uefi kernel
	mkdir -p mnt/0
	mkdir -p mnt/1
	sudo losetup -Pf $(IMAGE_FILE)
	sudo mount /dev/loop0 ./mnt/0
	sudo mount /dev/loop1 ./mnt/1
	sudo umount ./mnt/0
	sudo umount ./mnt/1
	sudo losetup -d /dev/loop0

uefi:


clean:
	rm $(IMAGE_FILE)

make_partition: make_partition.sh
	./make_partition.sh $(IMAGE_FILE)
