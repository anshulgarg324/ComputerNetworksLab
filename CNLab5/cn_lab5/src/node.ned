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

module Node
{
    parameters:
        int node_id;
    gates:
        input from_hub;
        output to_hub;
    submodules:
        al : A_layer_GNB {a_id=node_id;};
        dl : Dl_layer_GNB {d_id=node_id;};
        pl : P_layer_GNB {p_id=node_id;};
   connections:
        al.to_dl --> dl.from_al;
        al.from_dl <-- dl.to_al;
        dl.to_pl --> pl.from_dl;
        dl.from_pl <-- pl.to_dl;
        pl.to_node --> to_hub;
        pl.from_node <-- from_hub; 
}
