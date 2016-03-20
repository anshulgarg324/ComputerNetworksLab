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

#ifndef __CN_LAB6_NWLAYERE_H_
#define __CN_LAB6_NWLAYERE_H_

#include <omnetpp.h>
#include <utility>
#include <map>
#include <limits>
using namespace std;
/**
 * TODO - Generated class
 */
class NwlayerE : public cSimpleModule
{
    int nid;
    int src;
    int dest;
    int numSent;
    int numRec;
    map<int,pair<int,int>> table;
    map<int,cGate*> todlgate;
    cLongHistogram delayStats;
    cOutVector delayVector;

  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void updateDisplay();
    virtual void finish();
};

#endif
