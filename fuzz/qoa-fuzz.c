#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define QOA_IMPLEMENTATION
#include "../qoa.h"

unsigned int get_uint(const uint8_t* in) {
    return in[0] << 24 + in[1] << 16 + in[2] << 8 + in[3];
}

int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
    if (Size > 0) {
        uint8_t op = Data[Size - 1];
        qoa_desc desc;
        unsigned int len;
        switch (op) {
            case 0:
                if (Size > 2) {
                    desc.channels = Data[Size - 2];
                    desc.samplerate = Data[Size - 3];
                    desc.samples = Size / 2;
                    qoa_encode(Data, &desc, &len);
                }
                break;
            case 1:
                qoa_decode(Data, Size - 1, &desc);
                break;
        }
    }    
}