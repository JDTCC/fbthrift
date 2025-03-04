/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.patch;

import com.facebook.swift.codec.*;
import com.facebook.swift.codec.ThriftField.Requiredness;
import com.facebook.swift.codec.ThriftField.Recursiveness;
import com.google.common.collect.*;
import java.util.*;
import javax.annotation.Nullable;
import org.apache.thrift.*;
import org.apache.thrift.transport.*;
import org.apache.thrift.protocol.*;
import static com.google.common.base.MoreObjects.toStringHelper;
import static com.google.common.base.MoreObjects.ToStringHelper;

@SwiftGenerated
@com.facebook.swift.codec.ThriftStruct(value="MyUnionPatch", builder=MyUnionPatch.Builder.class)
public final class MyUnionPatch implements com.facebook.thrift.payload.ThriftSerializable {

    @ThriftConstructor
    public MyUnionPatch(
        @com.facebook.swift.codec.ThriftField(value=1, name="assign", requiredness=Requiredness.OPTIONAL) final test.fixtures.patch.MyUnion assign,
        @com.facebook.swift.codec.ThriftField(value=2, name="clear", requiredness=Requiredness.NONE) final boolean clear,
        @com.facebook.swift.codec.ThriftField(value=3, name="patchPrior", requiredness=Requiredness.NONE) final test.fixtures.patch.MyUnionFieldPatch patchPrior,
        @com.facebook.swift.codec.ThriftField(value=4, name="ensure", requiredness=Requiredness.NONE) final test.fixtures.patch.MyUnion ensure,
        @com.facebook.swift.codec.ThriftField(value=6, name="patch", requiredness=Requiredness.NONE) final test.fixtures.patch.MyUnionFieldPatch patch
    ) {
        this.assign = assign;
        this.clear = clear;
        this.patchPrior = patchPrior;
        this.ensure = ensure;
        this.patch = patch;
    }
    
    @ThriftConstructor
    protected MyUnionPatch() {
      this.assign = null;
      this.clear = false;
      this.patchPrior = null;
      this.ensure = null;
      this.patch = null;
    }
    
    public static class Builder {
    
        private test.fixtures.patch.MyUnion assign = null;
        private boolean clear = false;
        private test.fixtures.patch.MyUnionFieldPatch patchPrior = null;
        private test.fixtures.patch.MyUnion ensure = null;
        private test.fixtures.patch.MyUnionFieldPatch patch = null;
    
        @com.facebook.swift.codec.ThriftField(value=1, name="assign", requiredness=Requiredness.OPTIONAL)
        public Builder setAssign(test.fixtures.patch.MyUnion assign) {
            this.assign = assign;
            return this;
        }
    
        public test.fixtures.patch.MyUnion getAssign() { return assign; }
    
            @com.facebook.swift.codec.ThriftField(value=2, name="clear", requiredness=Requiredness.NONE)
        public Builder setClear(boolean clear) {
            this.clear = clear;
            return this;
        }
    
        public boolean isClear() { return clear; }
    
            @com.facebook.swift.codec.ThriftField(value=3, name="patchPrior", requiredness=Requiredness.NONE)
        public Builder setPatchPrior(test.fixtures.patch.MyUnionFieldPatch patchPrior) {
            this.patchPrior = patchPrior;
            return this;
        }
    
        public test.fixtures.patch.MyUnionFieldPatch getPatchPrior() { return patchPrior; }
    
            @com.facebook.swift.codec.ThriftField(value=4, name="ensure", requiredness=Requiredness.NONE)
        public Builder setEnsure(test.fixtures.patch.MyUnion ensure) {
            this.ensure = ensure;
            return this;
        }
    
        public test.fixtures.patch.MyUnion getEnsure() { return ensure; }
    
            @com.facebook.swift.codec.ThriftField(value=6, name="patch", requiredness=Requiredness.NONE)
        public Builder setPatch(test.fixtures.patch.MyUnionFieldPatch patch) {
            this.patch = patch;
            return this;
        }
    
        public test.fixtures.patch.MyUnionFieldPatch getPatch() { return patch; }
    
        public Builder() { }
        public Builder(MyUnionPatch other) {
            this.assign = other.assign;
            this.clear = other.clear;
            this.patchPrior = other.patchPrior;
            this.ensure = other.ensure;
            this.patch = other.patch;
        }
    
