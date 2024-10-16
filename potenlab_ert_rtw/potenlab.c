/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: potenlab.c
 *
 * Code generated for Simulink model 'potenlab'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue Oct  8 01:22:17 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "potenlab.h"
#include "potenlab_types.h"
#include "stm_adc_ll.h"
#include <stddef.h>
#include "potenlab_private.h"

/* Block signals (default storage) */
B_potenlab_T potenlab_B;

/* Block states (default storage) */
DW_potenlab_T potenlab_DW;

/* Real-time model */
static RT_MODEL_potenlab_T potenlab_M_;
RT_MODEL_potenlab_T *const potenlab_M = &potenlab_M_;

/* Forward declaration for local functions */
static void potenlab_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj);
static void potenlab_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj)
{
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S3>/Analog to Digital Converter' */
  obj->isInitialized = 1;
  adcStructLoc.InternalBufferPtr = (void *)(NULL);

  /* Start for MATLABSystem: '<S3>/Analog to Digital Converter' */
  adcStructLoc.InjectedNoOfConversion = 0U;
  adcStructLoc.peripheralPtr = ADC1;
  adcStructLoc.dmaPeripheralPtr = NULL;
  adcStructLoc.dmastream = 0;
  adcStructLoc.DataTransferMode = ADC_DR_TRANSFER;
  adcStructLoc.DmaTransferMode = ADC_DMA_TRANSFER_LIMITED;
  adcStructLoc.InternalBufferSize = 1U;
  adcStructLoc.RegularNoOfConversion = 1U;
  obj->ADCHandle = ADC_Handle_Init(&adcStructLoc, ADC_NORMAL_MODE, 1,
    ADC_TRIGGER_AND_READ, LL_ADC_REG_SEQ_SCAN_DISABLE);
  enableADCAutomaticCalibrationOffset(obj->ADCHandle, 2);
  enableADC(obj->ADCHandle);
  startADCConversionForExternalTrigger(obj->ADCHandle, 1);
  obj->isSetupComplete = true;
}

/* Model step function */
void potenlab_step(void)
{
  /* MATLABSystem: '<S3>/Analog to Digital Converter' */
  regularReadADCNormal(potenlab_DW.obj.ADCHandle, ADC_TRIGGER_AND_READ,
                       &potenlab_B.AnalogtoDigitalConverter);

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  potenlab_M->Timing.taskTime0 =
    ((time_T)(++potenlab_M->Timing.clockTick0)) * potenlab_M->Timing.stepSize0;
}

/* Model initialize function */
void potenlab_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(potenlab_M, -1);
  potenlab_M->Timing.stepSize0 = 0.2;

  /* External mode info */
  potenlab_M->Sizes.checksums[0] = (950023833U);
  potenlab_M->Sizes.checksums[1] = (1737259248U);
  potenlab_M->Sizes.checksums[2] = (3984138373U);
  potenlab_M->Sizes.checksums[3] = (21187978U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    potenlab_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(potenlab_M->extModeInfo,
      &potenlab_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(potenlab_M->extModeInfo, potenlab_M->Sizes.checksums);
    rteiSetTPtr(potenlab_M->extModeInfo, rtmGetTPtr(potenlab_M));
  }

  /* Start for MATLABSystem: '<S3>/Analog to Digital Converter' */
  potenlab_DW.obj.isInitialized = 0;
  potenlab_DW.obj.matlabCodegenIsDeleted = false;
  potenlab_SystemCore_setup(&potenlab_DW.obj);
}

/* Model terminate function */
void potenlab_terminate(void)
{
  /* Terminate for MATLABSystem: '<S3>/Analog to Digital Converter' */
  if (!potenlab_DW.obj.matlabCodegenIsDeleted) {
    potenlab_DW.obj.matlabCodegenIsDeleted = true;
    if ((potenlab_DW.obj.isInitialized == 1) && potenlab_DW.obj.isSetupComplete)
    {
      ADC_Handle_Deinit(potenlab_DW.obj.ADCHandle, ADC_NORMAL_MODE, 1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Analog to Digital Converter' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
