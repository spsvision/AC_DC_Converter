#include "__cf_three_level_PWM_ac_dc_conv.h"
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "three_level_PWM_ac_dc_conv_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "three_level_PWM_ac_dc_conv.h"
#include "three_level_PWM_ac_dc_conv_capi.h"
#include "three_level_PWM_ac_dc_conv_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/Combinatorial  Logic" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 1 , 0 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/Boolean Logic/Abs" ) , TARGET_STRING ( "" ) , 0 ,
1 , 1 , 0 , 1 } , { 2 , 0 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/Boolean Logic/Divide" ) , TARGET_STRING ( "" ) ,
0 , 1 , 1 , 0 , 2 } , { 3 , 0 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/Boolean Logic/Divide2" ) , TARGET_STRING ( "" ) ,
0 , 1 , 1 , 0 , 2 } , { 4 , 0 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/Boolean Logic/Subtract2" ) , TARGET_STRING ( "" )
, 0 , 1 , 1 , 0 , 1 } , { 5 , 0 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/Current Measurement/do not delete this gain" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 1 , 0 , 1 } , { 6 , 0 , TARGET_STRING (
 "three_level_PWM_ac_dc_conv/Discrete PWM Generator (6 Level)/Data Type  Conversion"
) , TARGET_STRING ( "" ) , 0 , 1 , 2 , 0 , 3 } , { 7 , 0 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/Voltage Measurement1/do not delete this gain" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 1 , 0 , 1 } , { 8 , 0 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/Voltage Measurement2/do not delete this gain" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 1 , 0 , 1 } , { 9 , 0 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/Voltage Measurement3/do not delete this gain" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 1 , 0 , 1 } , { 10 , 0 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/Voltage Measurement4/do not delete this gain" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 1 , 0 , 1 } , { 11 , 0 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/AC Voltage V = 120 V/Model/AC" ) , TARGET_STRING
( "" ) , 0 , 1 , 1 , 0 , 1 } , { 12 , 0 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/D1/Model/(gate)" ) , TARGET_STRING ( "" ) , 0 , 1
, 1 , 0 , 2 } , { 13 , 0 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/D1/Model/eee" ) , TARGET_STRING ( "" ) , 0 , 1 ,
1 , 0 , 2 } , { 14 , 0 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/D2/Model/(gate)" ) , TARGET_STRING ( "" ) , 0 , 1
, 1 , 0 , 2 } , { 15 , 0 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/D2/Model/eee" ) , TARGET_STRING ( "" ) , 0 , 1 ,
1 , 0 , 2 } , { 16 , 0 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/D3/Model/(gate)" ) , TARGET_STRING ( "" ) , 0 , 1
, 1 , 0 , 2 } , { 17 , 0 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/D3/Model/eee" ) , TARGET_STRING ( "" ) , 0 , 1 ,
1 , 0 , 2 } , { 18 , 0 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/D4/Model/(gate)" ) , TARGET_STRING ( "" ) , 0 , 1
, 1 , 0 , 2 } , { 19 , 0 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/D4/Model/eee" ) , TARGET_STRING ( "" ) , 0 , 1 ,
1 , 0 , 2 } , { 20 , 0 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/D5/Model/(gate)" ) , TARGET_STRING ( "" ) , 0 , 1
, 1 , 0 , 2 } , { 21 , 0 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/D5/Model/eee" ) , TARGET_STRING ( "" ) , 0 , 1 ,
1 , 0 , 2 } , { 22 , 0 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/D6/Model/(gate)" ) , TARGET_STRING ( "" ) , 0 , 1
, 1 , 0 , 2 } , { 23 , 0 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/D6/Model/eee" ) , TARGET_STRING ( "" ) , 0 , 1 ,
1 , 0 , 2 } , { 24 , 0 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/D7/Model/(gate)" ) , TARGET_STRING ( "" ) , 0 , 1
, 1 , 0 , 2 } , { 25 , 0 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/D7/Model/eee" ) , TARGET_STRING ( "" ) , 0 , 1 ,
1 , 0 , 2 } , { 26 , 0 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/D8/Model/(gate)" ) , TARGET_STRING ( "" ) , 0 , 1
, 1 , 0 , 2 } , { 27 , 0 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/D8/Model/eee" ) , TARGET_STRING ( "" ) , 0 , 1 ,
1 , 0 , 2 } , { 28 , 0 , TARGET_STRING (
 "three_level_PWM_ac_dc_conv/Discrete PWM Generator (6 Level)/Triangle/Look-Up Table1"
) , TARGET_STRING ( "" ) , 0 , 1 , 1 , 0 , 1 } , { 29 , 0 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/powergui/EquivalentModel1/State-Space" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 3 , 0 , 1 } , { 30 , 0 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/powergui/EquivalentModel1/State-Space" ) ,
TARGET_STRING ( "" ) , 1 , 1 , 4 , 0 , 1 } , { 0 , 0 , ( NULL ) , ( NULL ) ,
0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 31 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/AC Voltage V = 120 V" ) , TARGET_STRING (
"Amplitude" ) , 1 , 1 , 0 } , { 32 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/AC Voltage V = 120 V" ) , TARGET_STRING ( "Phase"
) , 1 , 1 , 0 } , { 33 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/AC Voltage V = 120 V" ) , TARGET_STRING (
"Frequency" ) , 1 , 1 , 0 } , { 34 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/Discrete PWM Generator (6 Level)" ) ,
TARGET_STRING ( "Internal" ) , 1 , 1 , 0 } , { 35 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/Discrete PWM Generator (6 Level)" ) ,
TARGET_STRING ( "mIndex" ) , 1 , 1 , 0 } , { 36 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/Discrete PWM Generator (6 Level)" ) ,
TARGET_STRING ( "Freq" ) , 1 , 1 , 0 } , { 37 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/Discrete PWM Generator (6 Level)" ) ,
TARGET_STRING ( "Phase" ) , 1 , 1 , 0 } , { 38 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/Combinatorial  Logic" ) , TARGET_STRING (
"TruthTable" ) , 0 , 5 , 0 } , { 39 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/Boolean Logic/Constant" ) , TARGET_STRING (
"Value" ) , 1 , 1 , 0 } , { 40 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/Boolean Logic/Constant1" ) , TARGET_STRING (
"Value" ) , 1 , 1 , 0 } , { 41 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/Boolean Logic/Vpp-60Hz" ) , TARGET_STRING (
"Value" ) , 1 , 1 , 0 } , { 42 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/Current Measurement/do not delete this gain" ) ,
TARGET_STRING ( "Gain" ) , 1 , 1 , 0 } , { 43 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/Discrete PWM Generator (6 Level)/Triangle" ) ,
TARGET_STRING ( "rep_seq_y" ) , 1 , 6 , 0 } , { 44 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/Discrete PWM Generator (6 Level)/Constant" ) ,
TARGET_STRING ( "Value" ) , 1 , 7 , 0 } , { 45 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/Discrete PWM Generator (6 Level)/Gain2" ) ,
TARGET_STRING ( "Gain" ) , 1 , 1 , 0 } , { 46 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/Discrete PWM Generator (6 Level)/Switch" ) ,
TARGET_STRING ( "Threshold" ) , 1 , 1 , 0 } , { 47 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/Voltage Measurement1/do not delete this gain" ) ,
TARGET_STRING ( "Gain" ) , 1 , 1 , 0 } , { 48 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/Voltage Measurement2/do not delete this gain" ) ,
TARGET_STRING ( "Gain" ) , 1 , 1 , 0 } , { 49 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/Voltage Measurement3/do not delete this gain" ) ,
TARGET_STRING ( "Gain" ) , 1 , 1 , 0 } , { 50 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/Voltage Measurement4/do not delete this gain" ) ,
TARGET_STRING ( "Gain" ) , 1 , 1 , 0 } , { 51 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/AC Voltage V = 120 V/Model/AC" ) , TARGET_STRING
( "Bias" ) , 1 , 1 , 0 } , { 52 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/Boolean Logic/Compare To Zero/Constant" ) ,
TARGET_STRING ( "Value" ) , 1 , 1 , 0 } , { 53 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/Boolean Logic/IsNegative/Constant" ) ,
TARGET_STRING ( "Value" ) , 1 , 1 , 0 } , { 54 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/D1/Model/(gate)" ) , TARGET_STRING ( "Value" ) ,
1 , 1 , 0 } , { 55 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/D1/Model/eee" ) , TARGET_STRING ( "Value" ) , 1 ,
1 , 0 } , { 56 , TARGET_STRING ( "three_level_PWM_ac_dc_conv/D2/Model/(gate)"
) , TARGET_STRING ( "Value" ) , 1 , 1 , 0 } , { 57 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/D2/Model/eee" ) , TARGET_STRING ( "Value" ) , 1 ,
1 , 0 } , { 58 , TARGET_STRING ( "three_level_PWM_ac_dc_conv/D3/Model/(gate)"
) , TARGET_STRING ( "Value" ) , 1 , 1 , 0 } , { 59 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/D3/Model/eee" ) , TARGET_STRING ( "Value" ) , 1 ,
1 , 0 } , { 60 , TARGET_STRING ( "three_level_PWM_ac_dc_conv/D4/Model/(gate)"
) , TARGET_STRING ( "Value" ) , 1 , 1 , 0 } , { 61 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/D4/Model/eee" ) , TARGET_STRING ( "Value" ) , 1 ,
1 , 0 } , { 62 , TARGET_STRING ( "three_level_PWM_ac_dc_conv/D5/Model/(gate)"
) , TARGET_STRING ( "Value" ) , 1 , 1 , 0 } , { 63 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/D5/Model/eee" ) , TARGET_STRING ( "Value" ) , 1 ,
1 , 0 } , { 64 , TARGET_STRING ( "three_level_PWM_ac_dc_conv/D6/Model/(gate)"
) , TARGET_STRING ( "Value" ) , 1 , 1 , 0 } , { 65 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/D6/Model/eee" ) , TARGET_STRING ( "Value" ) , 1 ,
1 , 0 } , { 66 , TARGET_STRING ( "three_level_PWM_ac_dc_conv/D7/Model/(gate)"
) , TARGET_STRING ( "Value" ) , 1 , 1 , 0 } , { 67 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/D7/Model/eee" ) , TARGET_STRING ( "Value" ) , 1 ,
1 , 0 } , { 68 , TARGET_STRING ( "three_level_PWM_ac_dc_conv/D8/Model/(gate)"
) , TARGET_STRING ( "Value" ) , 1 , 1 , 0 } , { 69 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/D8/Model/eee" ) , TARGET_STRING ( "Value" ) , 1 ,
1 , 0 } , { 70 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/Discrete PWM Generator (6 Level)/Triangle/Constant"
) , TARGET_STRING ( "Value" ) , 1 , 1 , 0 } , { 71 , TARGET_STRING (
 "three_level_PWM_ac_dc_conv/Discrete PWM Generator (6 Level)/Triangle/Look-Up Table1"
) , TARGET_STRING ( "BreakpointsForDimension1" ) , 1 , 6 , 0 } , { 72 ,
TARGET_STRING (
"three_level_PWM_ac_dc_conv/powergui/EquivalentModel1/State-Space" ) ,
TARGET_STRING ( "P1" ) , 1 , 8 , 0 } , { 73 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/powergui/EquivalentModel1/State-Space" ) ,
TARGET_STRING ( "P2" ) , 1 , 6 , 0 } , { 74 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/powergui/EquivalentModel1/State-Space" ) ,
TARGET_STRING ( "P3" ) , 1 , 9 , 0 } , { 75 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/powergui/EquivalentModel1/State-Space" ) ,
TARGET_STRING ( "P4" ) , 1 , 10 , 0 } , { 76 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/powergui/EquivalentModel1/State-Space" ) ,
TARGET_STRING ( "P5" ) , 1 , 11 , 0 } , { 77 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/powergui/EquivalentModel1/State-Space" ) ,
TARGET_STRING ( "P6" ) , 1 , 12 , 0 } , { 78 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/powergui/EquivalentModel1/State-Space" ) ,
TARGET_STRING ( "P7" ) , 1 , 13 , 0 } , { 79 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/powergui/EquivalentModel1/State-Space" ) ,
TARGET_STRING ( "P8" ) , 1 , 12 , 0 } , { 80 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/powergui/EquivalentModel1/State-Space" ) ,
TARGET_STRING ( "P9" ) , 1 , 1 , 0 } , { 81 , TARGET_STRING (
"three_level_PWM_ac_dc_conv/powergui/EquivalentModel1/State-Space" ) ,
TARGET_STRING ( "P10" ) , 1 , 1 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0
} } ; static const rtwCAPI_ModelParameters rtModelParameters [ ] = { { 0 , (
NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . lobxxus3zf [ 0 ] , & rtB .
hwgujgig0r , & rtB . nhlp2yjplc , & rtB . jbvxwyij0y , & rtB . jmr2urlziy , &
rtB . lhtjuefs1s , & rtB . npjsoehvli [ 0 ] , & rtB . boj5trihky , & rtB .
ky3ypmchwb , & rtB . i2ascqprig , & rtB . lyfopxbigf , & rtB . opl0oc5efs , &
rtB . ieqnits2k1 , & rtB . h4uqpfbbgz , & rtB . mtnwul5crs , & rtB .
cb1lqzfxpl , & rtB . l1vu1bkjhv , & rtB . br2tmxhmz2 , & rtB . e021regt1w , &
rtB . g4bvofm2sv , & rtB . bddpitx5vb , & rtB . ouxsqqztxa , & rtB .
gdyoxwm15d , & rtB . a15cmwzmks , & rtB . hiib4anv4i , & rtB . lwgwdivmux , &
rtB . mjnjjwxjad , & rtB . e4ua4g0fko , & rtB . ej0uzzsc2t , & rtB .
bqotgs0lpr [ 0 ] , & rtB . fw30ihycwi [ 0 ] , & rtP .
ACVoltageV120V_Amplitude , & rtP . ACVoltageV120V_Phase , & rtP .
ACVoltageV120V_Frequency , & rtP . DiscretePWMGenerator6Level_Internal , &
rtP . DiscretePWMGenerator6Level_mIndex , & rtP .
DiscretePWMGenerator6Level_Freq , & rtP . DiscretePWMGenerator6Level_Phase ,
& rtP . CombinatorialLogic_table [ 0 ] , & rtP . Constant_Value_cieer5snor ,
& rtP . Constant1_Value , & rtP . Vpp60Hz_Value , & rtP .
donotdeletethisgain_Gain_lbhty2tvzw , & rtP . Triangle_rep_seq_y [ 0 ] , &
rtP . Constant_Value_fqq1ckc0wv [ 0 ] , & rtP . Gain2_Gain , & rtP .
Switch_Threshold , & rtP . donotdeletethisgain_Gain_k14ykx3pkj , & rtP .
donotdeletethisgain_Gain , & rtP . donotdeletethisgain_Gain_jzoyz0z31n , &
rtP . donotdeletethisgain_Gain_aiprxxe3wc , & rtP . AC_Bias , & rtP .
Constant_Value , & rtP . Constant_Value_ouuylrsk2d , & rtP . gate_Value , &
rtP . eee_Value , & rtP . gate_Value_mefctpxgq1 , & rtP .
eee_Value_ltwrydmito , & rtP . gate_Value_lxdkjkxc5z , & rtP .
eee_Value_c3qjua3w0z , & rtP . gate_Value_cgaoozqbxm , & rtP .
eee_Value_bubd4jwjra , & rtP . gate_Value_godmk3yhan , & rtP .
eee_Value_feaxwyjqep , & rtP . gate_Value_jwa3agpy2x , & rtP .
eee_Value_itsuzfhxkb , & rtP . gate_Value_my4wneoq4r , & rtP .
eee_Value_hng2mmrvii , & rtP . gate_Value_m2iq3im1pa , & rtP .
eee_Value_cszrsograu , & rtP . Constant_Value_eblvmaugeh , & rtP .
LookUpTable1_bp01Data [ 0 ] , & rtP . StateSpace_P1 [ 0 ] , & rtP .
StateSpace_P2 [ 0 ] , & rtP . StateSpace_P3 [ 0 ] , & rtP . StateSpace_P4 [ 0
] , & rtP . StateSpace_P5 [ 0 ] , & rtP . StateSpace_P6 [ 0 ] , & rtP .
StateSpace_P7 [ 0 ] , & rtP . StateSpace_P8 [ 0 ] , & rtP . StateSpace_P9 , &
rtP . StateSpace_P10 , } ; static int32_T * rtVarDimsAddrMap [ ] = { ( NULL )
} ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { {
"unsigned char" , "boolean_T" , 0 , 0 , sizeof ( boolean_T ) , SS_BOOLEAN , 0
, 0 , 0 } , { "double" , "real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0
, 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_VECTOR , 0 , 2 , 0 } , { rtwCAPI_SCALAR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 4 , 2 , 0 } , { rtwCAPI_VECTOR , 6 , 2 , 0 } , {
rtwCAPI_VECTOR , 8 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 10 , 2 , 0 } , {
rtwCAPI_VECTOR , 12 , 2 , 0 } , { rtwCAPI_VECTOR , 14 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 16 , 2 , 0 } , { rtwCAPI_VECTOR , 18 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 20 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 22 , 2
, 0 } , { rtwCAPI_VECTOR , 24 , 2 , 0 } , { rtwCAPI_VECTOR , 26 , 2 , 0 } } ;
static const uint_T rtDimensionArray [ ] = { 3 , 1 , 1 , 1 , 6 , 1 , 5 , 1 ,
28 , 1 , 8 , 3 , 1 , 4 , 1 , 3 , 72 , 29 , 10 , 1 , 72 , 25 , 2 , 14 , 1 , 14
, 14 , 1 } ; static const real_T rtcapiStoredFloats [ ] = { 0.0 , 1.0 ,
5.0E-6 } ; static const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , (
NULL ) , rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static const
rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] , 1 ,
0 } , { ( const void * ) & rtcapiStoredFloats [ 0 ] , ( const void * ) &
rtcapiStoredFloats [ 0 ] , 0 , 0 } , { ( NULL ) , ( NULL ) , 3 , 0 } , { (
const void * ) & rtcapiStoredFloats [ 2 ] , ( const void * ) &
rtcapiStoredFloats [ 0 ] , 2 , 0 } } ; static rtwCAPI_ModelMappingStaticInfo
mmiStatic = { { rtBlockSignals , 31 , ( NULL ) , 0 , ( NULL ) , 0 } , {
rtBlockParameters , 51 , rtModelParameters , 0 } , { ( NULL ) , 0 } , {
rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap
, rtDimensionArray } , "float" , { 949554994U , 1332906209U , 109567221U ,
659647683U } , ( NULL ) , 0 , 0 } ; const rtwCAPI_ModelMappingStaticInfo *
three_level_PWM_ac_dc_conv_GetCAPIStaticMap ( void ) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void three_level_PWM_ac_dc_conv_InitializeDataMapInfo ( void ) {
rtwCAPI_SetVersion ( ( * rt_dataMapInfoPtr ) . mmi , 1 ) ;
rtwCAPI_SetStaticMap ( ( * rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ;
rtwCAPI_SetLoggingStaticMap ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetDataAddressMap ( ( * rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ;
rtwCAPI_SetVarDimsAddressMap ( ( * rt_dataMapInfoPtr ) . mmi ,
rtVarDimsAddrMap ) ; rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr )
. mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi
, ( NULL ) ) ; rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi ,
0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void three_level_PWM_ac_dc_conv_host_InitializeDataMapInfo (
three_level_PWM_ac_dc_conv_host_DataMapInfo_T * dataMap , const char * path )
{ rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap ( dataMap
-> mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL )
; rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
