#include "fw_reg_stc8g.h"

void wait()
{
  uint16_t t1, t2;
  for (t1 = 0; t1 < 10000; t1++)
    for (t2 = 0; t2 < 10; t2++);
}

void main()
{
  P2M1 = 0x00; P2M0 = 0x20; // set 25.5 as push-pull output

  while(1){
    P25 = 1;
    wait();
    P25 = 0;
    wait();
  }
}
