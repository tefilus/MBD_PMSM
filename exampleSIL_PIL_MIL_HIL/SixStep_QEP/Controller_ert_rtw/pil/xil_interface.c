/*
 * File: xil_interface.c
 *
 * PIL generated interface for code: "Controller"
 *
 */

#include "Controller.h"
#include "Controller_private.h"
#include "xil_interface.h"
#include "xil_instrumentation.h"

/* Functions with a C call interface */
#ifdef __cplusplus

extern "C"
{

#endif

#include "xil_data_stream.h"
#include "codeinstr_data_stream.h"
#ifdef __cplusplus

}

#endif

static XILIOData xil_fcnid0_task1_output_u[3];
static XILIOData xil_fcnid0_task4_output_u[2];
static XILIOData xil_fcnid0_task2_y[4];
static XILIOData xil_fcnid0_task3_y[3];
static XILIOData xil_fcnid0_init_y[6];

/* In-the-Loop Interface functions - see xil_interface.h */
XIL_INTERFACE_ERROR_CODE xilProcessParams(uint32_T xilFcnId)
{
  /* Single In-the-Loop Component */
  if (xilFcnId != 0) {
    return XIL_INTERFACE_UNKNOWN_FCNID;
  }

  return XIL_INTERFACE_SUCCESS;
}

void xilUploadCodeInstrData(void * pData, uint16_T numMemUnits, uint16_T
  sectionId)
{
  /* Send code instrumentation data to host */
  if (codeInstrWriteData((MemUnit_T *) &numMemUnits, sizeof(numMemUnits)) !=
      XIL_DATA_STREAM_SUCCESS) {
    for (;;) ;
  }

  if (codeInstrWriteData((MemUnit_T *) &sectionId, sizeof(uint16_T)) !=
      XIL_DATA_STREAM_SUCCESS) {
    for (;;) ;
  }

  if (codeInstrWriteData((MemUnit_T *) pData, numMemUnits) !=
      XIL_DATA_STREAM_SUCCESS) {
    for (;;) ;
  }
}

XIL_INTERFACE_ERROR_CODE xilGetDataTypeInfo(void)
{
  {
    /* send response id code */
    MemUnit_T memUnitData = XIL_RESPONSE_TYPE_SIZE;
    if (xilWriteData(&memUnitData, sizeof(memUnitData)) !=
        XIL_DATA_STREAM_SUCCESS) {
      return XIL_INTERFACE_COMMS_FAILURE;
    }

    /* send type id */
    memUnitData = 1;
    if (xilWriteData(&memUnitData, sizeof(memUnitData)) !=
        XIL_DATA_STREAM_SUCCESS) {
      return XIL_INTERFACE_COMMS_FAILURE;
    }

    /* PIL_FLOAT_SIZE should only be already defined for MathWorks testing */
#ifndef PIL_FLOAT_SIZE
#define PIL_FLOAT_SIZE                 sizeof(float)
#endif

    /* send size in bytes */
    memUnitData = (MemUnit_T) PIL_FLOAT_SIZE;

#ifndef HOST_WORD_ADDRESSABLE_TESTING

    /* convert MemUnits to bytes */
    memUnitData *= MEM_UNIT_BYTES;

#endif

    if (xilWriteData(&memUnitData, sizeof(memUnitData)) !=
        XIL_DATA_STREAM_SUCCESS) {
      return XIL_INTERFACE_COMMS_FAILURE;
    }
  }

  return XIL_INTERFACE_SUCCESS;
}

XIL_INTERFACE_ERROR_CODE xilInitialize(uint32_T xilFcnId)
{
  XIL_INTERFACE_ERROR_CODE errorCode = XIL_INTERFACE_SUCCESS;

  {
  }

  /* initialize output storage owned by In-the-Loop */
  {
    xilProfilingEstimateOverhead(2, 3, 4, 5, 1, 100);
  }

  /* Single In-the-Loop Component */
  if (xilFcnId == 0) {
    taskTimeStart_Controller(1U);
    Controller_initialize();
    taskTimeEnd_Controller(1U);
  } else {
    errorCode = XIL_INTERFACE_UNKNOWN_FCNID;
  }

  return errorCode;
}

XIL_INTERFACE_ERROR_CODE xilPause(uint32_T xilFcnId)
{
  XIL_INTERFACE_ERROR_CODE errorCode = XIL_INTERFACE_SUCCESS;
  if (xilFcnId == 0) {
    /* Nothing to do */
  } else {
    errorCode = XIL_INTERFACE_UNKNOWN_FCNID;
  }                                    /* if */

  return errorCode;
}

