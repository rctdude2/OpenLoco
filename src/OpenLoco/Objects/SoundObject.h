#pragma once

#include "../Types.hpp"
#include "Object.h"

namespace OpenLoco
{
    namespace SoundObjectId
    {
        constexpr SoundObjectId_t null = 0xFF;
    }
#pragma pack(push, 1)
    struct SoundObject
    {
        static constexpr auto kObjectType = ObjectType::sound;

        string_id name;
        void* data;
        uint8_t var_06;
        uint8_t pad_07;
        uint32_t volume; // 0x08
    };
#pragma pack(pop)
}
