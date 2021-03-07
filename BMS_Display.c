#include <stdio.h>




void DisplayParameterLLErrorStatus(char * BatterParameterName_p ,float ParamLimit_f)
{
    printf("Alert: %s  is less than %f !\n",BatterParameterName_p,ParamLimit_f);
}
void DisplayParameterULErrorStatus(char * BatterParameterName_p,float ParamLimit_f)
{
    printf("Alert: %s  is greater than %f!\n",BatterParameterName_p,ParamLimit_f);
}