        @ThriftConstructor
        public MyUnionPatch build() {
            MyUnionPatch result = new MyUnionPatch (
                this.assign,
                this.clear,
                this.patchPrior,
                this.ensure,
                this.patch
            );
            return result;
        }
    }
    
    public static final Map<String, Integer> NAMES_TO_IDS = new HashMap();
    public static final Map<String, Integer> THRIFT_NAMES_TO_IDS = new HashMap();
    public static final Map<Integer, TField> FIELD_METADATA = new HashMap<>();
    private static final TStruct STRUCT_DESC = new TStruct("MyUnionPatch");
    private final test.fixtures.patch.MyUnion assign;
    public static final int _ASSIGN = 1;
    private static final TField ASSIGN_FIELD_DESC = new TField("assign", TType.STRUCT, (short)1);
        private final boolean clear;
    public static final int _CLEAR = 2;
    private static final TField CLEAR_FIELD_DESC = new TField("clear", TType.BOOL, (short)2);
        private final test.fixtures.patch.MyUnionFieldPatch patchPrior;
    public static final int _PATCHPRIOR = 3;
    private static final TField PATCH_PRIOR_FIELD_DESC = new TField("patchPrior", TType.STRUCT, (short)3);
        private final test.fixtures.patch.MyUnion ensure;
    public static final int _ENSURE = 4;
    private static final TField ENSURE_FIELD_DESC = new TField("ensure", TType.STRUCT, (short)4);
        private final test.fixtures.patch.MyUnionFieldPatch patch;
    public static final int _PATCH = 6;
    private static final TField PATCH_FIELD_DESC = new TField("patch", TType.STRUCT, (short)6);
    static {
      NAMES_TO_IDS.put("assign", 1);
      THRIFT_NAMES_TO_IDS.put("assign", 1);
      FIELD_METADATA.put(1, ASSIGN_FIELD_DESC);
      NAMES_TO_IDS.put("clear", 2);
      THRIFT_NAMES_TO_IDS.put("clear", 2);
      FIELD_METADATA.put(2, CLEAR_FIELD_DESC);
      NAMES_TO_IDS.put("patchPrior", 3);
      THRIFT_NAMES_TO_IDS.put("patchPrior", 3);
      FIELD_METADATA.put(3, PATCH_PRIOR_FIELD_DESC);
      NAMES_TO_IDS.put("ensure", 4);
      THRIFT_NAMES_TO_IDS.put("ensure", 4);
      FIELD_METADATA.put(4, ENSURE_FIELD_DESC);
      NAMES_TO_IDS.put("patch", 6);
      THRIFT_NAMES_TO_IDS.put("patch", 6);
      FIELD_METADATA.put(6, PATCH_FIELD_DESC);
      com.facebook.thrift.type.TypeRegistry.add(new com.facebook.thrift.type.Type(
        new com.facebook.thrift.type.UniversalName("test.dev/fixtures/patch/MyUnionPatch"), 
        MyUnionPatch.class, MyUnionPatch::read0));
    }
    
    @Nullable
    @com.facebook.swift.codec.ThriftField(value=1, name="assign", requiredness=Requiredness.OPTIONAL)
    public test.fixtures.patch.MyUnion getAssign() { return assign; }
    
    
    
    @com.facebook.swift.codec.ThriftField(value=2, name="clear", requiredness=Requiredness.NONE)
    public boolean isClear() { return clear; }
    
    
    @Nullable
    @com.facebook.swift.codec.ThriftField(value=3, name="patchPrior", requiredness=Requiredness.NONE)
    public test.fixtures.patch.MyUnionFieldPatch getPatchPrior() { return patchPrior; }
    
    
    @Nullable
    @com.facebook.swift.codec.ThriftField(value=4, name="ensure", requiredness=Requiredness.NONE)
    public test.fixtures.patch.MyUnion getEnsure() { return ensure; }
    
    
    @Nullable
    @com.facebook.swift.codec.ThriftField(value=6, name="patch", requiredness=Requiredness.NONE)
    public test.fixtures.patch.MyUnionFieldPatch getPatch() { return patch; }
    
