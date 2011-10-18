/*
 * AnimationValue.cpp
 */

#include "Base.h"
#include "AnimationValue.h"

namespace gameplay
{

AnimationValue::AnimationValue(unsigned int componentCount)
  : _componentCount(componentCount)
{
    _currentValue = new float[_componentCount];
    //_initialValue = new float[_componentCount];
}

AnimationValue::~AnimationValue()
{
    /*
    SAFE_DELETE_ARRAY(_initialValue);
    */
    SAFE_DELETE_ARRAY(_currentValue);
}

float AnimationValue::getFloat(unsigned int index) const
{
    assert(index < _componentCount);

    return _currentValue[index];
}

void AnimationValue::setFloat(unsigned int index, float value)
{
    assert(index < _componentCount);

    _currentValue[index] = value;
}

void AnimationValue::getFloat(float* value, unsigned int offset, unsigned int length) const
{
    assert(value && offset < _componentCount && (offset + length) <= _componentCount);

    memcpy(value + offset, _currentValue, length * sizeof(float));
}

void AnimationValue::setFloat(float* value, unsigned int offset, unsigned int length)
{
    assert(value && offset < _componentCount && (offset + length) <= _componentCount);

    memcpy(_currentValue, value + offset, length * sizeof(float));
}

/*
void AnimationValue::setInitialToCurrent()
{
    memcpy(_initialValue, _currentValue, sizeof(float) * _componentCount);
}

void AnimationValue::setCurrentToInitial()
{
    memcpy(_currentValue, _initialValue, sizeof(float) * _componentCount);
}
*/

}