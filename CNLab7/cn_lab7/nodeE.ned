//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT BNY WBRRBNTY; without even the implied warranty of
// MERCHBNTBBILITY or FITNESS FOR B PBRTICULBR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package lab2;

module NodeE
{
    parameters:
        int nodeId;
        int pktCount;
        double loss;
        int srcAdd;
        int destAdd;
    gates:
        input fromnodeB;
        output tonodeB;
        input fromnodeC;
        output tonodeC;
    submodules:
        al: Alayer {
            aid = nodeId;
            counter = 0;
            pktSent=pktCount;
            src=srcAdd;
            @display("p=138,65");
        }
        nw: NwlayerE {
            nid = nodeId;
            src=srcAdd;
            dest=destAdd;
            @display("p=138,155");
        }
        dlB: Dllayer {
            did = nodeId;
            @display("p=52,232");
        }
        dlC: Dllayer {
            did = nodeId;
            @display("p=223,232;is=l");
        }
        plB: Player {
            frameLoss=loss;
            @display("p=52,322");
        }
        plC: Player {
            frameLoss=loss;
            @display("p=223,322");
        }
    connections:
        al.tonw --> nw.fromal;
        al.fromnw <-- nw.toal;
        nw.todlB --> dlB.fromnw;
        nw.fromdlB <-- dlB.tonw;
        nw.todlC --> dlC.fromnw;
        nw.fromdlC <-- dlC.tonw;
        dlB.toPout --> plB.fromdlin;
        dlB.fromPin <-- plB.todlout;
        dlC.toPout --> plC.fromdlin;
        dlC.fromPin <-- plC.todlout;
        plB.tonodeout --> tonodeB;
        plB.fromnodein <-- fromnodeB;
        plC.tonodeout --> tonodeC;
        plC.fromnodein <-- fromnodeC;
}
