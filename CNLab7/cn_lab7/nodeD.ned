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

package lab2;

module NodeD
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
    submodules:
        al: Alayer {
            aid = nodeId;
            counter = 0;
            pktSent=pktCount;
            src=srcAdd;
            @display("p=138,65");
        }
        nw: NwlayerD {
            nid = nodeId;
            src=srcAdd;
            dest=destAdd;
            @display("p=138,155");
        }
        dlA: Dllayer {
            did = nodeId;
            @display("p=138,238");
        }
        plA: Player {
            frameLoss=loss;
            @display("p=138,322");
        }
    connections:
        al.tonw --> nw.fromal;
        al.fromnw <-- nw.toal;
        nw.todlA --> dlA.fromnw;
        nw.fromdlA <-- dlA.tonw;
        dlA.toPout --> plA.fromdlin;
        dlA.fromPin <-- plA.todlout;
        plA.tonodeout --> tonodeA;
        plA.fromnodein <-- fromnodeA;
}
