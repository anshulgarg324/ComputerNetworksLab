//
// Generated file, do not edit! Created by nedtool 4.6 from Ack.msg.
//

#ifndef _ACK_M_H_
#define _ACK_M_H_

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0406
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Class generated from <tt>Ack.msg:16</tt> by nedtool.
 * <pre>
 * //
 * // This program is free software: you can redistribute it and/or modify
 * // it under the terms of the GNU Lesser General Public License as published by
 * // the Free Software Foundation, either version 3 of the License, or
 * // (at your option) any later version.
 * // 
 * // This program is distributed in the hope that it will be useful,
 * // but WITHOUT ANY WARRANTY; without even the implied warranty of
 * // MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * // GNU Lesser General Public License for more details.
 * // 
 * // You should have received a copy of the GNU Lesser General Public License
 * // along with this program.  If not, see http://www.gnu.org/licenses/.
 * //
 * packet Ack
 * {
 * }
 * </pre>
 */
class Ack : public ::cPacket
{
  protected:

  private:
    void copy(const Ack& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const Ack&);

  public:
    Ack(const char *name=NULL, int kind=0);
    Ack(const Ack& other);
    virtual ~Ack();
    Ack& operator=(const Ack& other);
    virtual Ack *dup() const {return new Ack(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
};

inline void doPacking(cCommBuffer *b, Ack& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, Ack& obj) {obj.parsimUnpack(b);}


#endif // ifndef _ACK_M_H_

