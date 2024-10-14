#ifndef ERRLIB_RESULT_H
#define ERRLIB_RESULT_H

#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define RESULT_SET_ERROR(result, err_msg){\
    (result).info.is_error = true;\
    (result).info.msg = err_msg;\
}

#define RESULT_SET_SUCCESS(result, result_value){\
    (result).info.is_error = false;\
    (result).info.msg = NULL;\
    (result).value = result_value;\
}

typedef struct ResultInfo
{
    bool is_error;
    char* msg;
} ResultInfo;

typedef struct ResultBool
{
    ResultInfo info;
    bool value;
} ResultBool;

typedef struct ResultUint8
{
    ResultInfo info;
    uint8_t value;
} ResultUint8;

typedef struct ResultUint16
{
    ResultInfo info;
    uint16_t value;
} ResultUint16;

typedef struct ResultUint32
{
    ResultInfo info;
    uint32_t value;
} ResultUint32;

typedef struct ResultUint64
{
    ResultInfo info;
    uint64_t value;
} ResultUint64;

typedef struct ResultInt8
{
    ResultInfo info;
    int8_t value;
} ResultInt8;

typedef struct ResultInt16
{
    ResultInfo info;
    int16_t value;
} ResultInt16;

typedef struct ResultInt32
{
    ResultInfo info;
    int32_t value;
} ResultInt32;

typedef struct ResultInt64
{
    ResultInfo info;
    int64_t value;
} ResultInt64;

typedef struct ResultSize
{
    ResultInfo info;
    size_t value;
} ResultSize;

typedef struct ResultOwnedString
{
    ResultInfo info;
    char* value;
} ResultOwnedString;

typedef struct ResultReadString
{
    ResultInfo info;
    char* value;
} ResultReadString;

typedef struct ResultFloat
{
    ResultInfo info;
    float value;
} ResultFloat;

typedef struct ResultDouble
{
    ResultInfo info;
    double value;
} ResultDouble;

#endif
