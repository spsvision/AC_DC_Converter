#include "__cf_three_level_PWM_ac_dc_conv.h"
#ifndef RTW_HEADER_three_level_PWM_ac_dc_conv_private_h_
#define RTW_HEADER_three_level_PWM_ac_dc_conv_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#if !defined(rt_VALIDATE_MEMORY)
#define rt_VALIDATE_MEMORY(S, ptr)   if(!(ptr)) {\
  ssSetErrorStatus(rtS, RT_MEMORY_ALLOCATION_ERROR);\
  }
#endif
#if !defined(rt_FREE)
#if !defined(_WIN32)
#define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((ptr));\
  (ptr) = (NULL);\
  }
#else
#define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((void *)(ptr));\
  (ptr) = (NULL);\
  }
#endif
#endif
extern real_T look1_binlxpw ( real_T u0 , const real_T bp0 [ ] , const real_T
table [ ] , uint32_T maxIndex ) ; extern void sfun_spid_contc ( SimStruct *
rts ) ;
#if defined(MULTITASKING)
#error Models using the variable step solvers cannot define MULTITASKING
#endif
#endif
