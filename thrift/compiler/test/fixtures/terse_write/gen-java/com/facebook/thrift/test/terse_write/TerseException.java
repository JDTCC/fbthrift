/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package com.facebook.thrift.test.terse_write;

import com.facebook.swift.codec.*;
import com.facebook.swift.codec.ThriftField.Requiredness;
import com.facebook.swift.codec.ThriftField.Recursiveness;
import java.util.*;
import javax.annotation.Nullable;
import org.apache.thrift.*;
import org.apache.thrift.transport.*;
import org.apache.thrift.protocol.*;

@SwiftGenerated
@com.facebook.swift.codec.ThriftStruct("TerseException")
public final class TerseException extends org.apache.thrift.TBaseException implements com.facebook.thrift.payload.ThriftSerializable {
    private static final long serialVersionUID = 1L;


    public static final Map<String, Integer> NAMES_TO_IDS = new HashMap();
    public static final Map<String, Integer> THRIFT_NAMES_TO_IDS = new HashMap();
    public static final Map<Integer, TField> FIELD_METADATA = new HashMap<>();

    private static final TStruct STRUCT_DESC = new TStruct("TerseException");
    private final String msg;
    public static final int _MSG = 1;
    private static final TField MSG_FIELD_DESC = new TField("msg", TType.STRING, (short)1);

    static {
      com.facebook.thrift.type.TypeRegistry.add(new com.facebook.thrift.type.Type(
        new com.facebook.thrift.type.UniversalName("facebook.com/thrift/test/terse_write/TerseException"), 
        TerseException.class, TerseException::read0));
    }

    @ThriftConstructor
    public TerseException(
        @com.facebook.swift.codec.ThriftField(value=1, name="msg", requiredness=Requiredness.TERSE) final String msg
    ) {
        this.msg = msg;
    }
    
    @ThriftConstructor
    protected TerseException() {
      this.msg = com.facebook.thrift.util.IntrinsicDefaults.defaultString();
    }
    
    public static class Builder {
    
        private String msg = com.facebook.thrift.util.IntrinsicDefaults.defaultString();
    
        @com.facebook.swift.codec.ThriftField(value=1, name="msg", requiredness=Requiredness.TERSE)
        public Builder setMsg(String msg) {
            this.msg = msg;
            return this;
        }
    
        public String getMsg() { return msg; }
    
        public Builder() { }
        public Builder(TerseException other) {
            this.msg = other.msg;
        }
    
        @ThriftConstructor
        public TerseException build() {
            TerseException result = new TerseException (
                this.msg
            );
            return result;
        }
    }
    
    
    @Nullable
    @com.facebook.swift.codec.ThriftField(value=1, name="msg", requiredness=Requiredness.TERSE)
    public String getMsg() { return msg; }
        
    @java.lang.Override
    public String getMessage() {
      return msg;
    }
    
    public static com.facebook.thrift.payload.Reader<TerseException> asReader() {
      return TerseException::read0;
    }
    
    public static TerseException read0(TProtocol oprot) throws TException {
      TField __field;
      oprot.readStructBegin(TerseException.NAMES_TO_IDS, TerseException.THRIFT_NAMES_TO_IDS, TerseException.FIELD_METADATA);
      TerseException.Builder builder = new TerseException.Builder();
      while (true) {
        __field = oprot.readFieldBegin();
        if (__field.type == TType.STOP) { break; }
        switch (__field.id) {
        case _MSG:
          if (__field.type == TType.STRING) {
            String msg = oprot.readString();
            builder.setMsg(msg);
          } else {
            TProtocolUtil.skip(oprot, __field.type);
          }
          break;
        default:
          TProtocolUtil.skip(oprot, __field.type);
          break;
        }
        oprot.readFieldEnd();
      }
      oprot.readStructEnd();
      return builder.build();
    }
    
    public void write0(TProtocol oprot) throws TException {
      oprot.writeStructBegin(STRUCT_DESC);
      int structStart = 0;
      int pos = 0;
      com.facebook.thrift.protocol.ByteBufTProtocol p = (com.facebook.thrift.protocol.ByteBufTProtocol) oprot;
      java.util.Objects.requireNonNull(msg, "msg must not be null");
      
      if (!com.facebook.thrift.util.IntrinsicDefaults.isDefault(msg)) {
        oprot.writeFieldBegin(MSG_FIELD_DESC);
        oprot.writeString(this.msg);
        oprot.writeFieldEnd();
      }
      oprot.writeFieldStop();
      oprot.writeStructEnd();
    }
    
    private static class _TerseExceptionLazy {
        private static final TerseException _DEFAULT = new TerseException.Builder().build();
    }
    
    public static TerseException defaultInstance() {
        return  _TerseExceptionLazy._DEFAULT;
    }}
