# ritJson

[![License](https://img.shields.io/github/license/sanny32/OpenModSim)](LICENSE)

lightweight JSON serializer for MCUs

## Welcome to ritJson

* ritJson converts a pair of keys and values of various datatypes into a JSON string suitable for sending as iot message
* 2 file library
* Supported data types with their equivalent ritJson datatypes are:

| C Datatype | ritJson Datatype |
| ---------- | ---------------- |
| int8_t | RITJSON_TYPE_INT8 | 
| int16_t | RITJSON_TYPE_INT16 |
| int32_t | RITJSON_TYPE_INT32 |
| int | RITJSON_TYPE_INT |
| uint8_t | RITJSON_TYPE_UINT8 |
| uint16_t | RITJSON_TYPE_UINT16 |
| uint32_t | RITJSON_TYPE_UINT32 |
| float | RITJSON_TYPE_FLOAT |
| char* | RITJSON_TYPE_STRING |

* Does not support arrays, will be added soon
* Uses `snprintf()` and `strncpy()`methods, ensure they are supported in your MCU else modify `ritJson.c` to use `sprintf()` and `strcpy()` instead
* Valgrind checked: no memory leakage

## Usage

* Add ritJson.c and ritJson.h to your project
* Declare a JSON output char buffer with sufficient size
* Add individual key data pairs using `ritJson_addObject()` method
* Parameters:
    * JSON buffer
    * "KEY"
    * Pointer to value
    * ritJson Datatype
* Example:

```c
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
```

## Build Example

```sh
mkdir build
cd build\
cmake ..
make
./ritJson
#output
ritJson Serialized JSON Data:
{"SOC":50,"VOLTAGE":6550,"NAME":"ABCDE","CURRENT":-21.100}
```

## Contributor
[Ritesh Sharma](https://www.linkedin.com/in/ritexarma/)