XIL_INTERFACE_ERROR_CODE xilSystemInitialize(uint32_T xilFcnId)
{
  XIL_INTERFACE_ERROR_CODE errorCode = XIL_INTERFACE_SUCCESS;

  /* Single In-the-Loop Component */
  if (xilFcnId == 0) {
    /* No Function to Call */
    /* No Function to Call */
  } else {
    errorCode = XIL_INTERFACE_UNKNOWN_FCNID;
  }

  return errorCode;
}

XIL_INTERFACE_ERROR_CODE xilSystemReset(uint32_T xilFcnId)
{
  XIL_INTERFACE_ERROR_CODE errorCode = XIL_INTERFACE_SUCCESS;

  /* Single In-the-Loop Component */
  if (xilFcnId == 0) {
    /* No Function to Call */
  } else {
    errorCode = XIL_INTERFACE_UNKNOWN_FCNID;
  }

  return errorCode;
}

XIL_INTERFACE_ERROR_CODE xilGetHostToTargetData(uint32_T xilFcnId,
  XIL_COMMAND_TYPE_ENUM xilCommandType, uint32_T xilCommandIdx, XILIOData
  ** xilIOData)
{
  XIL_INTERFACE_ERROR_CODE errorCode = XIL_INTERFACE_SUCCESS;
  *xilIOData = 0;

  /* Single In-the-Loop Component */
  if (xilFcnId != 0) {
    errorCode = XIL_INTERFACE_UNKNOWN_FCNID;
    return errorCode;
  }

  switch (xilCommandType) {
   case XIL_OUTPUT_COMMAND:
    {
      switch (xilCommandIdx) {
       case 1:
        {
          static int initComplete = 0;
          if (!initComplete) {
            uint32_T tableIdx = 0;

            {
              void * dataAddress = (void *) &(Controller_U.Iabc_fb[0]);
              xil_fcnid0_task1_output_u[tableIdx].memUnitLength = 3 * sizeof
                (uint16_T);
              xil_fcnid0_task1_output_u[tableIdx++].address = (MemUnit_T *)
                dataAddress;
            }

            {
              void * dataAddress = (void *) &(Controller_U.Hall_fb[0]);
              xil_fcnid0_task1_output_u[tableIdx].memUnitLength = 3 * sizeof
                (uint32_T);
              xil_fcnid0_task1_output_u[tableIdx++].address = (MemUnit_T *)
                dataAddress;
            }

            xil_fcnid0_task1_output_u[tableIdx].memUnitLength = 0;
            xil_fcnid0_task1_output_u[tableIdx++].address = (MemUnit_T *) 0;
            initComplete = 1;
          }                            /* if */

          *xilIOData = &xil_fcnid0_task1_output_u[0];
          break;
        }

       case 4:
        {
          static int initComplete = 0;
          if (!initComplete) {
            uint32_T tableIdx = 0;

            {
              void * dataAddress = (void *) &(Controller_U.Speed_ref);
              xil_fcnid0_task4_output_u[tableIdx].memUnitLength = 1 * sizeof
                (real32_T);
              xil_fcnid0_task4_output_u[tableIdx++].address = (MemUnit_T *)
                dataAddress;
            }

            xil_fcnid0_task4_output_u[tableIdx].memUnitLength = 0;
            xil_fcnid0_task4_output_u[tableIdx++].address = (MemUnit_T *) 0;
            initComplete = 1;
          }                            /* if */

          *xilIOData = &xil_fcnid0_task4_output_u[0];
          break;
        }

       default:
        errorCode = XIL_INTERFACE_UNKNOWN_TID;
        break;
      }
      break;
    }

   default:
    errorCode = XIL_INTERFACE_UNKNOWN_TID;
    break;
  }

  return errorCode;
}

XIL_INTERFACE_ERROR_CODE xilGetTargetToHostPreData(uint32_T xilFcnId,
  XIL_COMMAND_TYPE_ENUM xilCommandType, uint32_T xilCommandIdx, XILIOData
  ** xilIOData, MemUnit_T responseId, uint32_T serverFcnId)
{
  XIL_INTERFACE_ERROR_CODE errorCode = XIL_INTERFACE_SUCCESS;
  *xilIOData = 0;
  if (xilFcnId != 0) {
    errorCode = XIL_INTERFACE_UNKNOWN_FCNID;
    return errorCode;
  }                                    /* if */

  errorCode = XIL_INTERFACE_UNKNOWN_TID;
  UNUSED_PARAMETER(xilCommandType);
  UNUSED_PARAMETER(xilCommandIdx);
  UNUSED_PARAMETER(responseId);
  UNUSED_PARAMETER(serverFcnId);
  return errorCode;
}

