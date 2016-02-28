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
        n1:Node{nodeId=1;};
        n2:Node{nodeId=2;};
        hub: Hub;
    connections:
        n1.gout-->{delay=1ms;}-->hub.fromnode1;
        n1.gin<--{delay=1ms;}<--hub.tonode1;
        n2.gout-->{delay=1ms;}-->hub.fromnode2;
        n2.gin<--{delay=1ms;}<--hub.tonode2;
}
