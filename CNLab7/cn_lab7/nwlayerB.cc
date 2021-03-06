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

#include "nwlayerB.h"
#include "R_PDU_m.h"
#include "A_PDU_m.h"
#include "NW_PDU_m.h"
Define_Module(NwlayerB);

void NwlayerB::initialize()
{
    nid=par("nid");
    src=par("src");
    dest=par("dest");
    numSent=0;
    numRec=0;
    table[1]=make_pair(5,0);
    table[2]=make_pair(0,0);
    table[3]=make_pair(4,0);
    table[4]=make_pair(INT_MAX,0);
    table[5]=make_pair(3,0);
    todlgate[1]=gate("todlA");
    todlgate[3]=gate("todlC");
    todlgate[5]=gate("todlE");
    gatetoId[gate("fromdlA")]=1;
    gatetoId[gate("fromdlC")]=3;
    gatetoId[gate("fromdlE")]=5;
    delayStats.setName("Delay of Packets");
    delayStats.setRangeAutoUpper(0,10,2.0);
    delayVector.setName("Delay Vector");
}

void NwlayerB::handleMessage(cMessage *msg)
{
    if(msg->isSelfMessage())
    {
        R_PDU *rpdu = new R_PDU();
        rpdu->setM(table);
        NW_PDU *npdu =new NW_PDU();
        npdu->encapsulate(rpdu);
        npdu->setType('R');
        for(map<int,cGate*>::iterator it=todlgate.begin();it!=todlgate.end();it++)
        {
            send(npdu->dup(),it->second);
        }
    }else{

        NW_PDU *npdu = check_and_cast<NW_PDU*>(msg);
        //cPacket *pkt = npdu->decapsulate();
        R_PDU *rpdu = check_and_cast<R_PDU*>(npdu->decapsulate());
        map<int,pair<int,int>> temp = rpdu->getM();
        int rpduSrc=gatetoId[msg->getArrivalGate()];
       // EV << "RPDUSRC=" << rpduSrc << endl;
        int flag=0;
        for(int i=1;i<=5;i++)
        {
            if(table[rpduSrc].first!=INT_MAX && temp[i].first!=INT_MAX)
            {
                if(table[i].first > (table[rpduSrc].first + temp[i].first))
                {
                    flag=1;
                    table[i].first=table[rpduSrc].first + temp[i].first;
                    table[i].second=rpduSrc;
                }
            }
        }
        delete(rpdu);
        if(flag)
        {
            R_PDU *rpdu = new R_PDU();
            rpdu->setM(table);
            NW_PDU *npdu =new NW_PDU();
            npdu->encapsulate(rpdu);
            npdu->setType('R');
            for(map<int,cGate*>::iterator it=todlgate.begin();it!=todlgate.end();it++)
            {
                send(npdu->dup(),it->second);
            }
        }
    }

}
void NwlayerB::updateDisplay()
{
    char buf[40];
    sprintf(buf, "rcvd: %d sent: %d", numRec, numSent);
    getDisplayString().setTagArg("t",0,buf);
}
void NwlayerB::finish(){
    EV << "Id=" << nid << endl;
    for(map<int,pair<int,int>>::iterator it = table.begin();it!=table.end();it++)
    {
        EV << it->first << " => " << (it->second).first << " => " << (it->second).second << endl;
    }
}
