#include  <Uefi.h>
#include  <Library/UefiLib.h>

EFI_STATUS
EFIAPI
UefiMain (
    IN EFI_HANDLE ImageHandle,
    IN EFI_SYSTEM_TABLE *SystemTable
    )
{
  Print(L"Hello EDK II.\n");
  // parse partition
  

  
  // parse first minix file system

  // read kernel

  // switch to kernel


  while(1);
  return 0;
}