    @java.lang.Override
    public String toString() {
        ToStringHelper helper = toStringHelper(this);
        helper.add("assign", assign);
        helper.add("clear", clear);
        helper.add("patchPrior", patchPrior);
        helper.add("ensure", ensure);
        helper.add("patch", patch);
        return helper.toString();
    }
    
    @java.lang.Override
    public boolean equals(java.lang.Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || getClass() != o.getClass()) {
            return false;
        }
    
        MyUnionPatch other = (MyUnionPatch)o;
    
        return
            Objects.equals(assign, other.assign) &&
            Objects.equals(clear, other.clear) &&
            Objects.equals(patchPrior, other.patchPrior) &&
            Objects.equals(ensure, other.ensure) &&
            Objects.equals(patch, other.patch) &&
            true;
    }
    
    @java.lang.Override
    public int hashCode() {
        return Arrays.deepHashCode(new java.lang.Object[] {
            assign,
            clear,
            patchPrior,
            ensure,
            patch
        });
    }
    
    
    public static com.facebook.thrift.payload.Reader<MyUnionPatch> asReader() {
      return MyUnionPatch::read0;
    }
    
    public static MyUnionPatch read0(TProtocol oprot) throws TException {
      TField __field;
      oprot.readStructBegin(MyUnionPatch.NAMES_TO_IDS, MyUnionPatch.THRIFT_NAMES_TO_IDS, MyUnionPatch.FIELD_METADATA);
      MyUnionPatch.Builder builder = new MyUnionPatch.Builder();
      while (true) {
        __field = oprot.readFieldBegin();
        if (__field.type == TType.STOP) { break; }
        switch (__field.id) {
        case _ASSIGN:
          if (__field.type == TType.STRUCT) {
            test.fixtures.patch.MyUnion assign = test.fixtures.patch.MyUnion.read0(oprot);
            builder.setAssign(assign);
          } else {
            TProtocolUtil.skip(oprot, __field.type);
          }
          break;
        case _CLEAR:
          if (__field.type == TType.BOOL) {
            boolean clear = oprot.readBool();
            builder.setClear(clear);
          } else {
            TProtocolUtil.skip(oprot, __field.type);
          }
          break;
        case _PATCHPRIOR:
          if (__field.type == TType.STRUCT) {
            test.fixtures.patch.MyUnionFieldPatch patchPrior = test.fixtures.patch.MyUnionFieldPatch.read0(oprot);
            builder.setPatchPrior(patchPrior);
          } else {
            TProtocolUtil.skip(oprot, __field.type);
          }
          break;
        case _ENSURE:
          if (__field.type == TType.STRUCT) {
            test.fixtures.patch.MyUnion ensure = test.fixtures.patch.MyUnion.read0(oprot);
            builder.setEnsure(ensure);
          } else {
            TProtocolUtil.skip(oprot, __field.type);
          }
          break;
        case _PATCH:
          if (__field.type == TType.STRUCT) {
            test.fixtures.patch.MyUnionFieldPatch patch = test.fixtures.patch.MyUnionFieldPatch.read0(oprot);
            builder.setPatch(patch);
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
      if (assign != null) {
        oprot.writeFieldBegin(ASSIGN_FIELD_DESC);
        this.assign.write0(oprot);
        oprot.writeFieldEnd();
      }
      oprot.writeFieldBegin(CLEAR_FIELD_DESC);
      oprot.writeBool(this.clear);
      oprot.writeFieldEnd();
      if (patchPrior != null) {
        oprot.writeFieldBegin(PATCH_PRIOR_FIELD_DESC);
        this.patchPrior.write0(oprot);
        oprot.writeFieldEnd();
      }
      if (ensure != null) {
        oprot.writeFieldBegin(ENSURE_FIELD_DESC);
        this.ensure.write0(oprot);
        oprot.writeFieldEnd();
      }
      if (patch != null) {
        oprot.writeFieldBegin(PATCH_FIELD_DESC);
        this.patch.write0(oprot);
        oprot.writeFieldEnd();
      }
      oprot.writeFieldStop();
      oprot.writeStructEnd();
    }
    
    private static class _MyUnionPatchLazy {
        private static final MyUnionPatch _DEFAULT = new MyUnionPatch.Builder().build();
    }
    
    public static MyUnionPatch defaultInstance() {
        return  _MyUnionPatchLazy._DEFAULT;
    }
}
