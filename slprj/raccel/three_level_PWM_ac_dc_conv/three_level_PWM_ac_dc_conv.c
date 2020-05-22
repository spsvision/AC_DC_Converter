#include "__cf_three_level_PWM_ac_dc_conv.h"
#include "rt_logging_mmi.h"
#include "three_level_PWM_ac_dc_conv_capi.h"
#include <math.h>
#include "three_level_PWM_ac_dc_conv.h"
#include "three_level_PWM_ac_dc_conv_private.h"
#include "three_level_PWM_ac_dc_conv_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; extern boolean_T
gblExtModeStartPktReceived ; void raccelForceExtModeShutdown ( ) { if ( !
gblExtModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 3 , & stopRequested ) ; }
rtExtModeShutdown ( 3 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 4 ; const char_T
* gbl_raccel_Version = "9.2 (R2019b) 18-Jul-2019" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const char * gblSlvrJacPatternFileName =
 "slprj\\raccel\\three_level_PWM_ac_dc_conv\\three_level_PWM_ac_dc_conv_Jpattern.mat"
; const int_T gblNumRootInportBlks = 0 ; const int_T gblNumModelInputs = 0 ;
extern rtInportTUtable * gblInportTUtables ; extern const char *
gblInportFileName ; extern void * gblAperiodicPartitionHitTimes ; const int_T
gblInportDataTypeIdx [ ] = { - 1 } ; const int_T gblInportDims [ ] = { - 1 }
; const int_T gblInportComplex [ ] = { - 1 } ; const int_T
gblInportInterpoFlag [ ] = { - 1 } ; const int_T gblInportContinuous [ ] = {
- 1 } ; int_T enableFcnCallFlag [ ] = { 1 , 1 , 1 , 1 } ; const char *
raccelLoadInputsAndAperiodicHitTimes ( const char * inportFileName , int *
matFileFormat ) { return rt_RapidReadInportsMatFile ( inportFileName ,
matFileFormat , 1 ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
B rtB ; X rtX ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS =
& model_S ; real_T look1_binlxpw ( real_T u0 , const real_T bp0 [ ] , const
real_T table [ ] , uint32_T maxIndex ) { real_T frac ; uint32_T iRght ;
uint32_T iLeft ; uint32_T bpIdx ; if ( u0 <= bp0 [ 0U ] ) { iLeft = 0U ; frac
= ( u0 - bp0 [ 0U ] ) / ( bp0 [ 1U ] - bp0 [ 0U ] ) ; } else if ( u0 < bp0 [
maxIndex ] ) { bpIdx = maxIndex >> 1U ; iLeft = 0U ; iRght = maxIndex ; while
( iRght - iLeft > 1U ) { if ( u0 < bp0 [ bpIdx ] ) { iRght = bpIdx ; } else {
iLeft = bpIdx ; } bpIdx = ( iRght + iLeft ) >> 1U ; } frac = ( u0 - bp0 [
iLeft ] ) / ( bp0 [ iLeft + 1U ] - bp0 [ iLeft ] ) ; } else { iLeft =
maxIndex - 1U ; frac = ( u0 - bp0 [ maxIndex - 1U ] ) / ( bp0 [ maxIndex ] -
bp0 [ maxIndex - 1U ] ) ; } return ( table [ iLeft + 1U ] - table [ iLeft ] )
* frac + table [ iLeft ] ; } void MdlInitialize ( void ) { { SimStruct * rts
= ssGetSFunction ( rtS , 0 ) ; sfcnInitializeConditions ( rts ) ; if (
ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } } void MdlStart ( void ) {
{ void * * slioCatalogueAddr = rt_slioCatalogueAddr ( ) ; void * r2 = ( NULL
) ; void * * pOSigstreamManagerAddr = ( NULL ) ; const int maxErrorBufferSize
= 16384 ; char errMsgCreatingOSigstreamManager [ 16384 ] ; bool
errorCreatingOSigstreamManager = false ; const char *
errorAddingR2SharedResource = ( NULL ) ; * slioCatalogueAddr =
rtwGetNewSlioCatalogue ( rt_GetMatSigLogSelectorFileName ( ) ) ;
errorAddingR2SharedResource = rtwAddR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) , 1 ) ; if (
errorAddingR2SharedResource != ( NULL ) ) { rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = ( NULL ) ; ssSetErrorStatus ( rtS
, errorAddingR2SharedResource ) ; return ; } r2 = rtwGetR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ) ;
pOSigstreamManagerAddr = rt_GetOSigstreamManagerAddr ( ) ;
errorCreatingOSigstreamManager = rtwOSigstreamManagerCreateInstance (
rt_GetMatSigLogSelectorFileName ( ) , r2 , pOSigstreamManagerAddr ,
errMsgCreatingOSigstreamManager , maxErrorBufferSize ) ; if (
errorCreatingOSigstreamManager ) { * pOSigstreamManagerAddr = ( NULL ) ;
ssSetErrorStatus ( rtS , errMsgCreatingOSigstreamManager ) ; return ; } } {
bool externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( ) ; rtwISigstreamManagerGetInputIsInDatasetFormat (
pISigstreamManager , & externalInputIsInDatasetFormat ) ; if (
externalInputIsInDatasetFormat ) { } } { void * slioCatalogue =
rt_slioCatalogue ( ) ? rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) :
sdiGetSlioCatalogue ( rt_dataMapInfo . mmi . InstanceMap . fullPath ) ; if (
! slioCatalogue || ! rtwDisableStreamingToRepository ( slioCatalogue ) ) { {
{ sdiSignalSourceInfoU srcInfo ; sdiLabelU loggedName = sdiGetLabelFromChars
( "" ) ; sdiLabelU origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU
propName = sdiGetLabelFromChars ( "" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "three_level_PWM_ac_dc_conv/Voltage Measurement2" ) ;
sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. jti1ku22dn . AQHandles = sdiAsyncRepoCreateAsyncioQueue ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"934ef926-893b-4d74-8874-f412b5b93682" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; if ( rtDW . jti1ku22dn . AQHandles )
{ sdiSetSignalSampleTimeString ( rtDW . jti1ku22dn . AQHandles , "Continuous"
, 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetRunStartTime ( rtDW . jti1ku22dn .
AQHandles , ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . jti1ku22dn . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . jti1ku22dn . AQHandles , loggedName , origSigName , propName ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } } } rtDW .
jti1ku22dn . SlioLTF = ( NULL ) ; { void * treeVector = ( NULL ) ; void *
accessor = ( NULL ) ; const void * signalDescriptor = ( NULL ) ; void *
loggingInterval = ( NULL ) ; char * datasetName = "tmp_raccel_logsout" ; if (
slioCatalogue && rtwIsLoggingToFile ( slioCatalogue ) ) { treeVector =
rtwGetTreeVector ( ) ; { int_T sigDimsArray [ 1 ] = { 1 } ; rtwAddLeafNode (
0 , "" , "linear" , 0 , ( unsigned int * ) sigDimsArray , 1 , "double" , "" ,
"Continuous" , 0.0 , ssGetTFinal ( rtS ) , treeVector ) ; } signalDescriptor
= rtwGetSignalDescriptor ( treeVector , 1 , 1 , 0 , 1 , "" , "" ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"three_level_PWM_ac_dc_conv/Voltage Measurement2" , 1 , 0 , slioCatalogue , (
NULL ) , 0 , ( NULL ) , 0 ) ; if ( ! rt_slioCatalogue ( ) ) {
sdiSlioIsLoggingSignal ( rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"three_level_PWM_ac_dc_conv/Voltage Measurement2" , 1 , "" ) ; } if (
rtwLoggingOverride ( signalDescriptor , slioCatalogue ) ) { if ( ssGetRootSS
( rtS ) -> mdlInfo -> rtwLogInfo ) { loggingInterval = rtliGetLoggingInterval
( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ; } else { loggingInterval =
sdiGetLoggingIntervals ( rt_dataMapInfo . mmi . InstanceMap . fullPath ) ;
datasetName = "" ; } accessor = rtwGetAccessor ( signalDescriptor ,
loggingInterval ) ; rtwAddR2Client ( accessor , signalDescriptor ,
slioCatalogue , datasetName , 1 ) ; rtDW . jti1ku22dn . SlioLTF = accessor ;
} } } } { void * slioCatalogue = rt_slioCatalogue ( ) ?
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) : sdiGetSlioCatalogue (
rt_dataMapInfo . mmi . InstanceMap . fullPath ) ; if ( ! slioCatalogue || !
rtwDisableStreamingToRepository ( slioCatalogue ) ) { { {
sdiSignalSourceInfoU srcInfo ; sdiLabelU loggedName = sdiGetLabelFromChars (
"" ) ; sdiLabelU origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU
propName = sdiGetLabelFromChars ( "" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "three_level_PWM_ac_dc_conv/Voltage Measurement3" ) ;
sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. pexeigqnvk . AQHandles = sdiAsyncRepoCreateAsyncioQueue ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"b3b36e2b-3591-4935-afa9-a47b68d5e38d" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; if ( rtDW . pexeigqnvk . AQHandles )
{ sdiSetSignalSampleTimeString ( rtDW . pexeigqnvk . AQHandles , "Continuous"
, 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetRunStartTime ( rtDW . pexeigqnvk .
AQHandles , ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . pexeigqnvk . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . pexeigqnvk . AQHandles , loggedName , origSigName , propName ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } } } rtDW .
pexeigqnvk . SlioLTF = ( NULL ) ; { void * treeVector = ( NULL ) ; void *
accessor = ( NULL ) ; const void * signalDescriptor = ( NULL ) ; void *
loggingInterval = ( NULL ) ; char * datasetName = "tmp_raccel_logsout" ; if (
slioCatalogue && rtwIsLoggingToFile ( slioCatalogue ) ) { treeVector =
rtwGetTreeVector ( ) ; { int_T sigDimsArray [ 1 ] = { 1 } ; rtwAddLeafNode (
0 , "" , "linear" , 0 , ( unsigned int * ) sigDimsArray , 1 , "double" , "" ,
"Continuous" , 0.0 , ssGetTFinal ( rtS ) , treeVector ) ; } signalDescriptor
= rtwGetSignalDescriptor ( treeVector , 1 , 1 , 0 , 1 , "" , "" ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"three_level_PWM_ac_dc_conv/Voltage Measurement3" , 1 , 0 , slioCatalogue , (
NULL ) , 0 , ( NULL ) , 0 ) ; if ( ! rt_slioCatalogue ( ) ) {
sdiSlioIsLoggingSignal ( rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"three_level_PWM_ac_dc_conv/Voltage Measurement3" , 1 , "" ) ; } if (
rtwLoggingOverride ( signalDescriptor , slioCatalogue ) ) { if ( ssGetRootSS
( rtS ) -> mdlInfo -> rtwLogInfo ) { loggingInterval = rtliGetLoggingInterval
( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ; } else { loggingInterval =
sdiGetLoggingIntervals ( rt_dataMapInfo . mmi . InstanceMap . fullPath ) ;
datasetName = "" ; } accessor = rtwGetAccessor ( signalDescriptor ,
loggingInterval ) ; rtwAddR2Client ( accessor , signalDescriptor ,
slioCatalogue , datasetName , 1 ) ; rtDW . pexeigqnvk . SlioLTF = accessor ;
} } } } { static int_T rt_ToWksWidths [ ] = { 1 } ; static int_T
rt_ToWksNumDimensions [ ] = { 1 } ; static int_T rt_ToWksDimensions [ ] = { 1
} ; static boolean_T rt_ToWksIsVarDims [ ] = { 0 } ; static void *
rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ToWksCurrSigDimsSize
[ ] = { 4 } ; static BuiltInDTypeId rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ;
static int_T rt_ToWksComplexSignals [ ] = { 0 } ; static int_T
rt_ToWksFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ; static const char_T
* rt_ToWksLabels [ ] = { "" } ; static RTWLogSignalInfo rt_ToWksSignalInfo =
{ 1 , rt_ToWksWidths , rt_ToWksNumDimensions , rt_ToWksDimensions ,
rt_ToWksIsVarDims , rt_ToWksCurrSigDims , rt_ToWksCurrSigDimsSize ,
rt_ToWksDataTypeIds , rt_ToWksComplexSignals , rt_ToWksFrameData ,
rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels } , ( NULL ) , ( NULL
) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , ( NULL ) } ; static
const char_T rt_ToWksBlockName [ ] =
"three_level_PWM_ac_dc_conv/To Workspace" ; rtDW . kyyge3hbne . LoggedData =
rt_CreateStructLogVar ( ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) ,
ssGetTFinal ( rtS ) , 0.0 , ( & ssGetErrorStatus ( rtS ) ) , "simout" , 1 , 0
, 1 , 0.0 , & rt_ToWksSignalInfo , rt_ToWksBlockName ) ; if ( rtDW .
kyyge3hbne . LoggedData == ( NULL ) ) return ; } { void * slioCatalogue =
rt_slioCatalogue ( ) ? rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) :
sdiGetSlioCatalogue ( rt_dataMapInfo . mmi . InstanceMap . fullPath ) ; if (
! slioCatalogue || ! rtwDisableStreamingToRepository ( slioCatalogue ) ) { {
{ sdiSignalSourceInfoU srcInfo ; sdiLabelU loggedName = sdiGetLabelFromChars
( "" ) ; sdiLabelU origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU
propName = sdiGetLabelFromChars ( "" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "three_level_PWM_ac_dc_conv/Voltage Measurement1" ) ;
sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. aogymm20xl . AQHandles = sdiAsyncRepoCreateAsyncioQueue ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"4cd9f40d-bd14-492a-91ed-4bbda3a0d6bf" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; if ( rtDW . aogymm20xl . AQHandles )
{ sdiSetSignalSampleTimeString ( rtDW . aogymm20xl . AQHandles , "Continuous"
, 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetRunStartTime ( rtDW . aogymm20xl .
AQHandles , ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . aogymm20xl . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . aogymm20xl . AQHandles , loggedName , origSigName , propName ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } } } rtDW .
aogymm20xl . SlioLTF = ( NULL ) ; { void * treeVector = ( NULL ) ; void *
accessor = ( NULL ) ; const void * signalDescriptor = ( NULL ) ; void *
loggingInterval = ( NULL ) ; char * datasetName = "tmp_raccel_logsout" ; if (
slioCatalogue && rtwIsLoggingToFile ( slioCatalogue ) ) { treeVector =
rtwGetTreeVector ( ) ; { int_T sigDimsArray [ 1 ] = { 1 } ; rtwAddLeafNode (
0 , "" , "linear" , 0 , ( unsigned int * ) sigDimsArray , 1 , "double" , "" ,
"Continuous" , 0.0 , ssGetTFinal ( rtS ) , treeVector ) ; } signalDescriptor
= rtwGetSignalDescriptor ( treeVector , 1 , 1 , 0 , 1 , "" , "" ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"three_level_PWM_ac_dc_conv/Voltage Measurement1" , 1 , 0 , slioCatalogue , (
NULL ) , 0 , ( NULL ) , 0 ) ; if ( ! rt_slioCatalogue ( ) ) {
sdiSlioIsLoggingSignal ( rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"three_level_PWM_ac_dc_conv/Voltage Measurement1" , 1 , "" ) ; } if (
rtwLoggingOverride ( signalDescriptor , slioCatalogue ) ) { if ( ssGetRootSS
( rtS ) -> mdlInfo -> rtwLogInfo ) { loggingInterval = rtliGetLoggingInterval
( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ; } else { loggingInterval =
sdiGetLoggingIntervals ( rt_dataMapInfo . mmi . InstanceMap . fullPath ) ;
datasetName = "" ; } accessor = rtwGetAccessor ( signalDescriptor ,
loggingInterval ) ; rtwAddR2Client ( accessor , signalDescriptor ,
slioCatalogue , datasetName , 1 ) ; rtDW . aogymm20xl . SlioLTF = accessor ;
} } } } { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ; sfcnStart ( rts ) ;
if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } MdlInitialize ( ) ; }
void MdlOutputs ( int_T tid ) { int32_T rowIdx ; boolean_T llszal3asa ;
real_T lr11tre5sc ; real_T n1uc3i55fx ; boolean_T bandzzxji4_idx_0 ;
boolean_T dvh4afvxx4_idx_0 ; boolean_T bandzzxji4_idx_1 ; boolean_T
dvh4afvxx4_idx_1 ; real_T hiyaamm0k3_idx_0 ; real_T hiyaamm0k3_idx_1 ; rtB .
opl0oc5efs = muDoubleScalarSin ( 6.2831853071795862 * rtP .
ACVoltageV120V_Frequency * ssGetTaskTime ( rtS , 0 ) + rtP .
ACVoltageV120V_Phase * 3.1415926535897931 / 180.0 ) * rtP .
ACVoltageV120V_Amplitude + rtP . AC_Bias ; { SimStruct * rts = ssGetSFunction
( rtS , 0 ) ; sfcnOutputs ( rts , 0 ) ; } rtB . ky3ypmchwb = rtP .
donotdeletethisgain_Gain * rtB . bqotgs0lpr [ 2 ] ; rtB . i2ascqprig = rtP .
donotdeletethisgain_Gain_jzoyz0z31n * rtB . bqotgs0lpr [ 1 ] ; rtB .
lyfopxbigf = rtP . donotdeletethisgain_Gain_aiprxxe3wc * rtB . bqotgs0lpr [ 0
] ; rtB . lhtjuefs1s = rtP . donotdeletethisgain_Gain_lbhty2tvzw * rtB .
bqotgs0lpr [ 4 ] ; rtB . jmr2urlziy = ( ( rtB . nhlp2yjplc - ( rtB .
ky3ypmchwb + rtB . i2ascqprig ) ) * ( rtB . lyfopxbigf / rtB . nhlp2yjplc ) +
( rtB . i2ascqprig - rtB . ky3ypmchwb ) ) - rtB . lhtjuefs1s ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( ssIsMajorTimeStep ( rtS ) ) { rtDW .
k0d12xqate = ( rtB . jmr2urlziy <= rtP . Constant_Value ) ; } llszal3asa =
rtDW . k0d12xqate ; } if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . hwtnslxeeo =
( rtB . lyfopxbigf >= 0.0 ) ; } rtB . hwgujgig0r = rtDW . hwtnslxeeo > 0 ?
rtB . lyfopxbigf : - rtB . lyfopxbigf ; if ( ssIsSampleHit ( rtS , 1 , 0 ) )
{ if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . mrboyrtusm = ( rtB . jbvxwyij0y
<= rtB . hwgujgig0r ) ; rtDW . khbjj3tefj = ( rtB . lhtjuefs1s < rtP .
Constant_Value_ouuylrsk2d ) ; } rowIdx = ( int32_T ) ( ( ( ( ( uint32_T )
llszal3asa << 1 ) + rtDW . mrboyrtusm ) << 1 ) + rtDW . khbjj3tefj ) ; rtB .
lobxxus3zf [ 0U ] = rtP . CombinatorialLogic_table [ ( uint32_T ) rowIdx ] ;
rtB . lobxxus3zf [ 1U ] = rtP . CombinatorialLogic_table [ rowIdx + 8U ] ;
rtB . lobxxus3zf [ 2U ] = rtP . CombinatorialLogic_table [ rowIdx + 16U ] ; {
if ( ( rtDW . jti1ku22dn . AQHandles || rtDW . jti1ku22dn . SlioLTF ) &&
ssGetLogOutput ( rtS ) ) { sdiSlioSdiWriteSignal ( rtDW . jti1ku22dn .
AQHandles , rtDW . jti1ku22dn . SlioLTF , 0 , ssGetTaskTime ( rtS , 1 ) , (
char * ) & rtB . ky3ypmchwb + 0 ) ; } } { if ( ( rtDW . pexeigqnvk .
AQHandles || rtDW . pexeigqnvk . SlioLTF ) && ssGetLogOutput ( rtS ) ) {
sdiSlioSdiWriteSignal ( rtDW . pexeigqnvk . AQHandles , rtDW . pexeigqnvk .
SlioLTF , 0 , ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB . i2ascqprig + 0 )
; } } } { double locTime = ssGetTaskTime ( rtS , 0 ) ; ; if ( ssGetLogOutput
( rtS ) ) { { if ( rtwTimeInLoggingInterval ( rtliGetLoggingInterval (
ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) , locTime ) ) {
rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW . kyyge3hbne . LoggedData , &
locTime , & rtB . ky3ypmchwb ) ; } } } } if ( ssIsSampleHit ( rtS , 2 , 0 ) )
{ lr11tre5sc = 6.2831853071795862 * rtP . DiscretePWMGenerator6Level_Freq *
ssGetTaskTime ( rtS , 2 ) ; n1uc3i55fx = rtP . Gain2_Gain * rtP .
DiscretePWMGenerator6Level_Phase ; if ( rtP .
DiscretePWMGenerator6Level_Internal >= rtP . Switch_Threshold ) {
hiyaamm0k3_idx_0 = muDoubleScalarSin ( ( lr11tre5sc + n1uc3i55fx ) + rtP .
Constant_Value_fqq1ckc0wv [ 0 ] ) * rtP . DiscretePWMGenerator6Level_mIndex ;
hiyaamm0k3_idx_1 = muDoubleScalarSin ( ( lr11tre5sc + n1uc3i55fx ) + rtP .
Constant_Value_fqq1ckc0wv [ 1 ] ) * rtP . DiscretePWMGenerator6Level_mIndex ;
lr11tre5sc = muDoubleScalarSin ( ( lr11tre5sc + n1uc3i55fx ) + rtP .
Constant_Value_fqq1ckc0wv [ 2 ] ) * rtP . DiscretePWMGenerator6Level_mIndex ;
} else { hiyaamm0k3_idx_0 = 0.0 ; hiyaamm0k3_idx_1 = 0.0 ; lr11tre5sc = 0.0 ;
} } rtB . ej0uzzsc2t = look1_binlxpw ( muDoubleScalarRem ( ssGetT ( rtS ) -
0.0 , rtP . Constant_Value_eblvmaugeh ) , rtP . LookUpTable1_bp01Data , rtP .
Triangle_rep_seq_y , 3U ) ; if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { llszal3asa
= ( hiyaamm0k3_idx_0 >= rtB . ej0uzzsc2t ) ; dvh4afvxx4_idx_0 = ! llszal3asa
; bandzzxji4_idx_0 = llszal3asa ; llszal3asa = ( hiyaamm0k3_idx_1 >= rtB .
ej0uzzsc2t ) ; dvh4afvxx4_idx_1 = ! llszal3asa ; bandzzxji4_idx_1 =
llszal3asa ; llszal3asa = ( lr11tre5sc >= rtB . ej0uzzsc2t ) ; rtB .
npjsoehvli [ 0 ] = bandzzxji4_idx_0 ; rtB . npjsoehvli [ 1 ] =
dvh4afvxx4_idx_0 ; rtB . npjsoehvli [ 2 ] = bandzzxji4_idx_1 ; rtB .
npjsoehvli [ 3 ] = dvh4afvxx4_idx_1 ; rtB . npjsoehvli [ 4 ] = llszal3asa ;
rtB . npjsoehvli [ 5 ] = ! llszal3asa ; } rtB . boj5trihky = rtP .
donotdeletethisgain_Gain_k14ykx3pkj * rtB . bqotgs0lpr [ 3 ] ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { { if ( ( rtDW . aogymm20xl . AQHandles ||
rtDW . aogymm20xl . SlioLTF ) && ssGetLogOutput ( rtS ) ) {
sdiSlioSdiWriteSignal ( rtDW . aogymm20xl . AQHandles , rtDW . aogymm20xl .
SlioLTF , 0 , ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB . boj5trihky + 0 )
; } } } UNUSED_PARAMETER ( tid ) ; } void MdlOutputsTID3 ( int_T tid ) { rtB
. nhlp2yjplc = rtP . Vpp60Hz_Value / rtP . Constant_Value_cieer5snor ; rtB .
jbvxwyij0y = rtB . nhlp2yjplc / rtP . Constant1_Value ; rtB . h4uqpfbbgz =
rtP . eee_Value ; rtB . ieqnits2k1 = rtP . gate_Value ; rtB . cb1lqzfxpl =
rtP . eee_Value_ltwrydmito ; rtB . mtnwul5crs = rtP . gate_Value_mefctpxgq1 ;
rtB . br2tmxhmz2 = rtP . eee_Value_c3qjua3w0z ; rtB . l1vu1bkjhv = rtP .
gate_Value_lxdkjkxc5z ; rtB . g4bvofm2sv = rtP . eee_Value_bubd4jwjra ; rtB .
e021regt1w = rtP . gate_Value_cgaoozqbxm ; rtB . ouxsqqztxa = rtP .
eee_Value_feaxwyjqep ; rtB . bddpitx5vb = rtP . gate_Value_godmk3yhan ; rtB .
a15cmwzmks = rtP . eee_Value_itsuzfhxkb ; rtB . gdyoxwm15d = rtP .
gate_Value_jwa3agpy2x ; rtB . lwgwdivmux = rtP . eee_Value_hng2mmrvii ; rtB .
hiib4anv4i = rtP . gate_Value_my4wneoq4r ; rtB . e4ua4g0fko = rtP .
eee_Value_cszrsograu ; rtB . mjnjjwxjad = rtP . gate_Value_m2iq3im1pa ;
UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid ) { { SimStruct * rts
= ssGetSFunction ( rtS , 0 ) ; sfcnUpdate ( rts , 0 ) ; if ( ssGetErrorStatus
( rts ) != ( NULL ) ) return ; } UNUSED_PARAMETER ( tid ) ; } void
MdlUpdateTID3 ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void
MdlDerivatives ( void ) { { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ;
real_T * sfcndX_fx = ( real_T * ) & ( ( XDot * ) ssGetdX ( rtS ) ) ->
j0qvdxfy5g [ 0 ] ; ssSetdX ( rts , sfcndX_fx ) ; sfcnDerivatives ( rts ) ; if
( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } } void MdlProjection (
void ) { { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ; sfcnProjection (
rts ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } } void
MdlZeroCrossings ( void ) { ZCV * _rtZCSV ; _rtZCSV = ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) ; { SimStruct * rts = ssGetSFunction (
rtS , 0 ) ; ssSetNonsampledZCs ( rts , & ( ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) -> drb0bd0knk [ 0 ] ) ) ;
sfcnZeroCrossings ( rts ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) )
return ; } _rtZCSV -> bvugrqdz2l = rtB . jmr2urlziy - rtP . Constant_Value ;
_rtZCSV -> imhwcex0f1 = rtB . lyfopxbigf ; _rtZCSV -> iwd0msyekj = rtB .
jbvxwyij0y - rtB . hwgujgig0r ; _rtZCSV -> o0fromhfml = rtB . lhtjuefs1s -
rtP . Constant_Value_ouuylrsk2d ; } void MdlTerminate ( void ) { { SimStruct
* rts = ssGetSFunction ( rtS , 0 ) ; sfcnTerminate ( rts ) ; } { if ( rtDW .
jti1ku22dn . AQHandles ) { sdiTerminateStreaming ( & rtDW . jti1ku22dn .
AQHandles ) ; } if ( rtDW . jti1ku22dn . SlioLTF ) {
rtwDestructAccessorPointer ( rtDW . jti1ku22dn . SlioLTF ) ; } } { if ( rtDW
. pexeigqnvk . AQHandles ) { sdiTerminateStreaming ( & rtDW . pexeigqnvk .
AQHandles ) ; } if ( rtDW . pexeigqnvk . SlioLTF ) {
rtwDestructAccessorPointer ( rtDW . pexeigqnvk . SlioLTF ) ; } } { if ( rtDW
. aogymm20xl . AQHandles ) { sdiTerminateStreaming ( & rtDW . aogymm20xl .
AQHandles ) ; } if ( rtDW . aogymm20xl . SlioLTF ) {
rtwDestructAccessorPointer ( rtDW . aogymm20xl . SlioLTF ) ; } } if (
rt_slioCatalogue ( ) != ( NULL ) ) { void * * slioCatalogueAddr =
rt_slioCatalogueAddr ( ) ; rtwSaveDatasetsToMatFile (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ,
rt_GetMatSigstreamLoggingFileName ( ) ) ; rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = NULL ; } } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 10 ) ;
ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU (
rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS ,
3 ) ; ssSetNumBlocks ( rtS , 132 ) ; ssSetNumBlockIO ( rtS , 31 ) ;
ssSetNumBlockParams ( rtS , 4066 ) ; } void MdlInitializeSampleTimes ( void )
{ ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 0.0 ) ;
ssSetSampleTime ( rtS , 2 , 5.0E-6 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ;
ssSetOffsetTime ( rtS , 1 , 1.0 ) ; ssSetOffsetTime ( rtS , 2 , 0.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 949554994U ) ;
ssSetChecksumVal ( rtS , 1 , 1332906209U ) ; ssSetChecksumVal ( rtS , 2 ,
109567221U ) ; ssSetChecksumVal ( rtS , 3 , 659647683U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( void ) { static struct _ssMdlInfo mdlInfo
; ( void ) memset ( ( char * ) rtS , 0 , sizeof ( SimStruct ) ) ; ( void )
memset ( ( char * ) & mdlInfo , 0 , sizeof ( struct _ssMdlInfo ) ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { real_T * x = ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ;
( void ) memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void * dwork = (
void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork ,
0 , sizeof ( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset (
( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS
, & dtInfo ) ; dtInfo . numDataTypes = 14 ; dtInfo . dataTypeSizes = &
rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ;
dtInfo . BTransTable = & rtBTransTable ; dtInfo . PTransTable = &
rtPTransTable ; dtInfo . dataTypeInfoTable = rtDataTypeInfoTable ; }
three_level_PWM_ac_dc_conv_InitializeDataMapInfo ( ) ;
ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS ) ;
ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"three_level_PWM_ac_dc_conv" ) ; ssSetPath ( rtS ,
"three_level_PWM_ac_dc_conv" ) ; ssSetTStart ( rtS , 0.0 ) ; ssSetTFinal (
rtS , 0.05 ) ; { static RTWLogInfo rt_DataLoggingInfo ; rt_DataLoggingInfo .
loggingInterval = NULL ; ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ; } {
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogXSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; rtliSetLogT (
ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX ( ssGetRTWLogInfo ( rtS ) ,
"" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 )
; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssSolverInfo slvrInfo ; static struct _ssSFcnModelMethods3 mdlMethods3 ;
static struct _ssSFcnModelMethods2 mdlMethods2 ; static boolean_T
contStatesDisabled [ 10 ] ; static real_T absTol [ 10 ] = { 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 } ;
static uint8_T absTolControl [ 10 ] = { 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
, 0U , 0U } ; static uint8_T zcAttributes [ 19 ] = { ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) } ; ssSetSolverRelTol ( rtS , 0.001 ) ;
ssSetStepSize ( rtS , 0.0 ) ; ssSetMinStepSize ( rtS , 0.0 ) ;
ssSetMaxNumMinSteps ( rtS , - 1 ) ; ssSetMinStepViolatedError ( rtS , 0 ) ;
ssSetMaxStepSize ( rtS , 5.0E-6 ) ; ssSetSolverMaxOrder ( rtS , - 1 ) ;
ssSetSolverRefineFactor ( rtS , 1 ) ; ssSetOutputTimes ( rtS , ( NULL ) ) ;
ssSetNumOutputTimes ( rtS , 0 ) ; ssSetOutputTimesOnly ( rtS , 0 ) ;
ssSetOutputTimesIndex ( rtS , 0 ) ; ssSetZCCacheNeedsReset ( rtS , 1 ) ;
ssSetDerivCacheNeedsReset ( rtS , 0 ) ; ssSetNumNonContDerivSigInfos ( rtS ,
0 ) ; ssSetNonContDerivSigInfos ( rtS , ( NULL ) ) ; ssSetSolverInfo ( rtS ,
& slvrInfo ) ; ssSetSolverName ( rtS , "ode23tb" ) ; ssSetVariableStepSolver
( rtS , 1 ) ; ssSetSolverConsistencyChecking ( rtS , 0 ) ;
ssSetSolverAdaptiveZcDetection ( rtS , 1 ) ; ssSetSolverRobustResetMethod (
rtS , 0 ) ; ssSetAbsTolVector ( rtS , absTol ) ; ssSetAbsTolControlVector (
rtS , absTolControl ) ; ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetSolverStateProjection ( rtS , 1 ) ; ( void ) memset ( ( void * ) &
mdlMethods2 , 0 , sizeof ( mdlMethods2 ) ) ; ssSetModelMethods2 ( rtS , &
mdlMethods2 ) ; ( void ) memset ( ( void * ) & mdlMethods3 , 0 , sizeof (
mdlMethods3 ) ) ; ssSetModelMethods3 ( rtS , & mdlMethods3 ) ;
ssSetModelProjection ( rtS , MdlProjection ) ; ssSetSolverMassMatrixType (
rtS , ( ssMatrixType ) 0 ) ; ssSetSolverMassMatrixNzMax ( rtS , 0 ) ;
ssSetModelOutputs ( rtS , MdlOutputs ) ; ssSetModelLogData ( rtS ,
rt_UpdateTXYLogVars ) ; ssSetModelLogDataIfInInterval ( rtS ,
rt_UpdateTXXFYLogVars ) ; ssSetModelUpdate ( rtS , MdlUpdate ) ;
ssSetModelDerivatives ( rtS , MdlDerivatives ) ; ssSetSolverZcSignalAttrib (
rtS , zcAttributes ) ; ssSetSolverNumZcSignals ( rtS , 19 ) ;
ssSetModelZeroCrossings ( rtS , MdlZeroCrossings ) ;
ssSetSolverConsecutiveZCsStepRelTol ( rtS , 2.8421709430404007E-13 ) ;
ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ; ssSetSolverConsecutiveZCsError
( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic ( rtS , 1 ) ;
ssSetSolverIgnoredZcDiagnostic ( rtS , 0 ) ; ssSetSolverZcThreshold ( rtS ,
0.001 ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ;
ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid ( rtS , INT_MIN )
; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 19 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; }
ssSetChecksumVal ( rtS , 0 , 949554994U ) ; ssSetChecksumVal ( rtS , 1 ,
1332906209U ) ; ssSetChecksumVal ( rtS , 2 , 109567221U ) ; ssSetChecksumVal
( rtS , 3 , 659647683U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 1 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; rteiSetModelMappingInfoPtr (
ssGetRTWExtModeInfo ( rtS ) , & ssGetModelMappingInfo ( rtS ) ) ;
rteiSetChecksumsPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) )
; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; }
ssSetNumSFunctions ( rtS , 1 ) ; { static SimStruct childSFunctions [ 1 ] ;
static SimStruct * childSFunctionPtrs [ 1 ] ; ( void ) memset ( ( void * ) &
childSFunctions [ 0 ] , 0 , sizeof ( childSFunctions ) ) ; ssSetSFunctions (
rtS , & childSFunctionPtrs [ 0 ] ) ; ssSetSFunction ( rtS , 0 , &
childSFunctions [ 0 ] ) ; { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ;
static time_T sfcnPeriod [ 1 ] ; static time_T sfcnOffset [ 1 ] ; static
int_T sfcnTsMap [ 1 ] ; ( void ) memset ( ( void * ) sfcnPeriod , 0 , sizeof
( time_T ) * 1 ) ; ( void ) memset ( ( void * ) sfcnOffset , 0 , sizeof (
time_T ) * 1 ) ; ssSetSampleTimePtr ( rts , & sfcnPeriod [ 0 ] ) ;
ssSetOffsetTimePtr ( rts , & sfcnOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr (
rts , sfcnTsMap ) ; { static struct _ssBlkInfo2 _blkInfo2 ; struct
_ssBlkInfo2 * blkInfo2 = & _blkInfo2 ; ssSetBlkInfo2Ptr ( rts , blkInfo2 ) ;
} { static struct _ssPortInfo2 _portInfo2 ; struct _ssPortInfo2 * portInfo2 =
& _portInfo2 ; _ssSetBlkInfo2PortInfo2Ptr ( rts , portInfo2 ) ; }
ssSetMdlInfoPtr ( rts , ssGetMdlInfoPtr ( rtS ) ) ; { static struct
_ssSFcnModelMethods2 methods2 ; ssSetModelMethods2 ( rts , & methods2 ) ; } {
static struct _ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 ( rts , &
methods3 ) ; } { static struct _ssSFcnModelMethods4 methods4 ;
ssSetModelMethods4 ( rts , & methods4 ) ; } { static struct _ssStatesInfo2
statesInfo2 ; static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetStatesInfo2 ( rts , & statesInfo2 ) ; ssSetPeriodicStatesInfo ( rts , &
periodicStatesInfo ) ; ssSetAbsTolVector ( rts , ssGetAbsTolVector ( rtS ) +
0 ) ; ssSetAbsTolControlVector ( rts , ssGetAbsTolControlVector ( rtS ) + 0 )
; } { static struct _ssPortInputs inputPortInfo [ 2 ] ; _ssSetNumInputPorts (
rts , 2 ) ; ssSetPortInfoForInputs ( rts , & inputPortInfo [ 0 ] ) ; { static
struct _ssInPortUnit inputPortUnits [ 2 ] ; _ssSetPortInfo2ForInputUnits (
rts , & inputPortUnits [ 0 ] ) ; } ssSetInputPortUnit ( rts , 0 , 0 ) ;
ssSetInputPortUnit ( rts , 1 , 0 ) ; { static struct _ssInPortCoSimAttribute
inputPortCoSimAttribute [ 2 ] ; _ssSetPortInfo2ForInputCoSimAttribute ( rts ,
& inputPortCoSimAttribute [ 0 ] ) ; } ssSetInputPortIsContinuousQuantity (
rts , 0 , 0 ) ; ssSetInputPortIsContinuousQuantity ( rts , 1 , 0 ) ; { static
real_T const * sfcnUPtrs [ 9 ] ; sfcnUPtrs [ 0 ] = & rtB . opl0oc5efs ;
sfcnUPtrs [ 1 ] = & rtB . lwgwdivmux ; sfcnUPtrs [ 2 ] = & rtB . a15cmwzmks ;
sfcnUPtrs [ 3 ] = & rtB . ouxsqqztxa ; sfcnUPtrs [ 4 ] = & rtB . g4bvofm2sv ;
sfcnUPtrs [ 5 ] = & rtB . e4ua4g0fko ; sfcnUPtrs [ 6 ] = & rtB . br2tmxhmz2 ;
sfcnUPtrs [ 7 ] = & rtB . cb1lqzfxpl ; sfcnUPtrs [ 8 ] = & rtB . h4uqpfbbgz ;
ssSetInputPortSignalPtrs ( rts , 0 , ( InputPtrsType ) & sfcnUPtrs [ 0 ] ) ;
_ssSetInputPortNumDimensions ( rts , 0 , 1 ) ; ssSetInputPortWidth ( rts , 0
, 9 ) ; } { static real_T const * sfcnUPtrs [ 14 ] ; sfcnUPtrs [ 0 ] = & rtB
. hiib4anv4i ; sfcnUPtrs [ 1 ] = & rtB . gdyoxwm15d ; sfcnUPtrs [ 2 ] = & rtB
. bddpitx5vb ; sfcnUPtrs [ 3 ] = & rtB . e021regt1w ; sfcnUPtrs [ 4 ] = & rtB
. mjnjjwxjad ; sfcnUPtrs [ 5 ] = & rtB . l1vu1bkjhv ; sfcnUPtrs [ 6 ] = & rtB
. mtnwul5crs ; sfcnUPtrs [ 7 ] = & rtB . ieqnits2k1 ; sfcnUPtrs [ 8 ] = & rtB
. npjsoehvli [ 5 ] ; sfcnUPtrs [ 9 ] = & rtB . npjsoehvli [ 4 ] ; sfcnUPtrs [
10 ] = & rtB . npjsoehvli [ 3 ] ; sfcnUPtrs [ 11 ] = & rtB . npjsoehvli [ 2 ]
; sfcnUPtrs [ 12 ] = & rtB . npjsoehvli [ 1 ] ; sfcnUPtrs [ 13 ] = & rtB .
npjsoehvli [ 0 ] ; ssSetInputPortSignalPtrs ( rts , 1 , ( InputPtrsType ) &
sfcnUPtrs [ 0 ] ) ; _ssSetInputPortNumDimensions ( rts , 1 , 1 ) ;
ssSetInputPortWidth ( rts , 1 , 14 ) ; } } { static struct _ssPortOutputs
outputPortInfo [ 2 ] ; ssSetPortInfoForOutputs ( rts , & outputPortInfo [ 0 ]
) ; _ssSetNumOutputPorts ( rts , 2 ) ; { static struct _ssOutPortUnit
outputPortUnits [ 2 ] ; _ssSetPortInfo2ForOutputUnits ( rts , &
outputPortUnits [ 0 ] ) ; } ssSetOutputPortUnit ( rts , 0 , 0 ) ;
ssSetOutputPortUnit ( rts , 1 , 0 ) ; { static struct
_ssOutPortCoSimAttribute outputPortCoSimAttribute [ 2 ] ;
_ssSetPortInfo2ForOutputCoSimAttribute ( rts , & outputPortCoSimAttribute [ 0
] ) ; } ssSetOutputPortIsContinuousQuantity ( rts , 0 , 0 ) ;
ssSetOutputPortIsContinuousQuantity ( rts , 1 , 0 ) ; {
_ssSetOutputPortNumDimensions ( rts , 0 , 1 ) ; ssSetOutputPortWidth ( rts ,
0 , 5 ) ; ssSetOutputPortSignal ( rts , 0 , ( ( real_T * ) rtB . bqotgs0lpr )
) ; } { _ssSetOutputPortNumDimensions ( rts , 1 , 1 ) ; ssSetOutputPortWidth
( rts , 1 , 28 ) ; ssSetOutputPortSignal ( rts , 1 , ( ( real_T * ) rtB .
fw30ihycwi ) ) ; } } ssSetContStates ( rts , & rtX . j0qvdxfy5g [ 0 ] ) ;
ssSetContStateDisabled ( rts , & ( ( XDis * ) ssGetContStateDisabled ( rtS )
) -> j0qvdxfy5g [ 0 ] ) ; ssSetModelName ( rts , "State-Space" ) ; ssSetPath
( rts , "three_level_PWM_ac_dc_conv/powergui/EquivalentModel1/State-Space" )
; if ( ssGetRTModel ( rtS ) == ( NULL ) ) { ssSetParentSS ( rts , rtS ) ;
ssSetRootSS ( rts , ssGetRootSS ( rtS ) ) ; } else { ssSetRTModel ( rts ,
ssGetRTModel ( rtS ) ) ; ssSetParentSS ( rts , ( NULL ) ) ; ssSetRootSS ( rts
, rts ) ; } ssSetVersion ( rts , SIMSTRUCT_VERSION_LEVEL2 ) ; { static
mxArray * sfcnParams [ 10 ] ; ssSetSFcnParamsCount ( rts , 10 ) ;
ssSetSFcnParamsPtr ( rts , & sfcnParams [ 0 ] ) ; ssSetSFcnParam ( rts , 0 ,
( mxArray * ) rtP . StateSpace_P1_Size ) ; ssSetSFcnParam ( rts , 1 , (
mxArray * ) rtP . StateSpace_P2_Size ) ; ssSetSFcnParam ( rts , 2 , ( mxArray
* ) rtP . StateSpace_P3_Size ) ; ssSetSFcnParam ( rts , 3 , ( mxArray * ) rtP
. StateSpace_P4_Size ) ; ssSetSFcnParam ( rts , 4 , ( mxArray * ) rtP .
StateSpace_P5_Size ) ; ssSetSFcnParam ( rts , 5 , ( mxArray * ) rtP .
StateSpace_P6_Size ) ; ssSetSFcnParam ( rts , 6 , ( mxArray * ) rtP .
StateSpace_P7_Size ) ; ssSetSFcnParam ( rts , 7 , ( mxArray * ) rtP .
StateSpace_P8_Size ) ; ssSetSFcnParam ( rts , 8 , ( mxArray * ) rtP .
StateSpace_P9_Size ) ; ssSetSFcnParam ( rts , 9 , ( mxArray * ) rtP .
StateSpace_P10_Size ) ; } ssSetRWork ( rts , ( real_T * ) & rtDW . oetzn5jscx
[ 0 ] ) ; ssSetIWork ( rts , ( int_T * ) & rtDW . czwcnoupsx [ 0 ] ) ;
ssSetPWork ( rts , ( void * * ) & rtDW . kytgfvyij5 [ 0 ] ) ; { static struct
_ssDWorkRecord dWorkRecord [ 4 ] ; static struct _ssDWorkAuxRecord
dWorkAuxRecord [ 4 ] ; ssSetSFcnDWork ( rts , dWorkRecord ) ;
ssSetSFcnDWorkAux ( rts , dWorkAuxRecord ) ; _ssSetNumDWork ( rts , 4 ) ;
ssSetDWorkWidth ( rts , 0 , 15 ) ; ssSetDWorkDataType ( rts , 0 , SS_INTEGER
) ; ssSetDWorkComplexSignal ( rts , 0 , 0 ) ; ssSetDWork ( rts , 0 , & rtDW .
jtyytfci20 [ 0 ] ) ; ssSetDWorkWidth ( rts , 1 , 2 ) ; ssSetDWorkDataType (
rts , 1 , SS_DOUBLE ) ; ssSetDWorkComplexSignal ( rts , 1 , 0 ) ; ssSetDWork
( rts , 1 , & rtDW . oetzn5jscx [ 0 ] ) ; ssSetDWorkWidth ( rts , 2 , 23 ) ;
ssSetDWorkDataType ( rts , 2 , SS_INTEGER ) ; ssSetDWorkComplexSignal ( rts ,
2 , 0 ) ; ssSetDWork ( rts , 2 , & rtDW . czwcnoupsx [ 0 ] ) ;
ssSetDWorkWidth ( rts , 3 , 22 ) ; ssSetDWorkDataType ( rts , 3 , SS_POINTER
) ; ssSetDWorkComplexSignal ( rts , 3 , 0 ) ; ssSetDWork ( rts , 3 , & rtDW .
kytgfvyij5 [ 0 ] ) ; } ssSetModeVector ( rts , ( int_T * ) & rtDW .
jtyytfci20 [ 0 ] ) ; sfun_spid_contc ( rts ) ; sfcnInitializeSizes ( rts ) ;
sfcnInitializeSampleTimes ( rts ) ; ssSetSampleTime ( rts , 0 , 0.0 ) ;
ssSetOffsetTime ( rts , 0 , 0.0 ) ; sfcnTsMap [ 0 ] = 0 ;
ssSetNumNonsampledZCs ( rts , 15 ) ; _ssSetInputPortConnected ( rts , 0 , 1 )
; _ssSetInputPortConnected ( rts , 1 , 1 ) ; _ssSetOutputPortConnected ( rts
, 0 , 1 ) ; _ssSetOutputPortConnected ( rts , 1 , 1 ) ;
_ssSetOutputPortBeingMerged ( rts , 0 , 0 ) ; _ssSetOutputPortBeingMerged (
rts , 1 , 0 ) ; ssSetInputPortBufferDstPort ( rts , 0 , - 1 ) ;
ssSetInputPortBufferDstPort ( rts , 1 , - 1 ) ; } } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 3 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID3 ( tid ) ; }
