#ifndef __CC_H__
#define __CC_H__

#include "../local-include/rtl.h"

enum {
  CC_O, CC_NO, CC_B,  CC_NB,
  CC_E, CC_NE, CC_BE, CC_NBE,
  CC_S, CC_NS, CC_P,  CC_NP,
  CC_L, CC_NL, CC_LE, CC_NLE
};


/* Condition Code */

static inline const char* get_cc_name(int subcode) {
  static const char *cc_name[] = {
    "o", "no", "b", "nb",
    "e", "ne", "be", "nbe",
    "s", "ns", "p", "np",
    "l", "nl", "le", "nle"
  };
  return cc_name[subcode];
}

static inline void rtl_setcc(DecodeExecState *s, rtlreg_t* dest, uint32_t subcode) {
  uint32_t invert = subcode & 0x1;
  uint32_t is_sat = 0;

  // TODO: Query EFLAGS to determine whether the condition code is satisfied.
  // dest <- ( cc is satisfied ? 1 : 0)
  switch (subcode & 0xe) {
    case CC_O:
    case CC_B:
    case CC_E:
        if (cpu.eflags.ZF == 1) is_sat = 1;
        break;
    case CC_BE:
    case CC_S:
    case CC_L:
    case CC_LE:
       TODO();
    case CC_P: panic("PF is not supported");
    default: panic("should not reach here");
  }

  if (is_sat) {
      rtl_andi(s, dest, dest, 0x01);
      rtl_ori(s, dest, dest, 0x01);
  } else {
      rtl_andi(s, dest, dest, 0);
  }

  printf("dest val: %d\n", *dest);
  if (invert) {
    rtl_xori(s, dest, dest, 0x1);
  }
  assert(*dest == 0 || *dest == 1);
}

#endif
