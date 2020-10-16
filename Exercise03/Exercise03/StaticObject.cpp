#include "StaticObject.h"

StaticObject::StaticObject(int id, TypeOfBarrier type) : Object(id), type(type)
{
}

TypeOfBarrier StaticObject::GetType() const
{
	return TypeOfBarrier();
}
