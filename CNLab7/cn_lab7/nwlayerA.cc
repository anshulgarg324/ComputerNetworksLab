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

#include "nwlayerA.h"
#include "A_PDU_m.h"
#include "NW_PDU_m.h"
Define_Module(NwlayerA);

void NwlayerA::initialize()
{
    nid=par("nid");
    src=par("src");
    dest=par("dest");
    numSent=0;
    numRec=0;
    WATCH(numRec);
    WATCH(numSent);
    table[1]=make_pair(0,0);
    table[2]=make_pair(5,0);
    table[3]=make_pair(2,0);
    table[4]=make_pair(3,0);
    table[5]=make_pair(INT_MAX,0);
    todlgate[2]=gate("todlB");
    todlgate[3]=gate("todlC");
    todlgate[4]=gate("todlD");
    delayStats.setName("Delay of Packets");
    delayStats.setRangeAutoUpper(0,10,2.0);
    delayVector.setName("Delay Vector");

    if(nid==1)
    {

    }
}

void NwlayerA::handleMessage(cMessage *msg)
{


}
void NwlayerA::updateDisplay()
{
    char buf[40];
    sprintf(buf, "rcvd: %d sent: %d", numRec, numSent);
    getDisplayString().setTagArg("t",0,buf);
}
void NwlayerA::finish(){
    EV << "Id=" << nid << endl;
    for(map<int,pair<int,int>>::iterator it = table.begin();it!=table.end();it++)
    {
        EV << it->first << " => " << (it->second).first << " => " << (it->second).first << endl;
    }
}
