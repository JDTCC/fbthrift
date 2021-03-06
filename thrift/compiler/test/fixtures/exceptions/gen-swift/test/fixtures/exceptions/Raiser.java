/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.exceptions;

import com.facebook.swift.codec.*;
import com.facebook.swift.codec.ThriftField.Requiredness;
import com.facebook.swift.service.*;
import com.facebook.swift.transport.client.*;
import com.google.common.util.concurrent.ListenableFuture;
import java.io.*;
import java.util.*;

@SwiftGenerated
@com.facebook.swift.service.ThriftService("Raiser")
public interface Raiser extends java.io.Closeable {
    @com.facebook.swift.service.ThriftService("Raiser")
    public interface Async extends java.io.Closeable {
        @java.lang.Override void close();

        @ThriftMethod(value = "doBland")
        ListenableFuture<Void> doBland();

        default ListenableFuture<Void> doBland(
            RpcOptions rpcOptions) {
            throw new UnsupportedOperationException();
        }

        default ListenableFuture<ResponseWrapper<Void>> doBlandWrapper(
            RpcOptions rpcOptions) {
            throw new UnsupportedOperationException();
        }

        @ThriftMethod(value = "doRaise",
                      exception = { 
                          @ThriftException(type=test.fixtures.exceptions.Banal.class, id=1),
                          @ThriftException(type=test.fixtures.exceptions.Fiery.class, id=2),
                          @ThriftException(type=test.fixtures.exceptions.Serious.class, id=3)
                      })
        ListenableFuture<Void> doRaise();

        default ListenableFuture<Void> doRaise(
            RpcOptions rpcOptions) {
            throw new UnsupportedOperationException();
        }

        default ListenableFuture<ResponseWrapper<Void>> doRaiseWrapper(
            RpcOptions rpcOptions) {
            throw new UnsupportedOperationException();
        }

        @ThriftMethod(value = "get200")
        ListenableFuture<String> get200();

        default ListenableFuture<String> get200(
            RpcOptions rpcOptions) {
            throw new UnsupportedOperationException();
        }

        default ListenableFuture<ResponseWrapper<String>> get200Wrapper(
            RpcOptions rpcOptions) {
            throw new UnsupportedOperationException();
        }

        @ThriftMethod(value = "get500",
                      exception = { 
                          @ThriftException(type=test.fixtures.exceptions.Fiery.class, id=1),
                          @ThriftException(type=test.fixtures.exceptions.Banal.class, id=2),
                          @ThriftException(type=test.fixtures.exceptions.Serious.class, id=3)
                      })
        ListenableFuture<String> get500();

        default ListenableFuture<String> get500(
            RpcOptions rpcOptions) {
            throw new UnsupportedOperationException();
        }

        default ListenableFuture<ResponseWrapper<String>> get500Wrapper(
            RpcOptions rpcOptions) {
            throw new UnsupportedOperationException();
        }
    }
    @java.lang.Override void close();

    @ThriftMethod(value = "doBland")
    void doBland() throws org.apache.thrift.TException;

    default void doBland(
        RpcOptions rpcOptions) throws org.apache.thrift.TException {
        throw new UnsupportedOperationException();
    }

    default ResponseWrapper<Void> doBlandWrapper(
        RpcOptions rpcOptions) throws org.apache.thrift.TException {
        throw new UnsupportedOperationException();
    }

    @ThriftMethod(value = "doRaise",
                  exception = { 
                      @ThriftException(type=test.fixtures.exceptions.Banal.class, id=1),
                      @ThriftException(type=test.fixtures.exceptions.Fiery.class, id=2),
                      @ThriftException(type=test.fixtures.exceptions.Serious.class, id=3)
                  })
    void doRaise() throws test.fixtures.exceptions.Banal, test.fixtures.exceptions.Fiery, test.fixtures.exceptions.Serious, org.apache.thrift.TException;

    default void doRaise(
        RpcOptions rpcOptions) throws test.fixtures.exceptions.Banal, test.fixtures.exceptions.Fiery, test.fixtures.exceptions.Serious, org.apache.thrift.TException {
        throw new UnsupportedOperationException();
    }

    default ResponseWrapper<Void> doRaiseWrapper(
        RpcOptions rpcOptions) throws test.fixtures.exceptions.Banal, test.fixtures.exceptions.Fiery, test.fixtures.exceptions.Serious, org.apache.thrift.TException {
        throw new UnsupportedOperationException();
    }

    @ThriftMethod(value = "get200")
    String get200() throws org.apache.thrift.TException;

    default String get200(
        RpcOptions rpcOptions) throws org.apache.thrift.TException {
        throw new UnsupportedOperationException();
    }

    default ResponseWrapper<String> get200Wrapper(
        RpcOptions rpcOptions) throws org.apache.thrift.TException {
        throw new UnsupportedOperationException();
    }

    @ThriftMethod(value = "get500",
                  exception = { 
                      @ThriftException(type=test.fixtures.exceptions.Fiery.class, id=1),
                      @ThriftException(type=test.fixtures.exceptions.Banal.class, id=2),
                      @ThriftException(type=test.fixtures.exceptions.Serious.class, id=3)
                  })
    String get500() throws test.fixtures.exceptions.Fiery, test.fixtures.exceptions.Banal, test.fixtures.exceptions.Serious, org.apache.thrift.TException;

    default String get500(
        RpcOptions rpcOptions) throws test.fixtures.exceptions.Fiery, test.fixtures.exceptions.Banal, test.fixtures.exceptions.Serious, org.apache.thrift.TException {
        throw new UnsupportedOperationException();
    }

    default ResponseWrapper<String> get500Wrapper(
        RpcOptions rpcOptions) throws test.fixtures.exceptions.Fiery, test.fixtures.exceptions.Banal, test.fixtures.exceptions.Serious, org.apache.thrift.TException {
        throw new UnsupportedOperationException();
    }

    interface Reactive extends Closeable {
        @java.lang.Override void close();

        reactor.core.publisher.Mono<Void> doBland();

        default reactor.core.publisher.Mono<Void> doBland(RpcOptions rpcOptions) {
            throw new UnsupportedOperationException();
        }

        default reactor.core.publisher.Mono<ResponseWrapper<Void>> doBlandWrapper(RpcOptions rpcOptions) {
            throw new UnsupportedOperationException();
        }

        reactor.core.publisher.Mono<Void> doRaise();

        default reactor.core.publisher.Mono<Void> doRaise(RpcOptions rpcOptions) {
            throw new UnsupportedOperationException();
        }

        default reactor.core.publisher.Mono<ResponseWrapper<Void>> doRaiseWrapper(RpcOptions rpcOptions) {
            throw new UnsupportedOperationException();
        }

        reactor.core.publisher.Mono<String> get200();

        default reactor.core.publisher.Mono<String> get200(RpcOptions rpcOptions) {
            throw new UnsupportedOperationException();
        }

        default reactor.core.publisher.Mono<ResponseWrapper<String>> get200Wrapper(RpcOptions rpcOptions) {
            throw new UnsupportedOperationException();
        }

        reactor.core.publisher.Mono<String> get500();

        default reactor.core.publisher.Mono<String> get500(RpcOptions rpcOptions) {
            throw new UnsupportedOperationException();
        }

        default reactor.core.publisher.Mono<ResponseWrapper<String>> get500Wrapper(RpcOptions rpcOptions) {
            throw new UnsupportedOperationException();
        }

    }
}
