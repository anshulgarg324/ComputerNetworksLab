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

network LayerNetwork
{
    submodules:
        nodeA: NodeA {
            nodeId = 1;
            @display("p=50,111");
        }
        nodeB: NodeB {
            nodeId = 2;
            @display("p=332,111");
        }
        nodeC: NodeC {
            nodeId = 3;
            @display("p=185,205");
        }
        nodeD: NodeD {
            nodeId = 4;
            @display("p=50,268");
        }
        nodeE: NodeE {
            nodeId = 5;
            @display("p=332,268");
        }
    connections:
        nodeA.tonodeB --> nodeB.fromnodeA;
        nodeA.fromnodeB <-- nodeB.tonodeA;
        nodeA.tonodeC --> nodeC.fromnodeA;
        nodeA.fromnodeC <-- nodeC.tonodeA;
        nodeA.tonodeD --> nodeD.fromnodeA;
        nodeA.fromnodeD <-- nodeD.tonodeA;
        nodeB.tonodeC --> nodeC.fromnodeB;
        nodeB.fromnodeC <-- nodeC.tonodeB;
        nodeB.tonodeE --> nodeE.fromnodeB;
        nodeB.fromnodeE <-- nodeE.tonodeB;
        nodeE.tonodeC --> nodeC.fromnodeE;
        nodeE.fromnodeC <-- nodeC.tonodeE;       
}
