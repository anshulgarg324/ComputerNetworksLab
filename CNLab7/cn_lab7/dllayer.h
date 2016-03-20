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

#ifndef __LAB2_DLLAYER_H_
#define __LAB2_DLLAYER_H_

#include <omnetpp.h>
#include "dllayer.h"
#include "DL_PDU_m.h"
#include <queue>
using namespace std;
/**
 * TODO - Generated class
 */
class Dllayer : public cSimpleModule
{
  private:
    simtime_t timeout;  // timeout
    cMessage *timeoutEvent,*delaysen,*delayrec;
    int start;
    int end;
    //DL_PDU *buffer[100];
    queue<DL_PDU*> buffer;
    DL_PDU *copydpdu,*copysen;
    int counter;
    int did;
    int numSent;
    int numRec;
  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void updateDisplay();
};

#endif
