#include "types.h"
#include "kernel.h"

static u8 ping_packet[] = {
  0x52, 0x55, 0x0a, 0x00, 0x02, 0x02, 0x52, 0x54, 0x00, 0x12,
  0x34, 0x56, 0x08, 0x00, 0x45, 0x00, 0x00, 0x54, 0x00, 0x00,
  0x40, 0x00, 0x40, 0x01, 0x22, 0x99, 0x0a, 0x00, 0x02, 0x0f,
  0x0a, 0x00, 0x02, 0x02, 0x08, 0x00, 0x94, 0xa0, 0x03, 0x07,
  0x00, 0x01, 0x71, 0xfc, 0xec, 0x4e, 0x00, 0x00, 0x00, 0x00,
  0x3b, 0x39, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x11,
  0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b,
  0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25,
  0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
  0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37
};

void
netfree(void *va)
{
  kfree(va);
}

void *
netalloc(void)
{
  return kalloc();
}

void
netrx(void *va, u16 len)
{
  cprintf("netrx %lx len %x\n", va, len);
}

void
nettest(void)
{
  void *ping;
  u32 len;

  ping = netalloc();
  len = sizeof(ping_packet);
  memmove(ping, ping_packet, len);
  e1000tx(ping, len);
  
  //e1000tx(ping_packet, sizeof(ping_packet));
}
