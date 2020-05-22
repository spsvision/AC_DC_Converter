#include "three_level_PWM_ac_dc_conv_capi_host.h"
static three_level_PWM_ac_dc_conv_host_DataMapInfo_T root;
static int initialized = 0;
__declspec( dllexport ) rtwCAPI_ModelMappingInfo *getRootMappingInfo()
{
    if (initialized == 0) {
        initialized = 1;
        three_level_PWM_ac_dc_conv_host_InitializeDataMapInfo(&(root), "three_level_PWM_ac_dc_conv");
    }
    return &root.mmi;
}

rtwCAPI_ModelMappingInfo *mexFunction() {return(getRootMappingInfo());}
