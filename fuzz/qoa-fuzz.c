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
        uint8_t op = Data[0];
        qoa_desc desc;
        unsigned int len;
        void* res = 0;
        switch (op) {
            case 0:
                if (Size > 2) {
                    desc.channels = 1;
                    desc.samplerate = 1;
                    desc.samples = Size - 1;
                    res = qoa_encode(Data + 1, &desc, &len);
                    if (res) {
                        free(res);
                    }
                }
                break;
            case 1:
                res = qoa_decode(Data + 1, Size - 1, &desc);
                if (res) {
                    free(res);
                }
                break;
        }
    }    
}