//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "player.h"
#include "P_PDU_m.h"
#include "DL_PDU_m.h"
Define_Module(Player);

void Player::initialize()
{
    // TODO - Generated method body
}

void Player::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    if(msg->getArrivalGate()==gate("fromdlin"))
   {
       P_PDU* ppdu=new P_PDU();
       DL_PDU *dpdu=check_and_cast<DL_PDU *>(msg);
       ppdu->encapsulate(dpdu);
       send(ppdu,gate("tonodeout"));
   }else if(msg->getArrivalGate()==gate("fromnodein"))
   {
       P_PDU* ppdu=check_and_cast<P_PDU*>(msg);
       send(ppdu->decapsulate(),gate("todlout"));
   }
}
