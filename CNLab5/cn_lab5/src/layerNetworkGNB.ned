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

package cn_lab5;

network LayerNetworkGNB
{
    submodules:
        n1 : Node {node_id=1;};
        n2 : Node {node_id=2;};
        hub : Hub;
   	connections:
   	    n1.to_hub --> {delay=1ms;} --> hub.from_node1;
   	    n1.from_hub <-- {delay=1ms;} <-- hub.to_node1;
   	    n2.to_hub --> {delay=1ms;} --> hub.from_node2;
   	    n2.from_hub <-- {delay=1ms;} <-- hub.to_node2;
   	     
}
