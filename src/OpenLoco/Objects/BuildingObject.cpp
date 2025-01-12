#include "BuildingObject.h"
#include "../Graphics/Colour.h"
#include "../Graphics/Gfx.h"
#include "../Interop/Interop.hpp"
#include "ObjectManager.h"

using namespace OpenLoco::Interop;

namespace OpenLoco
{
    // 0x0042DE40
    void BuildingObject::drawPreviewImage(Gfx::Context& context, const int16_t x, const int16_t y) const
    {
        Colour_t colour = Utility::bitScanReverse(colours);

        if (colour == 0xFF)
        {
            colour = 0;
        }

        drawBuilding(&context, 1, x, y + 40, colour);
    }

    // 0x0042DB95
    void BuildingObject::drawBuilding(Gfx::Context* clipped, uint8_t buildingRotation, int16_t x, int16_t y, Colour_t colour) const
    {
        registers regs;
        regs.cx = x;
        regs.dx = y;
        regs.esi = colour;
        regs.eax = buildingRotation;
        regs.edi = X86Pointer(clipped);
        regs.ebp = X86Pointer(this);
        call(0x0042DB95, regs);
    }

    // 0x0042DE82
    void BuildingObject::drawDescription(Gfx::Context& context, const int16_t x, const int16_t y, [[maybe_unused]] const int16_t width) const
    {
        Ui::Point rowPosition = { x, y };
        ObjectManager::drawGenericDescription(context, rowPosition, designedYear, obsoleteYear);
    }
}
