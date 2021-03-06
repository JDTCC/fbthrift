/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.basic;

import com.facebook.swift.codec.*;
import com.facebook.swift.codec.ThriftField.Requiredness;
import com.facebook.swift.service.*;
import com.facebook.swift.transport.client.*;
import com.google.common.util.concurrent.ListenableFuture;
import java.io.*;
import java.util.*;

@SwiftGenerated
@com.facebook.swift.service.ThriftService("DbMixedStackArguments")
public interface DbMixedStackArguments extends java.io.Closeable {
    @com.facebook.swift.service.ThriftService("DbMixedStackArguments")
    public interface Async extends java.io.Closeable {
        @java.lang.Override void close();

        @ThriftMethod(value = "getDataByKey0")
        ListenableFuture<byte[]> getDataByKey0(
            @com.facebook.swift.codec.ThriftField(value=1, name="key", requiredness=Requiredness.NONE) final String key);

        default ListenableFuture<byte[]> getDataByKey0(
            @com.facebook.swift.codec.ThriftField(value=1, name="key", requiredness=Requiredness.NONE) final String key,
            RpcOptions rpcOptions) {
            throw new UnsupportedOperationException();
        }

        default ListenableFuture<ResponseWrapper<byte[]>> getDataByKey0Wrapper(
            @com.facebook.swift.codec.ThriftField(value=1, name="key", requiredness=Requiredness.NONE) final String key,
            RpcOptions rpcOptions) {
            throw new UnsupportedOperationException();
        }

        @ThriftMethod(value = "getDataByKey1")
        ListenableFuture<byte[]> getDataByKey1(
            @com.facebook.swift.codec.ThriftField(value=1, name="key", requiredness=Requiredness.NONE) final String key);

        default ListenableFuture<byte[]> getDataByKey1(
            @com.facebook.swift.codec.ThriftField(value=1, name="key", requiredness=Requiredness.NONE) final String key,
            RpcOptions rpcOptions) {
            throw new UnsupportedOperationException();
        }

        default ListenableFuture<ResponseWrapper<byte[]>> getDataByKey1Wrapper(
            @com.facebook.swift.codec.ThriftField(value=1, name="key", requiredness=Requiredness.NONE) final String key,
            RpcOptions rpcOptions) {
            throw new UnsupportedOperationException();
        }
    }
    @java.lang.Override void close();

    @ThriftMethod(value = "getDataByKey0")
    byte[] getDataByKey0(
        @com.facebook.swift.codec.ThriftField(value=1, name="key", requiredness=Requiredness.NONE) final String key) throws org.apache.thrift.TException;

    default byte[] getDataByKey0(
        @com.facebook.swift.codec.ThriftField(value=1, name="key", requiredness=Requiredness.NONE) final String key,
        RpcOptions rpcOptions) throws org.apache.thrift.TException {
        throw new UnsupportedOperationException();
    }

    default ResponseWrapper<byte[]> getDataByKey0Wrapper(
        @com.facebook.swift.codec.ThriftField(value=1, name="key", requiredness=Requiredness.NONE) final String key,
        RpcOptions rpcOptions) throws org.apache.thrift.TException {
        throw new UnsupportedOperationException();
    }

    @ThriftMethod(value = "getDataByKey1")
    byte[] getDataByKey1(
        @com.facebook.swift.codec.ThriftField(value=1, name="key", requiredness=Requiredness.NONE) final String key) throws org.apache.thrift.TException;

    default byte[] getDataByKey1(
        @com.facebook.swift.codec.ThriftField(value=1, name="key", requiredness=Requiredness.NONE) final String key,
        RpcOptions rpcOptions) throws org.apache.thrift.TException {
        throw new UnsupportedOperationException();
    }

    default ResponseWrapper<byte[]> getDataByKey1Wrapper(
        @com.facebook.swift.codec.ThriftField(value=1, name="key", requiredness=Requiredness.NONE) final String key,
        RpcOptions rpcOptions) throws org.apache.thrift.TException {
        throw new UnsupportedOperationException();
    }

    interface Reactive extends Closeable {
        @java.lang.Override void close();

        reactor.core.publisher.Mono<byte[]> getDataByKey0(final String key);

        default reactor.core.publisher.Mono<byte[]> getDataByKey0(final String key, RpcOptions rpcOptions) {
            throw new UnsupportedOperationException();
        }

        default reactor.core.publisher.Mono<ResponseWrapper<byte[]>> getDataByKey0Wrapper(final String key, RpcOptions rpcOptions) {
            throw new UnsupportedOperationException();
        }

        reactor.core.publisher.Mono<byte[]> getDataByKey1(final String key);

        default reactor.core.publisher.Mono<byte[]> getDataByKey1(final String key, RpcOptions rpcOptions) {
            throw new UnsupportedOperationException();
        }

        default reactor.core.publisher.Mono<ResponseWrapper<byte[]>> getDataByKey1Wrapper(final String key, RpcOptions rpcOptions) {
            throw new UnsupportedOperationException();
        }

    }
}
