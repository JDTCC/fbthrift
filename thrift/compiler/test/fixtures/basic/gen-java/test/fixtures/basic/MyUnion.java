/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.basic;

import com.facebook.swift.codec.*;
import com.facebook.swift.codec.ThriftField.Requiredness;
import com.facebook.swift.codec.ThriftField.Recursiveness;
import java.util.*;
import org.apache.thrift.*;
import org.apache.thrift.transport.*;
import org.apache.thrift.protocol.*;

import static com.google.common.base.MoreObjects.toStringHelper;

@SwiftGenerated
@ThriftUnion("MyUnion")
public final class MyUnion implements com.facebook.thrift.payload.ThriftSerializable {
    private static final TStruct STRUCT_DESC = new TStruct("MyUnion");
    private static final Map<String, Integer> NAMES_TO_IDS = new HashMap();
    public static final Map<String, Integer> THRIFT_NAMES_TO_IDS = new HashMap();
    private static final Map<Integer, TField> FIELD_METADATA = new HashMap<>();

    public static final int _MYENUM = 1;
    private static final TField MY_ENUM_FIELD_DESC = new TField("myEnum", TType.I32, (short)1);
    public static final int _MYSTRUCT = 2;
    private static final TField MY_STRUCT_FIELD_DESC = new TField("myStruct", TType.STRUCT, (short)2);
    public static final int _MYDATAITEM = 3;
    private static final TField MY_DATA_ITEM_FIELD_DESC = new TField("myDataItem", TType.STRUCT, (short)3);
    public static final int _FLOATSET = 4;
    private static final TField FLOAT_SET_FIELD_DESC = new TField("floatSet", TType.SET, (short)4);

    static {
      NAMES_TO_IDS.put("myEnum", 1);
      THRIFT_NAMES_TO_IDS.put("myEnum", 1);
      FIELD_METADATA.put(1, MY_ENUM_FIELD_DESC);
      NAMES_TO_IDS.put("myStruct", 2);
      THRIFT_NAMES_TO_IDS.put("myStruct", 2);
      FIELD_METADATA.put(2, MY_STRUCT_FIELD_DESC);
      NAMES_TO_IDS.put("myDataItem", 3);
      THRIFT_NAMES_TO_IDS.put("myDataItem", 3);
      FIELD_METADATA.put(3, MY_DATA_ITEM_FIELD_DESC);
      NAMES_TO_IDS.put("floatSet", 4);
      THRIFT_NAMES_TO_IDS.put("floatSet", 4);
      FIELD_METADATA.put(4, FLOAT_SET_FIELD_DESC);
    }

    private Object value;
    private short id;

    @ThriftConstructor
    public MyUnion() {
    }
    
    @ThriftConstructor
    @Deprecated
    public MyUnion(final test.fixtures.basic.MyEnum myEnum) {
        this.value = myEnum;
        this.id = 1;
    }
    
    @ThriftConstructor
    @Deprecated
    public MyUnion(final test.fixtures.basic.MyStruct myStruct) {
        this.value = myStruct;
        this.id = 2;
    }
    
    @ThriftConstructor
    @Deprecated
    public MyUnion(final test.fixtures.basic.MyDataItem myDataItem) {
        this.value = myDataItem;
        this.id = 3;
    }
    
    @ThriftConstructor
    @Deprecated
    public MyUnion(final Set<Float> floatSet) {
        this.value = floatSet;
        this.id = 4;
    }
    
    public static MyUnion fromMyEnum(final test.fixtures.basic.MyEnum myEnum) {
        MyUnion res = new MyUnion();
        res.value = myEnum;
        res.id = 1;
        return res;
    }
    
    public static MyUnion fromMyStruct(final test.fixtures.basic.MyStruct myStruct) {
        MyUnion res = new MyUnion();
        res.value = myStruct;
        res.id = 2;
        return res;
    }
    
