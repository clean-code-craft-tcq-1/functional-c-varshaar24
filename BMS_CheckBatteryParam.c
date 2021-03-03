
#include "BMS_Display.h"


static int CheckParameterUpperLimit(float Paramvalue_f, float ParamUpperLimit_f)
{
    int returnVal_u8=0;

    returnVal_u8 = Paramvalue_f > ParamUpperLimit_f ? 1 : 0;

    return returnVal_u8;

}

static int CheckParameterLowerLimit(float Paramvalue_f, float ParamLowerLimit_f)
{
    int returnVal_u8=0;

    returnVal_u8 = Paramvalue_f < ParamLowerLimit_f ? 1 : 0;

    return returnVal_u8;

}

int CheckTemperatureInRange(float ParamVal_f, float UL, float LL)
{
    int returnVal_u8 = 1;
    char *BatterParameterName = "Temperature";

    if( CheckParameterLowerLimit(ParamVal_f,LL))
    {
        DisplayParameterLLErrorStatus(BatterParameterName,LL);
        returnVal_u8 = 0;
    }
    else if(CheckParameterUpperLimit(ParamVal_f,UL))
    {
        DisplayParameterULErrorStatus(BatterParameterName,UL);
        returnVal_u8 = 0;
    }
    else
    {

    }
    return returnVal_u8;
}

int CheckSocInRange(float ParamVal_f, float UL, float LL)
{
    int returnVal_u8 = 1;
    char *BatterParameterName = "State of Charge";

    if( CheckParameterLowerLimit(ParamVal_f,LL))
    {
        DisplayParameterLLErrorStatus(BatterParameterName,LL);
        returnVal_u8 = 0;
    }
    else if(CheckParameterUpperLimit(ParamVal_f,UL))
    {
        DisplayParameterULErrorStatus(BatterParameterName,UL);
        returnVal_u8 = 0;
    }
    else
    {

    }
    return returnVal_u8;
}

int CheckChargeRateInRange(float ParamVal_f, float UL)
{
    int returnVal_u8 = 1;
    char *BatterParameterName = "Charge Rate";

    if(CheckParameterUpperLimit(ParamVal_f,UL))
    {
        DisplayParameterULErrorStatus(BatterParameterName,UL);
        returnVal_u8 = 0;
    }

    return returnVal_u8;
}
