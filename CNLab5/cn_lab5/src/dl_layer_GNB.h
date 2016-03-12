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

#ifndef __CN_LAB5_DL_LAYER_GNB_H_
#define __CN_LAB5_DL_LAYER_GNB_H_

#include <omnetpp.h>
#include <vector>
#include "DL_PDU_m.h"
using namespace std;

/**
 * TODO - Generated class
 */
class Dl_layer_GNB : public cSimpleModule
{
    int d_id;
    int k;
    vector<DL_PDU *> vec;
    int sl,s,sf;
    int flag;
    int counter;
    DL_PDU *copydpdu;
    simtime_t timeout;  // timeout
    cMessage *timeoutEvent,*delaysen,*delayrec;
    int numSent,numRec;
    simtime_t iniTime[26];
    simtime_t finalTime[26];
    cLongHistogram delayStats;
    cOutVector delayVector;
    cLongHistogram rttStats;
    cOutVector rttVector;
  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void updateDisplay();
    virtual void finish();
};

#endif