    public static MyUnion fromMyDataItem(final test.fixtures.basic.MyDataItem myDataItem) {
        MyUnion res = new MyUnion();
        res.value = myDataItem;
        res.id = 3;
        return res;
    }
    
    public static MyUnion fromFloatSet(final Set<Float> floatSet) {
        MyUnion res = new MyUnion();
        res.value = floatSet;
        res.id = 4;
        return res;
    }
    

    @com.facebook.swift.codec.ThriftField(value=1, name="myEnum", requiredness=Requiredness.NONE)
    public test.fixtures.basic.MyEnum getMyEnum() {
        if (this.id != 1) {
            throw new IllegalStateException("Not a myEnum element!");
        }
        return (test.fixtures.basic.MyEnum) value;
    }

    public boolean isSetMyEnum() {
        return this.id == 1;
    }

    @com.facebook.swift.codec.ThriftField(value=2, name="myStruct", requiredness=Requiredness.NONE)
    public test.fixtures.basic.MyStruct getMyStruct() {
        if (this.id != 2) {
            throw new IllegalStateException("Not a myStruct element!");
        }
        return (test.fixtures.basic.MyStruct) value;
    }

    public boolean isSetMyStruct() {
        return this.id == 2;
    }

    @com.facebook.swift.codec.ThriftField(value=3, name="myDataItem", requiredness=Requiredness.NONE)
    public test.fixtures.basic.MyDataItem getMyDataItem() {
        if (this.id != 3) {
            throw new IllegalStateException("Not a myDataItem element!");
        }
        return (test.fixtures.basic.MyDataItem) value;
    }

    public boolean isSetMyDataItem() {
        return this.id == 3;
    }

    @com.facebook.swift.codec.ThriftField(value=4, name="floatSet", requiredness=Requiredness.NONE)
    public Set<Float> getFloatSet() {
        if (this.id != 4) {
            throw new IllegalStateException("Not a floatSet element!");
        }
        return (Set<Float>) value;
    }

    public boolean isSetFloatSet() {
        return this.id == 4;
    }

    @ThriftUnionId
    public short getThriftId() {
        return this.id;
    }

    public String getThriftName() {
        TField tField = (TField) FIELD_METADATA.get((int) this.id);
        if (tField == null) {
            return "null";
        } else {
            return tField.name;
        }
    }

    public void accept(Visitor visitor) {
        if (isSetMyEnum()) {
            visitor.visitMyEnum(getMyEnum());
            return;
        }
        if (isSetMyStruct()) {
            visitor.visitMyStruct(getMyStruct());
            return;
        }
        if (isSetMyDataItem()) {
            visitor.visitMyDataItem(getMyDataItem());
            return;
        }
        if (isSetFloatSet()) {
            visitor.visitFloatSet(getFloatSet());
            return;
        }
    }

    @Override
    public String toString() {
        return toStringHelper(this)
            .add("value", value)
            .add("id", id)
            .add("name", getThriftName())
            .add("type", value == null ? "<null>" : value.getClass().getSimpleName())
            .toString();
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || getClass() != o.getClass()) {
            return false;
        }

        MyUnion other = (MyUnion)o;

