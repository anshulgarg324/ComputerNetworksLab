//
// Generated file, do not edit! Created by nedtool 4.6 from NW_PDU.msg.
//

#ifndef _NW_PDU_M_H_
#define _NW_PDU_M_H_

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0406
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Class generated from <tt>NW_PDU.msg:19</tt> by nedtool.
 * <pre>
 * //
 * // TODO generated message class
 * //
 * packet NW_PDU
 * {
 *     simtime_t time;
 *     int srcAdd;
 *     int destAdd;
 * }
 * </pre>
 */
class NW_PDU : public ::cPacket
{
  protected:
    simtime_t time_var;
    int srcAdd_var;
    int destAdd_var;

  private:
    void copy(const NW_PDU& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const NW_PDU&);

  public:
    NW_PDU(const char *name=NULL, int kind=0);
    NW_PDU(const NW_PDU& other);
    virtual ~NW_PDU();
    NW_PDU& operator=(const NW_PDU& other);
    virtual NW_PDU *dup() const {return new NW_PDU(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual simtime_t getTime() const;
    virtual void setTime(simtime_t time);
    virtual int getSrcAdd() const;
    virtual void setSrcAdd(int srcAdd);
    virtual int getDestAdd() const;
    virtual void setDestAdd(int destAdd);
};

inline void doPacking(cCommBuffer *b, NW_PDU& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, NW_PDU& obj) {obj.parsimUnpack(b);}


#endif // ifndef _NW_PDU_M_H_

