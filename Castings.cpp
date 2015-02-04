What are the proper uses of:

static_cast
dynamic_cast
const_cast
reinterpret_cast
C-style cast (type)value
Function-style cast type(value)

static_cast can also cast through inheritance hierarchies. It is unnecessary when casting upwards
(towards a base class), but when casting downwards it can be used as long as it doesn't cast 
through virtual inheritance. It does not do checking, however, and it is undefined behavior 
to static_cast down a hierarchy to a type that isn't actually the type of the object.

const_cast can be used to remove or add const to a variable; no other C++ cast is capable of removing
it (not even reinterpret_cast). It is important to note that modifying a formerly const value is only
undefined if the original variable is const; if you use it to take the const off a reference to
something that wasn't declared with const, it is safe. This can be useful when overloading member
functions based on const, for instance. It can also be used to add const to an object, such as 
to call a member function overload.

dynamic_cast is almost exclusively used for handling polymorphism. You can cast a pointer or reference
to any polymorphic type to any other class type (a polymorphic type has at least one virtual function, 
declared or inherited). You can use it for more than just casting downwards -- you can cast sideways or
even up another chain. The dynamic_cast will seek out the desired object and return it if possible.
If it can't, it will return NULL in the case of a pointer, or throw std::bad_cast in the case of
a reference.

dynamic_cast has some limitations, though. It doesn't work if there are multiple objects of the 
same type in the inheritance hierarchy (the so-called 'dreaded diamond') and you aren't using 
virtual inheritance. It also can only go through public inheritance - it will always fail to 
travel through protected or private inheritance. This is rarely an issue, however, as such 
forms of inheritance are rare.

Below are some of the practical examples
when I used static_cast, dynamic_cast ,const_cast ,reinterpret_cast.

//static_cast
OnEventData(void* pData)
{
  ......

  //  pData is a void* pData, 

  //  EventData is a structure e.g. 
  //  typedef struct _EventData {
  //  std::string id;
  //  std:: string remote_id;
  //  } EventData;

  // On Some Situation a void pointer *pData
  // has been static_casted as 
  // EventData* pointer 

  EventData *evtdata = static_cast<EventData*>(pData);
  .....
}

//dynamic_cast
void DebugLog::OnMessage(Message *msg)
{
    // typecasting the message data based on the message type
    switch (msg->message_id)
    {
        case MSG_DEBUG_OUT:
        {
            DebugMsgData *data = dynamic_cast<DebugMsgData*>(msg->pdata);
                }

            case MSG_XYZ:
        {
            XYZMsgData *data = dynamic_cast<XYZMsgData*>(msg->pdata);
             }
         .....
         }
}

// *Passwd declared as a const
const unsigned char *Passwd
// on some situation it require to remove its constness
const_cast<unsigned char*>(Passwd)

typedef unsigned short uint16;
// Read Bytes returns that 2 bytes got read.

bool ByteBuffer::ReadUInt16(uint16& val)
{
  return ReadBytes(reinterpret_cast<char*>(&val), 2);
}