        return Objects.equals(this.id, other.id)
                && Objects.deepEquals(this.value, other.value);
    }

    @Override
    public int hashCode() {
        return Arrays.deepHashCode(new Object[] {
            id,
            value,
        });
    }

    public interface Visitor {
        void visitMyEnum(test.fixtures.basic.MyEnum myEnum);
        void visitMyStruct(test.fixtures.basic.MyStruct myStruct);
        void visitMyDataItem(test.fixtures.basic.MyDataItem myDataItem);
        void visitFloatSet(Set<Float> floatSet);
    }

    public void write0(TProtocol oprot) throws TException {
      if (this.id != 0 && this.value == null ){
         return;
      }
      oprot.writeStructBegin(STRUCT_DESC);
      switch (this.id) {
      case _MYENUM: {
        oprot.writeFieldBegin(MY_ENUM_FIELD_DESC);
        test.fixtures.basic.MyEnum myEnum = (test.fixtures.basic.MyEnum)this.value;
        oprot.writeI32(myEnum == null ? 0 : myEnum.getValue());
        oprot.writeFieldEnd();
        break;
      }
      case _MYSTRUCT: {
        oprot.writeFieldBegin(MY_STRUCT_FIELD_DESC);
        test.fixtures.basic.MyStruct myStruct = (test.fixtures.basic.MyStruct)this.value;
        myStruct.write0(oprot);
        oprot.writeFieldEnd();
        break;
      }
      case _MYDATAITEM: {
        oprot.writeFieldBegin(MY_DATA_ITEM_FIELD_DESC);
        test.fixtures.basic.MyDataItem myDataItem = (test.fixtures.basic.MyDataItem)this.value;
        myDataItem.write0(oprot);
        oprot.writeFieldEnd();
        break;
      }
      case _FLOATSET: {
        oprot.writeFieldBegin(FLOAT_SET_FIELD_DESC);
        Set<Float> _iter0 = (Set<Float>)this.value;
        oprot.writeSetBegin(new TSet(TType.FLOAT, _iter0.size()));
        for (float _iter1 : _iter0) {
          oprot.writeFloat(_iter1);
        }
        oprot.writeSetEnd();
        oprot.writeFieldEnd();
        break;
      }
      default:
          // ignore unknown field
      }
      oprot.writeFieldStop();
      oprot.writeStructEnd();
    }
    
    
    public static com.facebook.thrift.payload.Reader<MyUnion> asReader() {
      return MyUnion::read0;
    }
    
    public static MyUnion read0(TProtocol oprot) throws TException {
      MyUnion res = new MyUnion();
      res.value = null;
      res.id = (short) 0;
      oprot.readStructBegin(MyUnion.NAMES_TO_IDS, MyUnion.THRIFT_NAMES_TO_IDS, MyUnion.FIELD_METADATA);
      TField __field = oprot.readFieldBegin();
      if (__field.type != TType.STOP) {
          switch (__field.id) {
          case _MYENUM:
            if (__field.type == MY_ENUM_FIELD_DESC.type) {
              test.fixtures.basic.MyEnum myEnum = test.fixtures.basic.MyEnum.fromInteger(oprot.readI32());
              res.value = myEnum;
            }
            break;
          case _MYSTRUCT:
            if (__field.type == MY_STRUCT_FIELD_DESC.type) {
              test.fixtures.basic.MyStruct myStruct = test.fixtures.basic.MyStruct.read0(oprot);
              res.value = myStruct;
            }
            break;
          case _MYDATAITEM:
            if (__field.type == MY_DATA_ITEM_FIELD_DESC.type) {
              test.fixtures.basic.MyDataItem myDataItem = test.fixtures.basic.MyDataItem.read0(oprot);
              res.value = myDataItem;
            }
            break;
          case _FLOATSET:
            if (__field.type == FLOAT_SET_FIELD_DESC.type) {
              Set<Float> floatSet;
            {
            TSet _set = oprot.readSetBegin();
            floatSet = new HashSet<Float>(Math.max(0, _set.size));
            for (int _i = 0; (_set.size < 0) ? oprot.peekSet() : (_i < _set.size); _i++) {
                
                float _value1 = oprot.readFloat();
                floatSet.add(_value1);
            }
            oprot.readSetEnd();
            }
              res.value = floatSet;
            }
            break;
          default:
            TProtocolUtil.skip(oprot, __field.type);
          }
        if (res.value != null) {
          res.id = __field.id;
        }
        oprot.readFieldEnd();
        TField __stopField = oprot.readFieldBegin(); // Consume the STOP byte
        if (__stopField.type != TType.STOP) {
          throw new TProtocolException(TProtocolException.INVALID_DATA, "Union 'MyUnion' is missing a STOP byte");
        }
      }
      oprot.readStructEnd();
      return res;
    }
}
