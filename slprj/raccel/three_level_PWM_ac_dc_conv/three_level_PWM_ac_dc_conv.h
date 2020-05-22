#include "__cf_three_level_PWM_ac_dc_conv.h"
#ifndef RTW_HEADER_three_level_PWM_ac_dc_conv_h_
#define RTW_HEADER_three_level_PWM_ac_dc_conv_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef three_level_PWM_ac_dc_conv_COMMON_INCLUDES_
#define three_level_PWM_ac_dc_conv_COMMON_INCLUDES_
#include <stdlib.h>
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "three_level_PWM_ac_dc_conv_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME three_level_PWM_ac_dc_conv
#define NSAMPLE_TIMES (4) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (31) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (10)   
#elif NCSTATES != 10
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T opl0oc5efs ; real_T bqotgs0lpr [ 5 ] ; real_T
fw30ihycwi [ 28 ] ; real_T ky3ypmchwb ; real_T i2ascqprig ; real_T lyfopxbigf
; real_T lhtjuefs1s ; real_T jmr2urlziy ; real_T hwgujgig0r ; real_T
ej0uzzsc2t ; real_T npjsoehvli [ 6 ] ; real_T boj5trihky ; real_T nhlp2yjplc
; real_T jbvxwyij0y ; real_T h4uqpfbbgz ; real_T ieqnits2k1 ; real_T
cb1lqzfxpl ; real_T mtnwul5crs ; real_T br2tmxhmz2 ; real_T l1vu1bkjhv ;
real_T g4bvofm2sv ; real_T e021regt1w ; real_T ouxsqqztxa ; real_T bddpitx5vb
; real_T a15cmwzmks ; real_T gdyoxwm15d ; real_T lwgwdivmux ; real_T
hiib4anv4i ; real_T e4ua4g0fko ; real_T mjnjjwxjad ; boolean_T lobxxus3zf [ 3
] ; } B ; typedef struct { real_T oetzn5jscx [ 2 ] ; void * kytgfvyij5 [ 22 ]
; struct { void * LoggedData [ 2 ] ; } e3nmbwzb2u ; struct { void *
LoggedData [ 3 ] ; } drxsehypdl ; struct { void * AQHandles ; void * SlioLTF
; } jti1ku22dn ; struct { void * AQHandles ; void * SlioLTF ; } pexeigqnvk ;
struct { void * LoggedData ; } kyyge3hbne ; struct { void * LoggedData [ 6 ]
; } hxaystgzkw ; struct { void * AQHandles ; void * SlioLTF ; } aogymm20xl ;
struct { void * LoggedData ; } ine0liz2jy ; int_T czwcnoupsx [ 23 ] ; int_T
jtyytfci20 [ 15 ] ; int_T hwtnslxeeo ; boolean_T k0d12xqate ; boolean_T
mrboyrtusm ; boolean_T khbjj3tefj ; } DW ; typedef struct { real_T j0qvdxfy5g
[ 10 ] ; } X ; typedef struct { real_T j0qvdxfy5g [ 10 ] ; } XDot ; typedef
struct { boolean_T j0qvdxfy5g [ 10 ] ; } XDis ; typedef struct { real_T
j0qvdxfy5g [ 10 ] ; } CStateAbsTol ; typedef struct { real_T drb0bd0knk [ 15
] ; real_T bvugrqdz2l ; real_T imhwcex0f1 ; real_T iwd0msyekj ; real_T
o0fromhfml ; } ZCV ; typedef struct { rtwCAPI_ModelMappingInfo mmi ; }
DataMapInfo ; struct P_ { real_T ACVoltageV120V_Amplitude ; real_T
DiscretePWMGenerator6Level_Freq ; real_T ACVoltageV120V_Frequency ; real_T
DiscretePWMGenerator6Level_Internal ; real_T ACVoltageV120V_Phase ; real_T
DiscretePWMGenerator6Level_Phase ; real_T DiscretePWMGenerator6Level_mIndex ;
real_T Triangle_rep_seq_y [ 4 ] ; real_T Constant_Value ; real_T
Constant_Value_ouuylrsk2d ; real_T AC_Bias ; real_T StateSpace_P1_Size [ 2 ]
; real_T StateSpace_P1 [ 2088 ] ; real_T StateSpace_P2_Size [ 2 ] ; real_T
StateSpace_P2 [ 4 ] ; real_T StateSpace_P3_Size [ 2 ] ; real_T StateSpace_P3
[ 10 ] ; real_T StateSpace_P4_Size [ 2 ] ; real_T StateSpace_P4 [ 1800 ] ;
real_T StateSpace_P5_Size [ 2 ] ; real_T StateSpace_P5 [ 28 ] ; real_T
StateSpace_P6_Size [ 2 ] ; real_T StateSpace_P6 [ 14 ] ; real_T
StateSpace_P7_Size [ 2 ] ; real_T StateSpace_P7 [ 14 ] ; real_T
StateSpace_P8_Size [ 2 ] ; real_T StateSpace_P8 [ 14 ] ; real_T
StateSpace_P9_Size [ 2 ] ; real_T StateSpace_P9 ; real_T StateSpace_P10_Size
[ 2 ] ; real_T StateSpace_P10 ; real_T donotdeletethisgain_Gain ; real_T
donotdeletethisgain_Gain_jzoyz0z31n ; real_T
donotdeletethisgain_Gain_aiprxxe3wc ; real_T
donotdeletethisgain_Gain_lbhty2tvzw ; real_T Gain2_Gain ; real_T
Constant_Value_fqq1ckc0wv [ 3 ] ; real_T Switch_Threshold ; real_T
LookUpTable1_bp01Data [ 4 ] ; real_T donotdeletethisgain_Gain_k14ykx3pkj ;
real_T Constant_Value_cieer5snor ; real_T Constant1_Value ; real_T
Vpp60Hz_Value ; real_T Constant_Value_eblvmaugeh ; real_T eee_Value ; real_T
gate_Value ; real_T eee_Value_ltwrydmito ; real_T gate_Value_mefctpxgq1 ;
real_T eee_Value_c3qjua3w0z ; real_T gate_Value_lxdkjkxc5z ; real_T
eee_Value_bubd4jwjra ; real_T gate_Value_cgaoozqbxm ; real_T
eee_Value_feaxwyjqep ; real_T gate_Value_godmk3yhan ; real_T
eee_Value_itsuzfhxkb ; real_T gate_Value_jwa3agpy2x ; real_T
eee_Value_hng2mmrvii ; real_T gate_Value_my4wneoq4r ; real_T
eee_Value_cszrsograu ; real_T gate_Value_m2iq3im1pa ; boolean_T
CombinatorialLogic_table [ 24 ] ; } ; extern const char *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW rtDW ;
extern P rtP ; extern const rtwCAPI_ModelMappingStaticInfo *
three_level_PWM_ac_dc_conv_GetCAPIStaticMap ( void ) ; extern SimStruct *
const rtS ; extern const int_T gblNumToFiles ; extern const int_T
gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern rtInportTUtable
* gblInportTUtables ; extern const char * gblInportFileName ; extern const
int_T gblNumRootInportBlks ; extern const int_T gblNumModelInputs ; extern
const int_T gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ;
extern const int_T gblInportComplex [ ] ; extern const int_T
gblInportInterpoFlag [ ] ; extern const int_T gblInportContinuous [ ] ;
extern const int_T gblParameterTuningTid ; extern DataMapInfo *
rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ;
void MdlOutputs ( int_T tid ) ; void MdlOutputsParameterSampleTime ( int_T
tid ) ; void MdlUpdate ( int_T tid ) ; void MdlTerminate ( void ) ; void
MdlInitializeSizes ( void ) ; void MdlInitializeSampleTimes ( void ) ;
SimStruct * raccel_register_model ( void ) ;
#endif
