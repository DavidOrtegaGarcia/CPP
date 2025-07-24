#pragma once

#include <iostream>
#include <stdint.h>

typedef struct tData
{
	int	data;
}	Data;

class Serializer 
{
	private:
		Serializer();
		Serializer(const Serializer &other);
		~Serializer();
		Serializer &operator = (const Serializer &other);
	public:
		static uintptr_t 	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
			
};