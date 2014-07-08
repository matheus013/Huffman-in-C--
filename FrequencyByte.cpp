#include "FrequencyByte.h"


FrequencyByte::FrequencyByte(){
    for(int i = 0;i < 256;i++){
        element[i] = i;
    }
}

char FrequencyByte::getElement(unsigned char element){
    return this->element[element];
}
long FrequencyByte::getFrequency(unsigned char element){
    return frequency[element];
}
void FrequencyByte::setFrequency(unsigned char frequency,int id){
    this->frequency[id] = frequency;
}

void FrequencyByte::plusFrequency(unsigned char element){
    this->frequency[element]++;
}
