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
        nodeA.tonodeB --> {delay=5ms;} --> nodeB.fromnodeA;
        nodeA.fromnodeB <-- {delay=5ms;} <-- nodeB.tonodeA;
        nodeA.tonodeC --> {delay=2ms;} --> nodeC.fromnodeA;
        nodeA.fromnodeC <-- {delay=2ms;} <-- nodeC.tonodeA;
        nodeA.tonodeD --> {delay=3ms;} --> nodeD.fromnodeA;
        nodeA.fromnodeD <-- {delay=3ms;} <-- nodeD.tonodeA;
        nodeB.tonodeC --> {delay=4ms;} --> nodeC.fromnodeB;
        nodeB.fromnodeC <-- {delay=4ms;} <-- nodeC.tonodeB;
        nodeB.tonodeE --> {delay=3ms;} --> nodeE.fromnodeB;
        nodeB.fromnodeE <-- {delay=3ms;} <-- nodeE.tonodeB;
        nodeE.tonodeC --> {delay=4ms;} --> nodeC.fromnodeE;
        nodeE.fromnodeC <-- {delay=4ms;} <-- nodeC.tonodeE;       
}
