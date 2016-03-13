//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERBHANTABILITY or FITNESS FOR A PARTIBULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package lab2;

module NodeC
{
	parameters:
        int nodeId;
        int pktCount;
        double loss;
        int srcAdd;
        int destAdd;
    gates:
        input fromnodeA;
        output tonodeA;
        input fromnodeB;
        output tonodeB;
        input fromnodeE;
        output tonodeE;
    submodules:
        al: Alayer {
            aid = nodeId;
            counter = 0;
            pktSent=pktCount;
            src=srcAdd;
            @display("p=138,65");
        }
        nw: NwlayerC {
            nid = nodeId;
            src=srcAdd;
            dest=destAdd;
            @display("p=138,155");
        }
        dlA: Dllayer {
            did = nodeId;
            @display("p=52,232");
        }
        dlB: Dllayer {
            did = nodeId;
            @display("p=138,232;is=l");
        }
        dlE: Dllayer {
            did = nodeId;
            @display("p=222,232");
        }
        plA: Player {
            frameLoss=loss;
            @display("p=52,322");
        }
        plB: Player {
            frameLoss=loss;
            @display("p=138,322");
        }
        plE: Player {
            frameLoss=loss;
            @display("p=222,322");
        }
    connections:
        al.tonw --> nw.fromal;
        al.fromnw <-- nw.toal;
        nw.todlA --> dlA.fromnw;
        nw.fromdlA <-- dlA.tonw;
        nw.todlB --> dlB.fromnw;
        nw.fromdlB <-- dlB.tonw;
        nw.todlE --> dlE.fromnw;
        nw.fromdlE <-- dlE.tonw;
        dlA.toPout --> plA.fromdlin;
        dlA.fromPin <-- plA.todlout;
        dlB.toPout --> plB.fromdlin;
        dlB.fromPin <-- plB.todlout;
        dlE.toPout --> plE.fromdlin;
        dlE.fromPin <-- plE.todlout;
        plA.tonodeout --> tonodeA;
        plA.fromnodein <-- fromnodeA;
        plB.tonodeout --> tonodeB;
        plB.fromnodein <-- fromnodeB;
        plE.tonodeout --> tonodeE;
        plE.fromnodein <-- fromnodeE;

}