XIL_INTERFACE_ERROR_CODE xilOutput(uint32_T xilFcnId, uint32_T xilTID)
{
  /* Single In-the-Loop Component */
  if (xilFcnId != 0) {
    return XIL_INTERFACE_UNKNOWN_FCNID;
  }

  switch (xilTID) {
   case 1:
    taskTimeStart_Controller(2U);
    Controller_step0();
    taskTimeEnd_Controller(2U);
    break;

   case 2:
    taskTimeStart_Controller(3U);
    Controller_step1();
    taskTimeEnd_Controller(3U);
    break;

   case 3:
    taskTimeStart_Controller(4U);
    Controller_step2();
    taskTimeEnd_Controller(4U);
    break;

   case 4:
    taskTimeStart_Controller(5U);
    Controller_step3();
    taskTimeEnd_Controller(5U);
    break;

   default:
    return XIL_INTERFACE_UNKNOWN_TID;
  }

  return XIL_INTERFACE_SUCCESS;
}

XIL_INTERFACE_ERROR_CODE xilUpdate(uint32_T xilFcnId, uint32_T xilTID)
{
  /* Single In-the-Loop Component */
  if (xilFcnId != 0) {
    return XIL_INTERFACE_UNKNOWN_FCNID;
  }

  /* No Update Function */
  UNUSED_PARAMETER(xilTID);
  return XIL_INTERFACE_SUCCESS;
}

