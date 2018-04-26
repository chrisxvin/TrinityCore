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

  /* ScriptData
  Name: cx_cheat_commandscript
  %Complete: 100
  Comment: Chris cheat commands.
  Category: commandscripts
  EndScriptData */

#include "ScriptMgr.h"
#include "ObjectMgr.h"
#include "Chat.h"
#include "AccountMgr.h"
#include "Language.h"
#include "World.h"
#include "WorldSession.h"
#include "Player.h"
#include "Opcodes.h"
#include "cx_script.h"

class cx_cheat_commandscript : public CommandScript
{
public:
    cx_cheat_commandscript() : CommandScript("cx_cheat_commandscript") { }

    std::vector<ChatCommand> GetCommands() const override
    {
        /*
        static std::vector<ChatCommand> gmCommandTable =
        {
            { "chat",    rbac::RBAC_PERM_COMMAND_GM_CHAT,    false, &HandleGMChatCommand,       "" },
            { "fly",     rbac::RBAC_PERM_COMMAND_GM_FLY,     false, &HandleGMFlyCommand,        "" },
            { "ingame",  rbac::RBAC_PERM_COMMAND_GM_INGAME,   true, &HandleGMListIngameCommand, "" },
            { "list",    rbac::RBAC_PERM_COMMAND_GM_LIST,     true, &HandleGMListFullCommand,   "" },
            { "visible", rbac::RBAC_PERM_COMMAND_GM_VISIBLE, false, &HandleGMVisibleCommand,    "" },
            { "",        rbac::RBAC_PERM_COMMAND_GM,         false, &HandleGMCommand,           "" },
        };
        */
        static std::vector<ChatCommand> commandTable =
        {
            { "wt",      rbac::RBAC_PERM_COMMAND_HELP,            false, &HandleWorldTalkCommand, ""},
            //{ "gm", rbac::RBAC_PERM_COMMAND_GPS, false, NULL, "", gmCommandTable },
        };
        return commandTable;
    }

    static bool HandleWorldTalkCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        std::string name("Console");
        if (WorldSession* session = handler->GetSession())
        {
            Player* p = session->GetPlayer();
            uint32 cost = WORLD_TALK_COST;
            if (session->GetSecurity() == SEC_ADMINISTRATOR)
                cost = 0;

            auto money = p->GetMoney();
            if (money < cost)
            {
                sWorld->SendServerMessage(SERVER_MSG_STRING, "Need at least 1 Gold to talk to the world!", p);
                return true;
            }

            name = session->GetPlayer()->GetName();
            p->SetMoney(money - cost);
        }

        sWorld->SendWorldText(LANG_ANNOUNCE_COLOR, name.c_str(), args);
        return true;
    }
};

void AddSC_cx_cheat_commandscript()
{
    new cx_cheat_commandscript();
}
