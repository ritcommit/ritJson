/**
 * main.c
 * @brief example use of ritJson
 * @author ritesh sharma (https://github.com/ritcommit)
 * @date 24/12/2025
 * @license MIT, no guarantees whatsover, developed for personal use
 * released for public
 */
#include <stdio.h>
#include <stdint.h>
#include <ritJson.h>

int main()
{
    /* data */
    uint8_t soc=50;
    int voltage=6550;
    char* batt_name="ABCDE";
    float current=-21.10;

    /* buffer, make sure size is sufficient */
    char buffer[512] = {0};

    /* start serialization */
    ritJson_Open(buffer);

    /**
     * add various json objects 
     * @parameters (output string buffer, json key, adress of value, data type)
     */

    ritJson_addObject(buffer, "SOC", &soc, RITJSON_TYPE_UINT8);
    ritJson_addObject(buffer, "VOLTAGE", &voltage, RITJSON_TYPE_INT);
    ritJson_addObject(buffer, "NAME", batt_name, RITJSON_TYPE_STRING);
    ritJson_addObject(buffer, "CURRENT", &current, RITJSON_TYPE_FLOAT);

    /* end serialization */
    ritJson_Close(buffer);

    /* print Json formatted serial buffer*/
    printf("ritJson Serialized JSON Data:\n%s\n", buffer);
    return 0;
}