XIL_INTERFACE_ERROR_CODE xilGetTargetToHostData(uint32_T xilFcnId,
  XIL_COMMAND_TYPE_ENUM xilCommandType, uint32_T xilCommandIdx, XILIOData
  ** xilIOData, MemUnit_T responseId, uint32_T serverFcnId)
{
  XIL_INTERFACE_ERROR_CODE errorCode = XIL_INTERFACE_SUCCESS;

  /* Single In-the-Loop Component */
  *xilIOData = 0;
  if (xilFcnId != 0) {
    errorCode = XIL_INTERFACE_UNKNOWN_FCNID;
    return errorCode;
  }

  switch (xilCommandType) {
   case XIL_INITIALIZE_COMMAND:
    {
      static int initComplete = 0;
      if (!initComplete) {
        uint32_T tableIdx = 0;

        {
          void * dataAddress = (void *) &(Controller_Y.Speedref);
          xil_fcnid0_init_y[tableIdx].memUnitLength = 1 * sizeof(real32_T);
          xil_fcnid0_init_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(Controller_Y.Speedfb);
          xil_fcnid0_init_y[tableIdx].memUnitLength = 1 * sizeof(real32_T);
          xil_fcnid0_init_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(Controller_Y.Dutycycles[0]);
          xil_fcnid0_init_y[tableIdx].memUnitLength = 6 * sizeof(real32_T);
          xil_fcnid0_init_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(Controller_Y.Idcref);
          xil_fcnid0_init_y[tableIdx].memUnitLength = 1 * sizeof(real32_T);
          xil_fcnid0_init_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(Controller_Y.Idc_fb);
          xil_fcnid0_init_y[tableIdx].memUnitLength = 1 * sizeof(real32_T);
          xil_fcnid0_init_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        xil_fcnid0_init_y[tableIdx].memUnitLength = 0;
        xil_fcnid0_init_y[tableIdx++].address = (MemUnit_T *) 0;
        initComplete = 1;
      }                                /* if */

      {
        if (xilWriteData(&responseId, sizeof(responseId)) !=
            XIL_DATA_STREAM_SUCCESS) {
          return XIL_INTERFACE_COMMS_FAILURE;
        }                              /* if */

        if (responseId == XIL_RESPONSE_CS_REQUEST_SERVICE) {
          if (xilWriteData((MemUnit_T *) &serverFcnId, sizeof(serverFcnId)) !=
              XIL_DATA_STREAM_SUCCESS) {
            return XIL_INTERFACE_COMMS_FAILURE;
          }                            /* if */
        }                              /* if */
      }

      *xilIOData = &xil_fcnid0_init_y[0];
      break;
    }

   case XIL_OUTPUT_COMMAND:
    {
      switch (xilCommandIdx) {
       case 2:
        {
          static int initComplete = 0;
          if (!initComplete) {
            uint32_T tableIdx = 0;

            {
              void * dataAddress = (void *) &(Controller_Y.Dutycycles[0]);
              xil_fcnid0_task2_y[tableIdx].memUnitLength = 6 * sizeof(real32_T);
              xil_fcnid0_task2_y[tableIdx++].address = (MemUnit_T *) dataAddress;
            }

            {
              void * dataAddress = (void *) &(Controller_Y.Idcref);
              xil_fcnid0_task2_y[tableIdx].memUnitLength = 1 * sizeof(real32_T);
              xil_fcnid0_task2_y[tableIdx++].address = (MemUnit_T *) dataAddress;
            }

            {
              void * dataAddress = (void *) &(Controller_Y.Idc_fb);
              xil_fcnid0_task2_y[tableIdx].memUnitLength = 1 * sizeof(real32_T);
              xil_fcnid0_task2_y[tableIdx++].address = (MemUnit_T *) dataAddress;
            }

            xil_fcnid0_task2_y[tableIdx].memUnitLength = 0;
            xil_fcnid0_task2_y[tableIdx++].address = (MemUnit_T *) 0;
            initComplete = 1;
          }                            /* if */

          {
            if (xilWriteData(&responseId, sizeof(responseId)) !=
                XIL_DATA_STREAM_SUCCESS) {
              return XIL_INTERFACE_COMMS_FAILURE;
            }                          /* if */

            if (responseId == XIL_RESPONSE_CS_REQUEST_SERVICE) {
              if (xilWriteData((MemUnit_T *) &serverFcnId, sizeof(serverFcnId))
                  != XIL_DATA_STREAM_SUCCESS) {
                return XIL_INTERFACE_COMMS_FAILURE;
              }                        /* if */
            }                          /* if */
          }

          *xilIOData = &xil_fcnid0_task2_y[0];
          break;
        }

       case 3:
        {
          static int initComplete = 0;
          if (!initComplete) {
            uint32_T tableIdx = 0;

            {
              void * dataAddress = (void *) &(Controller_Y.Speedref);
              xil_fcnid0_task3_y[tableIdx].memUnitLength = 1 * sizeof(real32_T);
              xil_fcnid0_task3_y[tableIdx++].address = (MemUnit_T *) dataAddress;
            }

            {
              void * dataAddress = (void *) &(Controller_Y.Speedfb);
              xil_fcnid0_task3_y[tableIdx].memUnitLength = 1 * sizeof(real32_T);
              xil_fcnid0_task3_y[tableIdx++].address = (MemUnit_T *) dataAddress;
            }

            xil_fcnid0_task3_y[tableIdx].memUnitLength = 0;
            xil_fcnid0_task3_y[tableIdx++].address = (MemUnit_T *) 0;
            initComplete = 1;
          }                            /* if */

          {
            if (xilWriteData(&responseId, sizeof(responseId)) !=
                XIL_DATA_STREAM_SUCCESS) {
              return XIL_INTERFACE_COMMS_FAILURE;
            }                          /* if */

            if (responseId == XIL_RESPONSE_CS_REQUEST_SERVICE) {
              if (xilWriteData((MemUnit_T *) &serverFcnId, sizeof(serverFcnId))
                  != XIL_DATA_STREAM_SUCCESS) {
                return XIL_INTERFACE_COMMS_FAILURE;
              }                        /* if */
            }                          /* if */
          }

          *xilIOData = &xil_fcnid0_task3_y[0];
          break;
        }

       default:
        errorCode = XIL_INTERFACE_UNKNOWN_TID;
        break;
      }
      break;
    }

   default:
    errorCode = XIL_INTERFACE_UNKNOWN_TID;
    break;
  }

  return errorCode;
}

XIL_INTERFACE_ERROR_CODE xilTerminate(uint32_T xilFcnId)
{
  if (xilFcnId != 0) {
    return XIL_INTERFACE_UNKNOWN_FCNID;
  }                                    /* if */

  /* Invoke any terminate Function */
  taskTimeStart_Controller(6U);
  Controller_terminate();
  taskTimeEnd_Controller(6U);

  /* Free Opaque Region Based Data */
  return XIL_INTERFACE_SUCCESS;
}

XIL_INTERFACE_ERROR_CODE xilInitTargetData()
{
  return XIL_INTERFACE_SUCCESS;
}

XIL_INTERFACE_ERROR_CODE xilEnable(uint32_T xilFcnId, uint32_T xilTID)
{
  /* Single In-the-Loop Component */
  if (xilFcnId != 0) {
    return XIL_INTERFACE_UNKNOWN_FCNID;
  }

  UNUSED_PARAMETER(xilTID);

  /* No Enable Function - this function should never be called */
  return XIL_INTERFACE_UNKNOWN_TID;
}

XIL_INTERFACE_ERROR_CODE xilDisable(uint32_T xilFcnId, uint32_T xilTID)
{
  /* Single In-the-Loop Component */
  if (xilFcnId != 0) {
    return XIL_INTERFACE_UNKNOWN_FCNID;
  }

  UNUSED_PARAMETER(xilTID);

  /* No Disable Function - this function should never be called */
  return XIL_INTERFACE_UNKNOWN_TID;
}
