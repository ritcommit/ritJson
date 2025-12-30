/**
 * ritJson.c
 * @brief 1 depth JSON serializer for lightweight implementation
 * on MCUs to convert variable data into JSON string and send in
 * key value pairs for mqtt or other iot communications
 * @author ritesh sharma (https://github.com/ritcommit)
 * @date 24/12/2025
 * @license MIT, no guarantees whatsover, developed for personal use
 * released for public
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ritJson.h>

static int size = 0;

void ritJson_Open(char* buffer)
{
    size = 0;
    buffer[size++] = '{';
}

void ritJson_Close(char* buffer)
{
    buffer[size-1] = '}';
    buffer[size] = '\0';
}

void ritJson_addObject(char* buffer, char* key, void* value, ritJson_datatype_t dtype)
{
    char* val_str = NULL;
    switch(dtype)
    {
        case RITJSON_TYPE_INT8:
            val_str = (char*)calloc(4, 1);
            snprintf(val_str, 5, "%d", *((int8_t*)value));
            break;
        case RITJSON_TYPE_INT16:
            val_str = (char*)calloc(6, 1);
            snprintf(val_str, 7, "%d", *((int16_t*)value));
            break;
        case RITJSON_TYPE_INT32:
            val_str = (char*)calloc(11, 1);
            snprintf(val_str, 11, "%d", *((int32_t*)value));
            break;
        case RITJSON_TYPE_UINT8:
            val_str = (char*)calloc(4, 1);
            snprintf(val_str, 5, "%u", *((uint8_t*)value));
            break;
        case RITJSON_TYPE_UINT16:
            val_str = (char*)calloc(6, 1);
            snprintf(val_str, 7, "%u", *((uint16_t*)value));
            break;
        case RITJSON_TYPE_UINT32:
        case RITJSON_TYPE_INT:
            val_str = (char*)calloc(11, 1);
            snprintf(val_str, 11, "%lu", *((uint32_t*)value));
            break;
        case RITJSON_TYPE_FLOAT:
            val_str = (char*)calloc(21, 1);
            snprintf(val_str, 21, "%0.3f", *((float*)value));
            break;
        case RITJSON_TYPE_STRING:
            val_str = (char*)calloc(strlen(value), 1);
            strncpy(val_str, (char*)value, strlen(value));
            break;
        default:
            break;
    }
    if (val_str != NULL)
    {
        buffer[size++] = '\"';
        strncpy(&buffer[size], key, strlen(key));
        size += strlen(key);
        buffer[size++] = '\"';
        buffer[size++] = ':';
        if (dtype == RITJSON_TYPE_STRING)
        {
            buffer[size++] = '\"';
        }
        strncpy(&buffer[size], val_str, strlen(val_str));
        size += strlen(val_str);
        if (dtype == RITJSON_TYPE_STRING)
        {
            buffer[size++] = '\"';
        }
        buffer[size++] = ',';
    }
    free(val_str);
}





