/**
 * ritJson.h
 * @brief header file for 1 depth JSON serializer for lightweight implementation
 * on MCUs to convert variable data into JSON string and send in
 * JSON formatted key value pairs for mqtt or other iot communications
 * @author ritesh sharma (https://github.com/ritcommit)
 * @date 24/12/2025
 * @license MIT, no guarantees whatsover, developed for personal use
 * released for public
 */

#ifndef _RIT_JSON_H_
#define _RIT_JSON_H_

typedef enum
{
    RITJSON_TYPE_INT8=0,
    RITJSON_TYPE_INT16,
    RITJSON_TYPE_INT32,
    RITJSON_TYPE_INT,
    RITJSON_TYPE_UINT8,
    RITJSON_TYPE_UINT16,
    RITJSON_TYPE_UINT32,
    RITJSON_TYPE_FLOAT,
    RITJSON_TYPE_STRING
} ritJson_datatype_t;

void ritJson_Open(char* buffer);
void ritJson_Close(char* buffer);
void ritJson_addObject(char* buffer, char* key, void* value, ritJson_datatype_t dtype);

#endif /* _RIT_JSON_H_ */