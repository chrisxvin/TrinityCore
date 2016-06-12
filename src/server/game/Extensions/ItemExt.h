/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

 /*
  * Copyright (C) 2010-2016 Chris Infinity <http://www.ixvin.com/>
  * All rights reserved.
  */

#ifndef __ItemExt__h
#define __ItemExt__h

#include "Common.h"

#define CX_MAX_SAVED_LOC 8
#define CX_ITEMUPG_MATERIAL_COUNT 5
#define CX_ITEMUPG_ELIXR_SUCC_RATE 0.5
#define CX_ITEMUPG_MAX_INCREASED_SUCC_RATE 0.9

enum CXSpecialItems
{
    CXITEM_UPGRADE_TOOLBOX              = 211001,
    CXITEM_UPGRADE_ELIXR                = 211002,
    CXITEM_UNBINDER                     = 211004,
    CXITEM_ONLINE_TICKET                = 211005,
};

struct TeleLocation
{
    uint32 map;
    float x;
    float y;
    float z;
    float o;
};

#endif // __ItemExt__h
