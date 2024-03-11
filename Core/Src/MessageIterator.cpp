#include "MessageIterator.h"

void MessageIterator::operator++() 
{

}

MESSAGE& MessageIterator::operator*() 
{
    return *reinterpret_cast<MESSAGE*>(RawDataMessagePointer);
}
